#include <stdio.h>
#include <math.h>

int main() {
	
	float a, b, c; 
	float e1=0.001;
	float e2=0.1;
	float x1, x2, x1K, x2K, D, t;
	
	printf("Unesite koeficijente a, b i c: ");
	scanf("%f", &a);
	scanf("%f", &b);
	scanf("%f", &c);
	
	D =( b*b - 4.*a*c);
	t = sqrt(D);
	x1 = (-b + t)/(2*a);
	x2 =( -b - t)/(2*a);
	
	if(D<0){
		
		printf("Rjesenja su imaginarni brojevi.\n");
		return 0;
	}
	
	do{
		
		printf("Unesite rjesenje x1: ");
		scanf("%f", &x1K);
		
		if((fabs(x1K-x1)<e1)){
		
			printf("Tacno\n");
			break;
		
		}
		else if((x1-x1K<e2) && (x1-x1K>0)){
			
			printf("Priblizno manje\n");
			
		}
		else if((x1-x1K<0) && (x1-x1K>-e2)){
			
			printf("Priblizno vece\n");
			
		}else if(x1K>x1){
			
			printf("Vece\n");
			
		}else if(x1K<x1){
			
			printf("Manje\n");
		}
		
}while(1);
		
	do{	
		printf("Unesite rjesenje x2: ");
		scanf("%f", &x2K);
		
		if(fabs(x2K-x2)<e1){
		
		printf("Tacno\n");
		break;
		
		}else if((x2-x2K<0) && (x2-x2K>-e2)){
		
				printf("Priblizno vece\n");
		
		}else if((x2-x2K<e2) && (x2-x2K>0)){
				
				printf("Priblizno manje\n");
		
			
		}else if(x2K<x2){
		
		printf("Manje\n");
		
		}else if(x2K>x2){
		
		printf("Vece\n");
	
			
		}	
		
		
	}while(1);
	

		return 0;
}
