#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	float a1=1,b1=1,a2=1,b2=1,x,y;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f", &a1,&b1,&a2,&b2);
	if(fabs(a1-a2)<0.001 && fabs(b1-b2)<0.001) {
		printf("Poklapaju se");
		return 0;
	}
	if(fabs(a1-a2)<0.001) {
		printf("Paralelne su");
		return 0;
	}
	x=(b2-b1)/(a1-a2);
	y=((b2-b1)/(a1-a2))*a1+b1;
	printf("Prave se sijeku u tacci (%.1f,%.1f)", x,y);
	return 0;
}
