#include <stdio.h>

int main() {
	int n, a, b, c, d=0, e, k=1;
	printf("Unesite broj: ");
	scanf("%d", &n);
	if(n>=-9 && n<=9) { printf("0"); return 0; }
	if(n<0) n*=-1;
	c=n;
	while(c>=10)
	{
		a=c%10;
		c/=10;
		b=c%10;
		e=a-b;
		if(e<0) e*=-1;
		d+=e*k;
		k*=10;
		
	}  
	printf("%d", d);
	return 0;
}
