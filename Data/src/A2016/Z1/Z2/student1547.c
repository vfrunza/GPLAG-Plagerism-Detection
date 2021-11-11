#include <stdio.h>
#include <math.h>

int main() {
	float a1, b1, b2, a2, x, y;
	printf ("Unesite a1,b1,a2,b2: ");
	scanf ("%f, %f, %f, %f", &a1, &b1, &a2, &b2);
	if (a1-a2<0.0000001 && a2-a1<0.0000001 && b1-b2<0.0000001 && b2-b1<0.0000001)
	printf ("Poklapaju se");
	else if (fabs(a1-a2)<0.00000001 && fabs(a2-a1)<0.0000001)
	printf("Paralelne su");
	else {
		x=(b2-b1)/(a1-a2);
		y=a1*x+b1;
		printf ("Prave se sijeku u tacci (%.1f,%.1f)", x, y);
	}
	return 0;
}
