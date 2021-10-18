#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
#define E 0.1

int main() {
	
	double a, b, c, x1, x2, x1_, x2_, t, D;
	
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	
	D=b*b-4.0*a*c;
	
	
	if(D<0)
	{
		printf("Rjesenja su imaginarni brojevi.");
		
	}
	else
	
	if(a>0)
	{
		t=sqrt(D);
		x1 = (-b - t)/(2*a);
		x2 = (-b + t)/(2*a);
		
		do {
		    
		    printf("Unesite rjesenje x1: ");
		    scanf("%lf", &x1_);
		    
		    if (fabs(x1_-x1)<EPSILON)
		    printf("Tacno\n");
		    
		    else if(fabs(x1_-x1)<0.1 && x1_<x1)
		    printf("Priblizno manje\n");
		    
		    else if(fabs(x1_-x1)<0.1 && x1_>x1)
		    printf("Priblizno vece\n");
		    
		    else if(x1_<x1)
		    printf("Manje\n");
		    
		    else if(x1_>x1)
		    printf("Vece\n"); }
	  
	   while(fabs(x1_-x1)>=EPSILON);
	   
	  		do {

		    printf("Unesite rjesenje x2: ");
		    scanf("%lf", &x2_);
		    
		    if (fabs(x2_-x2)<EPSILON)
		    printf("Tacno\n");
		    
		    else if(fabs(x2_-x2)<0.1 && x2_<x2)
		    printf("Priblizno manje\n");
		    
		    else if(fabs(x2_-x2)<0.1 && x2_>x2)
		    printf("Priblizno vece\n");
		    
		    else if(x2_<x2)
		    printf("Manje\n");
		    
		    else if(x2_>x2)
		    printf("Vece\n"); }
	  
	   while(fabs(x2_-x2)>=EPSILON);
	}
	
	if(a<0)
{
			t=sqrt(D);
			x1 = (-b + t)/(2*a);
		    x2 = (-b - t)/(2*a);
			
	   		do {
		    
		    printf("Unesite rjesenje x1: ");
		    scanf("%lf", &x1_);
		    
		    if (fabs(x1_-x1)<EPSILON)
		    printf("Tacno\n");
		    
		    else if(fabs(x1_-x1)<0.1 && x1_<x1)
		    printf("Priblizno manje\n");
		    
		    else if(fabs(x1_-x1)<0.1 && x1_>x1)
		    printf("Priblizno vece\n");
		    
		    else if(x1_<x1)
		    printf("Manje\n");
		    
		    else if(x1_>x1)
		    printf("Vece\n"); }
	  
	   while(fabs(x1_-x1)>=EPSILON);
	   
	   do {
			
		    printf("Unesite rjesenje x2: ");
		    scanf("%lf", &x2_);
		    
		    if (fabs(x2_-x2)<EPSILON)
		    printf("Tacno\n");
		    
		    else if(fabs(x2_-x2)<0.1 && x2_<x2)
		    printf("Priblizno manje\n");
		    
		    else if(fabs(x2_-x2)<0.1 && x2_>x2)
		    printf("Priblizno vece\n");
		    
		    else if(x2_<x2)
		    printf("Manje\n");
		    
		    else if(x2_>x2)
		    printf("Vece\n"); }
	  
	  while(fabs(x2_-x2)>=EPSILON); 
	
}

	return 0;
}		       
		       
		       
		       
		       
		       
		       
		       
		       
		       