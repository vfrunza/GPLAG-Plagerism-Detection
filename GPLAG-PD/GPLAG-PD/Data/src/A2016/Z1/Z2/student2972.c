#include <stdio.h>

int main() {
	float x, y1, y2, a1, a2, b1, b2;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f", &a1, &b1, &a2, &b2);
	if (a1==a2 && b1!=b2) {
		printf("Paralelne su \n");
	} else if (a1==a2 && b1==b2) {
		printf("Poklapaju se \n");
	} else {
		x=(b2-b1)/(a1-a2);
		y1==y2;
		y1=(a1*b2-a2*b1)/(a1-a2);
		printf("Prave se sijeku u tacci (%.1f,%.1f) \n", x, y1);
	}
	return 0;
}
