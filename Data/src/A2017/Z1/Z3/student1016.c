#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

int main() {
	double x1,x2,a,b,c,R1,R2,Determinanta,brojac=0,brojac2=0;
	printf("Unesite koeficijente a, b i c: ");
	scanf ("%lf %lf %lf",&a,&b,&c);
	Determinanta=b*b-4*a*c;
	 if (Determinanta>0){
	     R1=(-b+sqrt(Determinanta))/(2*a);
	     R2=(-b-sqrt(Determinanta))/(2*a);}
	 if (Determinanta==0){
	 	R1=-b/(2*a);
	 	R2=-b/(2*a);
	 }
	 if (Determinanta<0){printf ("Rjesenja su imaginarni brojevi.");return 0;}
	  do {
	  	printf ("Unesite rjesenje x1:");
	  	scanf ("%lf",&x1);
        if (R1<x1 && fabs(R1-x1)>=0.1){printf (" Vece\n");}
	  	if (R1>x1 && fabs(x1-R1)>=0.1){printf (" Manje\n");}
	  	if (fabs(R1-x1)<EPSILON ){printf (" Tacno\n");brojac=1;}
	  	if ((R1-x1)<0.1 && (R1-x1)>EPSILON){printf (" Priblizno manje\n");}
	  	if ((x1-R1)<0.1 && (x1-R1)>=EPSILON ){printf (" Priblizno vece\n");}}
	  	while(R1!=x1 && brojac==0);
	  	do {
	  	printf ("Unesite rjesenje x2:");
	  	scanf ("%lf",&x2);
     if (R2<x2 && fabs(R2-x2)>=0.1){printf (" Vece\n");}
	  	if (R2>x2 && fabs(x2-R2)>=0.1){printf (" Manje\n");}
	  	if (fabs(R2-x2)<EPSILON){printf (" Tacno\n");brojac2=1;}
	  	if ((R2-x2)<0.1 && (R2-x2)>EPSILON){printf (" Priblizno manje\n");}
	  	if ((x2-R2)<0.1 && (x2-R2)>=EPSILON){printf (" Priblizno vece\n");}}
	  	while(R2!=x2 && brojac2==0); 
	// printf ("%lf %lf",R1,R2);
	return 0;
}
