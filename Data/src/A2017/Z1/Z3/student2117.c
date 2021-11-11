#include <stdio.h>
#include <math.h>
#define epsilon 0.001
int main() {
	int C;
	double a,b,c,x1,x2,D,rx1,rx2;
	
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	
	D = b*b - 4*a*c;
    x1 = (-b+sqrt(b*b - (4*a*c))/(2*a));
    x2 = (-b-sqrt(b*b - (4*a*c))/(2*a));
    if (D<0){
    	printf("Rjesenja su imaginarni brojevi.");
    }
     else {
        
     do {
          C=0;
     	printf("Unesite rjesenje x1: ");
     	scanf("%lf",&rx1);
     	if(fabs(rx1-x1)<epsilon){
     		printf("Tacno\n");
     		C=1;
     	} else if(rx1<x1){
     		if(x1-rx1<0.1){
     			printf("Priblizno manje\n");
     		}
     		else{
     			printf("Manje\n");
     		}
     	}
     	else if(rx1>x1){
     		
     		if(rx1-x1<0.1)
     		{printf("Priblizno vece\n");
     	}
     	else { printf("Vece\n");
     }}} while(C==0); 
       
     do {
     	C=0;
     	printf("Unesite rjesenje x2: ");
     	scanf("%lf",&rx2);
     	if(fabs(rx2-x2)<epsilon){
     		printf("Tacno\n");
     		C=1;
     	} else if(x2>rx2){
     		if(x2-rx2<0.1){
     			printf("Priblizno manje\n");
     		}
     		else{
     			printf("Manje\n");
     		}
     	}
     	else if(rx2>x2){
     	
     		if(rx2-x2<0.1)
     		{printf("Priblizno vece\n");
     	}
     	else { printf("Vece\n");
     }}} while(C==0);}
	return 0;
}
