#include <stdio.h>
#include <math.h>
#define epsilon 0.00005
int main()
{
	//printf("Zadaća 1, Zadatak 2");
	float a,b,c,d,x,y;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f",&a,&b,&c,&d);
	if(fabs(a-c)<epsilon && fabs(b-d)<epsilon) {
		printf("Poklapaju se");
		return 0;
	}
	if(fabs(a-c)<epsilon) {
		printf("Paralelne su");
		return 0;
	}
	x=(d-b)/(a-c);
	y=a*x+b;
	printf("Prave se sijeku u tacci (%.1f,%.1f)",x,y);
	return 0;
}
