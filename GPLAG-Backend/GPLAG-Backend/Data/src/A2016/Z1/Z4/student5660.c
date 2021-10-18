#include <stdio.h>

int main() 
{
	int n, i, j, k;
	do
	{
		printf ("Unesite broj n: ");
		scanf ("%d", &n);
		if (n <= 0 || n > 50)
			printf ("Pogresan unos\n");
	}while (n <= 0 || n > 50);
	if (n == 1) printf ("***");
	else
	{
		k = n * 4 - 3;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < k; j++)
			{
				if(i == j || j == k/2+i || j == k/2-i || j == k-i-1)
					printf ("*");
				else
					printf (" ");
			}
			printf ("\n");
		}
	}
	return 0;
}
