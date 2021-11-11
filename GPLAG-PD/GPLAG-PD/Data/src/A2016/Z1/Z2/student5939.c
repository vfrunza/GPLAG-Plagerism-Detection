#include <stdio.h>
#include <math.h>
#define EPSILON 0.01

int main() {
	float a1,a2,b1,b2,x,koordinata2;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f", &a1, &b1, &a2, &b2);
	
	
	if (fabs(a1-a2)<EPSILON && fabs(b1-b2)<EPSILON) 
	{
		printf ("Poklapaju se");
	}
	else if (fabs(a1-a2)<EPSILON)
	{
		printf ("Paralelne su");
	}
	else {
	x=(b2-b1)/(a1-a2);
	koordinata2=a2*x+b2;
	printf("Prave se sijeku u tacci (%.1f,%.1f)",x, koordinata2);
	}
	return 0;
}


