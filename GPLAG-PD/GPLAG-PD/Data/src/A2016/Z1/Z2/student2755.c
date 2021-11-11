#include <stdio.h>

int main() {
	double a1, b1, a2, b2, presjekx, presjeky;
	
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%lf,%lf,%lf,%lf", &a1, &b1, &a2, &b2);
	
	if (a1==a2 && !(b1==b2)) printf("Paralelne su");
	else if(a1==a2 && b1==b2) printf("Poklapaju se");
	else {
		presjekx = (b2-b1)/(a1-a2);
		presjeky = a1*presjekx + b1;
		printf("Prave se sijeku u tacci (%.1lf,%.1lf)", presjekx, presjeky);
	}
	
	return 0;
}
