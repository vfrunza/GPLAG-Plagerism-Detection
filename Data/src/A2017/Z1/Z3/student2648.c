#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
#define EPSILON1 0.1

int main() {
	double a,b,c,x1,x2,diskriminanta,x11,x22;
	printf("Unesite koeficijente a, b i c: "); 
	scanf("%lf %lf %lf", &a, &b, &c);
	
	
	diskriminanta=b*b-4*a*c;
	if(a<0){
	x22=(-b-sqrt(diskriminanta))/ (2*a);
	x11=(-b+sqrt(diskriminanta))/ (2*a); 
	}
	else{
		x11=(-b-sqrt(diskriminanta))/ (2*a);
		x22=(-b+sqrt(diskriminanta))/ (2*a); 
	}
	if (diskriminanta<0)
	{printf("Rjesenja su imaginarni brojevi.");}
	
	
	else
	     {  do  
              {printf("Unesite rjesenje x1: ");
	          scanf("%lf", &x1);
	          
	          if(fabs(x1-x11)<EPSILON)
	            {printf("Tacno\n"); }
	         else if((x1<x11) && (fabs(x1-x11)>=EPSILON1))
	            {printf("Manje\n");}
	          else if ((x1>x11) && (fabs(x1-x11)>=EPSILON1))
	          {printf("Vece\n");}
	          
	          else if ((x1<x11) && (fabs(x1-x11)<EPSILON1))
	           {printf("Priblizno manje\n");}
	           else if((x1>x11) && (fabs(x1-x11)<EPSILON1))
	           { printf("Priblizno vece\n");}
	            }
	       while(fabs(x1-x11)>=EPSILON) ;   
	    
	           
	          do 
	             { printf("Unesite rjesenje x2: ");
	               scanf("%lf", &x2);
	           if(fabs(x2-x22)<EPSILON)
	            {printf("Tacno\n");
	            	
	            }
	         else if((x2<x22) && (fabs(x2-x22)>=EPSILON1))
	            {printf("Manje\n");}
	          else if((x2>x22) && (fabs(x2-x22)>= EPSILON1))
	          {printf("Vece\n");}
	          
	          else if((x2>x22) && (fabs(x2-x22)<EPSILON1))
	           {printf("Priblizno vece\n");}
	           else if ((x2<x22) && (fabs(x2-x22)<EPSILON1))
	           { printf("Priblizno manje\n");}
	           } 
	       while(fabs(x2-x22)>=EPSILON);
	       
	          }
	     
	          
	     
	return 0;
}
