#include <stdio.h>
#include <math.h>
#define E 0.001

int main() {
	double a, b, c, x1, x2, D, input;
	printf ("Unesite koeficijente a, b i c: ");
	scanf ("%lf %lf %lf", &a, &b, &c);
	D=b*b-4*a*c;
	x1=(-b+sqrt(D))/(2*a);
	x2=(-b-sqrt(D))/(2*a);
	if (D<0){
		printf ("Rjesenja su imaginarni brojevi.\n");
		return 1;
	}
    do{
    	printf ("Unesite rjesenje x1: ");
    	scanf ("%lf", &input);
    	if(x1>(input-E) && x1<(input+E)){
    		printf ("Tacno\n");
    		break;
    	}
    	else if(fabs(input-x1)<0.1 && input<x1){
    		printf("Priblizno manje\n");
    	}
    	else if (fabs(input-x1)<0.1 && input>x1){
    		printf ("Priblizno vece\n");
    	}
    	else if(input<x1){
    		printf ("Manje\n");
    	}
    	else if(input>x1){
    		printf("Vece\n");
    	}
    }while (input<=(x1-E) || input>=(x1-E));
    
    do{
    	printf ("Unesite rjesenje x2: ");
    	scanf ("%lf", &input);
    	if(x2>(input-E) && x2<(input+E)){
    		printf ("Tacno\n");
    		break;
    	}
    	else if(fabs(input-x2)<0.1 && input<x2){
    		printf("Priblizno manje\n");
    	}
    	else if (fabs(input-x2)<0.1 && input>x2){
    		printf ("Priblizno vece\n");
    	}
    	else if(input<x2){
    		printf ("Manje\n");
    	}
    	else if(input>x2){
    		printf("Vece\n");
    	}
    }while (input<=(x2-E) || input>=(x2-E));
    return 0;
}
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
	
	
	
	
	
	
