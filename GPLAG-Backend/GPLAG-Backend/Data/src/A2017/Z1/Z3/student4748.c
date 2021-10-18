#include <stdio.h>
#include<math.h>
#define EPSILON 0.001

int main() 
{
	double a,b,c,x11,x22,D,x1,x2;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	if (a==0){
		printf ("Jednacina nije kvadratna!");
		return 0;
	}
		D=b*b-4*a*c;
		if(D<0)
		{
			printf("Rjesenja su imaginarni brojevi.");
			return 0;
		}

		x11=(-b+sqrt(D))/(2*a);
		x22=(-b-sqrt(D))/(2*a);
		
    do{
    	printf("Unesite rjesenje x1: ");
    	scanf("%lf",&x1);
    	if ((fabs(x11-x1))<EPSILON)
    	{ 
    		printf("Tacno\n"); 

    	}
    	
    	else if (fabs(x1-x11)<0.1 && (x11>x1))
    	  {
    	  	printf("Priblizno manje\n");
    	  }	
    	  	else if (fabs(x1-x11)<0.1 && (x11<x1))
    	  {
    	  	printf("Priblizno vece\n");
    	  }	
    	  	else if (x1<x11)
    	  	{
    	  		printf("Manje\n");
    	  	}
    	  	else if(x1>x11)
    	  	{
    	  		printf("Vece\n");
    	  	}
     } while((fabs(x11-x1))>=EPSILON);
     
   	 do {
    	printf("Unesite rjesenje x2: ");
    	scanf("%lf",&x2);
    	if (fabs(x22-x2)<EPSILON)
    	{
    		printf("Tacno\n");
    	}
    		else if (fabs(x2-x22)<0.1 && (x22>x2))
    	  {
    	  	printf("Priblizno manje\n");
    	  }	
    	  	else if (fabs(x2-x22)<0.1 && (x22<x2))
    	  {
    	  	printf("Priblizno vece\n");
    	  }	
    	  	else if (x2<x22)
    	  	{
    	  		printf("Manje\n");
    	  	}
    	  	else if(x2>x22)
    	  	{
    	  		printf("Vece\n");
    	  	}
        } while(fabs(x22-x2)>=EPSILON);
	
		return 0;
}
