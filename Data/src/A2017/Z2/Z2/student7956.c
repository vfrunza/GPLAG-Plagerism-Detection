#include <stdio.h>

int main() {
	int niz[100], finaln[1000];
	int pomocni[1000], josjedan[1000];
	printf("Unesite velicinu niza: ");
	int n = 0, i = 0, brojac = 0, j = 0;
	scanf ("%d", &n);

	printf("Unesite clanove niza: ");
	for (i = 0; i < n; i++)
	  {
	  scanf("%d", &niz[i]);
	  }
	for (i = n - 1; i >= 0; i--)
	{
		if (niz[i] == 0)
		{
				pomocni[j] = niz[i];
				brojac++;
				j++;
			}
		while (niz[i] > 0)
			{
				pomocni[j] = niz[i] % 10;
				niz[i] = niz[i]/10;
				brojac++;
				j++;
			}
	}
	j = 0;
	for (i = brojac-1; i >= 0; i--, j++)
		josjedan[j] = pomocni[i];
	
	int ponavljanja = 1;
	j = 0;
	
	for (i = 0; i < brojac ; i++)
	{
		
		if ( i+1 != brojac && josjedan[i] == josjedan[i+1])
			{
				ponavljanja++;
				if (i + 1 == brojac - 1)
				{
					finaln[j] = josjedan[i];
					j++;
		
					finaln[j] = ponavljanja;
					ponavljanja = 1;
					j++;
				break;
				}
			}
		/*if (josjedan[i] != josjedan[i+1]) */
		else
			{
			
				finaln[j] = josjedan[i];
					
				j++;
		
				finaln[j] = ponavljanja;
					
				ponavljanja = 1;
				j++;
				
			}
		
	}
	printf("Finalni niz glasi:\n");
	for (i = 0; i < j; i++)
		{
			if (i == j - 1)	
				printf ("%d", finaln[i]);
			else 
			printf ("%d ", finaln[i]);
		}
		/*if(josjedan[i + 1] == brojac)
					{
						finaln[j] = josjedan[i];
						j++;
						finaln[j] = ponavljanja;
						j++;
						break;
					}*/
  return 0;
}
	

