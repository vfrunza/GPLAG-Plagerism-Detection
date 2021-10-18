#include <stdio.h>
#define epsilon 0.001

int main() {
	
	double a, b, c, x1, x2, D, x;
	
	
	do {
	printf("Unesite koeficijente a, b i c: ");
	scanf("%f %f %f", &a,&b,&c);
	} while (D=b*b-4*a*c);
	
     	if(D<0) 
     	{
	    printf("Rjesenja su imaginarni brojevi.",a,b,c);
        {
       
           
        printf("Unesite rjesenje x1: ");
        scanf("%f", &x1);
        
        if ((x1-x))<=epsilon) {
        	printf("Tacno: ");
        }
        else if(x<x1) {
        	printf("Manje\n");
        }
        else {
        	printf("Vece\n");
        }
	
	return 0;
}
