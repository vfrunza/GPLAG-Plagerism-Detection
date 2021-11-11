#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001 

int main() {
	float a1,a2,b1,b2;
	float x=0,y=0;
	float pomocni1=0,pomocni2=0;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f",&a1,&b1,&a2,&b2);
	if(fabs (a1-a2)<EPSILON && fabs(b1-b2)<EPSILON) { printf("Poklapaju se"); return 0; }
	if(fabs (a1-a2)<EPSILON) { printf("Paralelne su"); return 0; }
	
	pomocni1=b2-b1;
	pomocni2=a1-a2;
    x=pomocni1/pomocni2;
    y=(a1*x)+b1;
	printf("Prave se sijeku u tacci (%.1f,%.1f)",x,y);
	return 0;
	
}
