#include <stdio.h>

int main() {
	double a1,a2,b1,b2,e=0.001;
	double x,y;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%lf,%lf,%lf,%lf",&a1,&b1,&a2,&b2);
	if(a1+e==a2+e && b1+e == b2+e){printf("Poklapaju se");return 0;}
	else if(a1+e==a2+e){printf("Paralelne su");return 0;}
	x=((b2-b1)/(a1-a2));
	y=(a1*x+b1);
	printf("Prave se sijeku u tacci (%.1f,%.1f)",x,y);
	return 0;
}