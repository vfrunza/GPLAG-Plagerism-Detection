#include <stdio.h>
#include <math.h>
#define e 0.001

int main() {
	double a, b, c, x1, x2, D, j=0, k=0, temp;
	
	printf("Unesite koeficjente a, b i c: ");
	scanf("%lf, %lf, %lf", &a, &b, &c);
	
	D = pow(b,2) - (4 * a *c);
	
	if(D < 0) 
	printf("Rjesenja su imaginarni brojevi.\n");
	
	else if(D > 0){
		x1 = (-b - sqrt(D))/(2 * a);
		x2 = (-b + sqrt(D))/(2 * a);
		
	if(x1 > x2){
		temp = x1;
		x1 = x2;
		x2 = temp;
	}
	
	do{
		printf("Unesite rjesenje x1: ");
		scanf("%lf", &j);
		
		if(fabs(j - x1) < e)
		printf("Tacno\n");
		
		else if (fabs(j - x1) < 0.1 && j < x1)
		printf("Priblizno manje\n");
		
		else if (fabs(j - x1) <0.1 && j > x1)
		printf("Priblizno vece\n");
		
		else if (j > x1)
		printf("Vece\n");
		
		else if (j < x1)
		printf("Manje\n");
			}
			
			while(fabs(j - x1) >= e);
			
			do{
				printf("Unesite rjesenje x2: ");
				scanf("%lf", &k);
				
				if(fabs(k - x2) < e)
				printf("Tacno\n");
				
				else if(fabs(k - x2) < 0.1 && k < x2)
				printf("Priblizno manje\n");
				
				else if(fabs(k - x2) < 0.1 && k > x2)
				printf("Priblizno vece\n");
				
				else if(k > x2)
				printf("Vece\n");
				
				else if(k < x2)
				printf("Manje\n");
			}
			while (fabs(k - x2) >= e); 
	}
	return 0;
}
