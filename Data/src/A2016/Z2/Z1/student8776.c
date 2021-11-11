#include <stdio.h>

int main() {
	int n, cifra,razlika, a;
	int suma =0;
	int c=1;
	printf("Unesite broj: ");
	scanf("%d", &n);
	if(n<0)
	n=n*(-1);
	while(n>10){
		
		cifra=n%10;
		n=n/10;
		a=n%10;
		razlika=cifra-a;
		if(razlika<0)
		razlika=razlika*(-1);
		suma=suma+razlika*c;
		c=c*10;
	}
		
		
		
	printf("%d", suma);
	return 0;
}
