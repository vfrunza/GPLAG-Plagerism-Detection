#include <stdio.h>

int main() 
{
	short m, n, i, j, k, ix, kx, buul;
	short mat[200][200];
	do
	{
		printf("Unesite brojeve M i N: ");
		scanf("%hd %hd", &m, &n);
		if(m <= 0 || m > 200 || n <= 0 || n > 200)
		  printf("Brojevi nisu u trazenom opsegu.\n");
		  
	}while(m <= 0 || m > 200 || n <= 0 || n > 200);
	
	printf("Unesite elemente matrice: ");
	for(i = 0; i < m; i++)
	{
		for(k = 0; k < n; k++)
		{
			scanf("%hd", &mat[i][k]);
		}
	}
	
	for(i = 0; i < m - 1; i++)
	{
		for(j = i + 1; j < m; j++)
		{
			buul = 1;
			for(k = 0; k < n; k++)
			{	
				if(mat[i][k] != mat[j][k])
				{
					buul = 0;
					break;
				}
			}
			if(buul == 1)
			{
				for(ix = j; ix < m - 1; ix++)
				{
					for(kx = 0; kx < n; kx++)
					{
						mat[ix][kx] = mat[ix + 1][kx];
					}
				}
				j--;
				m--;
			}
		}
	}
	

	for(i = 0; i < n - 1; i++)
	{
		for(j = i + 1; j < n; j++)
		{
			buul = 1;
			for(k = 0; k < m; k++)
			{	
				if(mat[k][i] != mat[k][j])
				{
					buul = 0;
					break;
				}
			}
			if(buul == 1)
			{
				for(ix = j; ix < n - 1; ix++)
				{
					for(kx = 0; kx < m; kx++)
					{
						mat[kx][ix] = mat[kx][ix + 1];
					}
				}
				j--;
				n--;
			}
		}
	}
	
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i = 0; i < m; i++)
	{
		for(k = 0; k < n; k++)
		{
			if(mat[i][k] >= 10 || mat[i][k] < 0)
			  printf("   %d", mat[i][k]);
			else
			  printf("    %d", mat[i][k]);
		}
		printf("\n");
	}
	return 0;
}
