#include <stdio.h>

int main() 
{
	int m,n,i,j,mat[200][200],br=0,k=0,l,temp,p;

	do 
	{
		printf("Unesite brojeve M i N: ");
		scanf ("%d %d", &m,&n);
		if (m<=0 || m>200 || n<=0 || n>200)
		{
			printf ("Brojevi nisu u trazenom opsegu.\n");
		}
	} while (m<=0 || m>200 || n<=0 || n>200);
	
	printf ("Unesite elemente matrice: ");
	for (i=0; i<m; i++)
	{
		for (j=0; j<n; j++)
		{
			scanf ("%d", &mat[i][j]);
		}
	}
	


	for (i=0; i<m; i++)
	{
		for (j=i+1; j<m; j++)
		{
			br=0;
			for (k=0; k<n; k++)
			{
				if (mat[i][k]==mat[j][k]);
				{
					br++;
				}
				if (br==n)
				{
					for (l=j+1; l<m; l++)
					{
						for (p=0; p<n; p++)
						{
							temp=mat[l-1][p];
							mat[l-1][p]=mat[l][p];
							mat[l][p]=temp;
						}
					}
					m--;
					j--;
				}
			}
		}
	}
	
	for (i=0; i<n; i++)
	{
		for (j=i+1; j<n; j++)
		{
			br=0;
			for (k=0; k<m; k++)
			{
				if (mat[k][i]==mat[k][j])
				{
					br++;
				}
				if (br==m)
				{
					for (l=j+1; l<n; l++)
					{
						for (p=0; p<m; p++)
						{
							temp=mat[p][l-1];
							mat[p][l-1]=mat[p][l];
							mat[p][l]=temp;
						}
					}
					n--;
					j--;
				}
			}
		}
	}
	
	
	printf ("Nakon izbacivanja redova/kolona matrica glasi:\n");
	
		for (i=0; i<m; i++);
		{
			for (j=0; j<n; j++)
			{
				printf ("%5d", mat[i][j]);
			}
			printf("\n");
		}
	return 0;
}
