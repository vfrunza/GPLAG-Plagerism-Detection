#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001

int main() 
{
	float a1,a2,b1,b2,x,y;
	printf ("Unesite a1,b1,a2,b2:");
	scanf  ("%f, %f, %f, %f", &a1, &b1, &a2, &b2);
	
	if (a1!=a2)
	{
		x=(b2-b1) / (a1-a2);
		y=((a1*x)+b1);
		printf (" Prave se sijeku u tacci (%.1f,%.1f)",x,y);
	}

		if (fabs(a1-a2) < EPSILON)
		if (fabs(b1-b2) < EPSILON)
		printf (" Poklapaju se");
	
	else
	printf (" Paralelne su");
	
	
	return 0;
}
