#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EPSILON 0.001
int main() {

double a,b,c,D,x1,x2,K,T;
printf("Unesite koeficijente a, b i c: ");
scanf("%lf %lf %lf", &a,&b,&c);

D=(pow(b,2))-4.0*a*c;
	
	if(D<0){
		printf("Rjesenja su imaginarni brojevi.");}
		else{
			x1=(-b+sqrt(D))/(2*a);
			x2=(-b-sqrt(D))/(2*a);
			if(x1>x2){
				x2=x1;
				x1=x2;}
		do{
			printf("Unesite rjesenje x1: ");
			scanf("%lf", &K);
			
        if(fabs(x1-K)<EPSILON)
		printf("Tacno\n");
        else if(K<x1 && fabs(K-x1)>=0.1)
		printf("Manje\n");
		else if(K>x1 && fabs(K-x1)>=0.1)
		printf("Vece\n");
		else if(K<x1 && fabs(K-x1)<0.1)
		printf("Priblizno manje\n");
		else
		printf("Priblizno vece\n");}
		
		while(fabs(x1-K)>=EPSILON);
		
		do{
			printf("Unesite rjesenje x2: ");
			scanf("%lf", &T);
			
		if(fabs(x2-T)<EPSILON)
		printf("Tacno\n");
        else if(T<x2 && fabs(T-x2)>=0.1)
		printf("Manje\n");
		else if(T>x2 && fabs(T-x2)>=0.1)
		printf("Vece\n");
		else if(T<x2 && fabs(T-x2)<0.1)
		printf("Priblizno manje\n");
		else
		printf("Priblizno vece\n");}
		
		while(fabs(x2-T)>=EPSILON);
			}
		
	return 0;
}
