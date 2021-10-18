#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
int main() {
	double a,b,c,x1,x2,xp1,xp2,D,a1,a2;
    printf("Unesite koeficijente a, b i c: ");
    scanf("%lf %lf %lf",&a,&b,&c);
    D=b*b-4*a*c;
    a1=(-b-sqrt(D))/(2*a);
    a2=(-b+sqrt(D))/(2*a);
    if(a1<=a2)
    {
        x1=a1;
        x2=a2;
    }
    else if(a1>a2)
    {
        x1=a2;
        x2=a1;
    }
    if(D<0)
    printf("Rjesenja su imaginarni brojevi.");
    else
    { 

        do
        {
    	printf("Unesite rjesenje x1: ");
    	scanf("%lf",&xp1);
        if(fabs(x1-xp1)<EPSILON)
        {
      	printf("Tacno\n");
    	break;
        }
    	else if((fabs(xp1-x1)<0.1)&&(x1<xp1)&&(fabs(xp1-x1)>=EPSILON))
    	     printf("Priblizno vece\n");
     	else if(x1<xp1&&(fabs(xp1-x1)>=0.1)&&fabs(x1-xp1)>EPSILON)
    	  	 printf("Vece\n");
    	else if(x1>xp1&&(fabs(xp1-x1)>=0.1)&&fabs(x1-xp1)>EPSILON)
             printf("Manje\n");
    	else if((fabs(x1-xp1)<0.1)&&(xp1<x1)&&(fabs(x1-xp1)>=EPSILON))
   	         printf("Priblizno manje\n");
        } while(1);
    
        do
    	{
    	printf("Unesite rjesenje x2: ");
    	scanf("%lf",&xp2);
    	 if(fabs(x2-xp2)<EPSILON)
    	 {
    	 printf("Tacno\n");
    	 break;
    	 }
       	else if((fabs(xp2-x2)<0.1)&&(xp2<x2)&&(fabs(xp2-x2)>=EPSILON))
       		 	 printf("Priblizno manje\n");
     	else if(x2<xp2&&(fabs(xp2-x2)>=0.1)&&fabs(x2-xp2)>EPSILON)
     		 printf("Vece\n");
    	else if(x2>xp2&&(fabs(xp2-x2)>=0.1)&&fabs(x2-xp2)>EPSILON)
        	 printf("Manje\n");
    	else if((fabs(x2-xp2)<0.1)&&(xp2>x2)&&(fabs(x2-xp2)>=EPSILON))
          	     printf("Priblizno vece\n");
    	}
    	while(1);

    }
	return 0;
}
