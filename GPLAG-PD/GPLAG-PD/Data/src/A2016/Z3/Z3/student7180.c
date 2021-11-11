#include <stdio.h>

int main() {
	int mat[200][200];
	int m, n, i, j, k;
	int x, y;
	int ostavi=1;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m, &n);
		if(m<=0 || m>200 || n<=0 || n>200)
		printf("Brojevi nisu u trazenom opsegu.\n");
	} while (m<=0 || m>200 || n<=0 || n>200);
	
	printf("Unesite elemente matrice: ");
	i=0;
	while(i<m)
	{
		j=0;
		while(j<n)
		{
			scanf("%d", &mat[i][j]);
			j++;
		}
		i++;
	}

	for(i=0; i<m-1; i++)
	{
		for(j=i+1; j<m; j++)
		{	ostavi=1;
			for(k=0; k<n; k++)
			{ 	
				if(mat[i][k]!=mat[j][k]) 
				ostavi=0;
			}
			if(ostavi==1)
			{
				x=j;
				while(x<m-1)
				{
					y=0;
					while(y<n)
					{
						mat[x][y]=mat[x+1][y];
						y++;
					}
					x++;
				}
				m--;
				j--;
			}
		}
	}
	
	for(i=0; i<n-1; i++)
	{
		for(j=i+1; j<n; j++)
		{	ostavi=1;
			for(k=0; k<m; k++)
			{ 	
				if(mat[k][i]!=mat[k][j]) 
				ostavi=0;
			}
			if(ostavi==1)
			{
				x=j;
				while(x<n-1)
				{
					y=0;
					while(y<m)
					{
						mat[y][x]=mat[y][x+1];
						y++;
					}
					x++;
				}
				n--;
				j--;
			}
		}
	}
	
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	i=0;
	while(i<m)
	{
		j=0;
		while(j<n)
		{
			printf("%5d", mat[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}

	return 0;
}
