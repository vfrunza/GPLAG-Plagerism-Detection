#include <stdio.h>
#include <math.h>
#define epsilon 0.0001
int main() {
	float a1, a2, b1, b2, y, x;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f",&a1,&b1,&a2,&b2);
	x=(b2-b1)/(a1-a2);
	y=a2*x+b2;
	
	if((fabs(a1-a2) < epsilon) && (fabs(b1-b2) < epsilon)){
		printf("Poklapaju se");
	}else if(fabs(a1-a2) < epsilon){
		printf("Paralelne su");
	}else{
		printf("Prave se sijeku u tacci (%.1f,%.1f)",x,y);
	}
	return 0;
}
