#include<math.h>
#include <stdio.h>
#define E 0.01

int main() {
	double a1,b1;
	double a2,b2;
	double x,y; 
	
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%lf,%lf,%lf,%lf", &a1, &b1, &a2, &b2);
	
	if(fabs(a2-a1)<E) {
	   if(fabs(b2-b1)<E) printf("Poklapaju se");
	   else printf("Paralelne su");
	   return 0;
	}
	
	x=(b2-b1)/(a1-a2);
	y=a2*x+b2;
	
	printf("Prave se sijeku u tacci (%.1f,%.1f)", x,y);
	return 0;
}