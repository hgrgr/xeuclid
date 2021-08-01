#include <stdio.h>
#include <openssl/bn.h>
#define NBITS 256

void printBN(char *msg, BIGNUM * a)
{
	char *number = BN_bn2dec(a);
	printf("%s %s\n", msg, number);	
}

BIGNUM* euclid2(BIGNUM *a, BIGNUM* b)
{
	BN_CTX *ctx = BN_CTX_new();
	BIGNUM *r = BN_new();
	BIGNUM *t;

	if(BN_cmp(a,b) <0){//a < b
		t = a;
		a = b;
		b = t;
	}	
	while(!BN_is_zero(b)){
		if(!BN_mod(r,a,b,ctx)){
			goto err;
		}	
		BN_copy(a,b);
		BN_copy(b,r);
	}
	BN_copy(r,a);
	if(ctx !=NULL) BN_CTX_free(ctx);
	return r;
err:
	return NULL;
}
int main(int argc, char** argv)
{
	if(argc !=3)
	{
		printf("input error\n");
		return 0;
	}

	BIGNUM *a = BN_new();
	BIGNUM *b = BN_new();
	BIGNUM *result;
	
	BN_dec2bn(&a, argv[1]);
	BN_dec2bn(&b, argv[2]);	

	printBN("a = ", a);
	printBN("b = ", b);
	
	result = euclid2(a,b);
	printBN("(a,b) = ", result);
	
	if(a != NULL) BN_free(a);
	if(b != NULL) BN_free(b);
	if(result != NULL) BN_free(result);

	return 0;
}
