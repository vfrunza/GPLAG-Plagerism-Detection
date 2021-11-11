#include <stdio.h>
#include <math.h>

#define eps 0.001

int main() {
	double a,b,c;
	double D;
	double x1=0, x2=0;
	double unesenox1, unesenox2;
	double razlika;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	D= b*b - 4*a*c;
	if(D<0) 
	{
	    printf("Rjesenja su imaginarni brojevi.");
	    return 0;
	}
	x1 = (-b + sqrt(D))/(2*a);
	x2 = (-b - sqrt(D))/(2*a);
	
	do
	{
		printf("Unesite rjesenje x1: ");
		scanf("%lf", &unesenox1);
		razlika = x1 - unesenox1;
		if(razlika<0)
		{
			razlika*=-1;
			if(razlika<eps)
		    {
			  printf("Tacno\n");
		    }
		    else if(razlika<0.1)
		    {
			  printf("Priblizno vece\n");
		    }
		    else if(unesenox1>x1) 
		    {
		    	printf("Vece\n");
		    }
		    else {
		    	printf("Manje\n");
		    }

		} else {
				if(razlika<eps)
		    {
			  printf("Tacno\n");
		    }
		    else if(razlika<0.1)
		    {
			  printf("Priblizno manje\n");
		    }
		     else if(unesenox1<x1) 
		    {
		    	printf("Manje\n");
		    }
		    else {
		    	printf("Vece\n");
		    }
			
		}
	
		}while( razlika >= eps);
	
	
			do
	{
		printf("Unesite rjesenje x2: ");
		scanf("%lf", &unesenox2);
		razlika = x2 - unesenox2;
		if(razlika<0)
		{
			razlika*=-1;
			if(razlika<eps)
		    {
			  printf("Tacno\n");
		    }
		    else if(razlika<0.1)
		    {
			  printf("Priblizno vece\n");
		    }
		    else if(unesenox2>x2) 
		    {
		    	printf("Vece\n");
		    }
		    else {
		    	printf("Manje\n");
		    }

		} else {
				if(razlika<eps)
		    {
			  printf("Tacno\n");
		    }
		    else if(razlika<0.1)
		    {
			  printf("Priblizno manje\n");
		    }
		     else if(unesenox2<x2) 
		    {
		    	printf("Manje\n");
		    }
		    else {
		    	printf("Vece\n");
		    }
			
		}
	
		}while( razlika >= eps);
	
	return 0;
}
