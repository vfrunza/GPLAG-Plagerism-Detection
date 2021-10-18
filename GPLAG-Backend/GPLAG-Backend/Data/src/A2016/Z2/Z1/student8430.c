#include <stdio.h>
#include <math.h>

int main() {
	int broj, broj1, broj2, cifra, moj_broj=0, i=0;
	
	printf("Unesite broj: ");
	scanf("%d", &broj);
	if(broj<0) 
	broj*=-1;
	
	while(broj>0) {
		broj1=broj%10;
		broj/=10;
		if(broj==0) break;
		broj2=broj%10;
		cifra=broj1-broj2;
		if(cifra<0) cifra*=-1;
		moj_broj+=cifra*pow(10,i);
		i++;
	}
	
	printf("%d", moj_broj);
	return 0;
}