#include <stdio.h>
#define EPSILON 0.001
#include <math.h>

int main() {
	 double a,b,c,x1,x2,R1,R2,D, pom;
	 
	 printf("Unesite koeficijente a, b i c: ");
	 scanf(" %lf %lf %lf",&a,&b,&c);
	 
	 D=b*b-4*a*c;
	 R1=(-b-sqrt(D))/(2*a);
	 R2=(-b+sqrt(D))/(2*a);
	 
	 if(R2<R1) {
	 	pom=R2;
	 	R2=R1;
	 	R1=pom;
	 }
	 
	 if(D<0){
	  printf("Rjesenja su imaginarni brojevi.");
	 
	 return 0;
	 }
	 
	 do {
	 	printf("Unesite rjesenje x1: ");
	 	scanf("%lf",&x1);
	 	
	 	if(fabs(x1-R1)<EPSILON){
	 		printf("Tacno\n");
	 		break;
	 	}
	 	
	 	if(x1<R1){
	 		if(fabs(x1-R1)<0.1) printf("Priblizno manje\n");
	 		else printf("Manje\n");
	 	}
	 		
	    else if(x1>R1){
	    	if(fabs(x1-R1)<0.1) printf("Priblizno vece\n");
	   		else printf("Vece\n");
	    }
	   
	 }
	 
	 while(fabs(x1-R1)>0.0001);
	 
	 do {
	 	printf("Unesite rjesenje x2: ");
	 	scanf("%lf",&x2);
	 	
	 	if(fabs(x2-R2)<EPSILON){
	 		printf("Tacno\n");
	 		break;
	 	}
	 	
	 	if(x2<R2) {
	 		if(fabs(x2-R2)<0.1) printf("Priblizno manje\n");
	 		else printf("Manje\n");
	 	}
	 	
	 	else if(x2>R2){
	 	 if(fabs(x2-R2)<0.1) printf("Priblizno vece\n");
	 	 else printf("Vece\n");
	 	}
	    
	 }
	 	while(fabs(x2-R2)>0.0001);
	 	
	 	
	 
	 
	 

	return 0;
}
