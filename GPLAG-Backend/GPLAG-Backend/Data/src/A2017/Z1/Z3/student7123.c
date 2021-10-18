#include <stdio.h>
#include <math.h>
#define e 0.001
#define e1 0.00000000000000001

int main() {
	double a,b,c,x1,x2,x1u,x2u,x;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf%lf%lf", &a, &b, &c);
	if(pow(b,2)-4*a*c>=0){
		x1=(-b-sqrt(pow(b,2)-4*a*c))/(2*a);
		x2=(-b+sqrt(pow(b,2)-4*a*c))/(2*a);
		if(x2<x1){
			x=x1;
			x1=x2;
			x2=x;
		}
		do{
			printf("Unesite rjesenje x1: ");
			scanf("%lf", &x1u);
			if(x1u<x1+0.1-e1 && x1u>=x1+e){
				printf("Priblizno vece\n");
			}
			else if(x1u>=x1-0.1+e1 && x1u<=x1-e){
				printf("Priblizno manje\n");
			}
			else if(x1u>=x1+0.1-e1){
				printf("Vece\n");
			}
			else if(x1u<=x1-0.1+e1){
				printf("Manje\n");
			}
			
		}while(x1u>=x1+e || x1u<=x1-e);
		printf("Tacno\n");
		do{
			printf("Unesite rjesenje x2: ");
			scanf("%lf", &x2u);
			if(x2u<x2+0.1-e1 && x2u>=x2+e){
				printf("Priblizno vece\n");
			}
			else if(x2u>=x2-0.1+e1 && x2u<=x2-e){
				printf("Priblizno manje\n");
			}
			else if(x2u>=x2+0.1-e1){
				printf("Vece\n");
			}
			else if(x2u<=x2-0.1+e1){
				printf("Manje\n");
			}
			
		}while(x2u>=x2+e || x2u<=x2-e);
		printf("Tacno\n");
	}
	else{
		printf("Rjesenja su imaginarni brojevi.");
	}
	return 0;
}
