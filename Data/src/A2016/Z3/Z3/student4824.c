#include <stdio.h>

int main() {
	int m,n,i,j,z;
	int r=0,q=0,s=0,mat[200][200]={{0}};
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&m,&n);
		if((m<=0) || (m>200) || (n<=0) || (n>200))
		{
			printf("Brojevi nisu u trazenom opsegu.\n");
			
		}
		
	}while((m<=0)|| (m>200) || (n<=0) || (n>200));
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d ",&mat[i][j]);
			
		}
		
	}
	/* Ponovljene redove/vrste izbacujemo*/ 
	for(z=0;z<(m-1);z++)
	{
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(z==(i+1));
				else if(mat[z][j]==mat[i+1][j])
				r=1;
				else
				{
					r=0;
					break;
					
				}
				
			} 
			/*Pomijeramo preostale redove/vrste*/
			if(r==1)
			{
				for(q=i;q<(m-2);q++)
				{
					for(s=0;s<n;s++)
					{
						mat[q+1][s]=mat[q+2][s];
					}
					
				}
				m--;
				
			}
			
		}
		
	}
	/*Ponovljene kolone izbacujemo */ 
	for (z=0;z<(n-1);z++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(z==(i+1));
				else if(mat[j][z]==mat[j][i+1])
				r=1;
				else 
				{
					r=0;
					break;
					
				}
				
			} 
			/* Pomijeramo preostale kolone */ 
			if(r==1)
			{
				for(q=0;q<m;q++)
				{
					for(s=i;s<(n-2);s++)
					{
						mat[q][s+1]=mat[q][s+2];
						
					}
					
				}
				n--;
				
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
