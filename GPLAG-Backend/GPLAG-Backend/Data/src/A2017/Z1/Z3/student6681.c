#include <stdio.h>
#include <math.h>
#define E 0.001
int main()
{

	double x1, x2, a, b, c, X1, X2;
	double d;


	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b,&c);

	d=((b*b)-(4*a*c));
	x1=((-b+ sqrt(d))/(2*a));
	x2=((-b- sqrt(d))/(2*a));

	if(d<0) {
		printf("Rjesenja su imaginarni brojevi.");
	} else {
	
        for(;;){
        	
        	printf("Unesite rjesenje x1: ");
        	scanf("%lf", &X1);
        
		if(fabs(X1-x1)<E) {
			printf("Tacno\n");
			break;
		} 
		else{
			 if(X1<x1){
		
			 if((x1-X1)<0.1 && (x1-X1)>0)
			printf("Priblizno manje\n");
			else
			printf("Manje\n");
			 }
		else {
			
			 if((X1-x1)<0.1 && (X1-x1)>0 )
			printf("Priblizno vece\n");
			else
			printf("Vece\n");
			
		}
	
        }}
		
        for(;;){
        	printf("Unesite rjesenje x2: ");
        	scanf("%lf", &X2);
        	
		if(fabs(X2-x2)<E) {
			printf("Tacno\n");
			break;
		} 
		else{ 
			  if(X2<x2){
			
			 if((x2-X2)<0.1 && (x2-X2)>0)
			printf("Priblizno manje\n");
			else
			printf("Manje\n");
			 }
		else {
			
			 if((X2-x2)<0.1 && (X2-x2)>0 )
			printf("Priblizno vece\n");
			else
			printf("Vece\n");
			
		}}






	}}





	return 0;
}

