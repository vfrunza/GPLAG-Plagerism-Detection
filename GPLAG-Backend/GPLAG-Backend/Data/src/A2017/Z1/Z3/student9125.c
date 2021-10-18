#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
int main() {
	double a=0,b=0,c=0;
	double D, x1, x2, unosX1, unosX2,privremena;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
 D= b*b-4.0*a*c;
 if (D < 0)
 {
 	printf("Rjesenja su imaginarni brojevi.");
 	
 }
 else 
 {
 	 x1= (-b -sqrt(D))/(2.0 * a);
 	 x2=(-b+sqrt(D))/(2.0 * a);
 	 if(x1>x2)
 	 {
 	  
 	  privremena = x1;
    x1 = x2;
    x2 = privremena;
 	 
 	 }
 
 	while(1)
 	{
 		 printf("Unesite rjesenje x1: ");
 		 scanf("%lf", &unosX1);
 		 
 		 if (fabs(unosX1 - x1)<EPSILON)
 		 {
 		 	printf("Tacno\n");
 		 	break;
 		 }
 		 else if (unosX1-x1>0)
 		 {
 		 	if (unosX1-x1>=0.1)
 		 	{
 		 		printf("Vece\n");
 		 }
 		 else
 		 {
 		 	printf("Priblizno vece\n");
 		 }
 	 	}
 	else if (unosX1-x1 < 0)
 	{
 		if (unosX1-x1<=-0.1)
 		{
 			printf("Manje\n");
 		}
 		else
 		{
 			printf("Priblizno manje\n");
 		}
 	}
 	}
 	
 	
 	
 	while(1)
 	{
 		printf("Unesite rjesenje x2: ");
 		scanf("%lf", &unosX2);
 		
 		if (fabs(unosX2-x2)<EPSILON)
 		{
 			printf ("Tacno");
 			break;
 			
 		}
 		else if (unosX2-x2 >0)
 		{
 			if (unosX2-x2 >= 0.1)
 			{
 				printf("Vece\n");
 		}
 		else
 		{
 			printf("Priblizno vece\n");
 		}
 		}
 		else if (unosX2-x2 <0)
 		{
 			if (unosX2-x2 <= -0.1)
 			{
 				printf("Manje\n");
 			}
 			else
 			{
 				printf("Priblizno manje\n");
 			}
 		}
 			}
 }
 return 0;
}
 	
 	
 