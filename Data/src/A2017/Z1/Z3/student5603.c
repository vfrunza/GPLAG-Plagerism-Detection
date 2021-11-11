#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define eps 0.001
#define eps2 0.1

int main() {
	int a, b, c;
	float D,x1,x2; 
	double unos=0;
		printf("Unesite koeficijente a, b i c: ");
		scanf("%d %d %d",&a,&b,&c);
	
	if (a==0){
		return 0;	
	}
	
	D=b*b-4*a*c;
     	
	if(D<0)	{
		printf("Rjesenja su imaginarni brojevi.\n");
 		return 1;
	} else if (D==0){
		x1=x2= -b/2*a;
	}else if (D>0){
		x1=(-b + sqrt(D))/a*2;
		x2=(-b - sqrt(D))/a*2;
	}
	
	do {
		printf("Unesite rjesenje x1: ");
		scanf("%lf",&unos);
		
		if (fabs(unos-x1)<eps){
			printf("Tacno\n");
		}else if (fabs(unos-x1)<eps2 && unos >x1){
			printf("Priblizno vece\n");
		}else if (fabs(unos-x1)<eps2 && unos <x1){
			printf("Priblizno manje\n");
		}else if (fabs(unos-x1)>eps2 && unos >x1){
			printf("Vece\n");
		}else if (fabs(unos-x1)>eps2 && unos <x1){
			printf("Manje\n");
		}
	}while(fabs(unos-x1)>eps);
	
	do{
		printf("Unesite rjesenje x2: ");
		scanf("%lf",&unos);
	
		if (fabs(unos-x2)<eps){
			printf("Tacno\n");
		}else if (fabs(unos-x2)<eps2 && unos >x2){
			printf("Priblizno vece\n");
		}else if (fabs(unos-x2)<eps2 && unos <x2){
			printf("Priblizno manje\n");
		}else if (fabs(unos-x2)>eps2 && unos >x2){
			printf("Vece\n");
		}else if (fabs(unos-x2)>eps2 && unos <x2){
			printf("Manje\n");
		}
	} while (fabs(unos-x2)>eps);
	return 0;
}
