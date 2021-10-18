#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina);
int izbaci_kolonu(int matrica[][100], int visina, int sirina, int x);

int main() 
{
	int matrica[100][100], 
		visina, 
		sirina,
		prolaz,
		i, 
		j,
		x;
	
	do
	{
		printf("Unesite sirinu i visinu matrice: ");
		scanf("%d %d", &visina, &sirina);
		
	}while(visina <= 0 || visina > 100 || sirina <= 0 || sirina > 100);
	
	for(i = 0; i < visina; i++)
	{
		printf("Unesite elemente %d. reda: ", i + 1);
		for(j = 0; j < sirina; j++)
		{
			scanf("%d", &matrica[i][j]);
			}
		}
		printf("\n");
	
	
	prolaz = 1;
	
	do
	{
		x = max(matrica, visina, sirina);
		
		sirina = izbaci_kolonu(matrica, visina, sirina, x);
		
		if(sirina >= 1)
		{
			printf("Nakon %d. prolaza matrica glasi:\n", prolaz);
			for(i = 0; i < visina; i++)
			{
				for(j = 0; j < sirina; j++)
				{
					printf("%5d", matrica[i][j]);
				}
				printf("\n");
			}
			printf("\n");
			
			prolaz++;
		}
		
	}while(sirina > 1);
	
	printf("Nakon %d. prolaza matrica je prazna!", prolaz);
	
	return 0;
}

int max(int matrica[][100], int visina, int sirina)
{
	int niz[1000] = {0}, 
		niz2[1000], 
		brojac = 1,
		temp, 
		maxi,
		k = 0,
		i, 
		j;
		
	/* Pretvaranje 2D niza u 1D */
	for(i = 0; i < visina; i++)
    {
        for(j = 0; j < sirina; j++)
        {
            niz[k] = matrica[i][j];
            k++;
        }
    }
    
    /* Bubble sort */
    for(j = 0; j < k - 1; j++)
    {
        for(i = 0; i < k - j - 1; i++)
        {
            if(niz[i] > niz[i+1])
            {
                temp = niz[i];
                niz[i] = niz[i+1];
                niz[i+1] = temp;
            }
        }
    }
    
    /* Brojanje ponavljanje razlicitih elemenata na princip iz 2. zadatka iz zadace 2 */
		
	j = 0;
	
	for(i = 0; i < k; i++)
	{
		if(niz[i] == niz[i+1]) brojac++;
		else
		{
			
			niz2[j] = niz[i];
			niz2[j + 1] = brojac;
			brojac = 1;
	       	j = j + 2;
		}
	}
	
	
	/* Pretraga broja koji se najvise puta ponavlja */
	maxi = 1;
	
	for(i = 3; i < j; i = i + 2)
	{
		if(niz2[i] > niz2[maxi])
		{
			temp = i;
			i = maxi;
			maxi = temp;
		}
	}
	
	return niz2[maxi - 1];
}

int izbaci_kolonu(int matrica[][100], int visina, int sirina, int x)
{
	int i, j, k, l;
	
    for(j = 0; j < sirina; j++)
	{
		for(i = 0; i < visina; i++)
		{
			if(matrica[i][j] == x)
			{
				for(k = 0; k < visina; k++)
				{
					for(l = j; l < sirina; l++)
					{
					    matrica[k][l] = matrica[k][l+1];
					}
				}
					
				sirina--;
			}
		}
	}
		
	
	
	return sirina;
}
