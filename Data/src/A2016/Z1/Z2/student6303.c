#include <stdio.h>

int main() {
	float a1, b1, a2, b2, x, y;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f", &a1, &b1, &a2, &b2);
	if(a1!=a2 && b1!=b2) {
		x=((b2-b1)/(a1-a2));
		y=(a2*b1-b2*a1)/(a2-a1);
		printf("Prave se sijeku u tacci (%3.1f,%3.1f)",x,y);
	}
    if(a1==a2 && b1!=b2) {
		printf("Paralelne su");
	}
	else if(a1==a2 && b1==b2) {
		printf("Poklapaju se");
	}
	return 0;
}