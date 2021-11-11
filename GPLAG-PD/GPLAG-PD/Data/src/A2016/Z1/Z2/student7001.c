#include <stdio.h>
#include <math.h> 
#define EPSILON 0.1
int main() {
	float a1, a2, b1, b2, x, y;
	
	/*Unos potrebnih podataka sa tastature*/
	
	printf("Unesite a1,b1,a2,b2: ");
	scanf ("%f,%f,%f,%f", &a1,&b1,&a2,&b2);
	
	/*Obrada podataka & ispis rezultata*/
	
	if (fabs (a1 - a2) < EPSILON && fabs (b1 - b2) < EPSILON) printf ("Poklapaju se");
	else if (fabs (a1 - a2) < EPSILON) printf ("Paralelne su");
	else {
		x = (float) (b2 - b1) / (a1 - a2);
		y = a1 * x + b1;
		printf ("Prave se sijeku u tacci (%.1f,%.1f)", x,y);
	}
return 0;
}