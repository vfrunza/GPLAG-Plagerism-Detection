#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
#define CONST 0.1
int main()
{
	double a, b, c, x1, x2, xa, xb, t, D;
	printf( "\nUnesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a, &b, &c);
	D=b*b-4.0*a*c;
	
	if (D < 0) 
	{
		printf("Rjesenja su imaginarni brojevi. ");
	}
	else if(D >=  0)
	{ 
	do{	
		printf("Unesite rjesenje x1: ");
		scanf("%lf",&x1);
		t= sqrt(D);
		xa = (-b + t) / (2*a);
		xb = (-b - t) / (2*a);
		if (fabs(xa - x1) <= EPSILON)
		{ 
		 	printf("Tacno\n");
		    do{
		    	printf("Unesite rjesenje x2: ");
	        	scanf("%lf",&x2);
            	if (fabs(xb - x2) <= EPSILON)
            	{ 
            		printf("Tacno\n");
            	}
            	else if ( x2 < xb ){
    				if(fabs(x2-xb)<CONST && fabs(x2-xb)>EPSILON)
		    		{ 
		        		printf("Priblizno manje\n");
		    	    }	
        			else{
        				printf("Manje\n");
        			}
        		}
    		    else if( x2 > xb ){
    		    	if(fabs(x2-xb)<CONST && fabs(x2-xb)>EPSILON)
		    		{ 
		        		printf("Priblizno vece\n");
		    	    }	
        			else{
        				printf("Vece\n");
        			}
    		    }

        	}while(fabs(x2-xb)>EPSILON);
            
		}    
        else if ( x1 < xa ){
        	if(fabs(x1-xa)<CONST && fabs(x1-xa)>EPSILON)
		    		{ 
		        		printf("Priblizno manje\n");
		    	    }	
        			else{
        				printf("Manje\n");
        			}
        }
        else if( x1 > xa ){
          		if(fabs(x1-xa)<CONST && fabs(x1-xa)>EPSILON)
		    	{ 
		       		printf("Priblizno vece\n");
		   	    }	
       			else{
       				printf("Vece\n");
       			}
        	
        }
       
	}while(fabs(x1-xa)>EPSILON);    
	}
return 0;
}