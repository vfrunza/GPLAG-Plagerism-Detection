#include <stdio.h>
#include <math.h>
#define EPS 0.000001
int main() {
	float a1,a2,b1,b2,x,y,raza,razb;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f",&a1,&b1,&a2,&b2);
	raza=0;
	razb=0;
	raza=a2-a1;
	razb=b2-b1;
	if(((fabs)(raza)<EPS) && ((fabs)(razb)<EPS)) printf("Poklapaju se");
	else if((fabs)(raza)<EPS) printf("Paralelne su");
	else {
		x=(razb)/(-raza);
			y=a2*x+b2;
		printf("Prave se sijeku u tacci (%.1f,%.1f)",x,y);
	}
	return 0;
}
