#include <stdio.h>

int main() 
{
	float a1, a2, b1, b2, y1, y2, x;
	printf ("Unesite a1,b1,a2,b2: ");
	scanf ("%f, %f, %f, %f", &a1, &b1, &a2, &b2);
	
	x=(b2-b1)/(a1-a2);
	
	y1=a1*x+b1;
	y2=a2*x+b2;
	
	if (y1-y2==0) printf ("Prave se sijeku u tacci (%.1f,%.1f)\n", x, y1);

	if (a1-a2==0 && b1-b2==0) 
	{
		printf ("Poklapaju se\n");
		return 1;
	}
		if (a1-a2==0) 
	{
		printf ("Paralelne su\n");
		return 1;
	}
	return 0;
}
