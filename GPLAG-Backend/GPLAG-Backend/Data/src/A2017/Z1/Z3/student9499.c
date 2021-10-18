#include <stdio.h>
#include <math.h>

#define E 0.001
#define O_1 0.1

/* equal */
int equal(double x, double y) {
	return (fabs(x-y) < E);
}

/* check solution */
void check(double x, int tip) {
	double temp=0.0; 
	
	do {
		printf("Unesite rjesenje x%d: ", tip); scanf("%lf", &temp);
		temp = temp-x;
		if(temp < O_1 && temp >= E)
			printf("Priblizno vece\n");
		else if(temp > -O_1 && temp <= -E)
			printf("Priblizno manje\n");
		else if(temp >= O_1) 
			printf("Vece\n");
		else if(temp <= -O_1)
			printf("Manje\n");
	}
	while (!equal(temp, .0)); 
	printf("Tacno\n");
	
}

int main() {
	/* initial */
	double a, b, c, x1, x2, D, temp;
	printf("Unesite koeficijente a, b i c: "); scanf("%lf %lf %lf", &a, &b, &c);
	
	/* check */
	D = b*b - 4*a*c;
	if(D < 0) {
		printf("Rjesenja su imaginarni brojevi.\n");
		return 0;
	}
	else {
		if(fabs(a) < E) {
			x1 = -c/b;
			check(x1, 1);
		}
		else {
			x1 = (-b - sqrt(D))/(2*a);
			x2 = (-b + sqrt(D))/(2*a);
			/* sort */
			if(x1 > x2) {
				temp = x1;
				x1 = x2;
				x2 = temp;
			}
			check(x1, 1);
			check(x2, 2);
		}
	}
	return 0;
}