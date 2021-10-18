#include <stdio.h>
#define EPS 0.0001
#include <math.h>

int main() {
	int a,b,c;
	double x1,x2,D,x,y,t;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%d %d %d",&a,&b,&c);
	D=b*b-4.0*a*c;
	t=sqrt(D);
	if(D<0) { 
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	
	/* trazenje rjesenja x1 i x2 */
	
		x1=(-b+t)/(2*a);
		x2=(-b-t)/(2*a);
	
		do {
	printf("Unesite rjesenje x1: ");
		scanf("%lf",&x);
	    
	  if(fabs(x-x1)<EPS) {
	  	printf("Tacno\n");
	  	break;
	  }  
	  
	  else if(x<x1 && fabs(x-x1)>=0.1) printf("Manje\n");
	  else if(x>x1 && fabs(x-x1)>0.1) printf("Vece\n");
	  else if(x>x1 && (x-x1)<0.1) printf("Priblizno vece\n");
	  else if(x<x1  && (x1-x)<0.1) printf("Priblizno manje\n");
	    
	
	} while(fabs(x-x1)>=EPS);
	
		do {
	printf("Unesite rjesenje x2: ");
		scanf("%lf",&y);
	    
	   if(fabs(y-x2)<EPS) {
	  	printf("Tacno\n");
	  	return 0;
	  }  
	  
	  else if(y<x2 && fabs(y-x2)>=0) printf("Manje\n");
	  else if(y>x2 && fabs(y-x2)>0.1) printf("Vece\n");
	  else if(y>x1 && (y-x2)<0.1) printf("Priblizno vece\n");
	  else if(y<x2  && (x2-y)<0.1) printf("Priblizno manje\n");
	    
		
		
		
	} while(fabs(y-x2)>=EPS);
	
	
	return 0;
}
