#include <stdio.h>
#include <math.h>

int poredi(double a, double b) {
	double eps = 1e-10;
	return fabs(a - b) <= eps * (fabs(a) + fabs(b));
}

int main() {
	double a1, a2, b1, b2, x, y;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%lf,%lf,%lf,%lf", &a1, &b1, &a2, &b2);
	
	if (poredi(a1, a2) && poredi(b1, b2)) {
		printf("Poklapaju se");
	} else if (poredi(a1, a2)) {
		printf("Paralelne su");
	} else {
		x = (b2 - b1) / (a1 - a2);
		y = a1 * x + b1;
		
		printf("Prave se sijeku u tacci (%.1f,%.1f)", x, y);
	}
	
	return 0;
}
