#include <stdio.h>
#include <math.h>
#define EPSILON 0.1

int main() {
	float a1,b1,a2,b2;
	printf("\nUnesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f",&a1,&b1,&a2,&b2);
	if(fabs(a1-a2)<EPSILON) {
		if(fabs(b1-b2)<EPSILON)
		printf("Poklapaju se");
		else printf("Paralelne su");
	}
	else{
		float rez= (-b1+b2 );
	    float x=(rez/(a1-a2));
	    float y=(a1*x+b1);
		printf("Prave se sijeku u tacci (%g,%g)",x,y);
	}
return 0;
}
