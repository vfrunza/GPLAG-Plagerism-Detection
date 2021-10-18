#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
int main() {
	
    double a,b,c,x1,x2,m,D,x=0;
    
    printf("Unesite koeficijente a, b i c: ");
    scanf("%lf %lf %lf",&a,&b,&c);
    
    D=b*b-4*a*c;
    
    x1=((-b)+sqrt(D))/(2*a);
    x2=((-b)-sqrt(D))/(2*a);
    
    if(D<0){
        printf("Rjesenja su imaginarni brojevi.");
    }
	if(D>=0){
	while(1){
	x++;
	   printf("Unesite rjesenje x1: ");
	   scanf(" %lf",&m);
	    if(fabs(m-x1)<EPSILON){
	        printf("Tacno\n");
	        break;
	    }
	   else if(fabs(m-x1)<0.1 && m<x1){
	       printf("Priblizno manje\n");
	   }
	   else if(fabs(m-x1)<0.1 && m>x1){
	       printf("Priblizno vece\n");
	   }
	   else if(m>x1){
	       printf("Vece\n");
	   }
	   else if(m<x1){
	       printf("Manje\n");
	   }     
	    }
	while(1){
	x++;
	   printf("Unesite rjesenje x2: ");
	   scanf(" %lf",&m);
	    if(fabs(m-x2)<EPSILON){
	        printf("Tacno\n");
	        break;
	    }
	   else if(fabs(m-x2)<0.1 && m<x2){
	       printf("Priblizno manje\n");
	   }
	   else if(fabs(m-x2)<0.1 && m>x2){
	       printf("Priblizno vece\n");
	   }
	   else if(m>x2){
	       printf("Vece\n");
	   }
	   else if(m<x2){
	       printf("Manje\n");
	   }     
	    }
	    
	    
	    
	    
	    
	    
	    
	}	
		
		
		
		
		
		
		
		
		
		
	return 0;
}
