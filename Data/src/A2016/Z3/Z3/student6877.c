#include <stdio.h>

int main() {
    int mat[200][200];
    int M,N,i,j,k,l,iste,m;
    do
    {
    printf("\nUnesite brojeve M i N: ");
    scanf("%d %d",&M,&N);
    if (M<=0 || M>200 || N<=0 || N>200) printf("Brojevi nisu u trazenom opsegu.");
    }while(M<=0 || M>200 || N<=0 || N>200);
    printf("Unesite elemente matrice: ");
    for(i=1;i<=M;i++)
    {
    	for(j=1;j<=N;j++)
    	{
    		scanf("%d",&mat[i][j]);
    	}
    }
    
    for(k=1;k<=M;k++)
    {
    	for(i=k+1;i<=M;i++)
    	{
    		iste=1;  //Uslov za jednakost redova
    		for(j=1;j<=N;j++)
    		{
    				if(mat[k][j]!=mat[i][j]) iste=0;
    		}
    		if (iste) 
    		{
    				for(l=i;l<=M;l++)
    				{
    					for(j=1;j<=N;j++)
    					{
    						mat[l][j]=mat[l+1][j]; //Izbacivanje reda uz ocuvanje redoslijeda
    					}
    				}
    			M--;
    			i--;
    		}
    	}
    }
    for(m=1;m<=N;m++)
    {
        for(j=m+1;j<=N;j++)
        {
            iste=1;  //Uslov za jednakost kolona
            for(i=1;i<=M;i++)
            {
                if (mat[i][m]!=mat[i][j]) iste=0;
            }
            if(iste)
            {
             for(i=1;i<=M;i++)
             {
                 for(l=j;l<=N;l++)
                 {
                     mat[i][l]=mat[i][l+1]; //Izbacivanje kolone uz ocuvanje redoslijeda
                 }
             }
             N--;
             j--;
            }
        }
    }
    printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
    
    for(i=1;i<=M;i++)
    {
    	for(j=1;j<=N;j++)
    	{
    		printf("%5d",mat[i][j]);
    	}
    	printf("\n");
    }
    
    
    
    
    
  
  
 
	return 0;
}
