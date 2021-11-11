#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
int main() {
	double a, b, c, D=0, x11=0, x22=0, x1, x2;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	
	
	D=b*b-4.0*a*c;
	
	if (D<0) {
	printf ("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	else if (a>0){
		x11=(-b-sqrt(D))/(2*a);
		x22=(-b+sqrt(D))/(2*a);
	}

	else if(a<0){
		x11=(-b+sqrt(D))/(2*a);
		x22=(-b-sqrt(D))/(2*a);
	}
	
	do {
		printf("Unesite rjesenje x1: ");
		scanf("%lf", &x1);
		if (fabs(x1-x11)<EPSILON)
		printf("Tacno\n");
			else if((x1<x11) && (fabs(x1-x11)>=0.1))
			printf ("Manje\n");
			else if((fabs(x1-x11)>=0.1)&&(x1>x11)) printf("Vece\n");
		
			else if((x1<x11)&&(fabs(x1-x11)<0.1)) 
			printf ("Priblizno manje\n");
			else if ((fabs(x1-x11)<0.1)&&(x1>x11)) printf("Priblizno vece\n");
	}
	
	while (fabs(x1-x11)>=EPSILON);
	
	do {
		printf("Unesite rjesenje x2: ");
		scanf("%lf", &x2);
		if (fabs(x2-x22)<EPSILON)
		printf("Tacno\n");
			else if ((x2<x22)&&(fabs(x2-x22)>=0.1))
			printf("Manje\n");
			else if ((fabs(x2-x22)>=0.1)&&(x2>x22)) printf("Vece\n");
		
		else if((x2>x22)&&(fabs(x2-x22)<0.1))
			printf("Priblizno vece\n");
			else if ((fabs(x2-x22)<0.1)&&(x2<x22)) printf("Priblizno manje\n");
		}
	
	while (fabs(x2-x22)>=EPSILON);
	
return 0;
	
}
 