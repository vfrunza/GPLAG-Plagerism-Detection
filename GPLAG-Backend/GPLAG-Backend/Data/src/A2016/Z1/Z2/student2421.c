#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

int main() {
	float a1,b1,a2,b2,x,y1;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f",&a1,&b1,&a2,&b2);
	
	x=(b2-b1)/(a1-a2);
	y1=a1*x+b1;

	
	if (fabs(a1-a2)<EPSILON && fabs(b1-b2)>EPSILON){
		printf("Paralelne su");
	}else {
		if (fabs(a1-a2)<EPSILON && fabs(b1-b2)<EPSILON){
			printf("Poklapaju se");
		}else {
			printf("Prave se sijeku u tacci (%.1f,%.1f)",x,y1);
		}
	}
	
	
	return 0;
}
