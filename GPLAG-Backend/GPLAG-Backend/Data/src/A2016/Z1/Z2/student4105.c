#include <stdio.h>
#include <math.h>
#define EPSILON 0.000001

int main() {
	
	char c1, c2, c3;
	float a1, b1, a2, b2, x, y;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f%c%f%c%f%c%f", &a1,&c1,&b1,&c2,&a2,&c3,&b2);
	if (fabs(1+a1*a2)<EPSILON || fabs(atan((a2-a1)/(1+a1*a2)))>EPSILON)
	{
		x= (b2-b1)/(a1-a2);
		y= a1*x+b1;
		printf("Prave se sijeku u tacci");
		printf(" (%.1f,%.1f)", x, y);
	}
	else if (fabs(a1-a2)<EPSILON)
	{
		if (fabs(b1-b2)<EPSILON)
		printf("Poklapaju se");
		else printf("Paralelne su");
	}
	
	return 0;
}
