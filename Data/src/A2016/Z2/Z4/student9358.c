#include <stdio.h>
#include <math.h>
#define EPSILON 0.000001

int main() {
	int M,N,i,j;
	double mat[100][100];
	while(1)
	{
		printf("Unesite M i N: ");
		scanf("%d %d",&M,&N);
		if (M>100 || N>100 || N<=0 || M<=0)
		{ 
			printf("Pogresan unos!\n"); continue;
		}
		else break;
	}
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf("%lf",&mat[i][j]);
		}
	}
	
	if(M==1) 
	{	
		printf("Matrica je cirkularna"); 
		return 0;
	}
	
	if(N==1 && M!=1)
	{
		printf("Matrica je Teplicova");
	    return 0;
		
	}

	
	for(i=0;i<M-1;i++)
	{
		for(j=0;j<N-1;j++)
        {   
        	
        	if(fabs(mat[i][j]-mat[i+1][j+1])>EPSILON)
            
        	{
        		printf("Matrica nije ni cirkularna ni Teplicova");
        		return 0;
        	}
        }
	}   
    for(i=0;i<M-1;i++)
    {
    	for(j=0;j<N-1;j++)
    	{
            if ( (fabs(mat[i][j]-mat[i+1][j+1])<EPSILON) && (fabs(mat[i][N-1]-mat[i+1][0])>EPSILON)) 
        	{
        		printf("Matrica je Teplicova"); 
        		return 0;
        	}
    	}
    }
        
    for(i=0;i<M-1;i++)
    {
    	for(j=0;j<N-1;j++)
    	{
			if((fabs(mat[i][j]-mat[i+1][j+1])<EPSILON) && (fabs(mat[i][N-1]-mat[i+1][0])<EPSILON))
        	{
        		printf("Matrica je cirkularna"); 
            	return 0;
        	}
    	}
    }
            
        
	
	return 0;
}
