#include <stdio.h>
#define eps 0.00000000001
int main() {
	float a1, a2, b1, b2, y1, x, y;
	printf ("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f", &a1, &b1, &a2, &b2);
	if ((a1*eps-a2*eps)==0 && (b1*eps-b2*eps)==0) {
		printf ("Poklapaju se");
	}
	else if ((a1*eps-a2*eps)==0) {
		printf ("Paralelne su");
	}
	else {
		x=(b2-b1)/(a1-a2);
		y1=a1*x+b1;
		printf ("Prave se sijeku u tacci (%.1f,%.1f)", x, y1);
	}
	return 0;
	
	
}         
