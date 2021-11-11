#include <stdio.h>
#include <math.h>
#define epsilon 0.001

int main() 
{
	int a, b, c;
	double x1, x2, xp1, xp2, m, n;
	printf ("Unesite koeficijente a, b i c: ");
	scanf ("%d %d %d", &a, &b, &c);
	
	if ((b*b - 4*a*c) < 0 ) 
	{
		printf ("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	
	x1 = (-b - sqrt(b*b - 4*a*c)) / (2*a);
	x2 = (-b + sqrt(b*b - 4*a*c)) / (2*a);
	//printf ("x1 = %f\n", x1);
	//printf ("x2 = %f\n", x2);
	
	do
	{
		printf ("Unesite rjesenje x1: ");
		scanf ("%lf", &xp1);
		m = xp1 - x1; //printf ("xp1 - x1 = %f\n", m);
		if ( (fabs(xp1 - x1) < epsilon)) {printf ("Tacno\n"); break; } 
		else if ( (fabs(xp1 - x1) < 0.1) && (xp1 > x1) ) printf ("Priblizno vece\n");
	    else if ( (fabs(xp1 - x1) < 0.1) && (xp1 < x1) ) printf ("Priblizno manje\n");
		else if ( ((fabs(xp1) >= 0 && xp1 > x1)) ) printf ("Vece\n");
		else if ( ((fabs(xp1) > 0 && xp1 < x1)) ) printf ("Manje\n");
	    
	} while (xp1 > x1 || xp1 < x1 || xp1 - 0.1 < x1 || xp1 - 0.1 > x1 || (xp1 - epsilon > x1 || -xp1 - epsilon > x1));
	
	do
	{
		printf ("Unesite rjesenje x2: ");
		scanf ("%lf", &xp2); 
		n = xp2 - x2; //printf ("xp2 - x2 = %f\n", n);
		if ( (fabs(xp2 - x2) < epsilon)) {printf ("Tacno\n"); break; } 
		else if ( (fabs(xp2 - x2) < 0.1) && (xp2 > x2) ) printf ("Priblizno vece\n");
	    else if ( (fabs(xp2 - x2) < 0.1) && (xp2 < x2) ) printf ("Priblizno manje\n");
		else if ( ((fabs(xp2) >= 0 && xp2 > x2)) ) printf ("Vece\n");
		else if ( ((fabs(xp2) > 0 && xp2 < x2)) ) printf ("Manje\n");
	
	} while (xp2 > x2 || xp2 < x2 || xp2 - 0.1 < x2 || xp2 - 0.1 > x2 || (xp1 - epsilon > x1 || -xp1 - epsilon > x1));
	
	return 0;
}
