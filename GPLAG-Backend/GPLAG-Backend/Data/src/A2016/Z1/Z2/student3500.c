#include <stdio.h>

int main() {
	float a1, a2, b1, b2, X, Y;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f, %f, %f, %f", &a1, &b1, &a2, &b2);
	if ((a1==a2)&&(b1==b2)) printf("Poklapaju se");
	else if ((a1==a2)&&(b1!=b2)) printf ("Paralelne su");
	else {
		X=(b2-b1)/(a1-a2);
	    Y=a1*X+b1;
	    printf("Prave se sijeku u tacci (%.1f,%.1f)", X, Y);
	}
	return 0;
}
