#include <stdio.h>

int daj_prost ()
{
	static int z=1;
	int x, y=0;
	while (y==0)
	{
		z++;
		y=1;
		for (x=2;x<z;x++)
		{
			if (z%x==0)
			{
				y=0;
				break;
			}
		}
		if (y==1)
		return z;
	}
}

int main ()
{
	int y=0;
	int A,B;
	do {
		y=0;
		printf ("Unesite brojeve A i B: ");
		scanf ("%d %d" , &A, &B);
	
		if (A>=B)
		{
			y=1;
			printf ("A nije manji od  B. \n ");
		}
		else if (A<1 || B<1)
		{ 
			y=1;
			printf ("A nije prirodan broj. \n");
		}
	}
	while (y==1);
	int n;
	n=daj_prost();
	y=0;
	while (n<B)
	{
		if (n>A && n<B)
		{
			y+=n;
		}
		n=daj_prost();
		if (n>=B)
		break;
	}
	
		printf ("Suma prostih brojeva izmedju %d i %d je %d.", A, B, y);
		return 0;
		
		}