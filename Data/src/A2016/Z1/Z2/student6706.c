#include <stdio.h>
#include <math.h>
#define eps 0.0000001
int main() {
	float a1,a2,b1,b2,x=0,y=0;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f",&a1,&b1,&a2,&b2);
	if((fabs(a1-a2)<eps) && !(fabs(b1-b2)<eps))
	printf("Paralelne su");
	else if((fabs(a1-a2)<eps) && (fabs(b1-b2)<eps))
	printf("Poklapaju se");
	else{
	x=(float)(b2-b1)/(a1-a2);
	y=a1*x+b1;
	printf("Prave se sijeku u tacci (%.1f,%.1f)",x,y);
	}
	
	return 0;
}
