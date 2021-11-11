#include <stdio.h>

int main() {
	
	double x1, x2, y1, y2, x, y;
	
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%lf,%lf,%lf,%lf", &x1, &y1, &x2, &y2);
	
	//Paralelne su
	if(x1==x2 && y1==y2){
	printf("Poklapaju se");
	}
	
	//Poklapaju se
	else if(x1==x2){
		printf("Paralelne su");
	}
	
	//Sijeku se
	else{
		x=(y2-y1)/(x1-x2);
		y=x1*x+y1;
		printf("Prave se sijeku u tacci (%.1f,%.1f)", x, y);
	}
	
	return 0;
}
