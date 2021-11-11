#include <stdio.h>
#include <math.h>

int main() {
	float a1,a2,b1,b2;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f",&a1,&b1,&a2,&b2);
	float x,y;
	if(0.0000001>fabs(a1-a2) && 0.0000001>fabs(b1-b2)){
		printf("Poklapaju se");
	}
	else if(0.0000001>fabs(a1-a2)){
		printf("Paralelne su");
	}
	else{
		x = (b2 - b1) / (a1 - a2);
		y = (a2 * x) + b2;
		printf("Prave se sijeku u tacci (%.1f,%.1f)\n",x,y);
	}
	
	return 0;
}
