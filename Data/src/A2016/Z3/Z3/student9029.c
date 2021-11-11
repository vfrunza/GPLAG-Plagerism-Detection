#include <stdio.h>


int main() {
	
	int M=0, N=0, i, j, matrica[200][200], isti=0, k, a,b;
	
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
		if(M>200 || N>200 || N<=0 || M<=0)
			printf("Brojevi nisu u trazenom opsegu.\n");
	} while(M>200 || N>200 || N<=0 || M<=0);
	
	printf("Unesite elemente matrice: ");
	
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d", &matrica[i][j]);
		}
	}
	
	for(i=0;i<M;i++){
		for(k=i+1;k<M;k++){
			isti=0;
			for(j=0;j<N;j++){
				if(matrica[i][j]==matrica[k][j]) isti++;
			}
			if(isti==N){
				for(a=k;a<M;a++){
					for(b=0;b<N;b++){
						
						matrica[a][b]=matrica[a+1][b];
						
					}
				}
				M--;
				k--;
			}
		
		}
	}
  

    for(j=0;j<N;j++){
    	for(k=j+1;k<N;k++){
    		isti=0;
    		for(i=0;i<M;i++){
    			if(matrica[i][j]==matrica[i][k])isti++;
    		}
    		if(isti==M){
    			for(b=k;b<N;b++){
    				for(a=0;a<M;a++){
    					matrica[a][b]=matrica[a][b+1];
    				}
    			}
    			N--;
    			k--;
    		}
    	}
    }
    
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			if(j+1==N){printf("%5d\n", matrica[i][j]); break;}
			printf("%5d", matrica[i][j]);
		}
	}

	return 0;
}
