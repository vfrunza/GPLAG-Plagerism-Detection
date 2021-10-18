#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define eps 0.00000000000000000000000000000000001

int main() 
{
	float a1, a2, b1, b2, x;
	
	printf ("Unesite a1,b1,a2,b2: ");
	scanf ("%f,%f,%f,%f", &a1, &b1, &a2, &b2);
	x = (b2-b1)/(a1-a2);
	if (fabs(a2-a1) < eps && fabs(b2-b1) < eps)
		printf ("Poklapaju se");
	else if (fabs(a2-a1) < eps)
		printf ("Paralelne su");
	else
		printf ("Prave se sijeku u tacci (%.1f,%.1f)", x, a2 * x + b2);
	return 0;
}
