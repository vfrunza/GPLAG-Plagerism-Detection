#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

int main() {
	double a, b, c, x, y1, y2, x1, x2, D, razlika1, razlika2, t;
	
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	
	D = b*b -4.0*a*c;
	if(D<0) {
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	
	t = sqrt(D);
	y1 = (-b + t) / (2*a);
	y2 = (-b - t) / (2*a);
	do {
		printf("Unesite rjesenje x1: ");
		scanf("%lf", &x1);
	
	if(x1>y1)
		razlika1 = x1-y1;
	else if(x1<y1)
		razlika1 = y1-x1;
	else
		razlika1 = 0;
		
	if(razlika1 < EPSILON)
		printf("Tacno\n");
	else {
		if(x1>y1) {
			if(razlika1 < 0.1)
				printf("Priblizno vece\n");
			else
				printf("Vece\n");
		}		
		else if(x1<y1) {
			if(razlika1 < 0.1)
				printf("Priblizno manje\n");
			else
				printf("Manje\n");
		}
	}
	} while (razlika1 >= EPSILON);
	do {
		printf("Unesite rjesenje x2: ");
		scanf("%lf", &x2);
	
	if(x2>y2)
		razlika2 = x2-y2;
	else if(x2<y2)
		razlika2 = y2-x2;
	else
		razlika2 = 0;
	if(razlika2 < EPSILON)
		printf("Tacno\n");
	else {
			if(x2>y2) {
				if(razlika2 < 0.1)
					printf("Priblizno vece\n");
				else
					printf("Vece\n");
			}
			else if(x2<y2) {
				if(razlika2 < 0.1)
					printf("Priblizno manje\n");
				else
					printf("Manje\n");
			}
		} 
	}	while(razlika2 >= EPSILON);

	return 0;
}
