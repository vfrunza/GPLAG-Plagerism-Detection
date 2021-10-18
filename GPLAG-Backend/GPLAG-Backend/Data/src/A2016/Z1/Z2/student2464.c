#include <stdio.h>

int main() {
	float a1, b1, a2, b2, x, y1, y2, epsilon;
	printf ("Unesite a1,b1,a2,b2: ");
	scanf ("%f,%f,%f,%f", &a1,&b1,&a2,&b2);
	
	x=(b2-b1) / (a1-a2);
	y1=a1*x+b1;
	y2=a2*x+b2;
	epsilon=y1-y2;
	if (epsilon<0.0001 || epsilon>-0.0001) printf ("Prave se sijeku u tacci (%.1f,%.1f)", x,y1);
	else if (a1==a2 && b1==b2) printf ("Poklapaju se");
	else printf ("Paralelne su");
	
	return 0;
}