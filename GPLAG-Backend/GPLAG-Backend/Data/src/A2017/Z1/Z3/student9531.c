#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
#define PRBEPS 0.1
int main()
{
	double a, b, c, d, sqd, x1, x2, x1k, x2k;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	d=(pow(b, 2))-4.0*a*c;
	sqd=sqrt(d);
	if(d<0) {
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	} else {
		x1=(-b+sqd)/(2*a);
		x2=(-b-sqd)/(2*a);
		do {
			printf("Unesite rjesenje x1: ");
			scanf("%lf", &x1k);
			if(fabs(x1k-x1)<EPSILON)
				printf("Tacno\n");
			else if(x1k<x1&&fabs(x1k-x1)>=PRBEPS)
				printf("Manje\n");
			else if(x1k>x1&&fabs(x1k-x1)>=PRBEPS)
				printf("Vece\n");
			else if(x1k<x1&&fabs(x1k-x1)<PRBEPS)
				printf("Priblizno manje\n");
			else
				printf("Priblizno vece\n");
		} while(fabs(x1k-x1)>=EPSILON);
		do {
			printf("Unesite rjesenje x2: ");
			scanf("%lf", &x2k);
			if(fabs(x2k-x2)<EPSILON) {
				printf("Tacno\n");
				return 0;
			} else if(x2k<x2&&fabs(x2k-x2)>=PRBEPS)
				printf("Manje\n");
			else if(x2k>x2&&fabs(x2k-x2)>=PRBEPS)
				printf("Vece\n");
			else if(x2k<x2&&fabs(x2k-x2)<PRBEPS)
				printf("Priblizno manje\n");
			else
				printf("Priblizno vece\n");
		} while(fabs(x2k-x1)>=EPSILON);
	}
	return 0;
}
