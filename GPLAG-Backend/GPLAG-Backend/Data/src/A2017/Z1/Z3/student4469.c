#include <stdio.h>
#include <math.h>
#define epsilon 0.001
int main() {
		double a, b, c, x1, x2, x3, a1;
		do{
		printf("Unesite koeficijente a, b i c: ");
		scanf("%lf %lf %lf", &a, &b, &c);	
			
		}
		while (a==0); 
			
	
	/*da li su rjesenja imaginarni brojevi*/
	if((b*b)-(4.*a*c)<0){
	printf("Rjesenja su imaginarni brojevi.");
	return 1;
	}	
	x1=((b*(-1.)-(sqrt((b*b)-(4.*a*c))))/(2.*a));
	x2=((-b+(sqrt (b*b-4.*a*c)))/(2.*a));
	if(x2<x1){
		x3=x1;
		x1=x2;
		x2=x3;
	}
	do{
		printf("Unesite rjesenje x1: ");
		scanf("%lf", &a1);
				
			if(fabs(a1-x1)<epsilon){
				printf("Tacno");
			break;
			}
			else if(a1<x1)
			{
			 if((x1-a1)<0.1)
				printf("Priblizno manje");else
				printf("Manje");
			}
			else if (a1>x1)
			{
				
			 if ((a1-x1)<0.1)
				printf("Priblizno vece");else
				printf("Vece");
			}
				printf("\n");
	}	
	while(1==1);
						printf("\n");
	do{
		printf("Unesite rjesenje x2: ");
		scanf("%lf", &a1);
				
			if(fabs(a1-x2)<epsilon){
				printf("Tacno");
			break;
			}
				else if(a1<x2)
			{
			 if((x2-a1)<0.1)
				printf("Priblizno manje");else
				printf("Manje");
			}
			else if (a1>x2)
			{
				
			 if ((a1-x2)<0.1)
				printf("Priblizno vece");else
				printf("Vece");
			}
				printf("\n");
	}	
	while(1==1);
	
	
	
	return 0;
	
	
}
