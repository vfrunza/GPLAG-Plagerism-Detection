#include <stdio.h>
#include <math.h>

/* Make-shift boolean type. */
typedef int _bool;
#define true 1
#define false 0

/* Macros. */
/* EPSILON: Used for comparing floating-point numbers. */
/* COSINE: Calculates the cosine of the largest angle in any given triangle (derived from the Cosine theorem). */
#define EPSILON 0.0001 
#define COSINE ((pow(a, 2) + pow(b, 2) - pow(c, 2))/(2 * a * b))

/* Prototypes. */
/* fEqual: Checks whether two floating-point numbers are equal (makes the conditions in the if-statements look a bit nicer). */
_bool fEqual(double a, double b);

/* Point structure (added because it looks nicer; don't have to declare six variables for all the coordinates of the three points). */
struct point
{
	double x, y;	
};

int main(void)
{ 
	/* Variables. */
	/* Points, sides of the triangle, for-loop control variables, logical variables, etc. */
	struct point t1, t2, t3;
	double a, b, c, sides[3], temp;
	int i;
	_bool jednakostranican = false;
	_bool pravougli = false;
	
	/* Prompt for the user. */
	printf("Unesite koordinate tacke t1: "); scanf("%lf %lf", &t1.x, &t1.y);
	printf("Unesite koordinate tacke t2: "); scanf("%lf %lf", &t2.x, &t2.y);
	printf("Unesite koordinate tacke t3: "); scanf("%lf %lf", &t3.x, &t3.y);
	
	/* Calculates the lengths of the triangle's sides. */
	sides[0] = sqrt(pow(t3.x - t2.x, 2) + pow(t3.y - t2.y, 2));
	sides[1] = sqrt(pow(t2.x - t1.x, 2) + pow(t2.y - t1.y, 2));
	sides[2] = sqrt(pow(t3.x - t1.x, 2) + pow(t3.y - t1.y, 2));
	
	/* Sorts the sides of the triangle. */
	for (i = 0; i < 2; i++)
	{
		if (sides[i] > sides[i + 1])
		{
			temp = sides[i + 1];
			sides[i + 1] = sides[i];
			sides[i] = temp;
		}
	}
	
	/* Sides of the triangle from shortest to longest: a, b, c. */
	a = sides[0];
	b = sides[1];
	c = sides[2];
	
	/* Checks whether the three points form a triangle in the first place (triangle inequality). */
	if ((c < (a + b)) && (b < (a + c)) && (a < (c + b)))
	{
		/* Checks whether the triangle is equileteral. */
		if (fEqual(a, b) && fEqual(b, c))
		{
			printf("Jednakostranicni\n");
			jednakostranican = true;
		}
		
		/* Checks whether the triangle is a right-angled triangle. */
		if (fEqual(c, sqrt(pow(a, 2) + pow(b, 2))) || fEqual(a, sqrt(pow(b, 2) + pow(c, 2))) || fEqual(b, sqrt(pow(a, 2) + pow(c, 2))))
		{
			printf("Pravougli\n");
			pravougli = true;
		}
		
		/* Checks whether the triangle is isosceles. */
		if ((fEqual(a, b) || fEqual(b, c) || fEqual(a, c)) && !jednakostranican)
		{
			printf("Jednakokraki\n");
			jednakokraki = true;
		}
		
		if (!fEqual(a, b) && !fEqual(b, c) && !fEqual(a, c))
		{
			printf("Raznostranicni\n");
		}
		
		/* Prints out the largest angle in the triangle in degrees, minutes and seconds. */
		if (jednakostranican)
		{
			printf("Najveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.\n");
		}
		else if (pravougli)
		{
			printf("Najveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.\n");
		}
		else
		{	
			/* Computes the largest angle in the triangle (expressed only in degrees). */
			double d_degrees = acos(COSINE) * (180/M_PI);
			
			/* To express the the angle in degrees, minutes and seconds, some added computations need to be done. */
			int degrees = d_degrees;
			double d_minutes = (d_degrees - degrees) * 60;
			int minutes = d_minutes;
			double d_seconds = (d_minutes - minutes) * 60;
			int seconds = d_seconds; 
			
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.\n", degrees, minutes, seconds);
		}
		
	}
	/* In case the triangle inequality doesn't hold, then the three points form a line. */
	else
	{
		printf("Linija\n");
		printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.\n");
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