#include <stdio.h>
#include <math.h>
#define epsilon 0.001
#define eps 0.1

int main() {
	double a,b,c;
	double D;
	double x;
	double x1, x2;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	D=b*b-4.*a*c;
	if(D<0){
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	else{
		x1=(-b-sqrt(D))/(2*a);
		x2=(-b+sqrt(D))/(2*a);
		if(x2<x1) { 	/*D koristim kao privremenu varijablu*/ 
			D=x1;		/*x2 mora biti veće od x1*/
			x1=x2;
			x2=D;
		}
	}
	
	do{
		printf("Unesite rjesenje x1: ");
		scanf("%lf", &x);
		
		if((fabs(x-x1))<epsilon) {							/*x==x1*/
			printf("Tacno\n"); 
			break;
		} 
		else if(x<x1) {
			if(x1-x<eps) printf("Priblizno manje\n");
			else printf("Manje\n");
		}
		else {										
			if(x-x1<eps) printf("Priblizno vece\n");
			else printf("Vece\n");	
		} 
	}while(1);
	
	do{
		printf("Unesite rjesenje x2: ");
		scanf("%lf", &x);
		
		if((fabs(x-x2))<epsilon){
			printf("Tacno");
			break;
		}
		else if(x<x2){
			if(x2-x<eps) printf("Priblizno manje\n");
			else printf("Manje\n");
		}
		else{
			if(x-x2<eps) printf("Priblizno vece\n");
			else printf("Vece\n");
		}
	}while(1);
	
	
	
return 0;
}
