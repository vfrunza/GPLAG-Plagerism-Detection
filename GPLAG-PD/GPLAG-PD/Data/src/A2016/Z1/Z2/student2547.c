#include <stdio.h>
#include <math.h>
#define e 0.00000000001

int main() {
	float a1, a2, b1, b2;
	float x, y1, y2;
	printf("\nUnesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f1", &a1,&b1,&a2,&b2);
	x=(b2-b1)/(a1-a2);
	y1=a1*x+b1;
	y2=a2*x+b2;
	if(fabs(y2-y1)<e){
		printf("Prave se sijeku u tacci (%.1f,%.1f)", x,y1);
	}
	else if(fabs(a1-a2)<e && fabs(b1-b2)<e){
		printf("Poklapaju se");
	}
	else printf("Paralelne su");
	return 0;
}
