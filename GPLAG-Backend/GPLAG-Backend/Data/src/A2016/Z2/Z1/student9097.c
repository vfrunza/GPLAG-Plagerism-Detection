#include <stdio.h>

int main() {
	int n, i, j, a, b, c, d, x, f;
	x=1;
	f=0;
	a=1;
	printf("Unesite broj: ");
	scanf ("%d", &n);
	if (n<0)
	n=(-n);
	if (n<10)
	{n=0;
	printf ("%d", n);}
	else
	{
		for (i=10; i<=n; i=i*10)
		{
			x=x*10;
		}
		for (j=100; j<=n; j=j*10)
		{
			a=a*10;
		}
		b=n/x;
		n=n%x;
		x=x/10;
		while (x!=0)
		{
			c=n/x;
			d=b-c;
			if (d<0)
			{d=(-d);}
			f=f+d*a;
			b=c;
			n=n%x;
			x=x/10;
			a=a/10;
		}
		printf ("%d", f);
	}
	return 0;
}
