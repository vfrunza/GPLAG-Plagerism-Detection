#include <stdio.h>

int main() {
	int m, n, i, j, k, q, x[200][200], p=0;
	/*x[200][200] jer je to najveci format matrice*/
	do{
	printf("Unesite brojeve M i N: ");
	scanf ("%d %d", &m, &n);
	if (n<=0||m<=0||n>200||m>200)
	{
		printf ("Brojevi nisu u trazenom opsegu.\n");
	}
	}while(n<=0||m<=0||n>200||m>200); /*Osiguravamo da su dimenzije u zadanom opsegu*/
	printf ("Unesite elemente matrice: ");
	for (i=0; i<m; i++)
	{
		for (j=0; j<n; j++)
		{
			scanf ("%d", &x[i][j]);
		}
	}
	for (i=1; i<m; i++)
	{
		for (j=0; j<i; j++)
		{
			p=0;
			for (k=0; k<n; k++)
			{
				if (x[i][k]!=x[j][k]) /*Provjerava se da li su elementi dvije kolone jednaki*/
				{
					p=1;
					break;
				}
			}
			if (p==0)
			{
				/*Ako postoje jednake kolone izbacujemo jednu*/
				for (q=i; q<m-1; q++)
				{
					for (k=0; k<n; k++)
					{
						x[q][k]=x[q+1][k];
					}
				}
				m--;
				i--; 
				/*Ocuvanje redoslijeda*/
			}
		}
	}
		for (k=1; k<n; k++)
		{
			for (j=0; j<k; j++)
			{
				p=0;
				for (i=0; i<m; i++)
				{
					if (x[i][k]!=x[i][j]) /*Provjera jednakosti elemenata kod redova na slican nacin kao kod kolona*/
					{
						p=1;
						break;
					}
				}
				if (p==0)
				{
					for (q=k; q<n-1; q++)
					{
						for (i=0; i<m; i++)
						{
							x[i][q]=x[i][q+1];
							/*Ako postoje isti redovi izbacuje se jedan*/
						}
					}
					k--;
					n--; 
					/*Ocuvanje redoslijeda*/
				}
			}
		}
		printf ("Nakon izbacivanja redova/kolona matrica glasi:\n");
		for (i=0; i<m; i++)
		{
			printf (" ");
			for (j=0; j<n; j++)
			{
				printf ("%4d ", x[i][j]); /*Ispis je na 5 mjesta sirine*/
			}
			printf ("\n"); 
			/*Buduci da je u pitanju matrica moramo imati 2 for petlje, jedna za ispis elemenata u redove i druga za prebacivanje u novi red*/
		}
	return 0;
}
