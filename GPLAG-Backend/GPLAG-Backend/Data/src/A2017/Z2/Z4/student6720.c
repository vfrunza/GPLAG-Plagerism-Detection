#include <stdio.h>
#include <stdlib.h>

int main() {
    int M, N, i, j, da=1;
    int A[100][100], B[100][100], C[100][100];
    int brojacA[1000]={0}, brojacB[1000]={0}, brojacC[1000]={0}, nbrojacA[1000]={0}, nbrojacB[1000]={0}, nbrojacC[1000]={0};
    
    do{
	    printf("Unesite brojeve M i N: ");
	    scanf("%d %d", &M, &N);
    }while(M<0 || M>100 || N<0 || N>100);
    printf("Unesite clanove matrice A: ");
    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            scanf("%d", &A[i][j]);    
        }
    }
    printf("Unesite clanove matrice B: ");
    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            scanf("%d", &B[i][j]);    
        }
    }
    printf("Unesite clanove matrice C: ");
    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            scanf("%d", &C[i][j]);    
        }
    }
    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            if(A[i][j]>=0) brojacA[A[i][j]]++;
            else if(A[i][j]<0) nbrojacA[abs(A[i][j])]++;
        }
    }
    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            if(B[i][j]>=0) brojacB[B[i][j]]++;
            else if(B[i][j]<0) nbrojacB[abs(B[i][j])]++;
        }
    }
    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            if(C[i][j]>=0) brojacC[C[i][j]]++;
            else if(C[i][j]<0) nbrojacC[abs(C[i][j])]++;
        }
    }
    for(i=0; i<101; i++){
        if(brojacA[i]!=0){
            if(brojacA[i]!=brojacB[i] || brojacA[i]!=brojacC[i]){
                da=0;
                break;
            }
        }
    }
    for(i=0; i<101; i++){
        if(nbrojacA[i]!=0){
            if(nbrojacA[i]!=nbrojacB[i] || nbrojacA[i]!=nbrojacC[i]){
                da=0;
                break;
            }
        }
    }
    if(da==0) printf("NE\n");
    else printf("DA\n");
    
    /*for(i=0; i<20; i++) printf("%d:%d ", i, brojacA[i]);
    printf("\n");
    for(i=0; i<20; i++) printf("%d:%d ", i, nbrojacA[i]);
    printf("\n");
    for(i=0; i<20; i++) printf("%d:%d ", i, brojacB[i]);
    printf("\n");
    for(i=0; i<20; i++) printf("%d:%d ", i, nbrojacB[i]);
    printf("\n");
    for(i=0; i<20; i++) printf("%d:%d ", i, brojacC[i]);
    printf("\n");
    for(i=0; i<20; i++) printf("%d:%d ", i, nbrojacC[i]);
    printf("\n");
    */
    
    
	return 0;
}
