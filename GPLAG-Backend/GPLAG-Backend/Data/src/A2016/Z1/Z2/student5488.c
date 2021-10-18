#include <stdio.h>
#include <math.h>
int main() 
{
	float a1, a2, b1, b2, x, y;
	
	printf("\nUnesite a1, b1, a2, b2. ");
	scanf("%f, %f, %f, %f", &a1, &b1, &a2, &b2);
	
	if (a1 == a2 && b1 != b2)
	printf("Prave su paralelne!");
	else if (a1 == a2 && b1 == b2)
	printf("Prave se poklapaju!");
	
	x = (b2-b1) / (a1-a2);
	y = a1 * x + b1;
	printf("Prave se sijeku u tacki sa kordinatama %.1f, %.1f", x, y);
	
	return 0;
}
