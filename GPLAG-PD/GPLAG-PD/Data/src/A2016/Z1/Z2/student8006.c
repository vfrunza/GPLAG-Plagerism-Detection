#include <stdio.h>
#include <math.h>
#define Eps 0.00000000000001
int main() {
	float a1, a2, b1, b2, x, y1, y2;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f", &a1, &b1, &a2, &b2 );
	x=(b1-b2)/(a2-a1);
	y1=a1*x+b1;
	y2=a2*x+b2;
	if(fabs(a1-a2)<Eps && fabs(b1-b2)<Eps)
	{printf("Poklapaju se");}
	else if(fabs(a1-a2)<Eps)
	{printf("Paralelne su");}
	else if(fabs(y1-y2)<Eps)
	{printf("Prave se sijeku u tacci (%.1f,%.1f)", x, y1);}
	return 0;
}