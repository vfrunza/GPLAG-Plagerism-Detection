#include <stdio.h>
#include <math.h>
#define GRESKA 0.0001

int main() {
	
	float a1,b1,a2,b2;
	float x,y;
	
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f",&a1,&b1,&a2,&b2);
	if(fabs(a1-a2)<GRESKA&&fabs(b1-b2)<GRESKA){
		printf("Poklapaju se");
		return 0;
	}
	else if(fabs(a1-a2)<GRESKA){
		printf("Paralelne su");
		return 0;
	}
	else{
	x=(b2-b1)/(a1-a2);
	y=(a1*x)+b1;
	printf("Prave se sijeku u tacci (%.1f,%.1f)",x,y);}
	
	
	return 0;
}
