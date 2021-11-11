#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(){
	int k,p=0,d=0,x=0,broj=0,n;
	printf("Unesite broj: ");
	scanf("%d",&n);
	x=abs(n);
	k=1;
	while(x>=10)
	{
		p=x%10;
		d=(x/10)%10;
		broj+=abs(p-d)*k;
		k*=10;
		x/=10;
	}
	printf("%d",broj);
	return 0;
}