#include <stdio.h>

int main() {
	double a1=0, b1=0, a2=0, b2=0;
	float x=0, y=0, b=0, a=0; 
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%lf,%lf,%lf,%lf", &a1, &b1, &a2, &b2);
	b=(b2-b1);
	a=(a1-a2);
	x=b/a;
	y=(a1*x)+b1;
	if(a1==a2 && b1==b2)
	{
		printf("Poklapaju se\n");
	}
	else if(a1==a2)
	{
		printf("Paralelne su\n");
	}
	else
	{
		printf("Prave se sijeku u tacci (%.1f,%.1f)\n", x, y);
	}
	return 0;
}
