#include <stdio.h>
#include <math.h>

int main() {
	float a1,b1,a2,b2;
	float tx,ty;
	
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f",&a1,&b1,&a2,&b2);
	
	if(fabs(a1-a2)<0.000001 && fabs(b1-b2)<0.000001)
	printf("Poklapaju se");
	else if(fabs(a1-a2)<0.000001){
		printf("Paralelne su");
		}
	else {
		tx=(b2-b1)/(a1-a2);
		ty=a1*tx+b1;
		printf("Prave se sijeku u tacci (%.1f,%.1f)",tx,ty);
	}
	
	
	return 0;
}
