#include <stdio.h>
#include <math.h>
#define P 4
#define D 2
#define E 0.001

int main()
{
	double a, b, c, x1,x2, xm, xv, U, i=0,j=1,k=1,l=1,m=1,n=1;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf%lf%lf", &a, &b, &c);
	U=(b*b)-(4*a*c);
	if (U<0) {
		printf("Rjesenja su imaginarni brojevi.");
      i=1;
	}
	if (b==-12||b==0&&i!=1) {
		printf("GG");
		i=1;
	}

if (i!=1) {
		xm=(-b-(sqrt(U)))/D*a;
		xv=(-b+(sqrt(U)))/D*a;

		do {
			printf("Unesite rjesenje x1: ");
			scanf("%lf", &x1);

			if(x1<xm-0.1) {
				printf("Manje\n");
			}
			if(x1>xm+0.1) {
				printf("Vece\n");
			}
			if((x1<xm-E)&&(x1>=xm-0.1+E)) {
				printf("Priblizno manje\n");
			}
			if((x1>xm+E)&&(x1<xm+0.1-E)) {
				printf("Priblizno vece\n");
			}
			if(((x1>xm-E)&&(x1<xm+E))) {
				printf("Tacno\n");
				break;
			}
		} while (1);

		do {
			printf("Unesite rjesenje x2: ");
			scanf("%lf", &x2);

			if(x2<xv-0.1) {
				printf("Manje\n");
			}
			if(x2>xv+0.1) {
				printf("Vece\n");
			}
			if((x2<xv-E)&&(x2>=xv-0.1)) {
				printf("Priblizno manje\n");
			}
			if((x2>xv+E)&&(x2<=xv+0.1)) {
				printf("Priblizno vece\n");
			}
			if(((x2>xv-E)&&(x2<xv+E))) {
				printf("Tacno\n");
				break;
			}

		} while (1);






	}

}
