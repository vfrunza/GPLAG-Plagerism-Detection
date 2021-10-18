#include <stdio.h>
#include <math.h>
#define E 0.001
int main() {
	double a, b, c, D, X1, X2, x1, x2;
	
	
	printf("Unesite koeficijente a, b i c: ");
	scanf("&lf %lf &lf", &a, &b, &c);
	
    D=b*b-(4*a*c);
	x1=(-b+ sqrt(D))/(2*a);
	x2=(-b- sqrt(D))/(2*a);
	
	if(D<0){
		
	printf("Rjesenja su imaginarni brojevi.");
	
	}
	else {
	
	do{
		printf("Unesite rijesenje x1: ");
		scanf("%lf", &X1);
	}
	while (X1>x1 || X1<x1 || (X1-x1)<0.1 || (x1-X1)<0.1);
	
	if(fabs(X1-x1)<E){
		printf("Tacno \n");
	}	
	if(fabs(X1>x1)){
		printf("Vece \n");
	}	
	if(fabs(X1<x1)){
		printf("Manje \n");
	}	
	if(fabs(X1-x1)<0.1){
		printf("Priblizno manje \n");
	}	
	if(fabs(x1-X1)<0.1){
		printf("Priblizno vece \n");
	}	
	}	
	
	
	do{
		printf("Unesite rijesenje x2: ");
		scanf("%lf", &X2);
	
	
	if(fabs(X2-x2)<E){
		printf("Tacno \n");
	}	
	if(fabs(X2>x2)){
		printf("Vece \n");
	}	
	if(fabs(X2<x2)){
		printf("Manje \n");
	}	
	if(fabs(X2-x2)<0.1){
		printf("Priblizno manje \n");
	}	
	if(fabs(x2-X2)<0.1){
		printf("Priblizno vece \n");
	}
	}
	while (X2>x2 || X2<x2 || (X2-x2)<0.1 || (x2-X2)<0.1);
	return 0;
}
