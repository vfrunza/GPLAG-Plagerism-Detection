#include <stdio.h>
#include<math.h>
#define EPSILON 0.0001
#define printaj printf
#define citaj scanf

int main() {
	double a1,b1,a2,b2,x,y;
	printaj("Unesite a1,b1,a2,b2: ");
	citaj("%lf,%lf,%lf,%lf",&a1,&b1,&a2,&b2);
	if(fabs(a1-a2)<EPSILON && fabs(b1-b2)>EPSILON) {
		printaj("Paralelne su");
		return 0;
	}

	else if(fabs(a1-a2)<EPSILON && fabs(b1-b2)<EPSILON) {
		printaj("Poklapaju se");
		return 0;
	}
		
	x=(b2-b1)/(a1-a2);
	y=a1*x + b1;
	printaj("Prave se sijeku u tacci (%.1f,%.1f)",x,y);
	return 0;
}
