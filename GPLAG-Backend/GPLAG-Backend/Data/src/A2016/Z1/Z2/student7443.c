#include <stdio.h>

int main() {
	double a1=0, a2=0, b1=0, b2=0, x=0, y=0;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%lf,%lf,%lf,%lf",&a1, &b1 ,&a2, &b2);
	if(a1==a2) 
	{
	if(b1==b2)
	{
		printf("Poklapaju se");
	}
  	else
	{
		printf("Paralelne su");
	}
	}
	else if(a1!=a2 && b1!=b2)
	{
		x=((b2-b1)/(a1-a2));
		y=(a1*x+b1);
		printf("Prave se sijeku u tacci (%.1lf,%.1lf)", x,y);
		}
		return 0;
	}
