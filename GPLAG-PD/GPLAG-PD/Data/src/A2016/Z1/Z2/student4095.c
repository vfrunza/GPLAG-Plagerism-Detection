#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001

int main() {
	float a1, b1, a2, b2, sx, sy;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f", &a1, &b1, &a2, &b2);
	
	if (fabs(a1-a2)<EPSILON && fabs(b1-b2)<EPSILON)
	{
		printf("Poklapaju se");
	}
	else if (fabs(a1-a2)<EPSILON && fabs(b1-b2)>EPSILON)
	{
		printf("Paralelne su");
	}
	else 
	{
		sx=(b2-b1)/(a1-a2);
		sy=(a1*b2-b1*a2)/(a1-a2);
		printf("Prave se sijeku u tacci (%.1f,%.1f)", sx, sy);
	}
	
	return 0;
}
