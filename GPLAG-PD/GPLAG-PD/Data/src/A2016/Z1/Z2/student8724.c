#include <stdio.h>
#include <math.h>
#define EP 0.0000000000000001
int main() {
		float a1, b1, a2, b2, x, y1, y2, y;
		printf("Unesite a1,b1,a2,b2: ");
		scanf("%f,%f,%f,%f", &a1,&b1,&a2,&b2);
		x=(b2-b1)/(a1-a2);
		y=a1*x+b1;
		y1=a1*x+b1;
		y2=a2*x+b2;
		
		if(fabs(a1-a2)<EP && fabs(b1-b2)<EP){
			printf("Poklapaju se");
			return 0;
		}
		
		
		else if(fabs(a1-a2)<EP){
			printf("Paralelne su");
			return 0;
		}
		else if (y1==y2){
			printf("Prave se sijeku u tacci (%.1f,%.1f)" , x,y);
			return 0;
		}
		
	return 0;
}
