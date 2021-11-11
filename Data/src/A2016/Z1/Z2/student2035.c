#include <stdio.h>

int main() {
    double a1,a2, b1, b2, x, y;
    printf("Unesite a1,b1,a2,b2: ");
    scanf("%lf,%lf,%lf,%lf", &a1, &b1, &a2, &b2);
    y=-(b1*a2-b2*a1)/(a1-a2);
    x=-(b1-b2)/(a1-a2);
    if (a1==a2 && !(b1==b2)) {
    	printf("Paralelne su");
    }
    else if (a1==a2 && b1==b2) {
    	printf("Poklapaju se");
    }
    else {
    	printf("Prave se sijeku u tacci (%.1lf,%.1lf)",x, y);
    }
	return 0;
}
