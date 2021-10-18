#include <stdio.h>
#include <math.h>

int main() {
	float a1, a2, b1, b2, x, y, a, b;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f",&a1,&b1,&a2,&b2);
	if (a1==a2&&b1==b2){
	printf("Poklapaju se");
	}
	else if(a1==a2&&b1!=b2){
	printf("Paralelne su");
	}
	else {
		a=a1-a2;
		b=b2-b1;
		x=b/a;
		y=a1*x+b1;
		printf("Prave se sijeku u tacci (%.1f,%.1f)", x, y);
	}
	return 0;
}