#include <stdio.h>
#include <stdlib.h>

int main() {
	int x,y,z,r,a=0,b=1;
	printf ("Unesite broj: ");
	scanf ("%d", &x);
	x=abs(x);
	if (x<10)
	{
		x=0; 
		printf ("%d", x);
		return 0;
	}

	else
	{
	while (x>9)
		{
		y=x%10;
		x=x/10;
		z=x%10;
		r=abs(y-z);
		a=a+r*b;
		b=b*10;
		}
		
	}
	printf ("%d", a);
	return 0;
}
