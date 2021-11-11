#include <stdio.h>

int main() 
{
	int m,n,mat[200][200],i,j,k,isti,l;
	do
	{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&m,&n);
		if(m>200 || n>200 ||n<1 || m<1)
		{
			printf("Brojevi nisu u trazenom opsegu.\n");
		}
	} while(m>200 || m<1 || n<1 ||n>200);
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&mat[i][j]);
		}
	}
	
	for(k=0;k<m-1;k++)
	{
		for(i=k+1;i<m;i++)
		{
			isti=1;
			for(j=0;j<n;j++)
			{
				if(mat[k][j] != mat[i][j])
				{
					isti = 0;
				}
			}
			if(isti == 1)
			{
				for(l=i;l<m-1;l++)
				{
					for(j=0;j<n;j++)
					{
						mat[l][j] = mat[l+1][j];
					}
				}
				m--;
				i--;
			}
		}
	
	}
	
	for(k=0;k<n-1;k++)
	{
		for(i=k+1;i<n;i++)
		{
			isti=1;
			for(j=0;j<m;j++)
			{
				if(mat[j][k] != mat[j][i])
				{
					isti = 0;
				}
			}
			if(isti == 1)
			{
				for(l=i;l<n-1;l++)
				{
					for(j=0;j<m;j++) mat[j][l] = mat[j][l+1];
				}
				n--;
				i--;
			}
				
			
		}
	}
	
	
	
	
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0;i<m;i++)
	{
		printf(" ");
		for(j=0;j<n;j++)
		{
			printf("%4d ",mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}
