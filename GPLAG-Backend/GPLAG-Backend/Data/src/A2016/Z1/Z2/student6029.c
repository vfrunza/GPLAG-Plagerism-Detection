#include <stdio.h>
#include <math.h>
#define EPS 0.000001

int main() {
	double a1=0,b1=0,a2=0,b2=0,x=0,y=0;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%lf,%lf,%lf,%lf",&a1,&b1,&a2,&b2);
	if(fabs(a2-a1)<EPS &&fabs(b2-b1)<EPS){
		printf("Poklapaju se");
		return 0;
	}
	if(fabs(a2-a1)<EPS){
		printf("Paralelne su");
		return 0;
	}
	else{
		x=(b2-b1)/(a1-a2);
		y=a1*x+b1;
		printf("Prave se sijeku u tacci (%.1lf,%.1lf)",x,y);
	}
return 0;		
}
