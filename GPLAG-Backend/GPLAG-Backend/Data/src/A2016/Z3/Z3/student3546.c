#include <stdio.h>

int main() {
	int m,n,i,j,k,l;
	int isti=1;
	int matrica[200][200];
	do
	{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m, &n);
		if(m<=0 || n<=0 || m>200 || n>200)
			printf("Brojevi nisu u trazenom opsegu.\n");
	} while(m<=0 || n<=0 || m>200 || n>200);
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d", &matrica[i][j]);
	//Izbacivanje redova
	for(i=0;i<m-1;i++)
	{
		for(j=i+1;j<m;j++)
		{
			isti = 1;
			for(k=0;k<n;k++)
			{
				if(matrica[i][k]!=matrica[j][k])
				{
					isti = 0;
					break;
				}
			}
			if(isti)
			{
				for(l=j;l<m-1;l++)
					for(k=0;k<n;k++)
						matrica[l][k]=matrica[l+1][k];
				j--;
				m--;
			}
		}
	}
	// Izbacivanje kolona
	isti = 1;
	for(j=0;j<n-1;j++)
	{
		for(k=j+1;k<n;k++)		
		{
			isti=1;
			for(i=0;i<m;i++)
			{
				if(matrica[i][j]!=matrica[i][k])
				{
					isti = 0;
					break;
				}
			}
			if(isti)
			{
				for(l=k;l<n-1;l++)
					for(i=0;i<m;i++)
						matrica[i][l]=matrica[i][l+1];
				k--;
				n--;
			}
		}
	}
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			printf("%5d", matrica[i][j]);
		printf("\n");
	}
	return 0;
}
