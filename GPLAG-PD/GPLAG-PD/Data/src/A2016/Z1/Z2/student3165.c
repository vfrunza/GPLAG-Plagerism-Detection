#include <stdio.h>
#define EPS1 0.0001
#define EPS2 -0.0001

int main() {
	float a1, b1, a2, b2;
	float x, y;
	printf ("Unesite a1,b1,a2,b2: ");
	scanf ("%f,%f,%f,%f", &a1, &b1, &a2, &b2);
	
	if (((a1 - a2 < EPS1) && (a1 - a2 > EPS2)) && ((b1 - b2 > EPS1) || (b1 - b2 < EPS2))){
		printf ("Paralelne su");
	}
	if (((a1 - a2 < EPS1) && (a1 - a2 > EPS2)) && ((b1 - b2 < EPS1) && (b1 - b2 > EPS2))){
		printf ("Poklapaju se");
	}
	if ((a1 - a2 > EPS1) || (a1 - a2 < EPS2)){
		x = (b2-b1)/(a1-a2);
		y = a1*x + b1;
		printf ("Prave se sijeku u tacci (%.1f,%.1f)", x, y);
	}
	
	return 0;
}
