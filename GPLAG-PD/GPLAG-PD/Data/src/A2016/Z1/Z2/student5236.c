#include <stdio.h>
#include <math.h>
#define epsilon 0.001
int main() {
	float a1,b1,a2,b2,X,Y;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f",&a1,&b1,&a2,&b2);
	if(fabs(a1-a2)<epsilon  && fabs(b1-b2)<epsilon){
		printf("Poklapaju se");
	
     }else if(a1 != a2){
		X=(b2-b1)/(a1-a2);
		Y=a2*X + b2;
		printf("Prave se sijeku u tacci (%.1f,%.1f)",X,Y);
	}else if(fabs(a1-a2)<epsilon){
		printf("Paralelne su");
	}
	
	return 0;
}
