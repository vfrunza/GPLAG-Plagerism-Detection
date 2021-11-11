#include <stdio.h>

int main() {
	int M,N,i,j,r,f,elementi_isti=1,mat[200][200];
    do {
    	printf("\nUnesite brojeve M i N: ");
    	scanf("%d %d",&M,&N);
    	if(M<=0 || M>200 || N<=0 || N>200) {
    		printf("Brojevi nisu u trazenom opsegu.");
    	}
    } while (M<=0 || M>200 || N<=0 || N>200);
    
    printf("Unesite elemente matrice: ");
    for(i=0; i<M; i++) {
    	for(j=0; j<N; j++) {
    	    scanf("%d",&mat[i][j]);
    	}
    }

    for(r=1; r<M; r++) {
        for(i=0; i<r; i++) {
            elementi_isti=1;
            /*Ako clanovi matrice u redovima nisu isti, zavrsava se petlja*/
            for(j=0; j<N; j++) {
                if(mat[i][j]!=mat[r][j]) {
                    elementi_isti=0;
                    break;
                }
            }
            /*Ako su clanovi matrice u redovima isti, ti se redovi izbacuju*/
            if(elementi_isti==1) {
                for(f=r; f<M-1; f++) {
                    for(j=0; j<N; j++) {
                        mat[f][j]=mat[f+1][j];
                    }
                }
                M--;
                r--;
            } 
        }
    }
    for(j=1; j<N; j++) {
       for(i=0; i<j; i++) {
           elementi_isti=1;
           /*Ako clanovi matrice u kolonama nisu isti, prekidamo petlju*/
           for(r=0; r<M; r++) {
               if(mat[r][j]!=mat[r][i]) {
                   elementi_isti=0;
                   break;
               }
           }
           /*Ako su clanovi matrice u kolonama isti, te kolone se izbacuju*/
           if(elementi_isti==1) {
               for(f=j; f<N; f++) {
                   for(r=0; r<M; r++) {
                       mat[r][f]=mat[r][f+1];
                   }
               }
               N--;
               j--;
           }
       }
   }
   printf("Nakon izbacivanja redova/kolona matrica glasi: ");
   printf("\n");
   for(i=0; i<M; i++) {
       for(j=0; j<N; j++) {
           printf("%5d",mat[i][j]);
       }
       printf("\n");
   }
        
	return 0;
}
