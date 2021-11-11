#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main() {
	int n, a=0,i=0,b,c1,c2;
	printf("Unesite broj: ");
	scanf("%d",&n);
	n=abs(n);
	b=n;
	if(n>=0 && n<10)
	{
		printf("0");
	}      
	else
	{
		do
		{
		n=n/10;
		i++;
		}
		while(n!=0);
		n=b;
		do
		{
		c1=n/(pow(10,i-1));
		c2=(n-c1*(pow(10,i-1)))/pow(10,i-2);
		n=n-c1*pow(10,i-1);
		a=10*a+(abs(c1-c2));
		i--;
		}
		while(i>1);
		printf("%d",a);
	}

	return 0;
}
