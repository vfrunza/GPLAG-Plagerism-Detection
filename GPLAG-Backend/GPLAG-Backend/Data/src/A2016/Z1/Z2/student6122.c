#include <stdio.h>

int main() {
	printf("Zadaća 1, Zadatak 2");
	float a1,a2,b1,b2,x,y;
	printf("\nUnesite vrijednosti a1,b1,a2,b2:");
	scanf("%f,%f,%f,%f",&a1,&b1,&a2,&b2);
	if(a1==a2)
	{
		if(b1==b2)
		{
			printf("Poklapaju se.");
		}
		else
		{
			printf("Paralelne su.");
		}
	}
	else
	{
		x=(b2-b1)/(a1-a2);
		y=a1*x+b1;
		printf("Prave se sijeku u tacci %.1f, %.1f", x, y);
	}
	return 0;
}
