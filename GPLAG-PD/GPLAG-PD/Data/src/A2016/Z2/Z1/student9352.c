#include <stdio.h>
#include <math.h>

int main() 
{
	int a,b,c,d,x=0,brojac=0;
	printf("Unesite broj: ");
	scanf("%d",&a);
	if(a<0)
	{
		a=(int)(fabs(a));
	}
	/*
	else if(a>0 && a<10)
	{
		printf("0");
	}*/
	do
	{
		b=a%10;
		c=a/10;
		d=c%10;
		a=c;
		brojac++;
		if(c!=0)  x+=fabs((b-d)*pow(10.,brojac-1));
	}
	while (c!=0);
	printf("%d\n",x);
	return 0;
}
