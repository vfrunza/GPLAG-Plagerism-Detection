#include <stdio.h>
#define brojac 10001
int main() {
	int M,N,matA[100][100],matB[100][100],matC[100][100],i,j,k,l,brojac1[10001]={0},brojac2[10001]={0},jednak=1;
	
	
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&M,&N);
		
	}while(M>100 || N>100);
	
	printf("Unesite clanove matrice A: ");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			scanf("%d",&matA[i][j]);
		
		}
	}
	printf("Unesite clanove matrice B: ");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			scanf("%d",&matB[i][j]);
		}
	}
	printf("Unesite clanove matrice C: ");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			scanf("%d",&matC[i][j]);
		}
	}
	
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
		  for(k=0; k<M; k++){
		  	for(l=0; l<N; l++){
		  		if (matA[i][j] == matB[k][l]) brojac1[matA[i][j]]++;
		  		else if (matA[i][j] == matC[k][l]) brojac2[matA[i][j]]++;
		  		
	   }
	  }
	 }
	}
    for (i=0; i<M*N; i++){
    	if(brojac1[matA[i][j]] != brojac2[matA[i][j]]) jednak = 0; break;
    }
    if(jednak == 1) printf("DA\n");
    else printf("NE\n");
	
   
	
	return 0;
}
