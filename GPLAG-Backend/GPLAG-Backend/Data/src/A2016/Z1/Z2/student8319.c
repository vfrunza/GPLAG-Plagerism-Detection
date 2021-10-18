#include <stdio.h>
#include <math.h>
int main() {
	
	
	float a1,a2,b1,b2;
	float x=0;
	float y1=0;
	float y2=0;
	

	
	printf("Unesite a1,b1,a2,b2:");
	scanf("%f,%f,%f,%f",&a1,&b1,&a2,&b2);
    x=(b2-b1)/(a1-a2);
	y1=(a1*x+b1);
    y2=(a2*x+b2);
    

if((a1-a2==0) && (b1-b2==0))
printf(" Poklapaju se");
else if(a1-a2==0)
printf(" Paralelne su");
else if(y1-y2==0)
printf(" Prave se sijeku u tacci (%.1f,%.1f)",x,y1);


	return 0;
}
