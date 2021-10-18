#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

int main ()
{
	double a,b,c,D,rj1,rj2,x1,x2;
	int i=0;
	printf ("Unesite koeficijente a, b i c: ");
	scanf ("%lf %lf %lf",&a,&b,&c);
	D=b*b-4*a*c;
	if (D<0)
	{
		printf ("Rjesenja su imaginarni brojevi.");
		return 1;
	}
	
	rj1=(-b+sqrt(D))/(2*a);
	rj2=(-b-sqrt(D))/(2*a);
	
	do
	{
		if (i==0)
		printf ("Unesite rjesenje x1: ");
		else
		printf ("\nUnesite rjesenje x1: ");

		scanf ("%lf",&x1);
		
		if ((x1-rj1)<0 && !(fabs(x1-rj1)<EPSILON))
		{
			if (fabs(x1-rj1)<0.1 && x1<rj1)
			{
				printf ("Priblizno manje");
				i++;
				continue;
			}
			printf ("Manje");
			i++;
			continue;
		}
		else if (x1-rj1>0 && !(fabs (x1-rj1)<EPSILON))
		{
			if (fabs(x1-rj1)<0.1 && x1>rj1)
			{
				printf ("Priblizno vece");
				i++;
				continue;
			}
			printf ("Vece");
			i++;
			continue;
		}
	}while (!(fabs(x1-rj1)<EPSILON));
	
	
	if (fabs(x1-rj1)<EPSILON)
	{
		printf ("Tacno");
		do
		{
			printf ("\nUnesite rjesenje x2: ");
			scanf ("%lf", &x2);
			
			if (fabs(x2-rj2)<EPSILON) {
			printf ("Tacno");
			break; }
			
			if ((x2-rj2)<0)
			{
				if (fabs(x2-rj2)<0.1 && x2<rj2)
				{
					printf ("Priblizno manje");
					continue;
				}
				printf ("Manje");
				continue;
			}
			
			else if ((x2-rj2)>0 && !(fabs(x2-rj2)<EPSILON))
			{
				if (fabs(x2-rj2)<0.1 && x2>rj2 )
				{
					printf ("Priblizno vece");
					continue;
				}
				
				printf ("Vece");
				continue;
			}
		} while (!(fabs(x2-rj2)<EPSILON));

	}
	
	return 0;
}

