#include<stdio.h>
#include<math.h>
#define epsilon 0.001
int main(){
	double a,b,c,D,x1,x2,x11 = 32000,x22 = 32000;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a,&b,&c);
    D = b * b - 4 * a * c;
	if(D < 0){printf("Rjesenja su imaginarni brojevi.");goto kraj;}
	else{
		x1 = (-b + sqrt(D)) / (2 * a);
		x2 = (-b - sqrt(D)) / (2 * a);
		while(fabs(x11 - x1) >= epsilon){
			printf("Unesite rjesenje x1: ");
			scanf("%lf", &x11);
			if(fabs(x11 - x1) < epsilon)break;
		    if(fabs(x11 - x1) < 0.1 && x11 > x1)printf("Priblizno vece\n");
			else if(fabs(x11 - x1) < 0.1 && x11 < x1)printf("Priblizno manje\n"); 
			else if(x11 - x1 > epsilon)printf("Vece\n");
			else if(x11 - x1 < epsilon)printf("Manje\n");
		}
		printf("Tacno\n");
		while(fabs(x22 - x2) > epsilon){
			printf("Unesite rjesenje x2: ");
			scanf("%lf", &x22);
			if(fabs(x22 - x2) < epsilon)break;
			if(fabs(x22 - x2) < 0.1 && x22 > x2 && fabs(x22 - x2) > epsilon)printf("Priblizno vece\n");
			else if(fabs(x22 - x2) < 0.1 && x22 < x2)printf("Priblizno manje\n"); 
			else if(x22 - x2 > epsilon)printf("Vece\n");
			else if(x22 - x2 < epsilon)printf("Manje\n");
		}
		printf("Tacno\n");
	}
	kraj:return 0;
}