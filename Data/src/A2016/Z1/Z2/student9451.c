#include <stdio.h>

int main() {
	float a1,b1,a2,b2;
	float x1,x2;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f, %f, %f, %f", &a1, &b1, &a2, &b2);
	
	if(a1==a2) {/* isti koeficijenti pravca */
		if(b1==b2) {
			printf("Poklapaju se");
		} else {
			printf("Paralelne su");
		}
	}else {
		x1=(b2-b1)/(a1-a2);
		x2=((a1*b2)-(a2*b1))/(a1-a2);
		
		printf("Prave se sijeku u tacci (%.1f,%.1f)", x1,x2);
		
	}
	
	return 0;
}
