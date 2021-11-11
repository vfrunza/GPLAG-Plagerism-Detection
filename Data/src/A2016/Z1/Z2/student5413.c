#include <stdio.h>
#include <math.h>
#define EPS 0.00000000000000000000000000000000000000000000000000000000000000000000001

int main() 
{
	double a = 0, b = 0, c = 0, d = 0, x = 0, y = 0;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%lf, %lf, %lf, %lf", &a, &b, &c, &d);
	
	if(fabs(c - a) < EPS && fabs(b - d) >= EPS)
	{
		printf("Paralelne su");
		return 1;
	}
	else if(fabs(a - c) < EPS && fabs(b - d) < EPS)
	{
		printf("Poklapaju se");
		return 2;
	}
	x = (double)(d - b) / (a - c);
	y = (a * x) + b;
	printf("Prave se sijeku u tacci (%.1f,%.1f)", x, y);
	return 0;
}
