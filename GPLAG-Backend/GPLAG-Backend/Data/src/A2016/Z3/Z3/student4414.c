#include <stdio.h>

int main() {
	int M,N,i,j,mat[200][200],isti,k,z,l,iste;
	
	
	printf("Unesite brojeve M i N: ");
	scanf("%d", &M);
	scanf("%d", &N);
	
	while((M>200) || (N>200) || (M<=0) || (N<=0)){ 
	printf("Brojevi nisu u trazenom opsegu.\n");
	printf("Unesite brojeve M i N: ");
	scanf("%d", &M);
	scanf("%d", &N);
	}
	 
	
	 printf("Unesite elemente matrice: ");
	 
	 for(i=0; i<M; i++) {
	 	for(j=0; j<N; j++){
	 		scanf("%d", &mat[i][j]);
	 	}
	 }
	 
	 
	 for(i=0; i<M; i++) {
	 	for(k=i+1; k<M; k++) 
	 	{
	 		isti = 1;
	 		for(j=0; j<N; j++) {
	 		if(mat[i][j]!=mat[k][j]) isti=0;
	 	}
	 	if(isti==1){
	 		for(l=k; l<(M-1); l++) {
	 			for(z=0; z<N; z++) {
	 				mat[l][z]=mat[l+1][z];
	 			}
	 			
	 		}
	 		M--;
	 		k--;
	 	}
	 }
	 }
	 
	 /* ODAVDE POCINJEM RADITI ZA KOLONE */
	 
	 for(i=0; i<N; i++) {
	 	for(k=i+1; k<N; k++){
	 		iste=1;
	 		for(j=0; j<M; j++) {
	 			if(mat[j][i]!=mat[j][k])  iste=0; 
	 		}
	 	
	 		if(iste==1) {
	 			for(l=k; l<(N-1); l++) {
	 				for(z=0; z<M; z++) {
	 					mat[z][l]=mat[z][l+1];
	 				}
	 			}
	 		N--;
	 		k--;
	 			
	 		}
	 		
	 	}
	 
}	 
	 
	 printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	 
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			printf("%5d", mat[i][j]);
		}
		printf("\n");
	}

	return 0;
}
