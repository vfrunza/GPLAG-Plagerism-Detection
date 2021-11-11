#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main() {
	
	double a,b,c,D,pom,x1,x2,y1,y2; 
	int k;
	k=0;
	
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	D=b*b-4*a*c; /*printf("%f", D);*/
	if(D<0) printf("Rjesenja su imaginarni brojevi.");
	else
	{
		x1=(-b+sqrt(D))/(2*a);        
		x2=(-b-sqrt(D))/(2*a);   
		/*printf("%f\n",x1);*/
		if(x1>x2) {pom=x1; x1=x2; x2=pom;}
		
		do
		{
			printf("Unesite rjesenje x1: ");
			scanf("%lf", &y1);
			if(fabs((y1-x1))<0.001) {printf("Tacno\n"); k=1;}  /* EPSILON=0.001 */
			else if((fabs(y1-x1)<0.10) && y1>x1) printf("Priblizno vece\n");
			else if((fabs(y1-x1)<0.10) && y1<x1) printf("Priblizno manje\n");
			else if(y1>x1) printf("Vece\n");
			else printf("Manje\n");
			 
		
		} while(k==0);
		
		k=0;
		do
		{
			printf("Unesite rjesenje x2: ");
			scanf("%lf", &y2);
			if(fabs(y2-x2)<0.001) {printf("Tacno\n"); k=1;}  /* EPSILON=0.001 */
			else if(fabs(y2-x2)<0.1 && y2>=x2) printf("Priblizno vece\n");
			else if(fabs(y2-x2)<0.1 && y2<=x2) printf("Priblizno manje\n");
			else if(y2>x2) printf("Vece\n");
			else printf("Manje\n");
		} while(k==0);
	}
	return 0;
}
