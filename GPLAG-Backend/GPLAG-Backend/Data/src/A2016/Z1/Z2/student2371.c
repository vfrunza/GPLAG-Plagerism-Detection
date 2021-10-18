#include <stdio.h>
#include <math.h>
#define E 0.000000000000000001
int main() {
	float a1,b1,a2,b2, x, y;
	printf("Unesite a1,b1,a2,b2: ");
	scanf ("%f,%f,%f,%f", &a1, &b1, &a2, &b2);
	x=(b2-b1)/(a1-a2);
	y=a1*x+b1;
	if((fabs(a1-a2) < E) && (fabs(b1-b2) < E)) printf("Poklapaju se");
	else if (fabs(a1-a2) < E) printf("Paralelne su");
	
	else printf ("Prave se sijeku u tacci (%.1f,%.1f)", x, y);
	
	return 0;
}
