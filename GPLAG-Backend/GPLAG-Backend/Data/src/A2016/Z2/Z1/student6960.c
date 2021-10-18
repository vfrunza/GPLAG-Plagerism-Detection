#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int a,b,n,cifra1,cifra2;
	b=0;
	n=1;
	
	 /*Unos*/
	 printf("Unesite broj: ");
	 scanf("%d",&a);
	 a=abs(a);
	 
	 /*Obrada*/
	 while (a>=10) {
	 	cifra1=a%10;
	 	cifra2=(a/10)%10;
	  	b+=abs(cifra1-cifra2)*n;
	  	a/=10;
	 	n*=10;
	 } 
	 
	 /*Izlaz*/
	 printf("%d",b);

	return 0;
}
