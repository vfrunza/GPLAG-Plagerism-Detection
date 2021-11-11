#include <stdio.h>

int main() {
    int mat[200][200];
    int M,N,i,j,k,l,m,isti_redovi,iste_kolone;
    
    /* Unos opsega matrice */
    do
    {
    printf("\nUnesite brojeve M i N: ");
    scanf("%d %d",&M,&N);
    if (M<=0 || M>200 || N<=0 || N>200) printf("Brojevi nisu u trazenom opsegu.");
    }while(M<=0 || M>200 || N<=0 || N>200);
    printf("Unesite elemente matrice: ");
    for(i=1;i<=M;i++){
    	for(j=1;j<=N;j++){
    		scanf("%d",&mat[i][j]);
    	}
    }
    
    /* Izbacivanje istih reodva matrice */
    for(k=1;k<=M;k++){
    	for(i=k+1;i<=M;i++){    	
    		isti_redovi=1; 
    		for(j=1;j<=N;j++){
    				if(mat[k][j]!=mat[i][j]) 
    				isti_redovi=0;
    		}
    		if (isti_redovi==1){
    				for(l=i;l<=M;l++){
    					for(j=1;j<=N;j++){
   						mat[l][j]=mat[l+1][j]; 
    					}
    				}
    			M--;
    			i--;
    		}
    	}
    }
    
    /* Izbacivanje istih kolona */
    for(m=1;m<=N;m++){
        for(j=m+1;j<=N;j++){
            iste_kolone=1;  
            for(i=1;i<=M;i++){
                if (mat[i][m]!=mat[i][j]) iste_kolone=0;
            }
            if(iste_kolone==1){
               for(i=1;i<=M;i++){
                  for(l=j;l<=N;l++){
                     mat[i][l]=mat[i][l+1]; 
                 }
             }
             N--;
             j--;
            }
        }
    }
    
    /* Ispis matrice */
    printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
    for(i=1;i<=M;i++){
    	for(j=1;j<=N;j++){
    		printf("%5d",mat[i][j]);
    	}
    	printf("\n");
    }
   	return 0;
}
 