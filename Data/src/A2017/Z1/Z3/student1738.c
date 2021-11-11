#include <stdio.h>
#include <math.h>
#define ep 0.001
#define e 0.1

int main()
{
	double a, b, c, D, x1, x2, x1k, x2k, z;
	
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	
	D=(b*b - 4*a*c);
	
	x1=((-b+sqrt(D))/(2*a));
	x2=((-b-sqrt(D))/(2*a));
	
	
	if(D<0)
	{
	printf("Rjesenja su imaginarni brojevi.");
	return 0;
	}
	
	if(a==0)
	{
		return 0;
	}
	
	if(x1>x2)
	{
		x1=z;
		x1=x2;
		x2=z;
	}
	
	
	
	do{
		printf ("Unesite rjesenje x1: ");
		scanf("%lf", &x1k);
		
		if(fabs(x1k-x1)<ep )
		printf("Tacno\n");
		else if( (x1k<x1) && fabs(x1k-x1)<e)
		printf ("Priblizno manje\n");
		else if( (x1k>x1) && fabs(x1k-x1)<e)
		printf ("Priblizno vece\n");
		else if(x1k<x1)
		printf("Manje\n");
		else if (x1k>x1)
		printf("Vece\n");
		
	}while( fabs(x1k-x1)>=ep || fabs(x1k-x1)<=-ep );
	
	
	do{
		printf ("Unesite rjesenje x2: ");
		scanf("%lf", &x2k);
		
		if(fabs(x2k-x2)<ep )
		printf("Tacno\n");
		else if( x2k<x2 && fabs(x2k-x2)<e)
		printf ("Priblizno manje\n");
		else if( x2k>x2 && fabs(x2k-x2)<e)
		printf ("Priblizno vece\n");
		else if(x2k<x2)
		printf("Manje\n");
		else if (x2k>x2)
		printf("Vece\n");
		
	}while( fabs(x2k-x2)>=ep || fabs(x2k-x2)<=-ep );
	
	return 0;
}
	