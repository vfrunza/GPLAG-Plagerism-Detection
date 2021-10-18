#include <stdio.h>
#include <math.h>

#define eps 0.000000000001

int main() {
	float a1,b1,a2,b2, x, y1, y2;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f", &a1, &b1, &a2, &b2);
	if( fabs(a1-a2)<eps && fabs(b1-b2)>eps)
		printf("Paralelne su");
	else if( fabs(a1-a2)<eps && fabs(b1-b2)<eps )
		printf("Poklapaju se");
	else
		{
			x = (b1-b2) / (a2-a1);
			y1 = a1 * x + b1;
			y2 = a2 * x + b2;
			if(fabs(y1-y2)<eps)
				printf("Prave se sijeku u tacci (%.1f,%.1f)", x,y1);
		}
	return 0;
}
