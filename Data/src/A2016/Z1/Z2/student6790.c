#include <stdio.h>
#include <math.h>
#define eps 0.000000001

int main() {
	float k1,n1,k2,n2,k,n;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f",&k1,&n1,&k2,&n2);
	
	if (fabs(k1-k2)<eps) {
		if (fabs(n1-n2)<eps) {
		printf("Poklapaju se");
		}
		else {
		printf("Paralelne su");
		}
		
	}
	else {
		k=(n1-n2)/(k2-k1);
		n=k1*k+n1;
		printf("Prave se sijeku u tacci (%.1f,%.1f)",k,n);
	}
	
	
	return 0;
}
