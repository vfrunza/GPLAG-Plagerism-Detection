#include <stdio.h>

int main() {
	int matA[100][100], matB[100][100],matC[100][100];
	int i,j,M,N,brA=1, brB=1, brC=1, k, l;
	
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&M,&N);
	} while(M>100 || N>100);
    
    printf("Unesite clanove matrice A: ");
    for(i=0;i<M;i++){
	    for(j=0;j<N;j++){
			scanf("%d",&matA[i][j]);
	    }
	}
	
    
    printf("Unesite clanove matrice B: ");
    for(i=0;i<M;i++){
	    for(j=0;j<N;j++)
        scanf("%d",&matB[i][j]);
	}
    
    printf("Unesite clanove matrice C: ");
    for(i=0;i<M;i++){
	    for(j=0;j<N;j++)
		scanf("%d",&matC[i][j]);
    }
    
    for(i=0; i<M; i++){
    	for(j=0; j<N; j++){
    		
    		for(k=0; k<M; k++){
    			for(l=0;l<N; l++){
    				if(matA[i][j]==matA[k][l]) brA++;
    			}
    		}
    		
    		for(k=0; k<M; k++){
    			for(l=0;l<N; l++){
    				if(matA[i][j]==matB[k][l]) brB++;
    			}
    		}
    		
    		for(k=0; k<M; k++){
    			for(l=0;l<N; l++){
    				if(matA[i][j]==matC[k][l]) brC++;
    			}
    		}
    		if(brA!=brB || brA!=brC){
    			printf("NE");
    			return 0;
    		}
    	}
    }
    
    printf("DA");
	return 0;
}
