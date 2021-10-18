#include <stdio.h>
#include <math.h>
#define eps 0.001
int main() {
	double  a, b, c, x1, x2, x11, D, x22, m, k;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	D=b*b-4.0*a*c;
	x11=(-b-sqrt(D))/(2*a);
	x22=(-b+sqrt(D))/(2*a);
	if(x11>x22){
	k=x22;
	m=x11;} else {
		k=x11;
		m=x22;
	}
	
	if(D<0){
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	} else if (D>=0) {
		do {printf("Unesite rjesenje x1: ");
		scanf("%lf", &x1);
		if(fabs(k-x1)<eps){
		printf("Tacno\n");}
		else {
		if(fabs(k-x1)<0.1 && x1<k){
		printf("Priblizno manje\n");}
		else if (x1<k){
		printf("Manje\n");}
		else if(fabs(k-x1)<0.1 && x1>k){
		printf("Priblizno vece\n");	}
		else if(x1>k){printf("Vece\n");}
		}} while(fabs(x1-k)>=eps);
		do{
		printf("Unesite rjesenje x2: ");
		scanf("%lf", &x2);
		if(fabs(m-x2)<eps){
		printf("Tacno\n");}
		else { if(fabs(m-x2)<0.1 && x2<m){
		printf("Priblizno manje\n");}
		else if(x2<m){printf("Manje\n");}
		else if(fabs(m-x2)<0.1 && x2>m){
		printf("Priblizno vece\n");}
		else if(x2>m){
		printf("Vece\n");}
		}}while(fabs(x2-m)>=eps);}
	return 0;
}
