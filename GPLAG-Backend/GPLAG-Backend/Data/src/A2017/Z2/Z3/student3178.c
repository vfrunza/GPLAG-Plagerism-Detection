#include <stdio.h>
#include <stdlib.h>

int main() {
    int A[100][100] = {{0}};
    int B[100][100] = {{0}};

    int temp = 7; int i,j;
    int mA, mB, nA, nB;
    
    printf("Unesite sirinu i visinu matrice A: "); scanf("%d %d", &mA, &nA);
    printf("Unesite clanove matrice A: ");
    
    for(i = 0; i < mA; i++) {
    	for(j = 0; j < nA; j++) {
    		scanf("%d",&A[i][j]);
    	}
    }
    
    printf("Unesite sirinu i visinu matrice B: "); scanf("%d %d", &mB, &nB);
    printf("Unesite clanove matrice B: ");
    
    for(i = 0; i < mB; i++) {
    	for(j = 0; j < nB; j++) {
    		scanf("%d",&B[i][j]);
    	}
    }
    
    /* Rotiranje matrice A za 90° */
    /* -- begin -- */
    
    /* horizontalno obrtanje matrice A */
    for(i = 0; i < mA/2; i++) {
        for(j = 0; j < nA; j++) {
            temp = A[i][j];
            A[i][j] = A[mA - 1 - i][j];
            A[mA - 1 - i][j] = temp;
        }
    }
	/* transponovanje matrice A */
    for(i = 0; i < mA; i++) {
        for(j = i+1; j < nA; j++) {
            temp = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = temp;
        }
    }
    
    temp = mA; mA = nA; nA = temp;
    
   	/* -- end -- */
    
    for(i = 0; i < nA; i++) {
        for(j = 0; j < nB; j++) {
            if(A[i][j] != B[i][j]) {
            	printf("NE"); return 0;
            }
        }
    }
    printf("DA");
	return 0;
}