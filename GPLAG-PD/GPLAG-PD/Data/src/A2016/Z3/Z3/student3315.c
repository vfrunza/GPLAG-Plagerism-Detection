#include <stdio.h>

int main() {
	int M,N,i,j,m=0,t,s;
	int brojac=0,broj;
	int mat[200][200];
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&M,&N);
		if(M<1 || N<1 || M>200 || N>200) {
			printf("Brojevi nisu u trazenom opsegu.\n");
		}
		else
		break;
	}
	while(5);

  /* Unosenje matrice */	
   printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++) {
		for(j=0;j<N;j++){
		scanf("%d",&mat[i][j]);
	}
    }
    
    for(i=0;i<M;i++) {
    	for(j=i+1;j<M;j++) {
    		brojac=0;
    		for(m=0;m<N;m++) {
    			if(mat[i][m]==mat[j][m]) {
    				brojac++;
    			}
    			if(brojac==N) {
    				for(t=j+1;t<M;t++){
    					for(s=0;s<N;s++){
    						broj=mat[t-1][s];
    						
    						mat[t-1][s]=mat[t][s];
    						mat[t][s]=broj;
    					}
    				}
    				M--;
    				j--;
    			}
    		}
    	}
    }
    for(i=0;i<N;i++){
    	for(j=i+1;j<N;j++){
    		brojac=0;
    		
    		for(m=0;m<M;m++) {
    			if(mat[m][i]==mat[m][j]){
    				brojac++;
    			}
    			if(brojac==M) {
    				for(t=j+1;t<N;t++){
    					for(s=0;s<M;s++) {
    						broj=mat[s][t-1];
    						
    						mat[s][t-1]=mat[s][t];
    						mat[s][t]=broj;
    					}
    				}
    				N--;
    				j--;
    			}
    		}
    	}
    }
    
    printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
    for(i=0;i<M;i++) {
    	for(j=0;j<N;j++) {
    		printf("%5d",mat[i][j]);
    	}
    	printf("\n");
    }
    return 0;
    }