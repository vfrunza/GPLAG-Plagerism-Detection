#include <stdio.h>
#include <math.h>

/* Make-shift boolean type. */
typedef int _bool;
#define true 1
#define false 0

/* Macros. */
/* EPSILON: Used for comparing floating-point numbers (equality). */
/* APPROXIMATE: Used for comparing floating-point numbers (lesser or greater than). */ 
#define EPSILON 0.001
#define APPROXIMATE 0.1

/* Checks whether two floating-point numbers are equal. */
_bool fEqual(double a, double b);
/* Like fEqual(), but with APPROXIMATE (less precision) instead of EPSILON. */
_bool fCompare(double a, double b);

int main() 
{
	/* Variables. */
    double a, b, c, D, x1, x2, guess, temp1, temp2;
   
	/* Prompts for the user. */
	printf("Unesite koeficijente a, b i c: "); scanf("%lf %lf %lf", &a, &b, &c);
	/* Calculates the D of a given quadratic equation. */
	D = (b * b) - (4 * a * c);
	
	/* Checks whether the D is less than zero (we don't have to deal with it imaginary numbers in this problem). */
	if (D < 0)
	{
	    printf("Rjesenja su imaginarni brojevi.\n");
	}
	else
	{
		/* Calculates the two solutions of a given quadratic equation. */
	    temp1 = (-b - sqrt(D))/(2*a);
	    temp2 = (-b + sqrt(D))/(2*a);
	    
	    /* Checks which of the solutions (if any at all) is greater than the other, and properly sorts them. */
	    if (temp1 > temp2)
	    {
	    	/* x2 ends up being the greater solution. */
	    	x1 = temp2;
	    	x2 = temp1;
	    }
	    else
	    {
	    	/* x1 is greater or both are equal. */
	    	x1 = temp1;
	    	x2 = temp2;
	    }
	    
	    /* Prompts the user to guess the first solution. */
		do
		{
			printf("Unesite rjesenje x1: "); scanf("%lf", &guess);
			if (fEqual(guess, x1))
			{
				printf("Tacno\n");
			}
			else if ((guess - x1 > 0) && fCompare(guess, x1))
			{
				printf("Priblizno vece\n");
			}
			else if ((guess - x1 < 0) && fCompare(guess, x1))
			{
				printf("Priblizno manje\n");
			}
			else if (guess > x1)
			{
				printf("Vece\n");
			}
			else if (guess < x1)
			{
				printf("Manje\n");
			}
			
		} while (!fEqual(guess, x1));
		
		/* Prompts the user to the guess the second solution. */
		do
		{
			printf("Unesite rjesenje x2: "); scanf("%lf", &guess);
			if (fEqual(guess, x2))
			{
				printf("Tacno\n");
			}
			else if ((guess - x2 > 0) && fCompare(guess, x2))
			{
				printf("Priblizno vece\n");
			}
			else if ((guess - x2 < 0) && fCompare(guess, x2))
			{
				printf("Priblizno manje\n");
			}
			else if (guess > x2)
			{
				printf("Vece\n");
			}
			else if (guess < x2)
			{
				printf("Manje\n");
			}
			
		} while (!fEqual(guess, x2));
	}
	
	return 0;
}

_bool fEqual(double a, double b)
{
	if (fabs(a - b) < EPSILON)
		return true;
	else
		return false;
}

_bool fCompare(double a, double b)
{
	if (fabs(a - b) < APPROXIMATE)
		return true;
	else
		return false;
}