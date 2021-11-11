#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define y 0.001
#define k 0.1

int main()
{
	double a, b, c, x1, x2, DETERMINANTA, rjesenje1, rjesenje2, vr, mr, RAZIZMRJES1, RAZIZMRJES2;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	DETERMINANTA=(b*b)-4*a*c;
	if(DETERMINANTA<0) {
		printf("Rjesenja su imaginarni brojevi.");
	} else {
		rjesenje1=((-1)*b+sqrt(b*b-4*a*c))/(2*a);
		rjesenje2=((-1)*b-sqrt(b*b-4*a*c))/(2*a);

		if (rjesenje1<=rjesenje2) {
			mr=rjesenje1;
			vr=rjesenje2;
		} else {
			vr=rjesenje1;
			mr=rjesenje2;
		}
		do {
			printf("Unesite rjesenje x1: ");
			scanf("%lf", &x1);
			RAZIZMRJES1=fabs(x1-mr);
			if(RAZIZMRJES1>=k && mr<x1) {
				printf("Vece\n");
			} else if(RAZIZMRJES1>=k && mr>x1) {
				printf("Manje\n");
			} else if (RAZIZMRJES1>=y && mr<x1) {
				printf("Priblizno vece\n");
			} else if (RAZIZMRJES1>=y && mr>x1) {
				printf("Priblizno manje\n");
			} else {
				printf("Tacno\n");
			}
		} while((fabs(x1-mr)>=y) || (fabs(mr-x1)>=y));

		do {
			printf("Unesite rjesenje x2: ");
			scanf("%lf", &x2);
			RAZIZMRJES2=fabs(x2-vr);
			if(RAZIZMRJES2>=k && vr<x2) {
				printf("Vece\n");
			} else if(RAZIZMRJES2>=k && vr>x2) {
				printf("Manje\n");
			} else if (RAZIZMRJES2>=y && vr<x2) {
				printf("Priblizno vece\n");
			} else if (RAZIZMRJES2>=y && vr>x2) {
				printf("Priblizno manje\n");
			} else {
				printf("Tacno\n");
			}
		} while(fabs(x2-vr)>=y || fabs(vr-x2)>=y);
	}
	return 0;
}
