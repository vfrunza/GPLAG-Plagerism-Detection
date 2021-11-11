#include <stdio.h>

int main() {
	
	int mat[200][200];
	int k,y,z,pret;
	int m,n,i,j;
	
	pret=1;
	
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&m,&n);
		if(m<1 || n<1 || m>200 || n>200) printf("Brojevi nisu u trazenom opsegu.\n");
	  }while(m<1 || n<1 || m>200 || n>200);
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&mat[i][j]);
  
    for(i=0;i<m;i++)
	{
		for(j=i+1;j<m;j++)
  		{   pret=1;
  			for(k=0;k<n;k++)
  			{
  				if(mat[i][k]!=mat[j][k]) pret=0;
  			}
  			
  			if(pret==1)
  			{
  				for(z=j;z<m-1;z++)
  					{
  					  for(y=0;y<n;y++)
  						mat[z][y]=mat[z+1][y];
  					}
  			    m--;
			    j--;
  			}
  			
  		}
  	
	}
	
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
  		{   pret=1;
  			for(k=0;k<m;k++)
  			{
  				if(mat[k][i]!=mat[k][j]) pret=0;
  			}
  			if(pret==1 )
  			{ 	
  				for(z=j;z<n-1;z++)
  					{
  					  for(y=0;y<m;y++)
  						mat[y][z]=mat[y][z+1];
  					}
  				n--;
  				j--;
  			}
  		}
  	
	}

	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			printf("%5d",mat[i][j]);
		printf("\n");
	}
	
	
	return 0;
}
