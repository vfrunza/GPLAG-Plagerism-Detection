#include <stdio.h>
#include <math.h>
#define EPS 0.001

int main()
{
	int a, b, c; 
	double x1, x2, D, sarma, japrak;
	
	printf("Unesite koeficijente a, b i c: ");
	scanf("%d %d %d", &a, &b, &c);
	
	D = b*b-4*a*c;
	x1 = (-b+sqrt(D))/(2*a);
	x2 = (-b-sqrt(D))/(2*a);
	 
	if (D<0)
	{
		printf("Rjesenja su imaginarni brojevi.");
	}
	else
	{
		for (;;)
		{
			printf("Unesite rjesenje x1: ");
			scanf("%lf", &sarma);
			
			if (fabs(sarma - x1)<EPS)
			{
				printf("Tacno\n");
				
			/* ispitujemo za x2 */
			for (;;)
				{
					printf("Unesite rjesenje x2: ");
					scanf("%lf", &japrak);
					
					if (fabs(x2-japrak)<EPS)
					{
					printf("Tacno\n");
					return 0;
					}
					
					if (x2 > japrak && ((x2-japrak) < 0.1))
					{
						printf("Priblizno manje\n");
						continue;
					}
					
					if (x2 < japrak && ((japrak - x2) < 0.1))
					{
						printf("Priblizno vece\n");
						continue;
					}
					
					if (x2<japrak)
					{
						printf("Vece\n");
						continue;
					}
					
					if (x2>japrak)
					{
						printf("Manje\n");
						continue;
					}
				}
			}
			
			if (x1 > sarma && ((x1 - sarma) < 0.1))
			{
				printf("Priblizno manje\n");
				continue;
			}
			
			if (x1 < sarma && ((sarma - x1) < 0.1))
			{
				printf("Priblizno vece\n");
				continue;
			}
					
			if (x1<sarma)
			{
				printf("Vece\n");
				continue;
			}
			
			if (x1>sarma)
			{
				printf("Manje\n");
				continue;
			}
		}
	}
	return 0;
}