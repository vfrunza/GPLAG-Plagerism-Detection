#include <stdio.h>
#include <math.h>
#define E 0.001

int main() {
	double a,b,c,D,r,x1,x2,x1r,x2r;
	
	printf ("Unesite koeficijente a, b i c: ");
	scanf ("%lf%lf%lf", &a,&b,&c);
	D=b*b-4*a*c;
	r= sqrt (D);
   x1=(-b+r)/(2*a);
   x2=(-b-r)/(2*a);
   
  if ( D < 0) {
		printf ("Rjesenja su imaginarni brojevi.");
		return 0; }
	
	do {
	
	printf ("Unesite rjesenje x1: ");
    scanf ("%lf", &x1r);
    
        if (fabs(x1r-(x1)) >= E)
        printf ("Tacno");
        else if (x1r<x1) 
   	 	printf ("Manje\n");   
   	 	else if (x1r>x1) 
   	 	printf ("Vece\n");
   	 	else if(fabs(x1r-(x1)) < 0.1)
   	 	printf ("Priblizno manje \n");
   	 	else if(fabs(x1r-(x1)) > 0.1)
   	 	printf ("Priblizno vece\n");
    
 } while (fabs(x1r-x1) >= E); 
 
 do { 
     
     printf ("Unesite rjesenje x2: ");
    scanf ("%lf", &x2r);
    
    if (x2r<x2) 
   	 	printf ("Manje\n");   
   	 	else if (x2r>x2) 
   	 	printf ("Vece\n");
   	 	else if(fabs(x2r-x2) < 0.1)
   	 	printf ("Priblizno manje");
   	 	else if(fabs(x2r-x2) > 0.1)
   	 	printf ("Priblizno vece");
   	 	
   	 	 } while (fabs(x2r-x2) >= E); 
   
   return 0; }