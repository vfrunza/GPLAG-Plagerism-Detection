#include <stdio.h>

int main() 
{
	int m, n, i, j, z, logika = 0, ii, jj;
	int mat[200][200];

	do 											
	{
		printf("Unesite brojeve M i N: ");
		scanf("%d", &m);
		scanf("%d", &n);
		if(m <= 0 || n<=0 || m>200 || n>200) 
		{
			printf("Brojevi nisu u trazenom opsegu.\n"); 
		}
	}
	while(m <= 0 || n<=0 || m>200 || n>200); 	
	
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++) 							
	{
		for(j=0; j<n; j++)
		{
			scanf("%d", &mat[i][j]);
		}
	}
	
	for(i=0; i<m; i++) 						
	{										
		for(j=i+1; j<m; j++)					
		{
			for(z=0; z<n; z++)					
			{
				if(mat[i][z] == mat[j][z]) 		
				{
					logika = 1;				
				}
				else
				{
					logika = 0;					
					break;					
				}
			}
			
			if(logika == 1)						
			{
				for(ii=j; ii<m; ii++)			
				{
					for(jj=0; jj<n; jj++) 		
					{
						mat[ii][jj] = mat[ii+1][jj]; 
					}
				}
				j--; 							
				m--; 							
			}
		}
	}
	
	logika = 0;  								
	for(i=0; i<n; i++) 							
	{											
		for(j=i+1; j<n; j++)					
		{
			for(z=0; z<m; z++)					
			{
				if(mat[z][i] == mat[z][j]) 	
				{
					logika = 1; 				
				}
				else
				{
					logika = 0; 				
					break; 						
				}
			}
			
			if(logika == 1) 				
			{
				for(ii=0; ii<m; ii++) 		
				{
					for(jj=j; jj<n; jj++) 		
					{
						mat[ii][jj] = mat[ii][jj+1]; 
					}
				}
				j--; 							
				n--; 							
			}
		}
	}
	
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0; i<m; i++) 							
	{
		for(j=0; j<n; j++)						
		{
			printf("%5d", mat[i][j]); 		
		}
		printf("\n"); 							
	}
	
	return 0;
}