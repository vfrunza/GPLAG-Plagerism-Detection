#include <stdio.h>
#include <math.h>
#define A 0.0001
int main() {
	float a1, a2, b1, b2, y1, y2, x;
	printf ("Unesite a1,b1,a2,b2: ");
	scanf ("%f,%f,%f,%f", &a1, &b1, &a2, &b2);

	x=(b1-b2)/(a2-a1);
	y1=a1*x+b1;
	y2=a2*x+b2;
	if (fabs (a2-a1)<A && fabs (b2-b1)<A){
		printf ("Poklapaju se ");
	}
	 if (fabs (a2-a1)<A && fabs (b2-b1)>A){
	 	printf ("Paralelne su");
	 }
	 if (fabs (y2-y1)<A){
	 	printf ("Prave se sijeku u tacci (%.1f,%.1f)",x,y1);
	 }
	
	
	return 0;
}
