#include<stdio.h>
#include<math.h>
#define EPSILON 0.001
int main() {
double a,b,c,x1,D,t,x2,X1,X2;
int brojac; brojac=0;
printf("Unesite koeficijente a, b i c: ");
scanf("%lf  %lf  %lf",&a,&b,&c);	
D=b*b-4*a*c;

if(D<0)
{
 printf("Rjesenja su imaginarni brojevi.");
 
}
else if(D>=0)
 {
  
  
  t=sqrt(D);
 x1=(-b+t)/(2*a);
 x2=(-b-t)/(2*a);
 
n:
printf("Unesite rjesenje x1: ");
scanf("%lf",&X1);



if (fabs(X1-x1)<EPSILON)
{

printf("Tacno\n");
brojac=1;
}

else if (fabs(X1-x1)<0.1 && X1<x1)
{

printf("Priblizno manje\n");
}


else if(fabs(X1-x1)<0.1 && X1>x1)
{
printf("Priblizno vece\n");
}

else if (X1<x1){

printf("Manje\n");
}
else 
{
printf("Vece");
printf("\n");
}
if(brojac!=1) goto n;

brojac=0;

b:
printf("Unesite rjesenje x2: ");
scanf("%lf",&X2);
if (fabs(X2-x2)<EPSILON)
{
//printf("\n");
printf("Tacno\n");
brojac=1;
}

else if (fabs(X2-x2)<0.1 && X2<x2)
{
//printf("\n");
printf("Priblizno manje\n");
}


else if(fabs(X2-x2)<0.1 && X2>x2)
{
printf("Priblizno vece\n");
}

else if (X2<x2){
//printf("\n");
printf("Manje\n");
}
else 
{
printf("Vece");
printf("\n");
}
if(brojac==0) goto b;

}


return 0;
}

