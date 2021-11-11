#include <stdio.h>
#include <math.h>

int main() {
	float a, b, c, d;
	float x,y;
	printf ("Unesite a1,b1,a2,b2: ");
	scanf ("%f, %f, %f, %f", &a, &b, &c, &d);
	if (a==c) {if (b==d) printf ("Poklapaju se");
	          else printf ("Paralelne su");}
	else  {
		x=(d-b)/(a-c);
		y=a*x+b;
		printf("Prave se sijeku u tacci (%.1f,%.1f)", x, y);}
		
	return 0;
		
}
