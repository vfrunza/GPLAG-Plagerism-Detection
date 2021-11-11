#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

int main () {
	double a,b,c,x1,x2,D,R1,R2;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a,&b,&c);
	
    D= pow(b,2)-4*a*c;
	R1= (-b-sqrt(pow(b,2)-4*a*c))/(2.*a);
	R2= (-b+sqrt(pow(b,2)-4*a*c))/(2.*a);

	if(D<0){
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	else if(a<0 && b==0 && c>0){
		R1=-sqrt(c/-a);
		R2=sqrt(c/-a);
	}
	else if(a<0 && b==0 && c<0){
		R1=-sqrt(c/a);
		R2=sqrt(c/a);
	}
	
	while(x1=1){
	    printf("Unesite rjesenje x1: ");
	    scanf("%lf", &x1);
	
	if( (R1-EPSILON)<x1 && x1<(R1+EPSILON) ){
		printf("Tacno\n");
		break;
	   } 
	   else if( R1<x1 && x1<(R1+0.1) ){
	   	printf("Priblizno vece\n");
	   }
	   else if( (R1-0.1)<x1 && x1<R1 ){
	   	printf("Priblizno manje\n");
	   }
	   else if(x1>R1){
	   	printf("Vece\n");
	   }
	   else if(x1<R1){
	   	printf("Manje\n");
	   }
	
	}
	
	while(x2=1){
		printf("Unesite rjesenje x2: ");
		scanf("%lf", &x2);
		
		if( (R2-EPSILON)<x2 && x2<(R2+EPSILON) ){
			printf("Tacno\n");
		    break;
		}
		else if( R2<x2 && x2<(R2+0.1) ){
			printf("Priblizno vece\n");
		}
		else if( (R2-0.1)<x2 && x2<R2 ){
			printf("Priblizno manje\n");
		}
		else if(x2>R2){
			printf("Vece\n");
		}
		else if(x2<R2){
			printf("Manje\n");
		}
	}
	
	return 0;
}