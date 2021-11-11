#include <stdio.h>
#define EPSILON 0.001
#include <math.h>
#define epsilon 0.1

int main() 

{    double a, b, c, d=0, i, j, x1,x2, y1=0, y2=0, r1=0, r2=0, r12=0 ;

      printf("Unesite koeficijente a, b i c: ");
      
       scanf ("%lf""%lf""%lf" , &a, &b, &c);
       
        d = (b*b) - (4*a*c);
     
        if (d>=0) 
          { 
               r1=(-b-sqrt(d))/(2.*a);
               r2=(-b+sqrt(d))/(2.*a);
               if (r1 > r2)
                   {
                       r12 = r2;
                       r2 = r1;
                       r1 = r12;
                   }
		            for (i=0; ; i++)
          	      {
          	         printf("Unesite rjesenje x1: ");
          	    	      scanf ("%lf", &x1);
          	    	        y1 = fabs (r1-x1);
          	    	
                         if ( y1 < EPSILON)  {printf("Tacno\n");break;}    	    	
          	    	          else if (  r1 > x1 ) { 
          	    	                              if ( y1 < epsilon ) printf("Priblizno manje\n"); 
          	    	                               else printf("Manje\n"); 
          	    	                            }   
          	    	             else if (   r1 < x1 ) 
          	    	                            { 
          	    	                              if ( y1 < epsilon ) printf("Priblizno vece\n"); 
          	    	                               else printf("Vece\n"); 
          	    	                             } 
          	    	          
          	      }
          
          	    
          	 for (j=0; ; j++)
          	    {
          	      printf("Unesite rjesenje x2: ");	
          	    	  scanf ("%lf", &x2);
          	    	    y2 = fabs (r2-x2);
          	    	      if  (y2 < EPSILON) {printf ("Tacno\n");break;}
          	    	        else if ( r2 > x2 ) { 
          	    	                              if ( y2 < epsilon ) printf("Priblizno manje\n"); 
          	    	                               else printf("Manje\n"); 
          	    	                            }   
          	    	         else if ( r2 < x2 ) 
          	    	                            { 
          	    	                              if ( y2 < epsilon ) printf("Priblizno vece\n"); 
          	    	                               else printf("Vece\n"); 
          	    	                             } 
          	    	          
          	    }    
          }
		 else printf ("Rjesenja su imaginarni brojevi.") ;
		 
	return 0;
}