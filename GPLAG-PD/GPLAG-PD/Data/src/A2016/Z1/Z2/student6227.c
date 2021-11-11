#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
int main() {
	float a1, b1, a2, b2, x, y;
	printf("Unesite a1,b1,a2,b2: ");
	scanf ("%f,%f,%f,%f", &a1, &b1, &a2, &b2);
	x=(b2-b1)/(a1-a2);
	y=(b1*a2-b2*a1)/(a2-a1);
	if ((fabs(a1-a2)<EPSILON) && (fabs(b1-b2)<EPSILON)){ 
	    printf ("Poklapaju se"); return 0;
	}else if (fabs(a1-a2)<EPSILON){
		printf ("Paralelne su"); return 0;
	}else 
        printf ("Prave se sijeku u tacci (%.1f,%.1f)", x, y);
	return 0;
}
