#include <stdio.h>
#include <math.h>

#define E 0.001

int main() {
/*	printf("Zadaća 1, Zadatak 3");*/
	int t=0;
	double x1,x2,px1,px2,a,b,c;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	if(b*b-4*a*c<0)	printf("Rjesenja su imaginarni brojevi.\n");
	else{
		x1=(-b+sqrt(b*b-4*a*c))/(2*a);
		x2=(-b-sqrt(b*b-4*a*c))/(2*a);
		do{
			t=0;
			printf("Unesite rjesenje x1: ");
			scanf("%lf",&px1);
			if(fabs(px1-x1)<E){
				printf("Tacno\n");
				t=1;
			}
			else if(px1<x1){
				if(x1-px1<0.1) printf("Priblizno manje\n");
				else printf("Manje\n");
			}
			else if(x1<px1){
			 if(px1-x1<0.1) printf("Priblizno vece\n");
			 else printf("Vece\n");
			}
		} while(t==0);
		do{
			t=0;
			printf("Unesite rjesenje x2: ");
			scanf("%lf",&px2);
			if(fabs(x2-px2)<E){
				printf("Tacno\n");
				t=1;
			}
			else if(px2<x2){
				if(x2-px2<0.1) printf("Priblizno manje\n");
				else printf("Manje\n");
			}
			else if(x2<px2){
				if(px2-x2<0.1) printf("Priblizno vece\n");
				else printf("Vece\n");
			}
		} while(t==0);
	}	
	return 0;
}
