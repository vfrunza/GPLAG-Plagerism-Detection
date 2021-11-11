#include <stdio.h>
#define BROJ_REDOVA 200
#define BROJ_KOLONA 200


void modify(matrica[][],M,N) {
	
	int a=0;
	
  for(a=0; a<M; a++){
       for(i=0; i<M; i++){
	     	for(j=0; j<N; j++){
		    	if(matrica[a][j] != matrica[i+1][j])
			    {
			    	break;
			    }
			    else if(j==N-1){
				
				        for(k=0; k<N; k++){
					    matrica[i][k]=matrica[M-1][k];
				   }
			      	M--;
			    }
			}
		}
	}
}


int main() {
	
	int M,N,i,j,matrica[BROJ_REDOVA][BROJ_KOLONA];
	
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&M, &N);
		if(M<1 || M>200 || N<1 || N>200)
		{
			printf("Brojevi nisu u trazenom opsegu.\n");
		}
	}while(M<1 || M>200 || N<1 || N>200);
    
    printf("Unesite elemente matrice: \n");
	for(i=0; i<BROJ_REDOVA; i++){
		for(j=0; j<BROJ_KOLONA; j++ ){
			scanf("%d ", &matrica[i][j]);
		}
		printf("\n");
	}	
     
    modify(matrica,M,N);
     
	return 0;
}
