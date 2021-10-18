#include <stdio.h>
#include <math.h>
#define E 0.001

int main()
{
	double a,b,c,x1,x2,rijesenje1,rijesenje2,diskriminanta;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	diskriminanta=b*b-4*a*c;
	if(diskriminanta<0) {
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}

	x1=(-b-(sqrt(b*b-4*a*c)))/(2*a);
	x2=(-b+(sqrt(b*b-4*a*c)))/(2*a);

	do {
		printf("Unesite rjesenje x1: ");
		scanf("%lf",&rijesenje1);
		if((fabs(rijesenje1-x1))<E) {
			printf("Tacno\n");

		} else if (rijesenje1<x1 && (fabs(rijesenje1-x1))>=0.1) {
			printf("Manje\n");
		} else	if((rijesenje1-x1)<0.1 && rijesenje1<x1) {
			printf("Priblizno manje\n");
		}	else if ((rijesenje1>x1) && (fabs(rijesenje1-x1))>=0.1 ) {
		printf("Vece\n");
		}else if((rijesenje1-x1)<0.1 && rijesenje1>x1) {
			printf("Priblizno vece\n");

		}
	} while(fabs(rijesenje1-x1)>=E);


	do {
		printf("Unesite rjesenje x2: ");
		scanf("%lf",&rijesenje2);
		if((fabs(rijesenje2-x2))<E) {
			printf("Tacno\n");

		} else if (rijesenje2<x2 && (fabs(rijesenje2-x2))>=0.1) {
			printf("Manje\n");
		} else	if((rijesenje2-x2)<0.1 && rijesenje2<x2) {
			printf("Priblizno manje\n");
		}	else if ((rijesenje2>x2) && (fabs(rijesenje2-x2))>=0.1 ) {
		printf("Vece\n");
		}else if((rijesenje2-x2)<0.1 && rijesenje2>x2) {
			printf("Priblizno vece\n");

		}
	} while(fabs(rijesenje2-x2)>=E);

return 0;
}
