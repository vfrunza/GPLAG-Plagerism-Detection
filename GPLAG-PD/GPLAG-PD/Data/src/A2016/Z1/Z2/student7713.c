#include <stdio.h>
#include <math.h>
#define eps 0.000000000000000000001
int main() {
	
	float a1, b1, a2, b2, xT, yT;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f", &a1, &b1, &a2, &b2);
	
	if((fabs(a1-a2) < eps) && (fabs(b1-b2) < eps)) {
		printf("Poklapaju se");
		return 0;
	}
	if(fabs(a1-a2)<eps) {
		printf("Paralelne su");
		return 0;
	}
	
	else {	
	xT = ((b2-b1)/(a1-a2));
	yT = ((a1*(b2-b1)/(a1-a2)) + b1);
	}
	
	printf("Prave se sijeku u tacci (%.1f,%.1f)", xT, yT);
	return 0;
}
