#include <stdio.h>
#include <math.h>
#define T 0.001
#define G 0.1
#define E 0.00001

int main() {
	double a,b,c,x1,x2,d,pog1,pog2;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf%lf%lf",&a,&b,&c);
	d=b*b-4*a*c;
	if(d<0){
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	
	if(d==0) {
		x1=-b/(2*a);
		x2=-b/(2*a);
		while(1){
		printf("Unesite rjesenje x1: ");
		scanf("%lf",&pog1);
		if(fabs(pog1-x1)<T) {printf("Tacno\n"); break;}
		if((fabs(pog1-x1)<G && pog1>x1 && x1<0) || ( fabs(pog1-x1)<G && pog1>x1 && x1>=0) ) {printf("Priblizno vece\n"); continue;}
		if((fabs(pog1-x1)<G && pog1<x1 && x1<0) || (fabs(pog1-x1)<G && pog1<x1 && x1>=0)) {printf("Priblizno manje\n"); continue;}
		if(pog1<x1) printf("Manje\n");
		if(pog1>x1) printf("Vece\n");
		}
		while(1){
		printf("Unesite rjesenje x2: ");
		scanf("%lf",&pog2);
		if(fabs(pog2-x2)<T) {printf("Tacno\n"); break;}
		if((fabs(pog2-x2)<G && pog2>x2 && x2<0) || (fabs(pog2-x2)<G && pog2>x2 && x2>=0) ) {printf("Priblizno vece\n"); continue;}
		if((fabs(pog2-x2)<G && pog2<x2 && x2<0) || (fabs(pog2-x2)<G && pog2<x2 && x2>=0)) {printf("Priblizno manje\n"); continue;}
		if(pog2<x2) printf("Manje\n");
		if(pog2>x2) printf("Vece\n");
		}
		
	}
if(d>0){
		x1=(-b+sqrt(d))/(2*a);
		x2=(-b-sqrt(d))/(2*a);
		while(1){
		printf("Unesite rjesenje x1: ");
		scanf("%lf",&pog1);
		if(fabs(pog1-x1)<T) {printf("Tacno\n"); break;}
		if((fabs(pog1-x1)<G && pog1>x1 && x1<0) || ( fabs(pog1-x1)<G && pog1>x1 && x1>=0) ) {printf("Priblizno vece\n"); continue;}
		if((fabs(pog1-x1)<G && pog1<x1 && x1<0) || (fabs(pog1-x1)<G && pog1<x1 && x1>=0)) {printf("Priblizno manje\n"); continue;}
		if(pog1<x1) printf("Manje\n");
		if(pog1>x1) printf("Vece\n");
		}
		while(1){
		printf("Unesite rjesenje x2: ");
		scanf("%lf",&pog2);
		if(fabs(pog2-x2)<T) {printf("Tacno\n"); break;}
		if((fabs(pog2-x2)<G && pog2>x2 && x2<0) || (fabs(pog2-x2)<G && pog2>x2 && x2>=0) ) {printf("Priblizno vece\n"); continue;}
		if((fabs(pog2-x2)<G && pog2<x2 && x2<0) || (fabs(pog2-x2)<G && pog2<x2 && x2>=0)) {printf("Priblizno manje\n"); continue;}
		if(pog2<x2) printf("Manje\n");
		if(pog2>x2) printf("Vece\n");
		}
}
	

	return 0;
}
