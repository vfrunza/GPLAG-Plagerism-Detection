#include <stdio.h>

int main() 
{
	double a1, b1, a2, b2, x, y;
	printf ("Unesite a1,b1,a2,b2: ");
	scanf ("%lf %lf %lf %lf", &a1, &b1, &a2, &b2);
	x = 0.0;
	y = 0.0;
	if (a1==a2 && b1!=b2)
	{
		printf ("Paralelne su");
	}
	else if (a1==a2 && b1==b2)
	{
		printf ("Poklapaju se");
	}
	else
	{
		x = (b2 - b1) / (a1 - a2);
		y = a1 * x + b1;
		printf ("Prave se sijeku u tacci (%.1f,%.1f)", x, y);
	}
	return 0;
}
