#include <stdio.h>
#include <math.h>
#define EPSILON 0.00001
int main() {
	float y1,y2,a1,a2,b1,b2,x;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f", &a1,&b1,&a2,&b2);
		
    if (fabs(a1-a2)<EPSILON && fabs(b1-b2)<EPSILON)
	printf("Poklapaju se");
	else
	if (fabs(a1-a2)<EPSILON)
	printf("Paralelne su");
	else
    
    if(!(fabs(a1-a2)<EPSILON) && !(fabs(b1-b2)<EPSILON) )
    {
	    x=(b2-b1)/(a1-a2);
	    scanf("%f", &x);
		y1=a1*x+b1;
	    y2=a2*x+b2;
	    scanf("%f%f", &y1,&y2);
	    if(fabs(y1-y2)<EPSILON )
		printf("Prave se sijeku u tacci (%.1f,%.1f)", x,y1);
    	
    }
		

	return 0;
}
