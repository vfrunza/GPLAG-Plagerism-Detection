#include <stdio.h>
#include <math.h>

int main() {
	double a1, b1, a2, b2, y ;
	printf ("Unesite a1,b1,a2,b2: ");
	scanf ("%lf,%lf,%lf,%lf",&a1,&b1,&a2,&b2);
	
	if ((a1==a2) && (b1==b2)) {
		printf("Poklapaju se");
	}
	else if ((a1==a2) && (b1!=b2)) {
		printf ("Paralelne su");
	}
	else  {
		y=((b2-b1)/(a1-a2))*a1+b1;
		printf ("Prave se sijeku u tacci (%.1f,%.1f)", (b2-b1)/(a1-a2), y);
	}
	return 0;
	}
	
	

