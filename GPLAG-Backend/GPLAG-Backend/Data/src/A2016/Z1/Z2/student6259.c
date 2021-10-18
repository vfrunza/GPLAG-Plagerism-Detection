#include <stdio.h>
#include <math.h>
#define b 0.0001

int main() {
	
	float a1, b1, a2, b2, x, y;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f", &a1, &b1, &a2, &b2);
	
	if(fabs(a2-a1)<b && fabs(b2-b1)<b) printf("Poklapaju se");
	else if(fabs(a1-a2)<b) printf("Paralelne su");
	else{
		x=((b2-b1)+0.0)/(a1-a2);
		y=(((b2-b1)+0.0)/(a1-a2))*a1 + b1;
		printf("Prave se sijeku u tacci (%.1f,%.1f)", x, y);
		
	}
	
	return 0;
}
