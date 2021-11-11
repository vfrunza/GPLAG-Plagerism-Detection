#include <stdio.h>

#define eps 0.00000001
int main() {
	double a1, a2, b1, b2, x, y1, y2;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%lf,%lf,%lf,%lf", &a1, &b1, &a2, &b2);
	
	if (a1 - a2 < eps && a2 - a1 < eps && b1 - b2 < eps && b2 - b1 < eps) {
		printf("Poklapaju se\n");
		return 0;
	}
	if (a1 - a2 < eps && a2 - a1 < eps) {
		printf("Paralelne su\n");
		return 0;
	}
	x = (b2 - b1) / (a1 - a2);
	y1 = a1 * x + b1;
	y2 = a2 * x + b2;
	if (y1 - y2 < eps && y2 - y1 < eps)
		printf("Prave se sijeku u tacci (%.1f,%.1f)\n", x, y1);
	else printf("Paralelne su\n");
	return 0;
}
