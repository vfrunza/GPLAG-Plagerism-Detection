#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
#define GRESKA 0.00001

int main() {
	double a, b, c, v, m, x1, x2, X1, X2, D, t;
	
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	
	
	D=b*b-4*a*c;
	
	if(D<0)
	{
		printf("Rjesenja su imaginarni brojevi.\n");
		return 0;
	} 
	else
	{
		t=sqrt(D);
		m=((-b-t)/(2*a));
		v=((-b+t)/(2*a));
		
		if((v-m)>=EPSILON)
		{
			x1=m;
			x2=v;
		} 
		else
		{
			x1=v;
			x2=m;
		}
		
		
		do{
			printf("Unesite rjesenje x1: ");
			scanf("%lf", &X1);
			
			if(fabs(X1-x1)<EPSILON)
			{
				printf("Tacno\n");
			} 
			else if(fabs(X1-x1)-0.1>=0 && X1-x1>=EPSILON)
			{
				printf("Vece\n");
			} 
			else if(fabs(X1-x1)-0.1>=0 && x1-X1>=EPSILON)
			{
				printf("Manje\n");
			} 
			else if(0.1-fabs(X1-x1)>EPSILON && fabs(X1-x1)>=EPSILON && X1-x1>=EPSILON)
			{
				printf("Priblizno vece\n");
			} 
			else if(0.1-fabs(X1-x1)>EPSILON && fabs(X1-x1)>=EPSILON && x1-X1>=EPSILON)
			{
				printf("Priblizno manje\n");
			}
			else if(0.1-fabs(X1-x1)<EPSILON && fabs(X1-x1)>=EPSILON && X1-x1>=EPSILON)
			{
				printf("Priblizno vece\n");
			} 
			else if(0.1-fabs(X1-x1)<EPSILON && fabs(X1-x1)>=EPSILON && x1-X1>=EPSILON)
			{
				printf("Priblizno manje\n");
			}
			
		} while(fabs(X1-x1)>=EPSILON);
		
			do{
			printf("Unesite rjesenje x2: ");
			scanf("%lf", &X2);
			
			if(fabs(X2-x2)<EPSILON)
			{
				printf("Tacno\n");
			} 
			else if(fabs(X2-x2)-0.1>=0 && X2-x2>=EPSILON)
			{
				printf("Vece\n");
			} 
			else if(fabs(X2-x2)-0.1>=0 && x2-X2>=EPSILON)
			{
				printf("Manje\n");
			} 
			else if(0.1-fabs(X2-x2)>EPSILON && fabs(X2-x2)>=EPSILON && X2-x2>=EPSILON)
			{
				printf("Priblizno vece\n");
			} 
			else if(0.1-fabs(X2-x2)>EPSILON && fabs(X2-x2)>=EPSILON && x2-X2>=EPSILON)
			{
				printf("Priblizno manje\n");
			}
			else if(0.1-fabs(X2-x2)<EPSILON && fabs(X2-x2)>=EPSILON && X2-x2>=EPSILON)
			{
				printf("Priblizno vece\n");
			} 
			else if(0.1-fabs(X2-x2)<EPSILON && fabs(X2-x2)>=EPSILON && x2-X2>=EPSILON)
			{
				printf("Priblizno manje\n");
			}
			
			
		} while(fabs(X2-x2)>=EPSILON);
		
		}
		return 0;
		
}
