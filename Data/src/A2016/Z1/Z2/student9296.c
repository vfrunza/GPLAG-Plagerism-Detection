#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001

int main() {
	
	double a1=0, b1=0, a2=0, b2=0, y1, x;
	
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%lf, %lf, %lf, %lf", &a1, &b1, &a2, &b2);
	
	if(b2==b1 && a2==a1)   //ne valja, smrc :'(
	{
		printf("Poklapaju se");							
		return 0;
	}
	else if(b2!=b1 && a1==a2)
	{
		printf("Paralelne su");
		return 0;
	}
	else
	{
		x = ((b2-b1)/(a1-a2));
		
		y1 = a1*x+b1;
		
		printf("Prave se sijeku u tacci (%.1f,%.1f)", x, y1);
	}
	return 0;
}
