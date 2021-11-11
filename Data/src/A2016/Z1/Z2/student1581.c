#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001

int main() {
/*	printf("Zadaća 1, Zadatak 2");*/

float a1, a2, b1, b2, y;
printf("Unesite a1,b1,a2,b2: ");
scanf("%f,%f,%f,%f", &a1,&b1,&a2,&b2);

if(fabs(a1-a2) < EPSILON) 
{
	if(fabs(b1-b2) < EPSILON) printf("Poklapaju se");
	else if(fabs(b1-b2) > EPSILON) printf("Paralelne su");
}
else{
  float	x = (float)(b2-b1)/(float)(a1-a2);
	y=a1*x+b1;
	printf("Prave se sijeku u tacci (%.1f,%.1f)\n", x, y);
}
	return 0;
}
