#include <stdio.h>
#include <math.h>
#define e 0.001 
int main(){
	
	float a, b, c, x, x1, x2, X, D;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%f %f %f", &a, &b, &c);
	D=b*b-4*a*c;
	if(D<0){
	printf("Rjesenja su imaginarni brojevi.");
		return 1;
	}
	if(a>=0 && (b>=0 || b<=0)){
		x2=((-b+sqrt(D))/(2*a));
		x1=((-b-sqrt(D))/(2*a));
	}

	if(a<=0 && (b<=0 || b>=0)){
		x2=((-b-sqrt(D))/(2*a));
		x1=((-b+sqrt(D))/(2*a));
	}

	do{
		printf("Unesite rjesenje x1: ");
		scanf("%f", &x);
		if(fabs(x-x1)<=e){
			break;
		}
		if(fabs(x1-x)<0.1 && x<x1){
		printf("Priblizno manje\n");}
		else {
			if(x<x1)
		printf("Manje\n");}
		if(fabs(x-x1)<0.1 && x>x1){
		printf("Priblizno vece\n");}
		else{ 
			if(x>x1)
		printf("Vece\n");
		}} while(fabs(x-x1)>e);
	printf("Tacno\n");
		
	do{
		printf("Unesite rjesenje x2: ");
		scanf("%f", &X);
		if(fabs(X-x2)<=e){
			break;
		}
		if(fabs(X-x2)<0.1 && X<x2){
		printf("Priblizno manje\n");}
		else {
			if(X<x2)
		printf("Manje\n");}
		if(fabs(X-x2)<0.1 && X>x2){
		printf("Priblizno vece\n");}
		else{ 
			if(X>x2)
		printf("Vece\n");
		}} while(fabs(X-x2)>e);
	printf("Tacno");
		return 0;
}