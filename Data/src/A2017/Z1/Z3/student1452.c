#include <stdio.h>
#include <math.h>
#define e 0.001
int main() {
	double a,b,c,D,K,x1,x2,p,q,x3;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a,&b,&c);
	D=pow(b,2)-4*a*c;
	if(D<0) printf("Rjesenja su imaginarni brojevi. \n");
	else {
		K=sqrt(D);
		x1=(-b+K)/(2*a);
		x2=(-b-K)/(2*a);
if(x2<x1){
	x3=x1;
	x1=x2;
	x2=x3;
}
		do {
			printf("Unesite rjesenje x1: ");
			scanf("%lf",&p);
			if((p-x1)<0.1 && (p-x1)>=e) printf("Priblizno vece \n");
			else if((x1-p)<0.1 && (x1-p)>=e) printf("Priblizno manje \n");
			else if((p-x1)>=0.1) printf("Vece \n");
			else if((x1-p)>=0.1) printf("Manje \n");
		} while(fabs(p-x1)>=e);
		printf("Tacno \n");
		do {
			printf("Unesite rjesenje x2: ");
			scanf("%lf",&q);
			if((q-x2)<0.1 && (q-x2)>=e) printf("Priblizno vece \n");
			else if((x2-q)<0.1 && (x2-q)>=e) printf("Priblizno manje \n");
			else if((q-x2)>=0.1) printf("Vece \n");
			else if((x2-q)>=0.1) printf("Manje \n");
		} while(fabs(q-x2)>=e);
		printf("Tacno \n");
		
		
	}
	return 0;
}
