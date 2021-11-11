#include <stdio.h>
#include <math.h>


int main()
{
	int m,n,nizB[200][200],i,j,l;
	
	int brojac,k;
	
	do
	{
		printf("Unesite brojeve M i N: ");
		
		scanf("%d %d",&m, &n);
		
		if(m <= 0 || m >= 200 || n <= 0 || n >= 200)
			
			printf("Brojevi nisu u trazenom opsegu.\n");
	
		}
	
	while((m <= 0 || m >= 200) || (n <= 0 || n >= 200));
		
	printf("Unesite elemente matrice: ");
	
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			scanf("%d", &nizB[i][j]);
		}
	}
	
for(k = 0; k < m-1; k++)
{
	for(i = k+1;i < m; i++)
	{
		brojac = 0;
			
			for(j = 0; j < n; j++)
			{
				if(nizB[k][j] == nizB[i][j])
				{
					brojac++;
				}
				
				else if(nizB[k][j] != nizB[i][j])
					break;
			}
			if(brojac == n)
			{
				for(l = i; l < m-1; l++)
				{
					for(j=0; j < n; j++)
					{
						nizB[l][j]= nizB[l+1][j];
					}
				}
				m--;
				i--;
			}
	}
}



for(k = 0; k < n-1; k++)
{
	for(i = k+1; i < n; i++)
	{	
		brojac = 0;
		for(j = 0; j < m; j++)
		{
			if(nizB[j][k] == nizB[j][i])
			{
				brojac++;
			}
			else if(nizB[j][k] != nizB[j][i])
				break;
		}
		
		if(brojac == m)
		{
			for(j =0; j < m; j++)
			{
				for(l = i; l < n-1; l++)
				{
					nizB[j][l] = nizB[j][l+1];
				}
			}
			i--;
			n--;
		}
	}
}
printf("Nakon izbacivanja redova/kolona matrica glasi:\n");

for(i = 0; i < m; i++)
{
	for(j = 0; j < n; j++)
	{
		printf("%5d", nizB[i][j]);
	}
	printf("\n");
}
return 0;
}