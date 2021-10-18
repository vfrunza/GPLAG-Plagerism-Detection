#include <stdio.h>
#include <math.h>

int main() {
    double a,b,c,tacno_x1,tacno_x2,uneseno_x1,uneseno_x2,t,D;

    
   printf("Unesite koeficijente a, b i c: ");
   scanf("%lf %lf %lf",&a,&b,&c);
   
   D=b*b-(4*a*c);
   
   if(D>0) 
   {
       t=sqrt(D);
       tacno_x1=(-b+t)/(2*a);
       tacno_x2=(-b-t)/(2*a);
   }

   else if (fabs(D-0)<0.001)
   {
	tacno_x1=-b/(2*a);
	tacno_x2=-b/(2*a);
   }
   
   else 
   {
       t=sqrt(-D);
       printf("Rjesenja su imaginarni brojevi.");
       return 0;
       
   }
	
	 do{
	    
        printf("Unesite rjesenje x1: ");
        scanf("%lf",&uneseno_x1);
        if(fabs(uneseno_x1-tacno_x1)<0.001) printf("Tacno\n");
        else if(uneseno_x1<tacno_x1) 
        {
            if(tacno_x1-uneseno_x1<0.1) printf("Priblizno manje\n");
           else printf("Manje\n");
            
        }
        else if(uneseno_x1>tacno_x1)
        {
            if(uneseno_x1-tacno_x1<0.1) printf("Priblizno vece\n");
            else printf("Vece\n");}
        
        else   {
            printf("Tacno\n");
            
        }
        
	 
	 }
	 while(fabs(uneseno_x1-tacno_x1)>=0.001);
        
        
        
        
    do{
	    
        printf("Unesite rjesenje x2: ");
        scanf("%lf",&uneseno_x2);
        if(fabs(uneseno_x2-tacno_x2)<0.001) printf("Tacno\n");
        else if(uneseno_x2<tacno_x2) 
        {
            if(fabs(uneseno_x2-tacno_x2)<0.1) printf("Priblizno manje\n");
           else printf("Manje\n");
            
        }
        else if(uneseno_x2>tacno_x2)
        {
            if(uneseno_x2-tacno_x2<0.1) printf("Priblizno vece\n");
            else printf("Vece\n");}
        
        else  
        {
            printf("Tacno\n");
            
        }
        
	 
	 }
	 while(fabs(uneseno_x2-tacno_x2)>=0.001);
        
        
	
	
	
	
	
	
return 0;
}
