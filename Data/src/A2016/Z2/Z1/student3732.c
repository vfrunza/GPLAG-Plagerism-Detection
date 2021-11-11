#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int cf1, cf2, a=0, b=0, br, s=0;
	printf ("Unesite broj: ");
	scanf ("%d",&br);
	br=abs(br);
	if (br<10) printf ("");
	do{
	    cf1=br%10;
	    br/=10;
	    if(br!=0)
	    {
	        cf2=br%10;
	        a=abs(cf1-cf2);
	        b=b+a*pow(10,s);
	        s++;
	    }
	   
	}while (br!=0);
	printf ("%d",b);
	return 0;
}
