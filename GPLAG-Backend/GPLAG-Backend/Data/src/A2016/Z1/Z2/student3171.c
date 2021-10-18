#include <stdio.h>
#include <math.h>
#define e 0.0000001



int main() {
	
	double a1, a2, b1, b2, x, y;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%lf,%lf,%lf,%lf", &a1, &b1, &a2, &b2);
	
	if((fabs(a1-a2)<e || fabs(a2-a1)<e) && (fabs(b1-b2)<e || fabs(b2-b1)<e)) printf("Poklapaju se");
	else if(fabs(a1-a2)<e || fabs(a2-a1)<e) printf("Paralelne su");
	else {
	    
	    x=(b2-b1)/(a1-a2);
	    y=x*a1+b1;
	    
	    printf("Prave se sijeku u tacci (%.1f,%.1f)", x, y);
	    
	}
	
	
	return 0;
}
