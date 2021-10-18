#include <stdio.h>
#include <math.h>
#define EPS 0.000000001

int main() {
	float a1,a2,b1,b2,koordinata_x,koordinata_y;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f",&a1,&b1,&a2,&b2);
	
	if ((fabs(a1-a2)<EPS) && (fabs(b1-b2)<EPS))
	{
		printf("Poklapaju se");
		return 0;
	}
	else if ((fabs(a1-a2)<EPS))
	{
		printf("Paralelne su");
		return 0;
	}
	else
	{
		koordinata_x=(b2-b1)/(a1-a2);
		koordinata_y=a1*koordinata_x+b1;
		printf("Prave se sijeku u tacci (%.1f,%.1f)",koordinata_x,koordinata_y);
	}

	return 0;
}
