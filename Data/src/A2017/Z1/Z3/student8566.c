#include <stdio.h>
#include<math.h>
#define EPSILON 0.001


int main() {
	double a,b,c;
	double p1=0;
	double p2=0;
	double x1=0;
	double x2=0;
	double D=0;
	
	
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	D=pow(b,2)-4.0*a*c;
	if(D<0){
	   printf("Rjesenja su imaginarni brojevi.");
		return 0; }
		
	
	   
	    p1= (-b + sqrt(pow(b,2) - 4.0 * a * c))/(2.*a);
        p2= (-b - sqrt(pow(b,2) - 4.0 * a * c))/(2.*a);
	    do 
	    {printf("Unesite rjesenje x1: ");
	    scanf("%lf", &x1);
	     if ((x1-p1>-0.1) && (x1-p1<=-EPSILON))
	    printf("Priblizno manje\n");
	    
	    else if((x1-p1<0.1) && (x1-p1>=EPSILON))
	    printf("Priblizno vece\n");
	  
	    
	    if(x1-p1>=0.1)
	    printf("Vece\n");
	    if (x1-p1<=-0.1)
	   printf("Manje\n");
	    }
	    while((fabs(x1-p1)>=EPSILON));
	    
	    if ((fabs(x1-p1)<EPSILON)){
	   printf("Tacno\n");}
	    
	     do 
	    {printf("Unesite rjesenje x2: ");
	    scanf("%lf", &x2);
	    if ((x2-p2<0.1) && (x2-p2>=EPSILON))
	    printf("Priblizno vece\n");
	    else if( (x2-p2>-0.1) && (x2-p2<=-EPSILON))
	    printf("Priblizno manje\n");
	    
	    if(x2-p2>=0.1)
	    printf("Vece\n");
	    if (x2-p2<=-0.1)
	   printf("Manje\n");
	    }
	    while((fabs(x2-p2)>=EPSILON));
	    
	    if ((fabs(x2-p2)<EPSILON)) {
	   printf("Tacno\n");}
	    
	    
	   
	    
	    
	   
	   
	   
	   
	   

	 
	 
	 
	
	     
	  
	  
	      
	       
	       
	       
	       
	return 0;
}
