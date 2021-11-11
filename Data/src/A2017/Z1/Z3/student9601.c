#include <stdio.h>
#include <math.h>
#define E 0.001
int main() {
	double a,b,c,D,x1,x2,unosx1,unosx2,pom;
	do
	{
	 printf("Unesite koeficijente a, b i c: ");
	 scanf("%lf %lf %lf",&a,&b,&c);
	}while(fabs(a-0)<E);
	D=b*b-4.0*a*c;
	if(D<0) 
	{
	 printf("Rjesenja su imaginarni brojevi.");
	 return 1;
	}
	else if(D>=0) 
	{
	 x1=((-b+(sqrt(D)))/(2*a));
	 x2=((-b-(sqrt(D)))/(2*a));
	 if(x1>x2)
	 {
	  pom=x1;
	  x1=x2;
	  x2=pom;
	 }
      do
      {
	   printf("Unesite rjesenje x1: ");
	   scanf("%lf",&unosx1);
	   if(fabs(unosx1-x1)<E) printf("Tacno\n");
	   else if(fabs(unosx1-x1)<0.1 && unosx1<x1) printf("Priblizno manje\n");
	   else if(fabs(unosx1-x1)<0.1 && unosx1>x1) printf("Priblizno vece\n");
	   else if(unosx1<x1) printf("Manje\n");
	   else if(unosx1>x1) printf("Vece\n");
      }while(fabs(unosx1-x1)>=E);
      do
      {
	   printf("Unesite rjesenje x2: ");
	   scanf("%lf",&unosx2);
	   if(fabs(unosx2-x2)<E) printf("Tacno\n");
	   else if(fabs(unosx2-x2)<0.1 && unosx2<x2) printf("Priblizno manje\n");
	   else if(fabs(unosx2-x2)<0.1 && unosx2>x2) printf("Priblizno vece\n");
	   else if(unosx2<x2) printf("Manje\n");
	   else if(unosx2>x2) printf("Vece\n");
      }while(fabs(unosx2-x2)>=E);
	}
	return 0;
}
