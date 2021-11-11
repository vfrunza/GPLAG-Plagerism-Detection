#include <stdio.h>

int main() {
	int A[100][100],B[100][100],C[100][100],M,N,i,j,x,y,brojacA=0,brojacB=0,brojacC=0;
	
	do {
		printf("Unesite brojeve M i N: ");
		scanf ("%d %d", &M,&N); }
	while (M>100 || N>100);
	
	
	printf ("Unesite clanove matrice A: ");
	for (i=0; i<M; i++){
		for (j=0; j<N; j++){
			scanf ("%d", &A[i][j]);	} }
		
	printf ("Unesite clanove matrice B: ");
	for (i=0; i<M; i++){
		for (j=0; j<N; j++){
			scanf ("%d", &B[i][j]);	} }
		
	printf ("Unesite clanove matrice C: ");
	for (i=0; i<M; i++){
		for (j=0; j<N; j++){
			scanf ("%d", &C[i][j]);	} }
			

	for (i=0; i<M; i++) {
		for (j=0; j<N; j++ ) {
			for (x=0; x<M; x++) {
				for (y=0; y<N; y++)	{
			
					if (A[x][y]==A[i][j]) 
					brojacA++; 
		
					if (B[x][y]==A[i][j]) 
					brojacB++; 
		
					if (C[x][y]==A[i][j]) 
					brojacC++; } } 
		
			 if (brojacA!=brojacB || brojacA!=brojacC || brojacB!=brojacC) {
			 	printf ("NE\n");
			 	return 0; } } }
			 	
	printf ("DA\n");
		
	return 0;
}
