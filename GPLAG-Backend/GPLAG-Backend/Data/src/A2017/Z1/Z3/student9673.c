#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

int main() {
	
	double a,b,c,x1,x2;
	double D,t,pokusaj1,pokusaj2;
	double min,max;
	
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	
	D=b*b-4.0*a*c;
	
	if(D<0){ 
		printf ("Rjesenja su imaginarni brojevi.");
	return 0;}
	
	t=sqrt(D);
	x1=(-b-t)/(2.0*a);
	x2=(-b+t)/(2.0*a);
	
	min=x1;
	if(x2<min){
	min=x2;}
	
	max=x2;
	if(x1>max){
		max=x1;
	}
		
		do { 
			printf("Unesite rjesenje x1: ");
		scanf("%lf", &pokusaj1);
		
		if(fabs(pokusaj1-min)<EPSILON){
		printf("Tacno\n");
		break;}
		
		if(pokusaj1<min && fabs(pokusaj1-min)>=0.1) printf("Manje\n");
		if(pokusaj1<min && fabs (pokusaj1-min)<0.1) printf("Priblizno manje\n");
		if(pokusaj1>min && fabs(pokusaj1-min)>=0.1) printf("Vece\n");
		if(pokusaj1>min && fabs(pokusaj1-min)<0.1) printf("Priblizno vece\n");
			
		}
		while(fabs(pokusaj1-min)>=EPSILON);

		
		do {
			printf("Unesite rjesenje x2: ");
		scanf("%lf", &pokusaj2);
		if(fabs(pokusaj2-max)<EPSILON){
			 printf("Tacno");
			 break;}
		if(pokusaj2<max && fabs(pokusaj2-max)>=0.1) printf("Manje\n");
		if(pokusaj2<max && fabs (pokusaj2-max)<0.1) printf("Priblizno manje\n");
		if(pokusaj2>max && fabs(pokusaj2-max)>=0.1) printf("Vece\n");
		if(pokusaj2>max && fabs(pokusaj2-max)<0.1) printf("Priblizno vece\n");
			
		}
		while(fabs(pokusaj2-max)>=EPSILON);
		
		
	return 0;
}
