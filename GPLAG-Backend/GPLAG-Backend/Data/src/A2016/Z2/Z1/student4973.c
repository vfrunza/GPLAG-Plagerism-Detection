#include <stdio.h>
#include <stdlib.h>

int main()
{
	int broj,broj1,cifra1,cifra2,nbroj=0,m=1;
	printf("Unesite broj: ");
	scanf("%d",&broj);
	if(broj<0)broj*=-1;
	while(broj>10) {
		broj1=broj;
		cifra1=broj%10;
		cifra2=(broj1/10)%10;
		nbroj+=abs(cifra1-cifra2)*m;
		broj/=10;
		m*=10;
	}
	printf("%d",nbroj);
	return 0;
}
