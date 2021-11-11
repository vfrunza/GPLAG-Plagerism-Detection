#include <stdio.h>

int main() {
	
	int m,n,i,j,mat[200][200],k,l,pomkolona,pomred,prekid=0;
	
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m, &n);
		if(m>0 && m<=200 && n>0 && n<=200) break;
		else printf("Brojevi nisu u trazenom opsegu.\n");
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
		for(k=i+1;k<m;k++)
		{
			prekid=1;
			for(j=0;j<n;j++)
			if(mat[i][j]!=mat[k][j])
			{
				prekid=0;
				break;
			}
			if(prekid)
			{
				for(pomred=k;pomred<m-1;pomred++)
				{
					for(pomkolona=0;pomkolona<n;pomkolona++)
					{
						mat[pomred][pomkolona]=mat[pomred+1][pomkolona];
					}
					}
					m--;
					k--;
				}
			}
	}
	for(j=0;j<n;j++)
	{
		for(l=j+1;l<n;l++)
		{
				prekid=1;
				for(i=0;i<m;i++)
				{
					if(mat[i][j]!=mat[i][l])
					{
						prekid=0;
					    break;
						
					}
				}
				if(prekid)
				{
					for(pomkolona=l;pomkolona<n-1;pomkolona++)
					{
						for(pomred=0;pomred<m;pomred++)
						{
							mat[pomred][pomkolona]=mat[pomred][pomkolona+1];
						}
					}
					n--;
					l--;
				}
			}
		}
					
				
	
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	
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
