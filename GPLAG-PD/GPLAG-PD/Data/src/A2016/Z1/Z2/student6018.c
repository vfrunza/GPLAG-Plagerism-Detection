#include <stdio.h>
#include <math.h>
#define epsilon 0.00000000000001
int main() {
	
	double a1,a2,b1,b2,x,y;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%lf,%lf,%lf,%lf", &a1, &b1, &a2, &b2);
	if(fabs(a1-a2)<epsilon && fabs(b1-b2)<epsilon) printf("Poklapaju se");
	else if(fabs(a1-a2)<epsilon) printf("Paralelne su");
	
	else {
		x=(b2-b1)/(a1-a2);
		y=a1*x+b1;
		printf("Prave se sijeku u tacci (%.1f,%.1f)", x,y);
	}
	
	
	
	
	return 0;
}
