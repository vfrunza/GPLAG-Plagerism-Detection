#include <stdio.h>
#include<math.h>
#define EPS 0.001
#define E 0.1


int main() {
	double a, b, c, D, x, y,x1, x2;
	
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a, &b, &c);
	
	D=b*b-4*a*c;
	
	x=((-1)*b-sqrt(D))/(2*a);
	y=((-1)*b+sqrt(D))/(2*a);
	
	if(y<x)
	{
		x=y;
		y=((-1)*b-sqrt(D))/(2*a);
		
	}

	if (D<0)
	{
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	else {
		
	do {
		
		printf("Unesite rjesenje x1: ");
		scanf("%lf", &x1);
		
		if(fabs(x1-x)<EPS)
		{
			printf("Tacno\n");
			break;
		}
		
		else if(fabs(x1-x)>=EPS && fabs(x1-x)<E)
		{
			if(x1-x>0)
			printf("Priblizno vece\n");
		else 
		{
			printf("Priblizno manje\n");
		}
		}
		else if(x1<x)
		printf("Manje\n");
		else if(x1>x)
		printf("Vece\n");
		
	}
		while(fabs(x1-x)>=EPS);
		
		do{
			printf("Unesite rjesenje x2: ");
			scanf("%lf", &x2);
			
			if(fabs(x2-y)<EPS)
			{
				printf("Tacno\n");
				break;
			}
			else if(fabs(x2-y)>=EPS && fabs(x2-y)<E)
			{
				if(x2-y>0)
				printf("Priblizno vece\n");
			else
				printf("Priblizno manje\n");
			}
			
			else if(x2>y)
			{
				printf("Vece\n");
			}
			else if( x2<y)
			{
				printf("Manje\n");
			}
		
		}
		
		while(fabs(x2-y)>=EPS);
	}
		
	return 0;
}
