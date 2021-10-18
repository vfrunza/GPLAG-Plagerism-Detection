#include <stdio.h>
#include <math.h>
#define tacnost 0.00000000001

int main() 
{
	double a1=0, b1=0, a2=0, b2=0, x=0, y=0;
	
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%lf, %lf, %lf, %lf", &a1, &b1, &a2, &b2);
	
	if(fabs(a1-a2) < tacnost && fabs(b1-b2) < tacnost)
	{
		printf("Poklapaju se");
	}
	else if(fabs(a1-a2) < tacnost)
	{
		printf("Paralelne su");
	}
	else if (fabs(a1*a2 - (-1)) < tacnost)
	{
		printf("Okomite su");
	}
	
	else
	{
		x = (b2-b1)/(a1-a2);
		y = a1*x + b1;
		printf("Prave se sijeku u tacci (%.1f,%.1f)", x, y);
	}
	
	return 0;
}
