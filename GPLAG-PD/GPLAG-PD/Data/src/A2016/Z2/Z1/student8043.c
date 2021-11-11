#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main() {
	int x,broj=0,cifra1,cifra2,i,apsolutna_razlika;
	printf("Unesite broj: ");
	scanf("%d", &x);
	if(x<0) x=abs(x);
	i=1;
	while (x>=10) {
		cifra1=x%10;
		cifra2=(x/10)%10;
		apsolutna_razlika=abs(cifra1-cifra2);
		broj+=apsolutna_razlika*i;
		i*=10;
		x/=10;}
	printf("%d", broj);
	return 0;
}
