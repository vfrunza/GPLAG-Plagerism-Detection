#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
	int a1, a2, a3, a4=0, n, x, i;
	float p;
	printf("Unesite broj: ");
	scanf("%d", &n);
	if(n==0) {
	printf("0");
	return 0; }
	x=floor(log10(abs(n)))+1 ;
	if(x==1) {
		printf("0");
		return 0;
	}
	for(i=0; i<=x-2; i++) {
		p=pow(10,x-1-i);
		a1=n/(int)p;
		n=n%(int)p;
		p=pow(10,x-2-i);
		a2=n/(int)p;
		a3=a2-a1;
		a3=abs(a3);
		a4=a4+(int)p*a3;
	}
	printf("%d", a4);
	return 0;
}
