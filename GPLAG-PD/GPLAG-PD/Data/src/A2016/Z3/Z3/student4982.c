#include <stdio.h>

int main() {
	
	int i,j,k,l,m,n,p,mat[200][200];
	do{
	printf("Unesite brojeve M i N: ");
	scanf("%d %d",&m,&n);
	if(m<=0 || m>200 || n<=0 || n>200) printf("Brojevi nisu u trazenom opsegu.\n");
	
	
	} while(m<=0 || m>200 || n<=0 || n>200);
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&mat[i][j]);
		}
	}
	
	for(i=0;i<m;i++)
	{
		for(j=i+1;j<m;j++)
		{
			for(k=0;k<n;k++)
			{
				if(mat[j][k]!=mat[i][k]) break;
				if(k==n-1)
				{ 
					for(l=j;l<m-1;l++)
					{
						for(p=0;p<n;p++) {
						mat[l][p]=mat[l+1][p];
						}
					}
					m--; j--; 
				}
			}
			
		}
	}
	
	for(j=0;j<n;j++)
	{
		for(k=j+1;k<n;k++)
		{
		for(i=0;i<m;i++)
		{
		if(mat[i][k]!=mat[i][j]) break;
		if(i==m-1)
		{
			for(l=k;l<n-1;l++)
			{
				for(p=0;p<m;p++)
				{
					mat[p][l]=mat[p][l+1];
				}
			}
			n--; k--; break;
		}
		
		}
		
		}
	}
	
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%5d",mat[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
