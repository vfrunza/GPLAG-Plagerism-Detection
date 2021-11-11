#include <stdio.h>
#include <math.h> 
#define EPSILON 0.0001
int main() {
	double a1,a2,b1,b2;
    float x,y ;
	printf ("Unesite a1,b1,a2,b2:");
    scanf ("%lf,%lf,%lf,%lf " , &a1, &b1, &a2, &b2);
	if (fabs(a1-a2)<EPSILON && (fabs(b2-b1)<EPSILON))
	{printf(" Poklapaju se\n");
	}
	else if (fabs(a1-a2)<EPSILON && (fabs(b1-b2)>EPSILON))
	{printf(" Paralelne su\n");
	}
	else {
		x=(b2-b1)/(a1-a2);
	y=(a1*(b2-b1))/(a1-a2)+b1;

	printf(" Prave se sijeku u tacci (%.1f,%.1f)", x, y );
	}
	return 0;
}
