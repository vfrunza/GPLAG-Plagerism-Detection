#include <stdio.h>
#include <math.h>
int main() {
	float a1, b1, a2, b2;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f, %f, %f, %f", &a1, &b1, &a2, &b2);
	if(fabs(a1)==fabs(a2) && fabs(b1) == fabs(b2)) printf("Poklapaju se");
	else if(fabs(a1) == fabs(a2)) printf("Paralelne su");
	else
	{
		printf("Prave se sijeku u tacci (%.1f,%.1f)", (b2-b1)/(a1-a2), a1*((b2-b1)/(a1-a2))+b1);
	}
	return 0;
}
