#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int stepen=1,broj=0;
	int x,z=0,cifra1=0,cifra2=0;
	printf("Unesite broj: ");
	scanf("%d", &x);
	if(x<0){x=abs(x);}
	if(x/10==0){printf("0");return 0;}
	cifra1=x%10;
	x=x/10;
	while(x!=0){
	    cifra2=x%10;
	    z=abs(cifra1-cifra2)*stepen;
	    broj=broj+z;
	    x=x/10;
	    stepen=stepen*10;
	    cifra1=cifra2;
	}
	
	printf("%d", broj);

	return 0;
}
