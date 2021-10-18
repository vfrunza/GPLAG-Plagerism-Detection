#include <stdio.h>

int main() {
	int mat[202][202], m, n, i, j, k, poc, isti;
	do
	{
	    printf("Unesite brojeve M i N: ");
	    scanf("%d %d", &m, &n);
	    if(m<=0 || n<=0 || m>200 || n>200) printf("Brojevi nisu u trazenom opsegu.\n");
	} while(m<=0 || n<=0 || m>200 || n>200);
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d", &mat[i][j]);
		}
	}
	
	for(poc=0;poc<m;poc++)
	{
		for(i=poc+1;i<m;i++)
		{
			isti=1;
			for(j=0;j<n;j++)
			{
				if(mat[poc][j]!=mat[i][j]) isti=0;
			}
			if(isti)
			{
				// izbacivanje istog reda
				
				for(k=i;k<m-1;k++)
				{
					for(j=0;j<n;j++)
					{
						mat[k][j]=mat[k+1][j];
					}
				}
				i--;
				m--;
			}
		}
	}
	
	for(poc=0;poc<n;poc++)
	{
		for(j=poc+1;j<n;j++)
		{
			isti=1;
			for(i=0;i<m;i++)
			{
				if(mat[i][poc]!=mat[i][j]) isti=0;
			}
			if(isti)
			{
				// izbacivanje iste kolone
				
				for(i=0;i<m;i++)
				{
					for(k=j;k<n-1;k++)
					{
						mat[i][k]=mat[i][k+1];
					}
				}
				j--;
				n--;
			}
		}
	}
	
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0;i<m;i++)
	{
		printf(" ");
		for(j=0;j<n;j++)
		{
			printf("%4d ", mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}
