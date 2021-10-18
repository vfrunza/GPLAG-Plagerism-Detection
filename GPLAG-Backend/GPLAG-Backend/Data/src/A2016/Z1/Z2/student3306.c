#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
int main() {
	/*printf("Zadaća 1, Zadatak 2");*/
	double a1,b1,a2,b2,x,y;
	printf ("Unesite a1,b1,a2,b2: ");
	scanf ("%lf,%lf,%lf,%lf",&a1,&b1,&a2,&b2);
	if (fabs(a1-a2)<EPSILON && fabs (b1-b2)>EPSILON)
		printf ("Paralelne su");
	else if (fabs(a1-a2)<EPSILON && fabs (b1-b2)<EPSILON)
		printf ("Poklapaju se");
	else {
	x=(b2-b1)/(a1-a2);
	y=a1*x+b1;
	printf ("Prave se sijeku u tacci (%.1f,%.1f)",x,y);
	}
	return 0;
}
