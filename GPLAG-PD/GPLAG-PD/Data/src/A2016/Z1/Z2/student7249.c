#include <stdio.h>

int main() {
	float a1,b1,a2,b2,x,y;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f", &a1, &b1, &a2, &b2);
	if(a1==a2) {
		if(b1==b2)
		{printf("Poklapaju se");}
		else {printf("Paralelne su");}
	}
	else 
	{
		x=(b1-b2)/(a2-a1);
		y=a1*x+b1;
		printf("Prave se sijeku u tacci (%.1f,%.1f)", x,y);
	}
	
	return 0;
}
