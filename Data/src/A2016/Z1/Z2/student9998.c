#include <stdio.h>
#include <math.h>

int main() {
	double a1,a2,b1,b2,x,y;
	const double eps= 1e-5;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%lf,%lf,%lf,%lf",&a1,&b1,&a2,&b2);
	x=(b2-b1)/(a1-a2);
	y=a1*(b2-b1)/(a1-a2)+b1;
    if(fabs(a1-a2)<=eps && fabs(b1-b2)>eps) printf("Paralelne su");
	 	else if(fabs(a1-a2)<=eps && fabs(b1-b2)<=eps) printf("Poklapaju se");
    	else printf("Prave se sijeku u tacci (%.1f,%.1f)",x,y);
	
	return 0;
}
