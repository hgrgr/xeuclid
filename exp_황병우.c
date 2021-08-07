#include <stdio.h>
#include <openssl/bn.h>

void printBN(char *msg, BIGNUM *a)
{
	char * number_str = BN_bn2dec(a);
	printf("%s %s\n", msg, number_str);
	OPENSSL_free(number_str);
}

int getBufSize(int num);	

void printBuf(unsigned char *buf,int size);

void ExpMod(BIGNUM* res,BIGNUM *a,BIGNUM *e,BIGNUM *m)
{
// res =  a^e (mod m)
	int anum = BN_num_bits(a);
	int bnum = BN_num_bits(e);
	int cnum = BN_num_bits(m);
	int bnum_buf = getBufSize(bnum);	
	BN_CTX *ctx = BN_CTX_new();

	BIGNUM *temp_a = BN_new();
//	BIGNUM *real = BN_new();
//	BN_mod_exp(real,a,e,m,ctx);
	BN_dec2bn(&temp_a,"1");
//	printBN("test",temp_a);	
	unsigned char *buf = (unsigned char*)malloc(sizeof(unsigned char)*bnum_buf);
	BN_bn2bin(e,buf);	
	//printBuf(buf,bnum_buf);

	int first_bit = bnum - bnum_buf*8 ;
	//printf("bit - %d\n", first_bit);
	for(int i=0; i < bnum_buf; i++)
	{
	/*
		printf("%x ",(buf[i] & 128)>>7);		
		printf("%x ",(buf[i] & 64)>>6);		
		printf("%x ",(buf[i] & 32)>>5);		
		printf("%x ",(buf[i] & 16)>>4);		
		printf("%x ",(buf[i] & 8)>>3);		
		printf("%x ",(buf[i] & 4)>>2);		
		printf("%x ",(buf[i] & 2)>>1);		
		printf("%x ",(buf[i] & 1)>>0);		
		printf("\n");
	*/	
		if((buf[i] & 128)>>7 == 1){
			first_bit++;
			if(first_bit > 0){
				BN_sqr(temp_a,temp_a,ctx);// (An-1)^2
				BN_mul(temp_a,temp_a, a, ctx);	//(An-1)^2 * A
				BN_mod(temp_a,temp_a,m,ctx);
			}
		}else{
			first_bit++;
			if(first_bit > 0){
				BN_sqr(temp_a,temp_a,ctx);//  ^2
				BN_mod(temp_a,temp_a,m,ctx);
			}

		}
		if((buf[i] & 64)>>6 == 1){
			first_bit++;
			if(first_bit > 0){
				BN_sqr(temp_a,temp_a,ctx);// (An-1)^2
				BN_mul(temp_a,temp_a, a, ctx);	//(An-1)^2 * A
				BN_mod(temp_a,temp_a,m,ctx);
			}

		}else{
			first_bit++;
			if(first_bit > 0){
				BN_sqr(temp_a,temp_a,ctx);//  ^2
				BN_mod(temp_a,temp_a,m,ctx);
			}

		}
		if((buf[i] & 32)>>5 == 1){
			first_bit++;
			if(first_bit > 0){
				BN_sqr(temp_a,temp_a,ctx);// (An-1)^2
				BN_mul(temp_a,temp_a, a, ctx);	//(An-1)^2 * A
				BN_mod(temp_a,temp_a,m,ctx);
			}

		}else{
			first_bit++;
			if(first_bit > 0){
				BN_sqr(temp_a,temp_a,ctx);//  ^2
				BN_mod(temp_a,temp_a,m,ctx);
			}

		}
		if((buf[i] & 16)>>4 == 1){
			first_bit++;
			if(first_bit > 0){
				BN_sqr(temp_a,temp_a,ctx);// (An-1)^2
				BN_mul(temp_a,temp_a, a, ctx);	//(An-1)^2 * A
				BN_mod(temp_a,temp_a,m,ctx);
			}

		}else{
			first_bit++;
			if(first_bit > 0){
				BN_sqr(temp_a,temp_a,ctx);//  ^2
				BN_mod(temp_a,temp_a,m,ctx);
			}

		}
		if((buf[i] & 8)>>3 == 1){
			first_bit++;
			if(first_bit > 0){
				BN_sqr(temp_a,temp_a,ctx);// (An-1)^2
				BN_mul(temp_a,temp_a, a, ctx);	//(An-1)^2 * A
				BN_mod(temp_a,temp_a,m,ctx);
			}

		}else{
			first_bit++;
			if(first_bit > 0){
				BN_sqr(temp_a,temp_a,ctx);//  ^2
				BN_mod(temp_a,temp_a,m,ctx);
			}

		}
		if((buf[i] & 4)>>2 == 1){
			first_bit++;
			if(first_bit > 0){
				BN_sqr(temp_a,temp_a,ctx);// (An-1)^2
				BN_mul(temp_a,temp_a, a, ctx);	//(An-1)^2 * A
				BN_mod(temp_a,temp_a,m,ctx);
			}

		}else{
			first_bit++;
			if(first_bit > 0){
				BN_sqr(temp_a,temp_a,ctx);//  ^2
				BN_mod(temp_a,temp_a,m,ctx);
			}

		}
		if((buf[i] & 2)>>1 == 1){
			first_bit++;
			if(first_bit > 0){
				BN_sqr(temp_a,temp_a,ctx);// (An-1)^2
				BN_mul(temp_a,temp_a, a, ctx);	//(An-1)^2 * A
				BN_mod(temp_a,temp_a,m,ctx);
			}

		}else{
			first_bit++;
			if(first_bit > 0){
				BN_sqr(temp_a,temp_a,ctx);//  ^2
				BN_mod(temp_a,temp_a,m,ctx);
			}

		}
		if((buf[i] & 1)>>0 == 1){
			first_bit++;
			if(first_bit > 0){
				BN_sqr(temp_a,temp_a,ctx);// (An-1)^2
				BN_mul(temp_a,temp_a, a, ctx);	//(An-1)^2 * A
				BN_mod(temp_a,temp_a,m,ctx);
			}

		}else{
			first_bit++;
			if(first_bit > 0){
				BN_sqr(temp_a,temp_a,ctx);//  ^2
				BN_mod(temp_a,temp_a,m,ctx);
			}

		}
	}
	BN_copy(res,temp_a);
//	printf("bit size = %d\n", first_bit);
//	printBN("my answer = ", temp_a);
//	printBN("real answer= ", real);
}
/*
void printBN(char *msg, BIGNUM *a)
{
	char * number_str = BN_bn2dec(a);
	printf("%s %s\n", msg, number_str);
	OPENSSL_free(number_str);
}
*/

int main(int argc, char* argv[])
{
	BIGNUM *a = BN_new();
	BIGNUM *e = BN_new();
	BIGNUM *m = BN_new();
	BIGNUM *res = BN_new();
	BIGNUM *real = BN_new();
//	BN_CTX *ctx = BN_CTX_new();
	
	if(argc != 4)
	{
		printf("usage: exp base exponent modulus\n");
		return -1;
	}

	BN_dec2bn(&a,argv[1]);
	BN_dec2bn(&e,argv[2]);
	BN_dec2bn(&m,argv[3]);

	printBN("a = ", a);
	printBN("e = ", e);
	printBN("m = ", m);

	ExpMod(res,a,e,m);
//	BN_mod_exp(real,a,e,m,ctx);
	printBN("a**e mod m = ", res);
//	printBN("real a**e mod m = ", real);
	if(a != NULL) BN_free(a);
	if(e != NULL) BN_free(e);
	if(m != NULL) BN_free(m);
	if(res != NULL) BN_free(res);

	return 0;
}	
void printBuf(unsigned char *buf, int size){
	printf("usinged char buf = ");

	for(int i=0;i <size; i++)
	{
		printf("%x ", buf[i]);
	}
	printf("\n");
}

int getBufSize(int num){
	int div;
	int mod;
	div = num /8;
	mod = num % 8;

	if(mod !=0)
	{
		div +=1;
	}

	//printf("buf size =%d \n" ,div);
	return div;
}
