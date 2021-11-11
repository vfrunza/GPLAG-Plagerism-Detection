#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define e 0.01
int main () {
	float a,b,c,d,x,y;
	printf ("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f", &a,&b,&c,&d);
	x=((d-b)/(a-c));
	y=(a*x)+b;
	if (fabs(a-c)<e && fabs(b-d)<e) {
	printf("Poklapaju se");
	return 0;}
	else if (fabs(a-c)<e) {
	printf("Paralelne su");
	return 0;
	}
	printf("Prave se sijeku u tacci (%.1f,%.1f)", x,y);
	return 0;
}