#include <stdio.h>
#include <math.h>
int main() {
	const double Eps=1e-10;
	float a1,a2,b1,b2,y1,x;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f", &a1,&b1,&a2,&b2);
	x=(b2-b1)/(a1-a2);
	y1=a1*x+b1;
	if(fabs(a1-a2)<=Eps*(fabs(a1)+fabs(a2)) && fabs(b1-b2)<=Eps*(fabs(b1)+fabs(b2))){
		printf("Poklapaju se");
	}
	else if(fabs(a1-a2)<=Eps*(fabs(a1)+fabs(a2))){
		printf("Paralelne su");
	}
	else{
		printf("Prave se sijeku u tacci (%.1f,%.1f)",x,y1);
	}
	return 0;
}
