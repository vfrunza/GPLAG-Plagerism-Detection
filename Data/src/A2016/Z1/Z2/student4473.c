#include <stdio.h>
#include <math.h>
#define F 0.0001

int main() {
	float a1,b1,a2,b2;
	double x=0.0, y=0.0;
	printf("Unesite a1,b1,a2,b2:");
	scanf ("%f,%f,%f,%f", &a1,&b1,&a2,&b2);
	if ((fabs(a1-a2))<F && (fabs(b1-b2))<F)
	printf (" Poklapaju se");
	else if ((fabs(a1-a2))<F && (fabs(b1-b2))>F)
	printf (" Paralelne su");
	else {
		x=(b2-b1)/(a1-a2);
		y=a1*x+b1;
		printf (" Prave se sijeku u tacci (%.1f,%.1f)",x,y);
	}
	return 0;
}
