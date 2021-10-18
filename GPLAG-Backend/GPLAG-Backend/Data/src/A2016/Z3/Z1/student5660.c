#include <stdio.h>
#include <math.h>

long int daj_prost ()
{
	static long int n = 2;
	if (n == 2) {n++; return 2;}
	long int i, k, l;
	int prost = 1;
	do
	{
		l = sqrt(n);
		for (i = 2; i <= l+1; i++)
		{
			if (n%i == 0)
				{
					prost = 0;
					break;
				}
		}
		if (i == l+2) prost = 1;
		if (prost == 0) n++;
	}while(prost == 0);
	k = n++;
	return k; 
}

int main() {
	long int i = 0;
	long int a, b, pom, suma = 0;
	do
	{
		if (i != 0 && a < 1)
		printf ("A nije prirodan broj.\n");
		if (i != 0 && a >= b)
		printf ("A nije manje od B.\n");
		printf ("Unesite brojeve A i B: ");
		scanf ("%li", &a); scanf ("%li", &b);
		i++;
	} while (a >= b || a <= 0);
	
	do
	{
		pom = daj_prost();
		if (pom > a && pom < b)
			suma += pom;
	}while (pom < b);
	printf ("Suma prostih brojeva izmedju %li i %li je %li.", a, b, suma);
	
	return 0;
}
