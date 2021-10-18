#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
#define BROJ 0.1
int main() {
	double a,b,c,x1=0,x2=0,D,px1,px2,kx1,kx2;
	printf ("Unesite koeficijente a, b i c: ");
	scanf ("%lf %lf %lf", &a, &b, &c);
	
	if (a==0)
	{
		printf ("Linearna jednacina");
		return 0;
	}
	D=pow(b,2)-4*a*c;
	if (D<0)
	{
		printf ("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	kx1=(-b-sqrt(D))/(2*a);
	kx2=(-b+sqrt(D))/(2*a);
	
	if (kx1>kx2)
	{
		px1=kx2;
		px2=kx1;
	}
	else if (kx2>=kx1)
	{
		px1=kx1;
		px2=kx2;
	}
	
	do 
		{
	printf ("Unesite rjesenje x1: ");
	scanf ("%lf", &x1);
	
 if (x1<px1 && px1-x1<BROJ && fabs(px1-x1)>=EPSILON)
	{
		printf ("Priblizno manje\n");
		
	}
	
	else if (x1<px1 && px1-x1>=BROJ)
	{
		printf ("Manje\n");
	}

   else	if (x1>px1 && x1-px1<BROJ && fabs(px1-x1)>=EPSILON)
	{
		printf ("Priblizno vece\n");
	}
	else if (x1>px1 && x1-px1>=BROJ)
	{
		printf ("Vece\n");
	}
	else if (fabs(px1-x1)<EPSILON)
{
	printf ("Tacno\n");
		}
		}
	while (fabs(px1-x1)>=EPSILON);

	
	
	do 
		
	{
	printf ("Unesite rjesenje x2: ");
	scanf ("%lf", &x2);
	
 if (x2<px2 && px2-x2<BROJ && fabs(px2-x2)>=EPSILON)
	{
		printf ("Priblizno manje\n");
		
	}
	
	else if (x2<px2 && px2-x2>=BROJ)
	{
		printf ("Manje\n");
	}

   else	if (x2>px2 && x2-px2<BROJ && fabs(px2-x2)>=EPSILON)
	{
		printf ("Priblizno vece\n");
	}
	else if (x2>px2 && x2-px2>=BROJ)
	{
		printf ("Vece\n");
	}
	else if (fabs(px2-x2)<EPSILON)
	{
	printf ("Tacno");
	}
	}
	while (fabs(px2-x2)>=EPSILON);
	
	return 0;
}
