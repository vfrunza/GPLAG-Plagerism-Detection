#include <stdio.h>
#include<math.h>
#define EPSILON 0.001
#define EPSILON1 0.1

int main() {
	printf("Unesite koeficijente a, b i c: ");
	double a,b,c;
	scanf ("%lf %lf %lf", &a, &b, &c);
	double d;


	if (b*b-4*a*c+EPSILON<0){
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	d=sqrt(b*b-4*a*c);
	double x1,x2,x;
	x1=(-b-d)/(2*a);
	x2=(-b+d)/(2*a);
	 if (x2<x1) {
	 	x=x1;
	 	x1=x2;
	 	x2=x;
	 }
	double r1; 
	 do{
	 	printf("Unesite rjesenje x1: ");
	 	scanf ("%lf", &r1);
		
	 	if(fabs(r1-x1)<EPSILON) printf("Tacno\n");
	 	else if (fabs(r1-x1)<EPSILON1 && x1>r1) printf("Priblizno manje\n");
	 	else if (fabs(r1-x1)<EPSILON1 && x1<r1) printf("Priblizno vece\n");
	 	else if (r1<x1) printf("Manje\n");
	 	else if(r1>x1) printf ("Vece\n");
	 	 }while (fabs(r1-x1)>=EPSILON);
	 
	double r2;
	do{
		printf("Unesite rjesenje x2: ");
		scanf("%lf", &r2);
		if(fabs(r2-x2)<EPSILON) 
			printf("Tacno");
	 		else if (fabs(r2-x2)<EPSILON1 && x2>r2) printf("Priblizno manje\n");
	 		else if (fabs(r2-x2)<EPSILON1 && x2<r2) printf("Priblizno vece\n");
	 		else if (r2<x2) printf("Manje\n");
	 		else if(r2>x2) printf ("Vece\n");
	}while(fabs(r2-x2)>=EPSILON);
	
	return 0;
}
