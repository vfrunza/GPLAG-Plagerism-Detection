#include <stdio.h>
#include <math.h>
int main() {
	float a1,a2,b1,b2,x,y1/*y2*/;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f",&a1,&b1,&a2,&b2);
	x=(b2-b1)/(a1-a2);
	y1=a1*x+b1;
	/*y2=a2*x+b2;*/
	if (fabs(a1-a2)>0.001)
	printf("Prave se sijeku u tacci (%.1f,%.1f)",x,y1);
	
	else if(fabs(a1-a2)<0.001 && fabs(b1-b2)>0.001 )
	printf("Paralelne su");
	
	else
	printf("Poklapaju se");
	
	return 0;
}
