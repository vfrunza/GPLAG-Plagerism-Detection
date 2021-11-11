#include <stdio.h>
#define epsilon 0.0000001
#include <math.h>



int main() {
	
	double y1,y2,a1,a2,b1,b2,x;
	
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%lf,%lf,%lf,%lf",&a1,&b1,&a2,&b2);
	

	x=(b2-b1)/(a1-a2);
		y1=a1*x+b1;
	y2=a2*x+b2;
	
	
	if((fabs(y1-y2)<epsilon )) printf("Prave se sijeku u tacci (%.1f,%.1f)",x,y1);

      
     else if( (fabs(a1-a2)<epsilon) && (fabs(b1-b2)<epsilon)) { printf("Poklapaju se");}
     
       else  if (fabs(a1-a2)<=epsilon) {printf("Paralelne su");}
	

	return 0;
}
