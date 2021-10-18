#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

int main()
{
	double a,b,c,x1,x2,D,n1,n2;
	int brojac1=0;
	int brojac2=0;

	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);


	//NACI USLOVE ZA OVO PRIBLOZNO VECE MANJE I TO; POSEBNO ZA USLOV KADA JE ISPUNJEN PA SLIJEDI PRINTF TACNO I ZA OVO FABS VIDJETI

	D=((b * b) - (4 * a * c));
	x2=((-b - ( sqrt(D))) / (2 * a));
	x1=((-b + ( sqrt(D))) / (2 * a));

	if(D>=0) {
		do {
			printf("Unesite rjesenje x1: ");
			scanf("%lf", &n1);
			if(fabs(n1-(x1))<EPSILON) {
				printf("Tacno\n");
				brojac1=1;
			} else if((n1>x1) && fabs(n1-x1)< 0.1) {
				printf("Priblizno vece\n");
			} else if((n1<x1) && fabs(n1-x1)< 0.1) {
				printf("Priblizno manje\n");
			} else if(n1>x1) {
				printf("Vece\n");
			} else if(n1<x1) {
				printf("Manje\n");
			}
		} while(brojac1!=1);



		do {
			printf("Unesite rjesenje x2: ");
			scanf("%lf", &n2);
			if(fabs(n2-(x2))<EPSILON) {
				printf("Tacno\n");
				brojac2=1;
			} else if((n2>x2) && fabs(n2-x2)< 0.1) {
				printf("Priblizno vece\n");
			}

			else if((n2<x2) && fabs(n2-x2)< 0.1) {
				printf("Priblizno manje\n");
			} else if(n2>x2) {
				printf("Vece\n");
			} else if(n2<x2) {
				printf("Manje\n");
			}


		} while(brojac2!=1);

	}

	else {
		printf("Rjesenja su imaginarni brojevi. \n");
	}



	return 0;

}
