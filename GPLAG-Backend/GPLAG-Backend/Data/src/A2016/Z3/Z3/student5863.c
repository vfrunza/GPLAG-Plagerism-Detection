#include <stdio.h>
#include <stdlib.h>


int main() {
	int niz1[20],niz2[20],niz3[20],niz4[20];
	int m,n;
	int mat[100][100];
	int i,j,br=0,br2=0;
	do{
	printf("Unesite brojeve M i N: ");
	scanf("%d %d",&m,&n);
	if(m<=0 || m>=200 || n<=0 || n>=200 ) 
	printf("Brojevi nisu u trazenom opsegu.\n");
	}
	while(m<=0 || m>=200 || n<=0 || n>=200);
	
	
	printf("Unesite elemente matrice: ");
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&mat[i][j]);
		}
	}
	
	
	for(i=0;i<m;i++) {niz3[i]=0;}
	for(i=0;i<m;i++) {niz4[i]=0;}
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			niz3[0]=mat[0][j];
			
		}
	}
	
	for(i=1;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			niz4[i]=mat[i][j];
			
			
			if(niz3[0]==niz4[i])
			{
				
				mat[i][j]=mat[i+1][j];
				br2++;
			}
		}
		niz4[i]=0;
	}
	
	for(i=0;i<m;i++) {niz1[i]=0; niz1[0]=0;}
	for(i=0;i<m;i++) {niz2[i]=0; niz2[0]=0;}
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			niz1[i]=mat[i][0];
		}
	}
	
	for(i=0;i<m;i++)
	{
		for(j=1;j<n;j++)
		{
			niz2[i]=mat[i][j];
			
			if(niz1[0]==niz2[i])
			
			{
				mat[i][j]=mat[i][j+1];
				br++;
				
				
			}
		
		}
		niz2[i]=0;
	}
	
	
	
	
	
	
	

	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0;i<m-br2;i++)
	{
		for(j=0;j<n-br;j++)
		{
			printf("%5d",mat[i][j]);
	
		}
		printf("\n");
	}
	
	return 0;
}
