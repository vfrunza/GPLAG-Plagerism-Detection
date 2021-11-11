#include <stdio.h>
#include <math.h>

int main() {
	int n,a=0,b,k=1,suma=0;
	printf("Unesite broj: ");
	scanf("%d",&n);
	n=fabs(n);
	while(n>0)
	{ a=a*10+(n%10);
	n=n/10;
		if(n!=0) {
		b=fabs(a%10-n%10);
	    suma+=b*k;
		k*=10;
		}
	}
	printf("%d ",suma);
	
	return 0;
}
