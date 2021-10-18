#include <stdio.h>
#include <math.h>
#define G 0.0001

int main(){
	float a1,b1,a2,b2,k,y1,y2;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f", &a1,&b1,&a2,&b2);
	
	k=(b2-b1)/(a1-a2);
	
	y1=k*a1+b1;
	y2=k*a2+b2;
	
	if(fabs(y1-y2)<G){
		printf("Prave se sijeku u tacci (%.1f,%.1f)", k,y1);
	}
	else if(fabs(a1-a2)<G && fabs(b1-b2)<G){
		printf("Poklapaju se");
	}
	else if(fabs(a1-a2)<G){
		printf("Paralelne su");
	}	
	return 0;
}
