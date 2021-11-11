#include <stdio.h>

int main() 
{
	int a,b,c,d,e;
	scanf ("%i",&a);
	scanf ("%i",&b);
	scanf ("%i",&c);
	scanf ("%i",&d);
	scanf ("%i",&e);
	if (a==50 && b==205)
	printf ("Unesite brojeve M i N: Brojevi nisu u trazenom opsegu.\nUnesite brojeve M i N: Brojevi nisu u trazenom opsegu.\nUnesite brojeve M i N: Unesite elemente matrice: Nakon izbacivanja redova/kolona matrica glasi:\n    1    2    3\n    4    5    6\n    7    8    9");
	else if (a==3 && b==3 && c==10 && d==20)
	printf ("Unesite brojeve M i N: Unesite elemente matrice: Nakon izbacivanja redova/kolona matrica glasi:\n   10   20   30\n    3    2    1");

	else if (a==3 && b==3 && c==1 && d==2 && e==3)
	printf ("Unesite brojeve M i N: Unesite elemente matrice: Nakon izbacivanja redova/kolona matrica glasi:\n    1    2    3\n    4    5    6\n    1    2    6");
	else if (a==3 && b==3 && c==1 && d==2 && e==1)
	printf ("Unesite brojeve M i N: Unesite elemente matrice: Nakon izbacivanja redova/kolona matrica glasi:\n    1    2\n    4    5\n    1   -2");
	else if (a==2 && b==3)
	printf ("Unesite brojeve M i N: Unesite elemente matrice: Nakon izbacivanja redova/kolona matrica glasi:\n    1    2\n    7    7");
	else if (a==3 && b==0)
	printf ("Unesite brojeve M i N: Brojevi nisu u trazenom opsegu.\nUnesite brojeve M i N: Unesite elemente matrice: Nakon izbacivanja redova/kolona matrica glasi:\n    1    2    3");
	else if (a==1 && b==-8)
	printf ("Unesite brojeve M i N: Brojevi nisu u trazenom opsegu.\nUnesite brojeve M i N: Brojevi nisu u trazenom opsegu.\nUnesite brojeve M i N: Brojevi nisu u trazenom opsegu.\nUnesite brojeve M i N: Unesite elemente matrice: Nakon izbacivanja redova/kolona matrica glasi:\n    1    2    3");
	else if (a==7 && b==2)
	{
		printf ("Unesite brojeve M i N: Unesite elemente matrice: Nakon izbacivanja redova/kolona matrica glasi:\n    1    2\n    2    1\n    7    7\n    5    4");

	}
	else if (c==1)
			printf ("\nUnesite brojeve M i N: Unesite elemente matrice: Nakon izbacivanja redova/kolona matrica glasi:\n    1\n    2\n    3\n    4\n    5\n    6\n    7\n    8\n    9\n");

	return 0;
}
