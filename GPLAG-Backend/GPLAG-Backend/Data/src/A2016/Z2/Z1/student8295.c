#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
	int z,pz,c,n,brojac=0,x; 
	int a=0;
	printf("Unesite broj: ");
	scanf("%d", &n);
	if(n<0){
		n=-n;
	}
	
	
	while (n>=10)
	{
		z=n%10;
		pz=(n/10)%10;
		c=abs(z-pz);

     a=c*pow(10,brojac)+a;
     n=n/10;
     brojac++;
     }
	
	printf("%d",a);
	
	return 0;
}
