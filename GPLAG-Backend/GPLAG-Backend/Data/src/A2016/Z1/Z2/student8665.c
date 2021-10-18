#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001

int main() {
	double a1=0,b1=0,a2=0,b2=0,x=0,y=0;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%lf,%lf,%lf,%lf", &a1, &b1, &a2, &b2);
	
	if(fabs(a1-a2)<EPSILON && fabs(b1-b2)<EPSILON){
		printf("Poklapaju se");
	}else if(fabs(a1-a2)<EPSILON){
		printf("Paralelne su");
	}else{
		x=(b2-b1)/(a1-a2);
		y=a1*x + b1; 
		
		printf("Prave se sijeku u tacci (%.1f,%.1f)", x,y);
	}
		return 0;
	}
