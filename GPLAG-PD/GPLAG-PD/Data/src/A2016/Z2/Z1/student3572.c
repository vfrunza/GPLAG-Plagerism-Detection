#include <stdio.h>
#include <stdlib.h>

int main() {
	int x,c,a,b=0,d=1;
	printf("Unesite broj: ");
	scanf("%d", &x);
	
	if(x<0)
	{
	x=abs(x);
	scanf("%d", &x);
	}

else if(x<=9)
    {
	printf("0");
	return 0;
    }
	
	while(x>=10) 
	{
		c=x%10; 
		a=(x/10)%10;
		b+=(abs(c-a))*d;
		d*=10;
	    x/=10;
    }

	printf("%d",b);
	 
	
	
	 
	return 0; }
	

