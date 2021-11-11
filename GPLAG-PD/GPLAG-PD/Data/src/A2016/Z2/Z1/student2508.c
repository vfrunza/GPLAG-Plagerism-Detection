#include <stdio.h>
#include <stdlib.h>
int main() {
	int n,b,c,br=0,i=1,e,d;
	printf("Unesite broj: ");
	scanf("%d",&n);
	if (n<0)
	n=abs(n);
	do
	{
		b=n%10;
		n=n/10;
		if(n==0)
		break;
		c=n%10;
		d=b-c;
		if(d<0)
		d=abs(d);
		e=i*d;
		br=br+e;
		i=i*10;
	}
	while(n>0);
	printf("%d",br);
	return 0;
}
