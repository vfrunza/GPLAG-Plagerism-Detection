#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main () {
	int n,brojka1,brojka2,cifra1,broj=0,i=0,nbroj=0;
	printf("Unesite broj: ");
	scanf("%d", &n);
	if(n<0)
	n=abs(n);
	while(n!=0) {
		brojka2=n%10;
		brojka1=((n%100)-brojka2)/10;
		n=n/10;
		if(n==0) break;
		cifra1=abs(brojka2-brojka1);
		broj=pow(10,i)*cifra1;
		nbroj+=broj;
		i++; 
	}
	printf("%d", nbroj);
	return 0;
}
