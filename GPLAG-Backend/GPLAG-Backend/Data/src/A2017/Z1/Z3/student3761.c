#include <stdio.h>
#include <math.h>
#define E 0.001

int main ()
{
	double a=0, b=0, c=0, x1=0, x2=0, x_1=0, x_2=0, D=0; /*a,b,c-koef. j-ne; x2,x1-tacna rj. j-ne; x_1,x_2-unesena rj. j-ne; D-diskriminanta; x-rj. kad je D=0*/
	printf ("Unesite koeficijente a, b i c: ");
	scanf ("%lf %lf %lf", &a, &b, &c);
	D = pow(b,2)-4*a*c;
	if (D<0)
	{
		printf ("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	else
	{
		x1 = (-b-sqrt(D))/2*a;
		x2 = (-b+sqrt(D))/2*a;
		printf ("Unesite rjesenje x1: ");
		scanf ("%lf", &x_1);
		goto d_x;
	}
	
d_x:{
		if (fabs(x_1-x1)<E)
		{
			printf ("Tacno\n"); 
			printf ("Unesite rjesenje x2: ");
			scanf ("%lf", &x_2);
			do
			{
				if (fabs(x_2-x2)>0.1 && x2>x_2) 
				{
					printf ("Manje\n");
					printf ("Unesite rjesenje x2: "); 
					scanf ("%lf", &x_2);
					
				}
			else if (fabs(x_2-x2)<0.1 && x2>x_2 && fabs(x_1-x1)>E) 
				{
					printf ("Priblizno manje\n");
					printf ("Unesite rjesenje x2: "); 
					scanf ("%lf", &x_2);
				}
			else if (fabs(x_2-x2)>0.1 && x2<x_2)  
				{
					printf ("Vece\n");
					printf ("Unesite rjesenje x2: "); 
					scanf ("%lf", &x_2);
				}
			else if (fabs(x_2-x2)<0.1 && x2<x_2 && fabs(x_1-x1)>E)
				{
					printf ("Priblizno vece\n");
					printf ("Unesite rjesenje x2: "); 
					scanf ("%lf", &x_2);
					printf ("Priblizno vece\n");
				}
			}
			while (fabs(x_2-x2)>E);
			printf ("Tacno");
			return 0;
		}  
		{	do
			{
				if (fabs(x_1-x1)>0.1 && x1>x_1) 
				{
					printf ("Manje\n");
					printf ("Unesite rjesenje x1: "); 
					scanf ("%lf", &x_1);
					
				}
			else if (fabs(x_1-x1)<0.1 && x1>x_1 && fabs(x_1-x1)>E) 
				{
					printf ("Priblizno manje\n");
					printf ("Unesite rjesenje x1: "); 
					scanf ("%lf", &x_1);
				}
			else if (fabs(x_1-x1)>0.1 && x1<x_1)  
				{
					printf ("Vece\n");
					printf ("Unesite rjesenje x1: "); 
					scanf ("%lf", &x_1);
				}
			else if (fabs(x_1-x1)<0.1 && x1<x_1 && fabs(x_1-x1)>E)
				{
					printf ("Priblizno vece\n");
					printf ("Unesite rjesenje x1: "); 
					scanf ("%lf", &x_1);
					printf ("Priblizno vece\n");
				}
			}
			while (fabs(x_1-x1)>E);
			goto d_x;
		}
    }
	return 0;
}