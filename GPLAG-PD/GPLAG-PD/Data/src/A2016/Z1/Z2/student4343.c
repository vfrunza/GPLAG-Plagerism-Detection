#include <stdio.h>
#include <math.h>
int main() {
	float x,y,a1,a2,b1,b2,m;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f",&a1,&b1,&a2,&b2);
	m=-a1*a2;
	if (fabs (a1-a2)<0.0001 && fabs(b1-b2)<0.0001)
	{
			
	printf("Poklapaju se");		
	}
	else if (fabs(a1-a2)<0.0001 )
{printf("Paralelne su");
	
}
	else { 	
	y=(-a1*b2+b1*a2)/(a2-a1);
		x=(y-b2)/a2;
		printf("Prave se sijeku u tacci (%.1f,%.1f)",x,y);
		
	}
	return 0;
}
