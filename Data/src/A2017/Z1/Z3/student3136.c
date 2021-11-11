#include <stdio.h>
#include <math.h>
#define E 1e-3

void print(double _x, double x)
{
	if (!(_x - x < 0.1))
	    printf("Vece\n");
    else if (_x - x > 0)
	    printf("Priblizno vece\n");
	if (!(_x - x > -0.1))
	    printf("Manje\n");
	else if (_x - x < 0)
	    printf("Priblizno manje\n");
}
int main()
{
	double a, b, c, x1, x2, D, _x1, _x2;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	D = b*b - 4*a*c;
	if (D < 0)
	{
	    printf("Rjesenja su imaginarni brojevi.");
	    return 1;
	}
	x1 = (-b - sqrt(D)) / 2 / a;
	x2 = (-b + sqrt(D)) / 2 / a;
	if (x1 > x2) 
	{
		_x1 = x1;
	    x1 = x2;
	    x2 = _x1;
	}
	do
	{
		printf("Unesite rjesenje x1: ");
	    scanf("%lf", &_x1);
	    if (fabs(_x1 - x1) < E)
	        break;
	    print(_x1, x1);
	} while (1);
	printf("Tacno\n");
	do
	{
	    printf("Unesite rjesenje x2: ");
	    scanf("%lf", &_x2);
	    if (fabs(_x2 - x2) < E)
	        break;
	    print(_x2, x2);
	} while (1);
	printf("Tacno");
	return 0;
}
