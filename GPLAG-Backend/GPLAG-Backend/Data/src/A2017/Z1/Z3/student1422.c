#include <stdio.h>
#include <math.h>
#define e 0.001

int main() {
	double a, b, c, d, t, r1, r2, x1, x2;
	int i;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	/*Izracunavanje diskriminante i tacnih rjesenja(r1 i r2) za unesene koeficijente a, b i c*/
	d=(b*b-(4.00*a*c));
	t=sqrt(d);
	r1=(-b-t)/(2.00*a);
	r2=(-b+t)/(2.00*a);
	
	if (a<0){	
	r1=(-b+t)/(2.00*a);
	r2=(-b-t)/(2.00*a);
	
}
	if(d<0){	
	printf("Rjesenja su imaginarni brojevi.");
	return 0;
}
	
		
	for(i=0;;i++){
	printf("Unesite rjesenje x1: ");
	scanf("%lf", &x1);
	if(fabs(r1-x1)<e) {
	printf("Tacno\n");
	break;
	}
		else if(x1>r1){
		if (fabs(r1-x1)<0.1){
		printf("Priblizno vece\n");}
		else if(fabs(r1-x1)>=0.1){
		printf("Vece\n");}
	}
		else if(x1<r1){
		if (fabs(r1-x1)<0.1){
		printf("Priblizno manje\n");}
		else if(fabs(r1-x1)>=0.1){
		printf("Manje\n");}
	}
}
		
	for(i=0;;i++){
	printf("Unesite rjesenje x2: ");
	scanf("%lf", &x2);
	if(fabs(r2-x2)<e) {
	printf("Tacno\n");
	break;
	}
		else if(x2>r2){
		if (fabs(r2-x2)<0.1){
		printf("Priblizno vece\n");}
		else if(fabs(r2-x2)>=0.1){
		printf("Vece\n");}
	}
		else if(x2<r2){
		if (fabs(r2-x2)<0.1){
		printf("Priblizno manje\n");}
		else if(fabs(r2-x2)>=0.1){
		printf("Manje\n");}
	}


}
	return 0;
}
