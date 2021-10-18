#include <stdio.h>
#include <math.h>

int main() {
	
	int broj, br_cifara=0, cifra1, cifra2, rezultat, pom, i;


/*Prvo prebrojimo cifre unesenog broja, kako bi znali koja je najveca dekadska jedinica*/	
	printf("Unesite broj: ");
	scanf("%d", &broj);
	pom=broj;
	while(pom!=0) {
		br_cifara++;
		pom=pom/10;
	}
	i=1;
	while(broj!=0 && i<br_cifara) {
		cifra1=broj%10;
		broj=broj/10;
		cifra2=broj%10;
		rezultat=(cifra2-cifra1);
		if(rezultat<0) rezultat=-rezultat;
		if(i==1) pom=rezultat;
		else {
			pom=pom+(rezultat*pow(10, i-1));
		}
		i++;
		
	}
	printf("%d", pom);
	
	return 0;
}
