#include <stdio.h>
#include <math.h>
const double eps=0.001;

int main()
{
	int a, b, c;
	float x1, x2, x11, x22;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%d%d%d", &a, &b, &c);
	if (b*b-4*a*c<0) {
		printf("Rjesenja su imaginarni brojevi.");
		return 1;
	}
	x11=(-1*b-sqrt(b*b-4*a*c))/(2*a);
	x22=(-1*b+sqrt(b*b-4*a*c))/(2*a);

	if (x22>x11) {

		printf("Unesite rjesenje x1: ");
		scanf("%f", &x1);

		do {
			while ((x1-x11)>0.1) {
				printf("Vece");
				printf("\nUnesite rjesenje x1: ");
				scanf("%f", &x1);
			}
			while ((x11-x1)>0.1) {
				printf("Manje");
				printf("\nUnesite rjesenje x1: ");
				scanf("%f", &x1);
			}
			while ((x1-x11)<0.1 && (x1-x11)>eps) {
				printf("Priblizno vece");
				printf("\nUnesite rjesenje x1: ");
				scanf("%f", &x1);
			}
			while ((x11-x1)<0.1 && (x11-x1)>eps) {
				printf("Priblizno manje");
				printf("\nUnesite rjesenje x1: ");
				scanf("%f", &x1);
			}
		} while (fabs(x11-x1)>eps);

		printf("Tacno");

		printf("\nUnesite rjesenje x2: ");
		scanf("%f", &x2);

		do {
			while ((x2-x22)>0.1) {
				printf("Vece");
				printf("\nUnesite rjesenje x2: ");
				scanf("%f", &x2);
			}
			while ((x22-x2)>0.1) {
				printf("Manje");
				printf("\nUnesite rjesenje x2: ");
				scanf("%f", &x2);
			}
			while ((x2-x22)<0.1 && (x2-x22)>eps) {
				printf("Priblizno vece");
				printf("\nUnesite rjesenje x2: ");
				scanf("%f", &x2);
			}
			while ((x22-x2)<0.1 && (x22-x2)>eps) {
				printf("Priblizno manje");
				printf("\nUnesite rjesenje x2: ");
				scanf("%f", &x2);
			}
		} while (fabs(x22-x2)>eps);

		printf("Tacno");
	}

	else {

		printf("Unesite rjesenje x1: ");
		scanf("%f", &x2);

		do {
			while ((x2-x22)>0.1) {
				printf("Vece");
				printf("\nUnesite rjesenje x1: ");
				scanf("%f", &x2);
			}
			while ((x22-x2)>0.1) {
				printf("Manje");
				printf("\nUnesite rjesenje x1: ");
				scanf("%f", &x2);
			}
			while ((x2-x22)<0.1 && (x2-x22)>eps) {
				printf("Priblizno vece");
				printf("\nUnesite rjesenje x1: ");
				scanf("%f", &x2);
			}
			while ((x22-x2)<0.1 && (x22-x2)>eps) {
				printf("Priblizno manje");
				printf("\nUnesite rjesenje x1: ");
				scanf("%f", &x2);
			}
		} while (fabs(x22-x2)>eps);

		printf("Tacno");

		printf("\nUnesite rjesenje x2: ");
		scanf("%f", &x1);

		do {
			while ((x1-x11)>0.1) {
				printf("Vece");
				printf("\nUnesite rjesenje x2: ");
				scanf("%f", &x1);
			}
			while ((x11-x1)>0.1) {
				printf("Manje");
				printf("\nUnesite rjesenje x2: ");
				scanf("%f", &x1);
			}
			while ((x1-x11)<0.1 && (x1-x11)>eps) {
				printf("Priblizno vece");
				printf("\nUnesite rjesenje x2: ");
				scanf("%f", &x1);
			}
			while ((x11-x1)<0.1 && (x11-x1)>eps) {
				printf("Priblizno manje");
				printf("\nUnesite rjesenje x2: ");
				scanf("%f", &x1);
			}
		} while (fabs(x11-x1)>eps);

		printf("Tacno");
	}
	return 0;
}