#include <stdio.h>
#include <math.h>
int main() {
	double a1, b1, a2, b2, e=0.00000000001, x, y;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%lf,%lf,%lf,%lf", &a1, &b1, &a2, &b2);
	if(fabs(a1-a2)<e) {
		if(fabs(b1-b2)<e) {
		printf("Poklapaju se");
		}
		else{ printf("Paralelne su");
		}
	}
	else{
			x=(float)(b2-b1)/(a1-a2);
	y=(float)a1*x+b1;

		printf("Prave se sijeku u tacci (%.1f,%.1f)", x, y);
	}
	return 0;
}
