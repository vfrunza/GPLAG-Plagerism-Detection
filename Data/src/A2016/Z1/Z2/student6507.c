#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

int main() {
	float a1, b1, a2, b2, y1, x;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f, %f, %f, %f", &a1, &b1, &a2, &b2);
	if(EPSILON> fabs(a1-a2)){
	if(EPSILON>fabs(b1-b2)){
	printf("Poklapaju se");
	return 0;}
	printf("Paralelne su");
	
	}
	
	else{
	x=(b2-b1)/(a1-a2);
	y1=a1*x+b1;
	printf("Prave se sijeku u tacci (%.1f,%.1f)", x, y1);
	}
	 return 0;
}
