#include <stdio.h>
#include <openssl/bn.h>

void printBN(char * msg, BIGNUM * num)
{
	char *number = BN_bn2dec(num);
	printf("%s %s\n",msg,number);
}

BIGNUM *XEuclid(BIGNUM *x, BIGNUM *y, const BIGNUM *a, const BIGNUM *b)
{
	BN_CTX *ctx =BN_CTX_new();
	BIGNUM *tx = BN_new();
	BIGNUM *ty= BN_new();
	BIGNUM *ta = BN_new();
	BIGNUM *tb = BN_new();
	int chang =0;	
	BN_copy(tx,x);		
	BN_copy(ty,y);		
	BN_copy(ta,a);		
	BN_copy(tb,b);	

	BIGNUM *r = BN_new();
	BIGNUM *t= BN_new();
	BIGNUM *dap = BN_new();
	BIGNUM *q = BN_new();
	BIGNUM *temp = BN_new();
	BIGNUM *rem = BN_new();
	BIGNUM *temp_x1 = BN_new();
	BIGNUM *temp_y1 = BN_new();
	BIGNUM *temp_x2 = BN_new();
	BIGNUM *temp_y2 = BN_new();
	BIGNUM *temp_x3 = BN_new();
	BIGNUM *temp_y3 = BN_new();
	BIGNUM *tempx = BN_new();
	BIGNUM *tempy = BN_new();
	
	BN_dec2bn(&temp_x1,"1");
	BN_dec2bn(&temp_y1,"0");
	BN_dec2bn(&temp_x2,"0");
	BN_dec2bn(&temp_y2,"1");

	int ebit = 0;


	if(BN_cmp(ta,tb)<0){// if a< b swap
		t = ta;
		ta = tb;
		tb = t;
		chang =1;
	}
	while(!BN_is_zero(tb)){//get q
		if(!BN_mod(r,ta,tb,ctx)){
			ebit = 1;
			break;
		}
/*	
		if(BN_is_zero(tb))
		{
			break;
		}
	*/
		BN_sub(temp,ta,r);// temp = (a - r)
		BN_div(q,rem,temp,tb,ctx);//q = (a - r)/b
		
		BN_mul(temp_x3,temp_x2,q,ctx);// x2*q
		BN_sub(tempx,temp_x1,temp_x3);// x1 - x2*q

		BN_mul(temp_y3,temp_y2,q,ctx);//y2*q
		BN_sub(tempy,temp_y1,temp_y3);//y1 - y2*q


		BN_copy(temp_x1,temp_x2);//x1 = x2
		BN_copy(temp_x2,tempx);// x2 =temp
		
		BN_copy(temp_y1, temp_y2);//y1=y2
		BN_copy(temp_y2, tempy);// y2 = temp
	/*	
		BN_clear(tempx);
		BN_clear(temp_x3);
		BN_clear(temp_y3);
		BN_clear(tempy);
		BN_clear(tempy);
*/
///////////////////////////	
		BN_copy(ta,tb);
		BN_copy(tb,r);
	}
	//r ==0 
	if( chang ==1)
	{
	BN_copy(y,temp_x1);
	BN_copy(x,temp_y1);
	BN_copy(r,ta);
	}else
	{
		BN_copy(x,temp_x1);
		BN_copy(y,temp_y1);
		BN_copy(r,ta);
	}
	if(ebit == 1)
	{
		return NULL;
	}
	return r;
}

int main(int argc, char *argv[])
{
	BIGNUM *a = BN_new();
	BIGNUM *b = BN_new();
	BIGNUM *x = BN_new();
	BIGNUM *y = BN_new();
	BIGNUM *gcd;

	if(argc !=3){
		printf("usage: xeuclid num1 num2");
		return -1;
	}

	BN_dec2bn(&a, argv[1]);
	BN_dec2bn(&b, argv[2]);
	
	gcd = XEuclid(x,y,a,b);
	printBN("(a,b)= ", gcd);
	printBN("a = ", a);
	printBN("b = ", b);
	printBN("x = ", x);
	printBN("y = ", y);
	printf("%s*(%s) + %s*(%s) = %s \n", BN_bn2dec(a), BN_bn2dec(x), BN_bn2dec(b), BN_bn2dec(y),BN_bn2dec(gcd));

	if(a != NULL) BN_free(a);
	if(b != NULL) BN_free(b);
	if(x != NULL) BN_free(x);
	if(y != NULL) BN_free(y);
	if(gcd != NULL) BN_free(gcd);

	return 0;
}
