#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
int main() {
	double x1,x2,y1,y2,a,b,c,temp;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	if((b*b-4*a*c) < 0 || fabs(a-0)<EPSILON){
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	x1=((-b-sqrt(b*b-4*a*c))/(2*a));
	x2=((-b+sqrt(b*b-4*a*c))/(2*a));
	if(x1>x2)
	{
		temp=x1;
		x1=x2;
		x2=temp;
	}
	do {
	printf("Unesite rjesenje x1: ");
	scanf("%lf",&y1);
	if(fabs(x1-y1)<EPSILON){  break;}		
	if(y1>x1){
		if(y1-x1<0.1) printf("Priblizno vece\n");
		else printf("Vece\n");
		
	}
	else if(y1<x1){
		if(x1-y1<0.1) printf("Priblizno manje\n");
		else printf("Manje\n");
	}
	}while(1);
	if ((y1-x1)<EPSILON){ 
		printf("Tacno\n");
		do{
			printf("Unesite rjesenje x2: ");
			scanf("%lf",&y2);
			if(fabs(x2-y2)<EPSILON){
				printf("Tacno\n");
				break;
			}		
			if(y2>x2){
				if(y2-x2<0.1) printf("Priblizno vece\n");
				else printf("Vece\n");
				
			}
			else if(y2<x2){
				if(x2-y2<0.1) printf("Priblizno manje\n");
				else printf("Manje\n");
			}
		}while(1);
	}
  return 0;
}
