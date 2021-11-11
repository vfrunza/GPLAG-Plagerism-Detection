#include <stdio.h>
#include <stdlib.h>
#define e 0.0001

int main() {
    int M,N,i,j,k,l=0,t=1,c=1,el;
	double matrica[100][100];
	double matrica1[100][100];
	
	do {
	    printf("Unesite M i N: ");
	    scanf("%d %d", &M, &N);
	    if(M>100 || M<=0 || N>100 || N<=0) printf("Pogresan unos!\n");
	}
	while( M>100 || M<=0 || N>100 || N<=0);
	
	printf("Unesite elemente matrice: ");
	for (i=0;i<M;i++){
	    for (j=0;j<N;j++){
	        scanf("%lf",&matrica[i][j]);
	    }
	}
	for(i = 0; i < M; i++)
	    for(j = 0; j < N; j++)
	        matrica1[i][j] = 0;
	k=0;
	for(i=0;i<M;i++){
	    for(j=0;j<N;j++){
	        if(i==0) matrica1[i][j]=matrica[i][j];
	        else{
	            if(j<i){
	                matrica1[i][j]=matrica[0][N-l];
	                l--;
	            }
	            else{
	                matrica1[i][j]=matrica[0][k];
	                k++;
	            }
	        }
	    }
	    k=0;
	    l=i+1;
	}
	for(i=0;i<M;i++){
	    for(j=0;j<N;j++){
	        if (matrica1[i][j]!= matrica[i][j]) {
	            c=0;
	            break;
	        }
	    }
	}
	for(i=0;i<M;i++){
	    for(j=0;j<N;j++){
	        el=matrica[i][j];
	        k=1;
	        while(i+k<M && j+k<N){
	            if(matrica[i+k][j+k]!= el)
	            t=0;
	            k++;
	        }
	    }
	}
	if(c==1) printf("Matrica je cirkularna");
	else if(t==1) printf("Matrica je Teplicova");
	else printf("Matrica nije ni cirkularna ni Teplicova");
	
	return 0;
}
