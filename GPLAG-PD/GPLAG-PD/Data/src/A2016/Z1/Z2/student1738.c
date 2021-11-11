#include <stdio.h>

int main() 
{
	float a,b,a1,b1,x,y;
	printf ("Unesite a1,b1,a2,b2: ");
	scanf ("%f, %f, %f, %f",&a,&b,&a1,&b1);
	if (a==a1 && b==b1)
	{
		printf ("Poklapaju se");
	}
	
	else if (a==a1)
	{
	    printf ("Paralelne su");
	}

	else
	{
	    x=(b1-b)/(a-a1);
	    y=a*x+b;
	    printf ("Prave se sijeku u tacci (%.1f,%.1f)",x,y);
	}
	return 0;
}
