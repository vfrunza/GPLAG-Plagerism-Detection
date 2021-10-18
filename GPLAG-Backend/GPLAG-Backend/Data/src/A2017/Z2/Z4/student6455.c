#include <stdio.h>

int main() {
	
   int matA[100][100],nizA[i*k],matB[100][100],matC[100][100],i,j,M,N;
	do{
		printf("Unesite brojeve M i N: \n");
		scanf("%d %d", &M, &N);
		
		
	} while((M>0 && M<100) && (N>0 && N>100));
	
    printf("Unesite clanove matrice A: \n");
    for(i=0;i<M;i++){
    for(j=0;j<N;j++){
    	
    	scanf("%d", matA[i][j]);
    	
    }
    }
    printf("Unesite clanove matrice B: \n");
    for(i=0;i<M;i++)
    {
    	for(j=0;j<N;j++)
    	{
    		
    		scanf("%d", matB[i][j]);
    	}
    }
    
    printf("Unesite clanove matrice C: \n");
    for(i=0;i<M;i++){
    	for(j=0;j<N;j++){
    		scanf("%d", matC[i][j]);
    	}
    }
    
	return 0;
}
