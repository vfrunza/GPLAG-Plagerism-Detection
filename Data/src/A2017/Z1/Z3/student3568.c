#include <stdio.h>
#include <math.h>
#define e 0.001


int main()
{
	double a,b,c,x1,x2, rjesenje1, rjesenje2, temp;
	int tacno1=0, tacno2=0;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	if((b*b-4*a*c)<0) printf("Rjesenja su imaginarni brojevi.");
	else {
		x1= (-b - sqrt(b*b - 4*a*c)) / (2*a); /*manje*/
		x2= (-b + sqrt(b*b - 4*a*c)) / (2*a); /*veće*/

		if (x1>x2) {
			temp=x1;
			x1=x2;
			x2=temp;
		}

		do {
			printf("Unesite rjesenje x1: ");
			scanf("%lf", &rjesenje1);

			if(rjesenje1-x1-e>0 && rjesenje1-x1+e<0) {
				printf("Tacno\n");
				tacno1=1;
			} else if(rjesenje1-x1-e<0 && rjesenje1-x1>-e) {
				printf("Tacno\n");
				tacno1=1;
			} else if(rjesenje1-x1<0 && rjesenje1-x1>-0.1) printf("Priblizno manje\n");
			else if(rjesenje1-x1>0 && rjesenje1-x1<0.1) printf("Priblizno vece\n");
			else if(rjesenje1>x1) printf("Vece\n");
			else if(rjesenje1<x1) printf("Manje\n");


		} while (tacno1!=1);

		do {
			printf("Unesite rjesenje x2: ");
			scanf("%lf", &rjesenje2);

			if(rjesenje2-x2-e>0 && rjesenje2-x2+e<0) {
				printf("Tacno\n");
				tacno2=1;
			} else if(rjesenje2-x2-e<0 && rjesenje2-x2>-e) {
				printf("Tacno\n");
				tacno2=1;
			} else if(rjesenje2-x2<0 && rjesenje2-x2>-0.1) printf("Priblizno manje\n");
			else if(rjesenje2-x2>0 && rjesenje2-x2<0.1) printf("Priblizno vece\n");
			else if(rjesenje2>x2) printf("Vece\n");
			else if(rjesenje2<x2) printf("Manje\n");



		} while (tacno2!=1);
	}
	return 0;
}
