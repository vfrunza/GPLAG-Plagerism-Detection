#include <stdio.h>
#include <math.h>
#define EPSILON 0.01

int main() {
	float a1, a2, b1, b2, xkp=0, ykp=0;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f", &a1, &b1, &a2, &b2);
	if(fabs(a1-a2)<EPSILON && fabs(b1-b2)<EPSILON){
	    printf("Poklapaju se");
	    return 0;
	}
	if(fabs(a1-a2)<EPSILON){
	    printf("Paralelne su");
	    return 0;
	}
    xkp=(b2-b1)/(a1-a2);
    ykp=a1*xkp+b1;
    printf("Prave se sijeku u tacci (%.1f,%.1f)", xkp, ykp);
    
	return 0;
}
