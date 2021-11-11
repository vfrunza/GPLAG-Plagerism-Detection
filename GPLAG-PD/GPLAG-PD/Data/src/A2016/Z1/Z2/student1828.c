#include <stdio.h>
#include <math.h>
#define epsilon 0.00001

int main() {
	float a1,b1,a2,b2,y1,y2,x,y;
	printf ("Unesite a1,b1,a2,b2: ");
	scanf ("%f,""%f," "%f," "%f",&a1,&b1,&a2,&b2 );
	y1=a1*x+b1;
	y2=a2*x+b2;
	if (fabs (a1-a2)<epsilon && fabs(b1-b2)>epsilon) {printf("Paralelne su"); }
	else if (fabs (a1-a2)<epsilon && fabs(b1-b2)<epsilon) {printf ("Poklapaju se");}
	    else {
        x=(float)(b1-b2)/(float)(a2-a1);
        y=a1*x+b1;
        printf ("Prave se sijeku u tacci (%.1f,%.1f)", x, y); }

	return 0;
}
