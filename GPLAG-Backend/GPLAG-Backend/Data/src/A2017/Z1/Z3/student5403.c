#include <stdio.h>
#include <math.h>
#define EPSILON 0.001 


int main()
{
	int a,b,c;
	double delta,x1,x2,x2unos,x1unos,dif1, dif2;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%d %d %d",&a,&b,&c);
	if ( fabs(a-0)>EPSILON) {
	delta = b*b-4*a*c;
	if (delta < 0) {
	printf ("Rjesenja su imaginarni brojevi."); return 0; }
	else 
	{
		x1=(-b+sqrt(delta))/(2*a);
        	x2=(-b-sqrt(delta))/(2*a);
       
	
        	do { 
        		printf("Unesite rjesenje x1: ");
        	     scanf("%lf",&x1unos);
        	     
        	     dif1 = fabs(x1unos-x1);
        	     if(dif1 < EPSILON) {
        	     	printf("Tacno\n");
        	     }
        	     else {
        	     	if(x1unos > x1){
        	     		if(dif1 < 0.1){
	        	     		printf ("Priblizno vece\n");
	        	     	}
	        	     	else {
	        	     		printf ("Vece\n");
	        	     	}	
        	     		
        	     	}
        	     	else {
        	     		if(dif1 < 0.1){
	        	     	printf ("Priblizno manje\n");	
	        	     	}
	        	     	else {
	        	     	printf ("Manje\n");	
	        	     	}
        	     		
        	     	}
        	     }
        	     	
        	     }
        		
        	 while(dif1>=EPSILON);
        	 
        	 do { 
        		printf("\nUnesite rjesenje x2: ");
        	     scanf("%lf",&x2unos);
        	     
        	     dif2 = fabs(x2unos-x2);
        	     if(dif2 < EPSILON) {
        	     	printf("Tacno\n");
        	     }
        	     else {
        	     	if(x2unos > x2){
        	     		if(dif2 < 0.1){
	        	     		printf ("Priblizno vece\n");
	        	     	}
	        	     	else {
	        	     		printf ("Vece\n");
	        	     	}	
        	     		
        	     	}
        	     	else {
        	     		if(dif2 < 0.1){
	        	     	printf ("Priblizno manje\n");	
	        	     	}
	        	     	else {
	        	     	printf ("Manje\n");	
	        	     	}
        	     		
        	     	}
        	     }
        	     	
        	     }
        		
        	 while(dif2>=EPSILON);
        	
	}
        	
	}
	else
	{ printf ("Jednacina je linearna"); }

	
	return 0;
}

