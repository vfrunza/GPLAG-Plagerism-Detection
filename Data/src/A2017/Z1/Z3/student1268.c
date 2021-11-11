#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

int main() {
	double a,b,c, D, x1, x2, x11, x22;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	if(fabs(a-0)<EPSILON) printf("Jednacina je linearna.");
	else{
	D=b*b-4*a*c;
	if (D<0) printf("Rjesenja su imaginarni brojevi.");
	else if(D>=0 && a>0) {
		x1=(-b-sqrt(D))/(2*a);
	    x2=(-b+sqrt(D))/(2*a);
		do{
			printf("Unesite rjesenje x1: ");
			scanf("%lf", &x11);
			if(fabs(x11-x1)<EPSILON || (fabs(x11-x1)<0)){ 
				printf("Tacno\n"); 
				break;
		}
		else if(x11>x1){
			if(fabs(x11-x1)<0.1) printf("Priblizno vece\n");
	        else printf("Vece\n"); }
		else if(x11<x1) {
			if(fabs(x11-x1)<0.1) printf("Priblizno manje\n");
			else printf("Manje\n");}}
		while(fabs(x1-x11)>0);
		do {
			printf("Unesite rjesenje x2: ");
			scanf("%lf", &x22);
			if(fabs(x22-x2)<EPSILON || fabs(x22-x2)<0){ 
				printf("Tacno\n"); 
				break;
		}
		else if(x22>x2){
			if(fabs(x22-x2)<0.1) printf("Priblizno vece\n");
	        else printf("Vece\n"); }
		else if(x22<x2) {
			if(fabs(x22-x2)<0.1) printf("Priblizno manje\n");
			else printf("Manje\n");}}
		while(fabs(x2-x22)>0);
			
		}
		else if(D>=0 && a<0){
			x1=(-b+sqrt(D))/(2*a);
	    x2=(-b-sqrt(D))/(2*a);
		do{
			printf("Unesite rjesenje x1: ");
			scanf("%lf", &x11);
			if(fabs(x11-x1)<EPSILON || fabs(x11-x1)<0){ 
				printf("Tacno\n"); 
				break;
		}
		else if(x11>x1){
			if(fabs(x11-x1)<0.1) printf("Priblizno vece\n");
	        else printf("Vece\n"); }
		else if(x11<x1) {
			if(fabs(x11-x1)<0.1) printf("Priblizno manje\n");
			else printf("Manje\n");}}
		while(fabs(x1-x11)>0);
		do {
			printf("Unesite rjesenje x2: ");
			scanf("%lf", &x22);
			if(fabs(x22-x2)<EPSILON || fabs(x22-x2)<0){ 
				printf("Tacno\n"); 
				break;
		}
		else if(x22>x2){
			if(fabs(x22-x2)<0.1) printf("Priblizno vece\n");
	        else printf("Vece\n"); }
		else if(x22<x2) {
			if(fabs(x22-x2)<0.1) printf("Priblizno manje\n");
			else printf("Manje\n");}}
		while(fabs(x2-x22)>0);
			
		}
			
		}
	return 0;
}
