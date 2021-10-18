#include <stdio.h>
#include <math.h>
#define eps 0.001

int main() {
	
	float a1,a2,b1,b2,c,d;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f",&a1,&b1,&a2,&b2);
	if (fabs(a1-a2)<eps)
	{if(fabs(b1-b2)<eps)
	printf("Poklapaju se");
	else
	printf("Paralelne su");
	}
	else
	{
		c=(b2-b1)/(a1-a2);
		d=a1*c+b1;
	printf("Prave se sijeku u tacci (%.1f,%.1f)",c,d);
	
	}
	
	return 0;
}
