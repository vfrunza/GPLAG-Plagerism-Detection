#include <stdio.h>
#include <math.h>


int jednaki(float x, float y) {
	return fabs(x - y) <= 1e-10*(fabs(x) + fabs(y));
}

int main() {
	float a1, b1, a2, b2, x;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f", &a1, &b1, &a2, &b2);
	
	if (jednaki(a1, a2)) {
		if (jednaki(b1, b2)) {
			printf("Poklapaju se\n");
			return 0;
		}
		printf("Paralelne su\n");
		return 0;
	}
	
	x = (b2 - b1) / (a1 - a2);
	
	printf("Prave se sijeku u tacci (%.1f,%.1f)", x, a1*x + b1);
	
	
	return 0;
}
