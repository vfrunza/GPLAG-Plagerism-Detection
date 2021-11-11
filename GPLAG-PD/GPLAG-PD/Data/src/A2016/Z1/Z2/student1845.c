#include <stdio.h>
#define Z 0.001

int main() {
	double x,y,a1,a2,b1,b2;
	double razlika1,razlika2;
	
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%lf,%lf,%lf,%lf", &a1, &b1, &a2, &b2);
	razlika1=a1-a2;
	razlika2=b1-b2;
	if(razlika1<0) 
	razlika1=-razlika1;
	if(razlika2<0)
	razlika2=-razlika2;
	
	if(razlika1<Z && razlika2<Z)
	printf("Poklapaju se");
	
	else if(razlika1<Z && razlika2>Z)
	printf("Paralelne su");
	
	else {
		x=(b2-b1)/(a1-a2);
		y=a1*x+b1;
		printf("Prave se sijeku u tacci (%.1f,%.1f)", x,y);
	}

	return 0;
}
