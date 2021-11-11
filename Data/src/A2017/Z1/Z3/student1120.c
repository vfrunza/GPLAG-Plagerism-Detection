#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

int main() {
	double a,b,c,diskriminanta,rj1,rj2,pom,x1,x2;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	diskriminanta=b*b-4*a*c;
	if(diskriminanta<0) {printf("Rjesenja su imaginarni brojevi.");
						return 0;}
		pom=sqrt(diskriminanta);
		rj1=(-b+pom)/(2*a);
		rj2=(-b-pom)/(2*a);
		do{
			printf("Unesite rjesenje x1: ");
			scanf("%lf", &x1);
			if(fabs(x1-rj1)<EPSILON) {printf("Tacno\n"); break;}
			else if((x1+EPSILON)<rj1) printf("Manje\n");
			else if((x1+EPSILON)>rj1) printf("Vece\n");
			else if((fabs(x1-rj1))>=0.1*(fabs(x1)+fabs(rj1)))printf("Priblizno vece\n");
			else if((fabs(x1-rj1))<=0.1*(fabs(x1)+fabs(rj1))) printf("Priblizno manje\n");
		}while(fabs(x1-rj1)>EPSILON);
		
		do{
			printf("Unesite rjesenje x2: ");
			scanf("%lf", &x2);
			if(fabs(x2-rj2)<EPSILON) {printf("Tacno\n"); break;}
				else if((x2+EPSILON)<rj2) printf("Manje\n");
			else if((x2+EPSILON)>rj2) printf("Vece\n");
			else if((fabs(x2-rj2))>=0.1*(fabs(x2)+fabs(rj2))) printf("Priblizno vece\n");
			else if((fabs(x2-rj2))<=0.1*(fabs(x2)+fabs(rj2))) printf("Priblizno manje\n");
		
	
			
		
		
			
		
			
		}while(fabs(x2-rj2)>EPSILON);
		
	
	
	
	return 0;
}
