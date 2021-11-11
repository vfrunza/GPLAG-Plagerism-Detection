#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
int main() {
	double a, b, c, x1, x2, res1=0, res2=0;
	float D, t;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%1f %1f %1f", &a, &b, &c);
	
	D=b*b-4*a*c;
	t=sqrt(D);
	res1=(-b+t)/(2*a);
	res2=(-b-t)/(2*a);
	if(D<0){
	printf("Rjesenja su imaginarni brojevi.");
	}
	
	else{
		do{
			printf("Unesite rjesenje x1: ");
			scanf("%1f",&x1);
			if(fabs (x1-res1)<0.1 && fabs (x1-res1)>= EPSILON && x1>res1){
				printf("Priblizno vece\n");
				
			}
			else if(fabs(x1-res1)<0.1 && fabs(x1-res1)>=EPSILON && x1<res1){
				printf("Priblizno manje\n");
			}
			else if(fabs(x1-res1)>=0.1 && x1>res1){
				printf("Vece\n");
			}
			else if(fabs(x1-res1)>=0.1 && x1<res1){
				printf("Manje\n");
			}
		}
			while(fabs(x1-res1)>=EPSILON);
			{
				printf("Tacno\n");
			
		}
		do{
			printf("Unesite rjesenje x2: ");
			scanf("%1f",&x2);
			if(fabs(x2-res2)<0.1 && fabs(x2-res2)>=EPSILON && x2>res2){
				printf("Priblizno vece\n");
			}
			else if(fabs(x2-res2)<0.1 && fabs(x2-res2)>=EPSILON && x2<res2){
				printf("Priblizno manje\n");
			}
			else if(fabs(x2-res2)>=0.1 && x2>res2){
				printf("Vece\n");
			}
			else if(fabs(x2-res2)>=0.1 && x2<res2){
				printf("Manje\n");
			}
		}
			while(fabs(x2-res2)>=EPSILON);{
				printf("Tacno\n");}
			}
		return 0;
	
	
}
	
