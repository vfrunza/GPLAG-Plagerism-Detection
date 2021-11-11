#include <stdio.h>

int main() {
	float a1, b1, a2, b2, x, y;
	
	//Unos vrijednosti
	
	printf("Unesite a1,b1,a2,b2: ");
	scanf ("%f,%f,%f,%f", &a1, &b1, &a2, &b2);
	
	//Racunanje tacke u kojoj se tacke sijeku
	
	x = (b2 - b1) / (a1 - a2);
	y = a1 * x + b1;
	
	// Poklapaju, paralelne ili sijeku
	
	if (a1 == a2) {
		if (b1 == b2) {
			printf ("Poklapaju se");
		}
		else {
		printf ("Paralelne su");
		}
	}
	else {
	printf ("Prave se sijeku u tacci (%.1f,%.1f)", x, y);
	}
	
	return 0;
}
