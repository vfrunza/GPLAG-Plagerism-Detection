#include <stdio.h>
#include <math.h>
#define epsilon 0.0000000000001
int main() {
	double a1=0,a2=0,b1=0,b2=0,y1,y2,x;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%lf,%lf,%lf,%lf", &a1,&b1,&a2,&b2);
	x=(b2-b1)/(a1-a2);
	y1=a1*x+b1;
	y2=a2*x+b2;
	if(fabs(y2-y1)<epsilon) printf("Prave se sijeku u tacci (%.1f,%.1f)", x,y1);
	else if(fabs(a1-a2)<epsilon && fabs(b1-b2)<epsilon) printf("Poklapaju se");
	else printf("Paralelne su");
	return 0;
}
