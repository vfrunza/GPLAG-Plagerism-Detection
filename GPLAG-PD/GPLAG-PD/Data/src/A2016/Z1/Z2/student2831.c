#include <stdio.h>
int main() {
	
	float x,y,a1,a2,b1,b2;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f",&a1,&b1,&a2,&b2);
	
	if(a1==a2 && b1==b2) {
		printf("Poklapaju se");
	}
	else if(a1==a2) {
		printf("Paralelne su");
	}
	else {
		y=((a2*b1)-(a1*b2))/(a2-a1);
		x=(y-b2)/a2;
		
		printf("Prave se sijeku u tacci (%.1f,%.1f)",x,y);
	}
	return 0;
}
