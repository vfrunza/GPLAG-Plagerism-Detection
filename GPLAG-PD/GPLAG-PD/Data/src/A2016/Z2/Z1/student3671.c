#include <stdio.h>
#include <math.h>
int main() {
	int n,c,prva_cif,druga_cif,broj=0;
	printf("Unesite broj: ");
	scanf("%d", &n);
	c=1;
	while(n!=0)
	{
		prva_cif=n%10;
		druga_cif=(n/10)%10;
		n/=10;
		if(n==0)
		break;
		broj+=fabs(prva_cif-druga_cif)*c;
		c*=10;
	}
	printf("%d", broj);
	return 0;
}
