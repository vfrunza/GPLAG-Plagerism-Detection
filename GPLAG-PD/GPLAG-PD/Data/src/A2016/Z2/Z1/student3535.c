#include <stdio.h>

int main() {
	int n,a,b,c,d=0,e=1;
	printf("Unesite broj: ");
	scanf("%d",&n);
	if(n<0) n=n*(-1);
	while(n/10>1)
	{
		a=n%10;
		n=n/10;
		b=n%10;
		c=a-b;
		if(c<0) c=c*(-1);
		d=e*c+d;
		e=e*10;
	} 
	printf("%d",d);
	return 0;
}
