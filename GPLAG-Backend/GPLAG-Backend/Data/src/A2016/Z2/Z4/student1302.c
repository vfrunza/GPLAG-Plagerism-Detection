#include <stdio.h>

int main() {
	int M, N, i,j;
	float matrica[100][100];
	int cirkularna, teplica;
opet:
	do {
	printf("Unesite M i N: ");
	scanf("%d %d", &M, &N);
	if( M>100 || M<1 || N>100 || N<1) { printf("Pogresan unos!\n"); goto opet; }
	else  goto nastavak;
	}
	while((M<=100 && M>0 )||(N<=100 && N>0));
	
	nastavak:
printf("Unesite elemente matrice: ");
 for(i=0; i<M;i++){
 	for(j=0; j<N; j++){
 		scanf("%f", &matrica[i][j]);
 	}
 }
 teplica=1;
 cirkularna=1;
for(i=0; i<M-1;i++){
	for(j=0; j<N-1;j++){
		if (matrica[i][j]!=matrica[i+1][j+1]) { teplica=0; break;}}}
		if(teplica!=0){
			for(i=0; i<M-1;i++){
				for(j=0;j<N-1;j++){
					if(matrica[i+1][0]!=matrica[i][N-1]) {cirkularna=0; break;}
				}
			}
		if(cirkularna!=0) printf("Matrica je cirkularna\n");
		else if(teplica!=0) printf("Matrica je Teplicova\n");
	}

	else printf("Matrica nije ni cirkularna ni Teplicova");
	



	return 0;
}
