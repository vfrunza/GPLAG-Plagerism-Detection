#include <stdio.h>

int main() {
	int m,n,i,j,k,l,jednak=1;
	double matrica[200][200]={{0}};
	
	do
	{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m, &n);
		if(m<=0 || n<=0 || m>200 ||n>200)
			printf("Brojevi nisu u trazenom opsegu.\n");
	}
	while(m<=0 || n<=0 || m>200 || n>200);
	
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++)
		for(j=0; j<n; j++)
			scanf("%lf", &matrica[i][j]);
			
	/**izbacivanje redova*/
	for(i=0; i<m - 1; i++)
	{
		for(j=i + 1; j<m; j++)
		{
			jednak=1;
			for(k=0;k<n;k++)
			{
				if(matrica[i][k] != matrica[j][k])
				{
					jednak=0;
					break;
				}
			}
			if(jednak)
			{
				for(k=j; k<m - 1; k++)
					for(l=0; l<n; l++)
						matrica[k][l]=matrica[k+ 1][l];
				m--;
				j--;
			}
		}
	}
	/**Izbacivanje kolona*/
	for(i=0; i<n- 1;i++)
	{
		for(j=i+ 1; j<n; j++)
		{
			jednak=1;
			for(k=0;k<m;k++)
			{
				if(matrica[k][i] !=matrica[k][j])
				{
					jednak=0;
					break;
				}
			}
			if(jednak)
			{
				for(k=j; k< n - 1; k++)
					for(l=0; l<m; l++)
						matrica[l][k]=matrica[l][k+1];
				n--;
				j--;
			}
		}
	}
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			printf("%5g", matrica[i][j]);
			printf("\n");
	}
	
	return 0;
}
