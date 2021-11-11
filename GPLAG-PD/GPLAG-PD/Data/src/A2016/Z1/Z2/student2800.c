#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EPSILON 0.000001
int main() {
	/*printf("Zadaća 1, Zadatak 2");*/
	
	float a1,a2,b1,b2,x,y;
	
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f",&a1,&b1,&a2,&b2);
	
	if( (fabs(a2-a1)<=EPSILON*(fabs(a2)-fabs(a1))) && (fabs(b2-b1)<=EPSILON*(fabs(b2)-fabs(b1)))){
		printf("Poklapaju se");
		
	}
	else if( (fabs(a2-a1)<=EPSILON) && (fabs(b2-b1)!=EPSILON) ){
		printf("Paralelne su");
	}
	
	else{
		x=(b1-b2)/(a2-a1);
		y=a1*x+b1;
		printf("Prave se sijeku u tacci (%.1f,%.1f)",x,y);
		
		
	}
	return 0;
}
