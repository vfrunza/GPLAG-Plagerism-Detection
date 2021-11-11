#include <stdio.h>
#include <math.h>

int main() {
	double a,b,c,eps,x1,x2,D,unos1,unos2,raz1,raz2,min,max;
	eps=0.001;
	printf ("Unesite koeficijente a, b i c: ");
	scanf ("%lf %lf %lf",&a,&b,&c);
	D=pow(b,2)-4*a*c;
	x1=(-b-sqrt(D))/(2*a);
	x2=(-b+sqrt(D))/(2*a);
	if (x1<=x2)
	{min=x1; max=x2;}
	else if (x1>x2)
	{min=x2; max=x1;}
	
	if (D<0)
	printf ("Rjesenja su imaginarni brojevi.\n");
	else
	{
		do{
			printf ("Unesite rjesenje x1: ");
			scanf ("%lf",&unos1);
			raz1=min-unos1;
			if (raz1<0)
			raz1=raz1*(-1);
			if (raz1<eps)
			    printf ("Tacno\n");
			else if (raz1>=eps && raz1<0.1 && unos1<min)
			    printf ("Priblizno manje\n");
			else if (raz1>=eps && raz1<0.1 && unos1>min)
			    printf ("Priblizno vece\n");
			else if (unos1<min)
			    printf ("Manje\n");
			else if (unos1>min)
			    printf ("Vece\n");
				}
		while (raz1>=eps);
		do {
			printf ("Unesite rjesenje x2: ");
			scanf ("%lf",&unos2);
			raz2=max-unos2;
			if (raz2<0)
			raz2=raz2*(-1);
			if (raz2<eps)
			printf ("Tacno\n");
			else if (raz2>=eps && raz2<0.1 && unos2<max)
			printf ("Priblizno manje\n");
			else if (raz2>=eps && raz2<0.1 && unos2>max)
			printf ("Priblizno vece \n");
			else if (unos2<max)
			printf ("Manje\n");
			else if (unos2>max)
			printf ("Vece\n");
		}
		while (raz2>=eps);
	}
	
	return 0;
}
