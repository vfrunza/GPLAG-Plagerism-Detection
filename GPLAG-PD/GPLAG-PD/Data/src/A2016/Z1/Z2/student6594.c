#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
int main() {
float a1,b1,a2,b2,a,b,x,y2;
printf("Unesite a1,b1,a2,b2: ");
scanf("%f,%f,%f,%f",&a1,&b1,&a2,&b2);
	if(fabs(a1-a2)<EPSILON && fabs(b1-b2)>EPSILON){
		printf("Paralelne su");
		return 0;
	}
	if(fabs(a1-a2)<EPSILON && fabs(b1-b2)<EPSILON){
		printf("Poklapaju se");
		return 0;
	}
	
	a=(b2-b1);
	b=(a1-a2);
	x=a/b;
	y2=a2*x+b2;
	
	printf("Prave se sijeku u tacci (%.1f,%.1f)",x,y2);


return 0;
}
