#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {
	int n, brcifara=0, i, a, b, c, d, broj=0;
	printf("Unesite broj: ");
	scanf("%d", &n);
	n=abs(n);
	a=n;
	
	
	if( n>=0 && n<10)
	{
	    printf("0");
	}
	else
	{
	    while (n!=0)
	    {
	        n=n/10;
	        brcifara++;
	    }
	    
	    for (i=1; i<brcifara; i++)
	    {
	    	b=a/pow(10,(brcifara-i));
			c=(a-b*pow(10,brcifara-i))/pow(10,brcifara-i-1);	 
	    	d=abs(b-c);
	    	a=a-b*pow(10,brcifara-i);
	    	
	    	broj=broj+d*pow(10, brcifara-i-1);
	    	if (a==0) break;
	    }
	    printf("%d", broj);
	}
	return 0;
}
