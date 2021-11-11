#include <stdio.h>
#include <math.h>
#define EPSILON 0.001


int main() {
	double  xa, xb,xr1, xr2;
	float a,b,c, D=0  ;
do {
	printf ("Unesite koeficijente a, b i c: ");
	scanf ("%f %f %f", &a , &b, &c);
} while (a==0);
	
	D= (b*b-4*a*c);
	xa= ((-b + sqrt(b*b-4*a*c)))/(2*a);
	xb= ((-b - sqrt(b*b-4*a*c)))/(2*a);


/*if ( xa==xb )
{
		xa=x2;
	   xb=x1;
} 

else	if (xa>xb)
	{
		xa=x2;
	   xb=x1;
	}
else	if (xb>xa)
	{
		xb=x2;
		xa=x1;
	} */
	if (D<0)
	{
		printf ("Rjesenja su imaginarni brojevi.");
	}
	
else	                /*if (D>0 || D==0)*/
{

do {	printf ("Unesite rjesenje x1: ");
	scanf ("%lf", &xr1);


if ( xr1 - xa >= EPSILON && xr1- xa < 0.1 )  /* Za  rjesenja ,kad je razlika izmedju njih manja od  (neg) epsilona, ali veca  od - 0.1*/
 { printf ("Priblizno vece\n");}
else if (xr1 - xa <= -0.001 && xr1- xa > -0.1) /*Za  rjesenja, kad je razlika izmedju njih veca od epsilona, ali manja od 0.1*/
 { printf ("Priblizno manje\n");}
/*If-ovi za vece razlike unesenog i stvarnog rjesenja*/
if (xr1- xa <= -0.1) 
{ printf ("Manje\n");}

 if  (xr1- xa >= 0.1)
{ printf ("Vece\n"); }

} while ( (fabs (xr1- xa)) >= EPSILON);
	/* &&  x1-xr1 < EPSILON */
if (fabs (xr1- xa)< EPSILON)
			printf ("Tacno");	
        
/*Isti princip kao za x1*/
do {	printf ("\nUnesite rjesenje x2: ");
	scanf ("%lf", &xr2);

if ( xr2 - xb >= EPSILON && xr2- xb < 0.1)
 { printf ("Priblizno vece");}


 if ( xr2 - xb <= -0.001 && xr2- xb > -0.1)
 { printf ("Priblizno manje");}



if (xr2- xb <= -0.1)
{ printf ("Manje");}


else if  (xr2- xb >= 0.1)
{ printf ("Vece"); }

} while ( fabs (xr2- xb) >= EPSILON);
if (fabs (xr2- xb)< EPSILON)
			printf ("Tacno");
}



	return 0;
}
