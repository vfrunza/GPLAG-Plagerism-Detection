#include <stdio.h>
#include <math.h>
#define eps 0.0001

int main() {
	float a,b,c,x1,x2,D,r1,r2;
	printf("Unesite koeficijente a, b i c:");
	scanf("%f %f %f", &a, &b, &c);
	
	
	D=b*b-4*a*c;
	if(D<0){
		printf("Rjesenja su imaginarni brojevi. ");
		return 0;
		
	}
	if(a>=0 && (b>=0 || b<=0)){
	x1=(-b+sqrt(D)/(2*a));
	x2=(-b-sqrt(D)/(2*a));
	
	}
	if(a<=0 && (b<=0 || b>=0)){
		x1=(-b+sqrt(D)/(2*a));
		x2=(-b+sqrt(D)/(2*a));
	}
	do {
		printf("Unesite rjesenje x1: ");
		scanf("%f",&r1);
		if(fabs(r1-x1)<=eps){
			break;
		}
		if(fabs(r1-x1)<=0.1 && r1<x1){
			printf("Priblizno manje\n");
		}else {
			if(r1<x1){
		printf("Manje\n");}
	if(fabs(r1-x1)<=0.1 && r1>x1){
		printf("Priblizno vece\n");
	}else{
		if(r1>x1){
		 printf("Vece\n");
	}
	
}while (r1!=x1);
		printf("Tacno\n");
		
   do{
	    printf("Unesite rjesenje x2: ");
		scanf("%f", &r2);
		if(fabs(r2-x2)<=eps){
			break;
		}
		if(fabs(r2-x2)<=0.1 && r2<x2){
	    printf("Priblizno manje\n");}
		else{
			if(r2<x2){
		printf("Manje\n");
	if(fabs(r2-x2)<=0.1 && r2>x2){
    printf("Priblizno vece\n");
	}else{
		if(r2>x2){
    printf("Vece\n");
	}while (r2!=x2);
	printf("Tacno");

	return 0;
}