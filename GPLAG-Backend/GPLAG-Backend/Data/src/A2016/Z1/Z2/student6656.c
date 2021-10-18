#include <stdio.h>
#include <math.h>
#define e 0.0001

int main() {
	double a1, a2, b1, b2, x, y;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%lf ,%lf, %lf, %lf",&a1,&b1,&a2,&b2);
	if(fabs(a1-a2) < e)
	{
		if(fabs(b1-b2) < e)
		{
		printf("Poklapaju se");
		return 0;
		}
		else
		{
		printf("Paralelne su");
		return 0;
		}
	}
	else
	{
	x=(b1-b2)/(a2-a1);
	y=a2*x+b2;
	printf("Prave se sijeku u tacci (%.1f,%.1f)",x,y);
	}
	return 0;
}
