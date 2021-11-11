#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
	float a1, b1, a2, b2;
	char c;
	float epsilon=0.00001;
	float x, y;
	printf("Unesite a1,b1,a2,b2: ");
    scanf("%f",&a1);
    scanf("%c",&c);
    scanf("%f",&b1);
    scanf("%c",&c);
    scanf("%f",&a2);
    scanf("%c",&c);
    scanf("%f",&b2);
	
	if((abs(a1)-abs(a2))<epsilon && fabs((b1-b2)<epsilon)) printf("Poklapaju se");
	else if((abs(a1) - abs(a2))<epsilon) {printf("Paralelne su");}
	else {
		x = ((b2-b1) / (a1-a2));
		y = a1 * x + b1;
		printf("Prave se sijeku u tacci (%.1f,%.1f)",x,y);
	}
	
	return 0;
}
