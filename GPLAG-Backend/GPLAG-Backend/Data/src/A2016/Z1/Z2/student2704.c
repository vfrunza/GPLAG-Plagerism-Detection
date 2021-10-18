#include <stdio.h>

int main() {
	double a1, b1, a2, b2, y, x;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%lf,%lf,%lf,%lf", &a1, &b1, &a2, &b2);
	if(a1==a2 && b1==b2) {
		printf("Poklapaju se");
		return 1;
	}
	if(a1==a2) {
		printf("Paralelne su");
		return 1;
	}
	x=(b2-b1)/(a1-a2);
	y=a2*x+b2;
	if(b2!=b1 && a1!=a2) {
		printf("Prave se sijeku u tacci (%.1f,%.1f)", x,y);
		return 1;
	}
	return 0;
}