#include <stdio.h>
#include <math.h>

#define eps 0.001

int main() {
	double a, b, c, x1, x2, pokusaj, D;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	D = b*b - 4*a*c; 
	if(D < 0) printf("Rjesenja su imaginarni brojevi.");
	else{
		if(a < 0){
			x1 = (-b + sqrt(D)) / (2*a);
			x2 = (-b - sqrt(D)) / (2*a);
		}
		else{
			x1 = (-b - sqrt(D)) / (2*a);
			x2 = (-b + sqrt(D)) / (2*a);
		}
		
		do{
			printf("Unesite rjesenje x1: ");
			scanf("%lf", &pokusaj);
			if(pokusaj - x1 >= 0.1) printf("Vece\n");
			else if(x1 - pokusaj >= 0.1) printf("Manje\n");
			else if(pokusaj - x1 < 0.1 && pokusaj - x1 >= eps) printf("Priblizno vece\n");
			else if(x1 - pokusaj < 0.1 && x1 - pokusaj >= eps) printf("Priblizno manje\n");
			else printf("Tacno\n");
		}while(fabs(pokusaj - x1) >= eps);
		
		do{
			printf("Unesite rjesenje x2: ");
			scanf("%lf", &pokusaj);
			if(pokusaj - x2 >= 0.1) printf("Vece\n");
			else if(x2 - pokusaj >= 0.1) printf("Manje\n");
			else if(pokusaj - x2 < 0.1 && pokusaj - x2 >= eps) printf("Priblizno vece\n");
			else if(x2 - pokusaj < 0.1 && x2 - pokusaj >= eps) printf("Priblizno manje\n");
			else printf("Tacno\n");
		}while(fabs(pokusaj - x2) >= eps);
	}
	return 0;
}
