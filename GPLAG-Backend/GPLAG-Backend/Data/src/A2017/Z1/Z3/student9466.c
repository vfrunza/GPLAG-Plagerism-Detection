#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

int main()

{
 double a, b, c, x1, x2, resenje1=0, resenje2=0;
 
 printf ("Unesite koeficijente a, b i c: ");
 scanf("%1f %1f %1f", &a, &b, &c);
 
 resenje1=(-b+sqrt(b*b-4*a*c))/(2*a);
 resenje2=(-b-sqrt(b*b-4*a*c))/(2*a);
 
 if((b*b-4*a*c)<0)
 printf("Rjesenja su imaginarni brojevi.");
 else
 {
 	do
 {
 	printf("Unesite rjesenje x1: ");
 	scanf("%1f", &x1);
 	
 	if (fabs (x1-resenje1)<0.1&&fabs (x1-resenje1)>=EPSILON&&x1>resenje1)
 	{ printf("Priblizno vece\n"); }
 	
 	else if (fabs (x1-resenje1)<0.1&&fabs (x1-resenje1)>=EPSILON&&x1<resenje1)
 	{ printf("Priblizno manje\n"); }
 	
 	else if (fabs (x1-resenje1)>0.1&&x1>resenje1)
 	{ printf("Vece\n"); }
 	
 	else if(fabs (x1-resenje1)>0.1&&x1<resenje1)
 	{ printf("Manje\n"); }
 	
 }
 
 	while (fabs(x1-resenje1)>=EPSILON);
 	
 	
 	{ printf("Tacno\n"); }
 	
 	do
 	
 	{
 		printf("Unesite rjesenje x2: ");
 		scanf("%1f", &x2);
 		
 		if (fabs (x2-resenje2)<0.1&&fabs (x2-resenje2)>=EPSILON&&x2>resenje2)
 		{ printf("Priblizno vece\n"); }
 		 else if (fabs(x2-resenje2)<0.1&&fabs (x2-resenje2)>=EPSILON&&x2<resenje2)
 		 { printf("Priblizno manje\n"); }
 		 
 		 else if (fabs (x2-resenje2)>=0.1&&x2>resenje2)
 		 { printf("Vece\n"); }
 		 
 		 else if (fabs (x2-resenje2)>=0.1&&x2<resenje2)
 		 { printf("Manje\n"); }
 	}
 		  
 		  
 		  while (fabs(x2-resenje2)>=EPSILON);
 		  
 		{ printf ("Tacno/n"); }
 		 }
 		 return 0;
 }
 		
 	
 	
 	
 	
 	
 

