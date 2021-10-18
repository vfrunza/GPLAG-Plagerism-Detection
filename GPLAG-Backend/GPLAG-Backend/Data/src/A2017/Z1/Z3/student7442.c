#include <stdio.h>
#include <math.h>
#define eps 0.001

int main() {
	double a,b,c,D,x1,x2,xx1,xx2;
	double razlika= 0;
	int setovano = 0;

	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	D=b*b-4*a*c;

	if(D<0)
	{
	  printf("Rjesenja su imaginarni brojevi.");
	  return 0;
	}
	D= sqrt(D);
	xx2=(-b-D)/(2*a);
	xx1=(-b+D)/(2*a);
	do
	{
	printf("Unesite rjesenje x1: ");
	scanf("%lf",&x1);
	razlika=x1 - xx1;
	if(razlika<0)
	{
		if(razlika  * (-1) <eps)
		{
			printf("Tacno\n");
			setovano=1;
		}
		else if(razlika * (-1) < 0.1) 
		{
			printf("Priblizno manje\n");
			setovano = 1;
		}
		razlika=razlika*(-1);
	}
	
	if(setovano==0) 
	{
		if(razlika<eps)
		{
			printf("Tacno\n");
		}
		else if(razlika< 0.1)
		{
			printf("Priblizno vece\n");
		}
		else if(x1<xx1)
		{
		    printf("Manje\n");
		}
		else  if(x1>xx1)
		{
			printf("Vece\n");
		}
	}
	else 
	{
		setovano = 0;
	}

	}while(razlika>=eps);
	
		do
	{
	printf("Unesite rjesenje x2: ");
	scanf("%lf",&x2);
	razlika = x2 - xx2;
	if(razlika<0)
	{
		if(razlika * (-1) <eps)
		{
			printf("Tacno\n");
			setovano=1;
		}
		else if(razlika * (-1) < 0.1) 
		{
			printf("Priblizno manje\n");
			setovano = 1;
		}
		razlika=razlika*(-1);
	}
	
	if(setovano==0) 
	{
		if(razlika<eps)
		{
			printf("Tacno\n");
		}
		else if(razlika< 0.1)
		{
			printf("Priblizno vece\n");
		}
		else if(x2<xx2)
		{
		    printf("Manje\n");
		}
		else  if(x2>xx2)
		{
			printf("Vece\n");
		}
	}
	else 
	{
		setovano = 0;
	}

	}while(razlika>=eps);
	
	return 0;
}
