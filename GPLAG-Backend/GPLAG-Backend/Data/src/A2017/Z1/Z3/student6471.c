#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

int main() {
	double a,b,c,x1,X1,X2,x2;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	x1=((-b+sqrt(b*b-4*a*c))/(2*a));
	
	
	x2=((-b-sqrt(b*b-4*a*c))/(2*a));
	
	if(b*b-4*a*c<0){
		printf("Rjesenja su imaginarni brojevi.");
		
	}
	     else{
	do{	printf("Unesite rjesenje x1: ");
		scanf("%lf",&X1);
		if(fabs(X1-x1)<EPSILON){
			printf("Tacno\n");
		}
		else if(X1<x1 && fabs(X1-x1)>=0.1){
			printf("Manje\n");	}
		else if(X1>x1 && fabs(X1-x1)>=0.1){
			printf("Vece\n");	}
		else if(X1>x1 && fabs(X1-x1)<0.1){
			printf("Priblizno vece\n");}
		else if(X1<x1 && fabs(X1-x1)<0.1){
			printf("Priblizno manje\n");}
		else return 0;
		
	} while(fabs(X1-x1)>=EPSILON);
	
	do{	printf("Unesite rjesenje x2: ");
		scanf("%lf",&X2);
		if(fabs(X2-x2)<EPSILON){
			printf("Tacno");	}
		else if(X2<x2 && fabs(X2-x2)>=0.1){
			printf("Manje\n");}
			
		else if(X2>x2 && fabs(X2-x2)>=0.1){
			printf("Vece\n");
		}
		else if(X2>x2 && fabs(X2-x2)<0.1){
			printf("Priblizno vece\n");	}
		else if(X2<x2 && fabs(X2-x2)<0.1){
			printf("Priblizno manje\n");
		}
		else return 0;
	} while(fabs(X2-x2)>=EPSILON);}
	return 0;}

