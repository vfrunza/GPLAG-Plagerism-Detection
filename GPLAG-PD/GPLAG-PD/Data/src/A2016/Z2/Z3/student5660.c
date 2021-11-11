#include <stdio.h>

int main()
{
	int niz[20], brTacaka, i = 0, j = 0, k, pom, DaLiSeDesioBreak = 0;

	do
	{
		if (i > 0) printf ("Pogresan unos\n");
		printf ("Unesite broj tacaka: ");
		scanf ("%d", &brTacaka);
		i++;
	}while (brTacaka <= 0 || brTacaka > 10);

	for (i = 0; i < brTacaka; i++)
	{
		printf ("Unesite %d. tacku: ", i+1);
		scanf ("%d %d", &niz[j], &niz[j+1]);
		if (niz[j] < 0 || niz[j] > 19 || niz[j+1] < 0 || niz[j+1] > 19)
		{
			printf ("Pogresan unos\n");
			j-=2;
			i--;
		}
		j+=2;
	}
	j = 0;

	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 20; j++)
		{
			pom = 0; DaLiSeDesioBreak = 0;
			for (k = 0; k < brTacaka; k++)
			{
				if (niz[pom] == j && niz[pom+1] == i)
                {
                    printf ("*");
                    /* AKO SE DESI BREAK POSTAVI DaLiSeDesioBreak = 1 (LOGICKA ISTINA) */
                    DaLiSeDesioBreak++;
                    break;
                }
				pom+=2;
			}
			if (DaLiSeDesioBreak == 0) printf (" ");
		}
		printf ("\n");
	}

	return 0;
}
