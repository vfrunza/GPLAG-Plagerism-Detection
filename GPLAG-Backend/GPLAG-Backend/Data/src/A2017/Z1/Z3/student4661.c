#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

int main() {
	double a, b, c;
	double x1, x2; /*tacna rjesenja kvadratne jednacine*/
	double x1unos, x2unos; /*rjesenja koja korisnik unosi*/
	double d, t; /* d determinanta */
	
	do
	{
		printf("Unesite koeficijente a, b i c: ");
		scanf("%lf %lf %lf", &a, &b, &c);
	}while(fabs(a)<EPSILON);
	
	d=b*b-(4*a*c);
	x1=(-b+sqrt(d))/(2*a);
	x2=(-b-sqrt(d))/(2*a);
	
	if(x2<x1) /*x1  je manje rjesenje u ovom zadatku*/
	{
		t=x2;
		x2=x1;
		x1=t;
	}
	
	if(d<0)
	{
		printf("Rjesenja su imaginarni brojevi.\n");
		return 0;
	}
	
	do
	{
	  printf("Unesite rjesenje x1: ");
	  scanf("%lf", &x1unos);
	  
	  if(fabs(x1-x1unos)<EPSILON)
	  {
	  	printf("Tacno\n");
	
	  	do
	  	{
	    	printf("Unesite rjesenje x2: ");
	    	scanf("%lf", &x2unos);
	    
	    	if(fabs(x2-x2unos)<EPSILON)
	    	{
	    		printf("Tacno\n");
	    		return 0;
	    	}
	    	else if(fabs(x2unos-x2)<0.1 && x2unos>x2)
	    	{
	    		printf("Priblizno vece\n");
	    	}
	    	else if(fabs(x2unos-x2)<0.1 && x2unos<x2)
	    	{
	    		printf("Priblizno manje\n");
	    	}
	    	else if(x2unos>x2)
	    	{
	    		printf("Vece\n");
	    	}
	    	else
	    	{
	    		printf("Manje\n");
	    	}
	    
	  	}
	  	while(fabs(x2-x2unos)>=EPSILON);
	  }
	  
	  else if(fabs(x1unos-x1)<0.1 && x1unos>x1)
	  {
	  	printf("Priblizno vece\n");
	  }
	  
	  else if(fabs(x1-x1unos)<0.1 && x1unos<x2)
	  {
	  	printf("Priblizno manje\n");
	  }
	   
	  else if(x1unos>x1)
	  {
	   	printf("Vece\n");
	  }
	  
	  else
	  {
	  	printf("Manje\n");
	  }
	  
	}
	while(fabs(x1-x1unos)>=EPSILON);
	
	return 0;
}
