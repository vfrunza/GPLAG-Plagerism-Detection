#include <stdio.h>

int main() {
	float a1,b1,a2,b2;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f", &a1,&b1,&a2,&b2);
	float x,y1;
	if (a1==a2 && b1==b2)
	printf("Poklapaju se\n");
	else if (a1==a2 )
	printf("Paralelne su\n");
	else {
		x=(b2-b1)/(a1-a2);
		y1=a1*x+b1;
	printf ("Prave se sijeku u tacci (%.1f,%.1f)", x,y1); 
}
	return 0;
}
