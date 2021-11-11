#include <stdio.h>
#include <math.h>
#define E 0.001

int main() 
{
	float a, b, c, D, t, x1, x2, y1, y2;
	int s=0;
	
	printf("Unesite koeficijente a, b i c: ");
	scanf("%f %f %f", &a, &b, &c);
	
	D=b*b-4*a*c;
	
	if(D<0)
	{
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}

		t=sqrt(D);
		x1=(-b+t)/(2*a);
		x2=(-b-t)/(2*a);
	
	do
	{
		printf("Unesite rjesenje x1: ");
		scanf("%f", &y1);
		
		if((x1-y1<E && x1-y1>=0) || (x1-y1>-E && x1-y1<=0))
		{
			printf("Tacno");
			s++;
		}
		else if(x1-y1<0.1 && x1-y1>=0) printf("Priblizno manje");
		else if(x1-y1>-0.1 && x1-y1<=0) printf("Priblizno vece");
		else if(x1>y1) printf("Manje");
		else if(x1<y1) printf("Vece");
		else
		{
			printf("Tacno");
			s++;
		}
		printf("\n");
		
	}while(s!=1);
	
	s=0;
	
	do
	{
		printf("Unesite rjesenje x2: ");
		scanf("%f", &y2);
		
		if((x2-y2<E && x2-y2>=0) || (x2-y2>-E && x2-y2<=0))
		{
			printf("Tacno");
			s++;
		}
		else if(x2-y2<0.1 && x2-y2>=0) printf("Priblizno manje");
		else if(x2-y2>-0.1 && x2-y2<=0) printf("Priblizno vece");
		else if(x2>y2) printf("Manje");
		else if(x2<y2) printf("Vece");
		else
		{
			printf("Tacno");
			s++;
		}
		printf("\n");
		
	}while(s!=1);
	
	return 0;
}