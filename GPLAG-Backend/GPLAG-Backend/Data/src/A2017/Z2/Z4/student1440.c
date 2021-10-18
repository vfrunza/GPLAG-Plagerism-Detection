#include <stdio.h>

int main() {
	int matA[100][100],matB[100][100],matC[100][100],M,N,i,j,k,l,broj1=0,broj2=0,broj3=0,element;
	printf("Unesite brojeve M i N: ");
	scanf("%d%d",&M,&N);
	while (M>100 || N>100) {
	    printf("Unesite brojeve M i N: ");
	    scanf("%d%d",&M,&N);
	}
	printf("Unesite clanove matrice A: ");
	for(i=0;i<M;i++) {
	    for(j=0;j<N;j++) {
	        scanf("%d",&matA[i][j]);
	    }
	}
	printf("Unesite clanove matrice B: ");
	for(i=0;i<M;i++) {
	    for(j=0;j<N;j++) {
	        scanf("%d",&matB[i][j]);
	    }
	}
	printf("Unesite clanove matrice C: ");
	for(i=0;i<M;i++) {
	    for(j=0;j<N;j++) {
	        scanf("%d",&matC[i][j]);
	    }
	}
	for(i=0;i<M;i++) {
	    for(j=0;j<N;j++) {
	    	element=matA[i][j];
	    	for(k=0;k<M;k++) {
	    		for(l=0;l<N;l++) {
	    			if(matA[k][l]==element) broj1++;
	    			if(matB[k][l]==element) broj2++;
	    			if(matC[k][l]==element) broj3++;
	    		}
	    	}
	    	if(broj1!=broj2 || broj1!=broj3) {
	    		printf("NE");
	    		return 0;
	    	}
	    	broj1=0;
	    	broj2=0;
	    	broj3=0;
	    }
	}
    printf("DA");
    return 0;
}