#include <stdio.h>
#include <cmath.h>
#define e 0.0001

int main() {
	double x1,y1,x2,y2,x3,y3;
	double d1,d2,d3;
	printf ("Unesite koordinate tacke t1: ");
	scanf ("%f%f",&x1,&y1);
	printf ("Unesite koordinate tacke t2: ");
	scanf ("%f%f",&x2,&y2);
	printf ("Unesite koordinate tacke t3: ");
	scanf ("%f%f",&x3,&y3);
	d1=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	d2=sqrt((x1-x3)*(x3-x2)+(y1-y3)*(y1-y3));
	d3=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	return 0;
}
