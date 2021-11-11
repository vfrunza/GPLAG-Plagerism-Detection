#include <stdio.h>

int main() {
	/*NOTE: Testiraj sa jos brojeva i provjeri sto izbacuje warning*/
	
	/*Deklaracija varijabli*/
	float a1, b1, a2, b2, x, y;
	x = 0;
	y = 0;
	
	/*Unos podataka*/
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f, %f, %f, %f", &a1, &b1, &a2, &b2);
	
	/*Procesiranje*/
	if (a1 == a2 && b1 == b2)
			printf("Poklapaju se");
	
	else if (a1 == a2)
	{
		/*Ispis 1*/
		printf("Paralelne su");
	}
	else
	{
		x = (b2 - b1) / (a1 - a2);
		y = a1 * x + b1;
		
		/*Ispis 2*/
		printf ("Prave se sijeku u tacci (%2.1f,%2.1f)", x, y);
	}
	
	return 0;
}
