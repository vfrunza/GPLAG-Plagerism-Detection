#include <stdio.h>

int main() {
	float a1, b1, a2, b2, x, y;
	printf ("Unesite a1,b1,a2,b2: ");
	scanf ("%f,%f,%f,%f", &a1,&b1,&a2,&b2);
	x=(b1-b2)/(a2-a1);
	y=a1*x+b1;
	if (a1!=a2) {
	printf ("Prave se sijeku u tacci (%.1f,%.1f)\n", x,y);
	} else if (a1==a1 && b1==b2) {
		printf ("Poklapaju se\n");
	} else if (a1==a2 && b1!=b2) {
		printf ("Paralelne su\n");
	}
	return 0;
}
