#include <stdio.h>
#include <math.h>
#define epsilon 0.00000000000000000001
int main() {
	double a1,b1,a2,b2,xp,yp;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%lf,%lf,%lf,%lf",&a1,&b1,&a2,&b2);
	if(fabs(a1-a2)<epsilon && (fabs(b1-b2)>epsilon)) {
	    printf("Paralelne su");
	}
	if(a1==a2 && b1==b2) {printf("Poklapaju se");}
	if((int)(a1-a2)!=0) {
	    xp=(b2-b1)*(1./(a1-a2));
	    yp=a2*xp+b2;
	    printf("Prave se sijeku u tacci (%.1f,%.1f)",xp,yp);}
	return 0;
}
