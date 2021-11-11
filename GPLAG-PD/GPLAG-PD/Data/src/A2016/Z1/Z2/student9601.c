#include <stdio.h>
#include <math.h>
#define EPS 0.000000001

int main() {
	float a1,a2,b1,b2;
	float x,y;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f",&a1,&b1,&a2,&b2);
	if (fabs(a1-a2)<EPS&&fabs(b1-b2)<EPS)
			printf("Poklapaju se\n");
		else if(fabs(a1-a2)<EPS)
				printf("Paralelne su\n");
	else{
	x=(b1-b2)/(a2-a1);
	y=(a2*b1-a1*b2)/(a2-a1);
	printf("Prave se sijeku u tacci (%.1f,%.1f)\n",x,y);
	}
	return 0;
}
