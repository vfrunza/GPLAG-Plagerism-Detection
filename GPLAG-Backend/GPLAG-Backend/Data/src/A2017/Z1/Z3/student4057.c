#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main() {
	double a,b,c,x1,x2,pom,xx1,xx2;
	double epsilon=0.001;
	
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a,&b,&c);
	if((b*b-4*a*c)<0)
	{
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	else
	{
		x1=(-b+sqrt(b*b-4*a*c))/(2*a);
		x2=(-b-sqrt(b*b-4*a*c))/(2*a);
		if(x1>x2)
		{
			pom=x1;
			x1=x2;
			x2=pom;
		}
		
		do
		{
			printf("Unesite rjesenje x1: ");
			scanf("%lf",&xx1);
			if((xx1-x1<0.1)&&(xx1-x1>=0.001))
			printf("Priblizno vece\n");
			else if((x1-xx1<0.1)&&(x1-xx1>=0.001))
			printf("Priblizno manje\n");
			else if(xx1-x1>=0.1)
			printf("Vece\n");
			else if(x1-xx1>=0.1)
			printf("Manje\n");
			else
			{printf("Tacno\n");
			break;}
//printf("%g",xx1-x1);
		
		}
		while (fabs(xx1-x1)>epsilon) ;
		do
		{
				printf("Unesite rjesenje x2: ");
			scanf("%lf",&xx2);
			if((xx2-x2<0.1)&&(xx2-x2>=0.001))
			printf("Priblizno vece\n");
			else if((x2-xx2<0.1)&&(x2-xx2>=0.001))
			printf("Priblizno manje\n");
			else if(xx2-x2>=0.1)
			printf("Vece\n");
			else if(x2-xx2>=0.1)
			printf("Manje\n");
			else
			{printf("Tacno\n");/*((xx1!=x1+epsilon)||(xx1!=x1-epsilon))||(xx1!=x1)*/
			break;}
			
		}
		while(fabs(xx2-x1)>epsilon); /*((xx2!=x2+epsilon)||(xx2!=x2-epsilon)||(xx2!=x2))*/ 
		
		
	}
	return 0;
}
