#include <stdio.h>
#include <math.h>

int main() 
{
	int a, i, l, x, za, j;
	printf("Unesite broj: ");
	scanf ("%d", &a);
	i = 0;
	l = 0;
	j = 0;
	x = a;
	za = a;
	if (a/10==0)
	{
		printf ("0");
	}
	else if (a<0)
	{
		a = a*(-1);
		za = za*(-1);
		while (x/10!=0)
		{
			x = x/10;
			i++;
		}
		while (za/10!=0 && j<i)
			{
				int b, c, d;
				b = za%10;
				za = za/10;
				c = za%10;
				d = b-c;
				if (za/10==0)
					{
						c = za;
						d = b-c;
					}
				if (d<0)
					{
						d = d*(-1);
					}
				l = l + (d*pow (10,j));
				j++;
			}
		printf ("%d", l);
		return 0;
	}
	else
	{
		while (x/10!=0)
		{
			x = x/10;
			i++;
		}
		while (za/10!=0 && j<i)
		{
			int b, c, d;
			b = za%10;
			za = za/10;
			c = za%10;
			d = b-c;
			if (za/10==0)
			{
				c = za;
				d = b-c;
			}
			if (d<0)
			{
				d = d*(-1);
			}
			l = l + (d*pow(10,j));
			j++;
		}
		printf ("%d", l);
		return 0;
	}
	return 0;
}
