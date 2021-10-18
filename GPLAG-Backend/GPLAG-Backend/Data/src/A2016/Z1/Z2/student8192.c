#include <stdio.h>
#include <math.h>
#define EPS 0.0000001

int main() 
{
	float a1=0, b1=0, a2=0, b2=0, x=0, y=0;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f", &a1, &b1, &a2, &b2);
	
	if(fabs(a1-a2)>EPS) 
	{
		x = (b2-b1)/(a1-a2);
		y = x * a1 + b1;
		printf("Prave se sijeku u tacci (%.1f,%.1f)", x, y);
	}
	
	if(fabs(a1-a2)<EPS && fabs(b1-b2)>EPS) printf("Paralelne su");
	if(fabs(a1-a2)<EPS && fabs(b1-b2)<EPS) printf("Poklapaju se");
	
	return 0;
}
