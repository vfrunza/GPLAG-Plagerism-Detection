#include <stdio.h>
#include <math.h>
#define EPSILON 0.00001

int main ()
{
	double a1, b1, a2, b2;
	double x, y;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%lf,%lf,%lf,%lf", &a1, &b1, &a2, &b2);
	if(fabs(a1-a2)<EPSILON && fabs(b2-b1)<EPSILON)
	{
		printf("Poklapaju se\n");
	}
	if(fabs(a2-a1)<EPSILON && fabs(b2-b1)>EPSILON)
	{
		printf("Paralelne su\n");
	}
	if(fabs(a2-a1)>EPSILON && fabs(b2-b1)>EPSILON)
	{
		x=(b2-b1)/(a1-a2);
		y=a1*x+b1;
		printf("Prave se sijeku u tacci (%.1f,%.1f)\n", x, y);
	}
	return 0;
}