#include <stdio.h>

int main() 
{
	double a1,b1,a2,b2,x,y;
	
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%lf,%lf,%lf,%lf",&a1,&b1,&a2,&b2);

	    if(a1==a2)
    {
    	if(b1==b2)
    	{
    	   printf("Poklapaju se");
    	}
    	else 
    	{
    	printf("Paralelne su");
    	}
    }
    else{
    y=(a1*b2-a2*b1)/(a1-a2);
    x=(y-b1)/a1;
    printf("Prave se sijeku u tacci (%.1lf,%.1lf)",x,y);
    }

	return 0;
}
