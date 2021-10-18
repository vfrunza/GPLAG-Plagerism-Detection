#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main() {
	int broj, cifra1, cifra2, razlika=0, i, k=1; 
	printf("Unesite broj: ");
	scanf("%i", &broj);
	if (broj<10 && broj>-10) { 
		printf("0");
	} else {
		while(broj>=10 || broj<=-10) {
			cifra1=abs(broj%10);
			cifra2=abs((broj/10)%10);
			razlika+=fabs(cifra1-cifra2)*k;
			k*=10;
		broj=broj/10;	
		} 	printf("%d", razlika);
	} 
	return 0;
}
