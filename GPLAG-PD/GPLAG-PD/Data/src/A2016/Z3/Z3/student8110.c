#include <stdio.h>
int main () {
	int mat[201][201],M,N,i=0,j=0,k=0,l=0,istired=1,istakolona=1;
	do {
	    printf("Unesite brojeve M i N: ");
	    scanf("%d %d",&M,&N);
	    if(M<=0 || N<=0 || M>200 || N>200) {
	    	printf("Brojevi nisu u trazenom opsegu.\n");
	    }
	} while(M<=0 || N<=0 || M>200 || N>200);
	
    /*Unos elemenata matrice*/	
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++) {
        for(j=0;j<N;j++) {
            scanf("%2d", &mat[i][j]);
        }
    }
    
    /*Ispitivanje redova matrice*/
    for(k=0;k<M-1;k++) {
    	for(i=k+1;i<M;i++) {
    		for(j=0;j<N;j++) {
    			if(mat[k][j]!=mat[i][j]) { 
    			    istired=0; 
    			    break;
    			} 
    			else {
    				istired=1;
    			}
    		} 
            if (istired==1) {
                for(j=0;j<N;j++) {
                    for(l=i;l<M-1;l++) {
                        mat[l][j]=mat[l+1][j]; 
                    }
                }
                M--;
                i--;
            }
        } 
    }
    
    /*Ispitivanje kolona matrice*/
    for(k=0;k<N-1;k++) {
        for(i=k+1;i<N;i++) {
    	    for(j=0;j<M;j++) {
    		    if(mat[j][k]!=mat[j][i]) {
    		        istakolona=0;
    				break; 
    		    }
    			else {
    			    istakolona=1;
    			}
    		} 
            if (istakolona==1) {
                for(l=i;l<N-1;l++) {
                    for(k=0;k<M;k++) {
    	                mat[k][l]=mat[k][l+1];
                    } 
                    k--;
                } 
                N--; 
                i--;
            }
    	}
    }
    
    /*Ispisivanje matrice*/
    printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
    for (i=0; i<M; i++) {
    	for (j=0; j<N; j++) {
			printf("%5d", mat[i][j]); 
    	}
		printf("\n");
    }
    return 0;
} 