#include <stdio.h>
#include <math.h>
int main() {
	float a1,b1,a2,b2,x,y;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f, %f, %f, %f", &a1,&b1,&a2,&b2);
	x=(b2-b1)/(a1-a2);
	y=(b1*a2-b2*a1)/(a2-a1);
	if(a1==a2 && b1==b2) printf("Poklapaju se ");
	if(a1==a2 && b1!=b2) printf("Paralelne su");
	
	if(a1!=a2){
		printf("Prave se sijeku u tacci (%.1f,%.1f)", x, y);
	}
	return 0;
}

