#include <stdio.h>
#include <math.h>

int main() {
	
	double a,b,c;
	double D;
	double x1,x2,x11,x22;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf%lf%lf",&a,&b,&c);
	D=(b*b-4*a*c);
	
if(D<0) {
	printf("Rjesenja su imaginarni brojevi.");
	return 0;
}

x2=(-b+sqrt(D))/2*a;
x1=(-b-sqrt(D))/2*a;

do{
	printf("Unesite rjesenje x1: ");
	scanf("%lf",&x11);
	if(fabs(x1-x11)<0.001) printf("Tacno\n");
	else if(fabs(x1-x11)<0.1) printf("Priblizno manje\n");
   else if(fabs(x11-x1)<0.1) printf("Priblizno vece\n");
	else if(x11>x1 && fabs(x1-x11)>0.001 && fabs (x1-x11)>0.1) printf("Vece\n");
	else printf("Manje\n");
	
}
	while(fabs(x1-x11)>0.001);
	
	
	do{
	printf("Unesite rjesenje x2: ");
	scanf("%lf",&x22);
	if(fabs(x2-x22)<0.001) printf("Tacno\n");
	else if(fabs(x2-x22)<0.1) printf("Priblizno manje\n");
	else if(fabs(x22-x2)<0.1) printf("Priblizno vece\n");
	else if(x22>x2 && fabs(x2-x22)>0.001 && fabs (x2-x22)>0.1) printf("Vece\n");
	else printf("Manje\n");
	
	}
	while(fabs(x2-x22)>0.001);
	
	
	return 0;
	
	}