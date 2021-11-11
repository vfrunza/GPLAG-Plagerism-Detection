#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	float a1=0, a2=0, b1=0, b2=0, x=0, y=0;
	printf("Unesite a1,b1,a2,b2: ");
	scanf ("%f,%f,%f,%f", &a1, &b1, &a2, &b2);
    if (fabs(a1-a2)<0.0000001 && fabs(b1-b2)<0.0000001)
	{
		printf ("Poklapaju se");
		return 0;
	}
		if (fabs(a1-a2)<0.000000001)
	{
		printf ("Paralelne su");
		return 0;
	}
	x=(b2-b1)/(a1-a2);
	y=a1*x+b1;
	printf ("Prave se sijeku u tacci (%.1f,%.1f)", x,y);
	return 0;
	}

