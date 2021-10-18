#include <stdio.h>
#include <math.h>

#define EPSILON 0.001

int main() {
	double a, b, c;
	double delta;
	double x1, x2, unos;
	
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf%lf%lf", &a, &b, &c);
	
	delta = b * b - 4 * a * c;
	if (delta < 0) {
		printf("Rjesenja su imaginarni brojevi.\n");
		return 0;
	}
	
	x1 = (-b - sqrt(delta)) / (2 * a);
	x2 = (-b + sqrt(delta)) / (2 * a);
	
	do {
		printf("Unesite rjesenje x1: ");
		scanf("%lf", &unos);
		
		if (unos - x1 >= 0.1)
			printf("Vece\n");
		else if (x1 - unos >= 0.1)
			printf("Manje\n");
		else if (unos - x1 >= EPSILON)
			printf("Priblizno vece\n");
		else if (x1 - unos >= EPSILON)
			printf("Priblizno manje\n");
	}
	while (fabs(unos - x1) >= EPSILON);
	
	printf("Tacno\n");
	
	do {
		printf("Unesite rjesenje x2: ");
		scanf("%lf", &unos);
		
		if (unos - x2 >= 0.1)
			printf("Vece\n");
		else if (x1 - unos >= 0.1)
			printf("Manje\n");
		else if (unos - x1 >= EPSILON)
			printf("Priblizno vece\n");
		else if (x1 - unos >= EPSILON)
			printf("Priblizno manje\n");
	}
	while (fabs(unos - x2) >= EPSILON);
	
	printf("Tacno\n");
	
	return 0;
}
