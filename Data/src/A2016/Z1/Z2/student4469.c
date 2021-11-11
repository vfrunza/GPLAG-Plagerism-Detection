#include <stdio.h>
#include <math.h>
#define epsilon 0.001
int main() {
	
	float a1=0,b1=0,a2=0,b2=0;
	float x=0;
	float y=0;
		
	
	
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f, %f, %f, %f", &a1,&b1,&a2,&b2);
	if (fabs(a1-a2)<epsilon && fabs(b1-b2)<epsilon) {
		printf("Poklapaju se");
	}
	
	else if(fabs(a1-a2)<epsilon) {
		printf("Paralelne su");
	}
	
	else 
	{
	x=(b2-b1)/(a1-a2);
		y=a1*x+b1; 
		printf("Prave se sijeku u tacci (%.1f,%.1f)", x, y);
	}
	
	return 0;
}
