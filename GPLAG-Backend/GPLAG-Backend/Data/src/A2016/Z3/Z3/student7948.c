#include <stdio.h>
#define vel 200
int main() {
    // Unos
	int i,j,k,l,p,M,N,red,kol,mat[vel][vel];
	do {
	    printf("Unesite brojeve M i N: ");
	    scanf("%d %d", &M, &N);
	    if(M<=0 || M>vel || N<=0 || N>vel){
	        printf("Brojevi nisu u trazenom opsegu. \n");
	    }
	}while(M<=0 || M>vel || N<=0 || N>vel);
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++){
	    for(j=0; j<N; j++){
	        scanf("%d", &mat[i][j]);
	    }
	}
	// Obrada podatak
// Izbacivanje redova
	for(i=0; i<M; i++){
	    for(k=i+1; k<M; k++){
	        red=0;
	        for(j=0; j<N; j++){
                if(mat[i][j]==mat[k][j]){
                    red=1;
                }
                else{
                    red=0;
                    break;
                    
                }
            }
            if(red==1){
	           for(l=k; l<M; l++){
	               for(p=0; p<N; p++){
	                   if(l+1!=M){
	                     mat[l][p]=mat[l+1][p];
	                   }
	               }
	           }
	           M--;
	           i--;
	           break;
	        }
        }
	}
// Izbacivanje kolona	
	for(i=0; i<N; i++){
	    for(j=i+1; j<N; j++){
	        kol=0;
	        for(k=0; k<M; k++){
	            if(mat[k][i]==mat[k][j]){
	                kol=1;
	            }
	            else{
	                kol=0;
	                break;
	            }
	        }
	        if(kol==1){
	           for(l=j; l<N; l++){
	               for(p=0; p<M; p++){
	                   if(l+1!=N){
	                     mat[p][l]=mat[p][l+1];
	                   }
	               }
	           }
	           N--;
	           j--;
	        
	        }
	    }
	}
	// Ispis
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0; i<M; i++){
	    for(j=0; j<N; j++){
	        printf("%5d", mat[i][j]);
	    }
	    printf("\n");
	}
	return 0;
}
