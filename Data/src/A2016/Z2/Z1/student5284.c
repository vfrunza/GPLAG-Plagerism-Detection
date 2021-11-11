#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int n,a,b,c;
	int d=0, k=1;
	printf("Unesite broj: ");
	scanf("%d", &n);
	if(n<0) n*=-1;
	for(;;) 
	{
	if(n<=10) break;
		a=n%10;
		n/=10;
		b=n%10;
		c=abs(a-b);
		d+=k*c; 
		k*=10;
	}
	printf("%d", d);
	return 0;
}
