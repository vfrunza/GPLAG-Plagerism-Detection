#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int n,a,a1,a2,brojac=1,broj=0;
	printf("Unesite broj: ");
	scanf("%d",&n);
	if(n>=0 && n<10) printf("0");
	else {
	if(n<0) n=abs (n);
	while(n!=0) {
		a1=n%10;
		n=n/10;
		if(n!=0) {
		a2=n%10;
		a=abs(a2-a1); 
		broj+=a*brojac;
		brojac*=10;
	}
	
	}
		printf("%d",broj);
	}
	return 0;
}
