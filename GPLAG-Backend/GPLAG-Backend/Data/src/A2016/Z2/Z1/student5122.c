#include <stdio.h>
#include <stdlib.h>
int main() {
	int broj, cifra, brojac=1, pom1, pom2, pom,n=0;
	printf("Unesite broj: ");
	scanf("%d", &broj);
	if(broj<0){
		broj=abs(broj);
	}
	while(broj>9){
		pom1=broj%10;
		broj=broj/10;
		pom2=broj%10;
		pom=pom1-pom2;
		if(pom<0)
		pom=abs(pom);
		cifra=brojac*pom;
		n+=cifra;
		brojac*=10;
	}
	printf("%d", n);
	return 0;
}
