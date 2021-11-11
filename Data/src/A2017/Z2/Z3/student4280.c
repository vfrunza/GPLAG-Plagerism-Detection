#include <stdio.h>

int main() {
	
	int i=0,j=0,M=0,N=0,K=0,L=0,jednaka=1;
	float matA[100][100], matB[100][100];

	
	do {
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &M,&N); //M sirina,N visina
	if(M<=0 || N<=0) printf("Pogresan unos!");
	else break;
} while(1);

    printf("Unesite clanove matrice A: ");
    for(i=0;i<N;i++) {
    	for(j=0;j<M;j++) {
    		scanf("%f", &matA[i][j]);
    	}
    }
    
    
    do {
    	printf("Unesite sirinu i visinu matrice B: ");
    	scanf("%d %d", &K, &L); //K sirina, L visina
    	if(K<=0 || L<=0) printf ("Pogresan unos!");
    	else break;
    } while(1);
    
    printf("Unesite clanove matrice B: ");
    for(i=0;i<L;i++) { //K sirina,L visina
    	for(j=0;j<K;j++) {
    		scanf("%f", &matB[i][j]);
    	}
    }
    
    if(M!=L || N!=K) {
        printf("NE");
    } else {
        

    for(i=0; i<K && jednaka==1; i++) {
    	for(j=0; j<L; j++) {
    		if(matB[j][i]!=matA[K-i-1][j]) {
    		printf("NE");
    		jednaka=0;
    		break;
    	    }
        }
    }
    
    if(jednaka==1)  {
        printf("DA");
    }
}


    return 0;
    
}












