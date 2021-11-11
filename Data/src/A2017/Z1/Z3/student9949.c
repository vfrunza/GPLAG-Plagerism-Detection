#include <stdio.h>
#define e 0.001
#define k 0.1
#include <math.h>

int main() {
	double a,b,c,x1,x2,y1,y2,D;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a,&b,&c);
	
	D=b*b-4.00*a*c;
	if(D<0){
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	
	x1=(-b+sqrt(D))/(2*a);
	x2=(-b-sqrt(D))/(2*a);
	
	
	/*Prvo rjesenje y1*/
	do{
		printf("Unesite rjesenje x1: ");
		scanf("%lf", &y1);
		
		if(fabs(y1-x1)<e){
			printf("Tacno\n");
			break;
		}
		if(y1>x1){
			if(fabs(y1-x1)<k){
				printf("Priblizno vece\n");
		    } else {
		    	printf("Vece\n");
		    }
		} else if(y1<x1){
			if(fabs(y1-x1)<k){
				printf("Priblizno manje\n");
			} else {
				printf("Manje\n");
			}
		}
	} while(fabs(y1-x1)>=e);
	
	
	/*Drugo rjesenje y2*/
	do{
		printf("Unesite rjesenje x2: ");
	    scanf("%lf", &y2);
	   	
	   	if(fabs(y2-x2)<e){
	   		printf("Tacno");
	   		return 0;
	   	}
	    if(y2>x2){
	        if(fabs(y2-x2)<k){
	    		printf("Priblizno vece\n");
	    	} else {
	    		printf("Vece\n");
	    	}
	    } else if(y2<x2){
	    	if(fabs(y2-x2)<k){
	    		printf("Priblizno manje\n");
	    	} else {
	    		printf("Manje\n");
	    	}
	    }
	} while(fabs(y2-x2)>e);
	
	if(fabs(y2-x2)<e){
		printf("Tacno");
	}
	return 0;
}
