#include <stdio.h>
#include<stdlib.h>
int main() {
	int x,a,b,p=0,br=1;
	printf("Unesite broj: ");
	scanf("%d",&x);
while (x>=10 || x<0)
{ if (x<0) x=abs(x);
a=x%10;
	b=(x%100)/10;
	p+=abs(a-b)*br;
	br=br*10;
	x=x/10;
}
printf("%d\n",p);

	return 0;
}
