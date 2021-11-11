#include <stdio.h>
#include <stdlib.h>
int main() {
	int broj,rezultat,cifra1,cifra2,nbroj=0,p=1;
	printf("Unesite broj: ");
	scanf("%d",&broj);
	if (broj<0){
		broj=(abs(broj));}
	if(broj<10){
		printf("0");return 0;
	}
	else {
		do {
			cifra1=broj%10;
			broj=broj/10;
			cifra2=broj%10;
			rezultat=abs(cifra1-cifra2);
			nbroj=nbroj+(p*rezultat);
			p=p*10;
	}
	while (broj>9);
	printf("%d",nbroj);
	}
	return 0;
}
