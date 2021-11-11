#include <stdio.h>
#include <math.h>

int main() {
	int broj;
	int cifra1=0, cifra2=0, novibroj=0, i;

	printf("Unesite broj: ");
		scanf("%d",&broj);
	
	if(broj<0) broj=fabs(broj);
	i=0;
	while(broj>10){
		cifra1=broj%10;
		cifra2=broj%100;
		cifra2=(cifra2-cifra1)/10;
		novibroj+=fabs(cifra1-cifra2)*pow(10,i);
		broj/=10;
		i++;
	}
	
	printf("%d", novibroj);
	
return 0;
}
