#include <stdio.h>
#include <math.h>

int main() {
	float a1,a2,b1,b2,x,y;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f", &a1, &b1, &a2, &b2);
	x=(b2-b1)/(a1-a2);
	y=a2*x+b2;
	if(fabs(a1-a2)<0.00001 && fabs(b1-b2)>0.0001)
	printf("Paralelne su\n");
	else if(fabs(a1-a2)<0.0001 && fabs(b1-b2)<0.0001)
	printf("Poklapaju se");
	else printf("Prave se sijeku u tacci (%.1f,%.1f)\n", x,y);
	
	return 0;
}
