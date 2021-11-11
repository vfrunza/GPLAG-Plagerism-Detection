#include <stdio.h>
#include <stdlib.h>
int main() {
	/*printf("Zadaća 2, Zadatak 1");*/
	int broj,k,cifra1,cifra2,razlika;
	
	printf("Unesite broj: ");
	scanf("%d",&broj);
	broj=abs(broj);
	k=1;
	razlika=0;
	while(broj>=10){
		cifra1=broj%10;
		cifra2=(broj/10)%10;
		razlika+=abs(cifra1-cifra2)*k;
		k*=10;
		broj/=10;
	}
	printf("%d",razlika);
	
	
	return 0;
}
