#include <stdio.h>
#include <math.h>
#define epsilon 0.00000001

int main() {
	double a1,b1,a2,b2,x,t;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%lf,%lf,%lf,%lf", &a1,&b1,&a2,&b2);
	x=((b2-b1)/(a1-a2));
	t=(a1*x)+b1;
	if ((fabs(a1-a2)<epsilon) && (fabs(b1-b2)<epsilon))
		printf("Poklapaju se");
	else if(fabs(a1-a2)<epsilon)
		printf("Paralelne su");
	else{
		printf("Prave se sijeku u tacci (%.1f,%.1f)", x,t);
	}
	
	return 0;
}
