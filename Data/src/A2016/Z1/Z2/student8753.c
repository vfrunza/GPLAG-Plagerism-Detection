#include <stdio.h>
#include<math.h>

int main() {
	double a1,b1,a2,b2;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%lf,%lf,%lf,%lf", &a1,&b1,&a2,&b2);
	
	if(fabs(a1-a2)<0.001 && fabs(b1-b2)<0.001)
	printf("Poklapaju se");
	
	else if (fabs(a1-a2)<0.001)
	printf("Paralelne su");
	
	else {
		double x,y;
		x=(b2-b1)/(a1-a2);
		y=a2*(b2-b1)/(a1-a2)+b2;
		printf("Prave se sijeku u tacci (%.1lf,%.1lf)",x,y);
	}
	
	return 0;
}
