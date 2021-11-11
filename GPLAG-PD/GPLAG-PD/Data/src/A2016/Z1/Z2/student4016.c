#include <stdio.h>
#include <math.h> 
#define E 0.000000001

int main() {
	double a1, b1, a2, b2, x, y1, y2;
	printf ("Unesite a1,b1,a2,b2: ");
	scanf ("%lf, %lf, %lf, %lf",&a1,&b1,&a2,&b2);
	y1=a1*x+b1;
	y2=a2*x+b2;
	if(fabs(a1-a2)<E && fabs(b1-b2)<E){printf("Poklapaju se");return 0;}
	else if (fabs(a1-a2)<E){
		printf ("Paralelne su");return 0;
	} else {
		x=(b2-b1)/(a1-a2);
		y1=a1*x+b1;
		printf ("Prave se sijeku u tacci (%.1f,%.1f)",x,y1);
	}
	return 0;
}