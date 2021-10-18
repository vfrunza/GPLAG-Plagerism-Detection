#include <stdio.h>
#include <math.h>
#define N 0.0000001
int main() {
	double a1,a2,b1,b2,y,x;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%lf,%lf,%lf,%lf",&a1,&b1,&a2,&b2);
	if(fabs(a1-a2)<N && fabs(b1-b2)<N)printf("Poklapaju se");
	else if(fabs(a1-a2)<N)printf("Paralelne su");
	else {
		x=(b2-b1)/(a1-a2);
		y=a1*x+b1;
		printf("Prave se sijeku u tacci (%.1f,%.1f)",x,y);
	}
	return 0;
}
