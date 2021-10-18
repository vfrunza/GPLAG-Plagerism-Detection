#include <stdio.h>
#include <math.h>
#define EPSILON 0.001 
int main() {
	int a=0,b=0,c=0;
	double D=0,r1=0,r2=0,p1=0,p2=0;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%d %d %d",&a,&b,&c);
	D=b*b-4*a*c;
		if(D<0) {
			printf("Rjesenja su imaginarni brojevi.");
			return 1;
		}
		else {
		r1=(-b+sqrt(D))/(2*a);
		r2=(-b-sqrt(D))/(2*a);
		}
		do{
		printf("Unesite rjesenje x1: ");
		scanf("%lf",&p1);
		if(fabs(p1-r1)<EPSILON)
		printf("Tacno\n");
		else {
			if(p1>r1){
			if(fabs(p1-r1)<0.1)
			printf("Priblizno vece\n");
			else
				printf ("Vece\n");
			}else{
			if(fabs(p1-r1)<0.1)
			printf("Priblizno manje\n");
			else 
			printf("Manje\n");
			}
		}
		}
			while(fabs(p1-r1)>=EPSILON);
			do{
		printf("Unesite rjesenje x2: ");
		scanf("%lf",&p2);
		if(fabs(p2-r2)<EPSILON)
		printf("Tacno\n");
		else {
			if(p2>r2){
			if(fabs(p2-r2)<0.1)
			printf("Priblizno vece\n");
			else
				printf ("Vece\n");
			}else{
			if(fabs(p2-r2)<0.1)
			printf("Priblizno manje\n");
			else 
			printf("Manje\n");
			}
		}
		}
			while(fabs(p2-r2)>=EPSILON);
			return 0;
}