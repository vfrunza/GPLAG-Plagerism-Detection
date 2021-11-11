#include <stdio.h>
#include <math.h>
int Poredi(double x,double y)
{
	const double Eps=0.0000001 ;
	return fabs(x-y) <= Eps * (fabs(x)+fabs(y));
}

int main() {
	double a1,a2,b1,b2,x,y1,y2;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%lf,%lf,%lf,%lf",&a1,&b1,&a2,&b2);
	if((Poredi(a1,a2)) && !Poredi(b1,b2))
    	printf("Paralelne su");
	else if(Poredi(a1,a2) && Poredi(b1,b2))
	    printf("Poklapaju se");
	else if(!Poredi(a1,a2)){
		x=(b2-b1)/(a1-a2);
    	y1=a1*x+b1;
    	y2=a2*x+b2;
    	if(Poredi(y1,y2))
    		printf("Prave se sijeku u tacci (%.1lf,%.1lf)", x, y1);
	}
    return 0;
}