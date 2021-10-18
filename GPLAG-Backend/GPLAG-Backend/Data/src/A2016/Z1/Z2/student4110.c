#include <stdio.h>

int main() {
	float a1, b1, a2, b2, X, Y;
	printf ("\n Unesite a1,b1,a2,b2:");
	scanf ("%f, %f, %f, %f", &a1, &b1, &a2, &b2);
	if ((a1==a2)&&(b1==b2))
	{
		printf ("\n Prave se poklapaju.");
	}
	else if ((a1==a2)&&(b1!=b2))
	{
		printf ("\n Prave su paralelne.");
	}
	else 
	{
		X=(b2-b1)/(a1-a2);
		Y=(a1*X)+b1;
		printf ("\n Prave se sijeku u tačci %.1f %.1f", X,Y);
	}
	return 0;
}
