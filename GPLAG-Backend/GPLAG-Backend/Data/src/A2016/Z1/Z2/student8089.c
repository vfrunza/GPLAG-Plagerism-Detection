#include <stdio.h>

int main() {
	
	double a1,b1,a2,b2,x,y1,y2;
	
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%lf,%lf,%lf,%lf",&a1,&b1,&a2,&b2);
	
	if ((a1==a2) && (b1==b2))
	printf("Poklapaju se");
    if ((a1==a2) && (b1!=b2))
	printf("Paralelne su");
    
    x=(b2-b1)/(a1-a2);
	y1=a1*x+b1;
	y2=a2*x+b2;
	if ((a1!=a2) && (b1!=b2))
	printf("Prave se sijeku u tacci (%.1f,%.1f) ",x,y1);
	 
   
	
	
	
	return 0;
}
