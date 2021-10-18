#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
	int n, m, digit1, digit2, digitr, count, i;
	double digitp;
	double digitpf;
	digitp=0;
	count=0;
	printf ("Unesite broj: ");
	scanf ("%d", &n);
    if (n<0)
	{
		n=(-n);
	}
	m=n;
    while (m!=0)
	{
		m=m/10;
		count=count+1;
	}
	
	for (i=0; i<(count-1); i++)
	{
	   digit1=n%10;
	   digit2=(n/10)%10;
	   
	   if (digit2>digit1)
	   {
	   	digitr=digit2-digit1;
	   }
	   else
	   {
	    digitr=digit1-digit2;
	   }
	   
	   digitp=digitp+(digitr/pow(10, count-2-i));
	  
	   n=n/10;
	}
 
	digitpf=digitp*pow(10, count-2);
    printf ("%.0f", digitpf);
	return 0;
	
}
