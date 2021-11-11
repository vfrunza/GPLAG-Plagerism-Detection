#include <stdio.h>

int main() {
	double y,x,a1,b1,a2,b2;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%lf,%lf,%lf,%lf", &a1,&b1,&a2,&b2);
	if (a1==a2 && b1!=b2) {printf("Paralelne su");
	return 0;
	}
	else if(a1==a2 && b1==b2) {printf("Poklapaju se");
	return 0;
	}
	x=(b2-b1)/(a1-a2);
	y=a1*x+b1;
	printf("Prave se sijeku u tacci (%.1lf,%.1lf)", x,y);
	return 0;
}
