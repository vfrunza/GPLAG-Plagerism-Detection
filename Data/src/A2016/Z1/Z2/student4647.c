#include <stdio.h>
#define EPS 0.01
#include <math.h>

int main() {
	float a1, b1, a2, b2, x, y;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f", &a1, &b1, &a2, &b2);
	x=(b2-b1)/(a1-a2);
	y=x*a1+b1;
	if (fabs(a1-a2)<EPS && fabs(b1-b2)>EPS) printf("Paralelne su");
	else if (fabs(a1-a2)<EPS && fabs(b1-b2)<EPS) printf("Poklapaju se");
	else printf("Prave se sijeku u tacci (%.1f,%.1f)", x, y);
	
	return 0;
}
