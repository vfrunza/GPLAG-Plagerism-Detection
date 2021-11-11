#include <stdio.h>

int main() {
	int matrica[200][200],i,j,M,N,k,l,p,bm,bn,brojac,broj;
	
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
		if (M<1 || M>200 || N>200 || N<1 ) printf("Brojevi nisu u trazenom opsegu.\n");
	} while (M<1 || M>200 || N>200 || N<1 );
	
	printf("Unesite elemente matrice: ");
	for (i=0; i<M; i++){
		for (j=0; j<N; j++){
			scanf("%d", &matrica[i][j]);
		}
	}
	

bm=0;
     	for (i=0; i<M-1; i++){
		   for (j=0; j<N; j++){
		   	for (k=i+1; k<M; k++){
		   		if (matrica[i][j]!=matrica[k][j]) continue;
		   		else { for(l=j+1; l<N; l++) { 
		   			                   
		   			                    if (matrica[i][l]!=matrica[k][l]) {i--; k++; break;}
		   			                    else if (l!=N-1) { continue;}
		   			                    else if (l==N-1) { if(k==M-1) {M--; break;}
		   			                    					else {for (p=l; p>=0; p--) {
		   			                    						matrica[k][p]=matrica[k+1][p]; if(p==0) bm++;
		   			                    					}
		   			                    					}
		   			                    }
		   		
		   	} 
		   		}
		   	} break;
		   } break;
     	}
     	
     	M=M-bm; 
     		if(M==1) {
		i=0; 
		for (j=0; j<N; j++){
			for (k=j+1; k<N; k++){
				if (matrica[i][j]!=matrica[i][k]) continue;
				else { if (k==N-1) {N--; break;}
		                else { broj=k; for(l=N-1; l>=k; l--){
		                	        
		                	       matrica[i][broj]=matrica[i][broj+1];
		                	       if (l==k) {N--; break;}
		                	       broj++; 
		                }		
					
					
			}
		}
	j--; break;}
		} 
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
     	for (i=0; i<M; i++){
     		for (j=0; j<N; j++){
     			printf("%5d", matrica[i][j]);
     		}
     		printf("\n");
     	} return 0;
     		}
     	bn=0;
     	for (j=0; j<N-1; j++){
		   for (i=0; i<M; i++){
		   	for (k=j+1; k<N; k++){
		   		if (matrica[i][j]!=matrica[i][k]) {continue;}
		   		else { for(l=i+1; l<M; l++) {
		   			                   
		   			                    if (matrica[l][j]!=matrica[l][k]) {j--; k++; break;}
		   			                    else if (l!=M-1) { continue;}
		   			                    else if (l==M-1) { if(k==N-1) {N--; break;}
		   			                    					else {for (p=l; p>=0; p--) {
		   			                    						matrica[p][k]=matrica[p][k+1]; if(p==0) bn++;
		   			                    					}
		   			                    					}
		   			                    }
		   		
		   	} 
		   		} 
		   	} break;
		 break;  } 
     	}
     	N=N-bn;
     	
     	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
     	for (i=0; i<M; i++){
     		for (j=0; j<N; j++){
     			printf("%5d", matrica[i][j]);
     		}
     		printf("\n");
     	}
     	
	return 0;
}
