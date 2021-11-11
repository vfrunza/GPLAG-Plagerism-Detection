#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

int main() {
	double  a,b,c,x1,x2,X1,X2,D,d,min,max;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	d=pow(b,2);
	D=d-(4*a*c);
		if (D<0) {
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	x1=(-b+D)/(2*a);
	x2=(-b-D)/(2*a);
	max=x2;
	min=x1;
	if(x1>max) {
		max=x1;
		min=x2;
	}

	do {
		printf("Unesite rjesenje x1: ");
	scanf("%lf",&X1);
	
		 
		if (fabs(min-X1)<EPSILON) {
		printf("Tacno\n");
		break;
		}
	else if (fabs(min-X1)<0.1 && (X1<min)) {
		printf("Priblizno manje\n");
		continue;
	}
	else if (fabs(min-X1)<0.1 && (X1>min)) {
		printf("Priblizno vece\n");
		continue;
	}
	else if (min>X1) {
	printf("Manje\n");
	continue;
	} 
	else if (min<X1)	{
	printf("Vece\n");
	continue;
	}
	}
	while (1);
    do {
		printf("Unesite rjesenje x2: ");
	scanf("%lf",&X2);
   if (fabs(max-X2)<EPSILON) {
		printf("Tacno\n");
		break;
	}
	else if (fabs(max-X2)<0.1 && (X2<max)) {
		printf("Priblizno manje\n");
		continue;
	}
	else if (fabs(max-X2)<0.1 && (X2>max)) {
		printf("Priblizno vece\n");
		continue;
	}
	else if (max>X2) {
	printf("Manje\n");
	continue;
	} 
	else if (max<X2)	{
	printf("Vece\n");
	continue;
	} 
    }
    while (1);
	return 0;
	}
	
