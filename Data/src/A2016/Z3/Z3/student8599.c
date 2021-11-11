#include <stdio.h>

int main() {
	int mat[200][200], i, j, k, l, s, M, N;
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
		if(M<1 || M>200 || N<1 || N>200) {
			printf("Brojevi nisu u trazenom opsegu.\n");
		}
	} while(M<1 || M>200 || N<1 || N>200);
	
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
/*i petljom prolazimo kroz redove; u j petlji uporedjujemo clanove jednog reda sa clanovima redova ispod tog reda. Da bismo 
uporedili jedan red sa vise redova uvodimo k petlju.*/
	for(i=0; i<M-1; i++) {
		for(k=0; k<M-i-1; k++) {
			for(j=0; j<N; j++) {
				if(mat[i][j]!=mat[i+k+1][j]) 
				break;
				}	
/*Ako se j petlja ne prekine, znaci da su redovi jednaki i vrsimo izbacivanje pomocu s petlje*/			
				if(j==N) {
				 	for(s=0; s<M-i-k-1; s++) {
						for(j=0; j<N; j++) {
							mat[i+k+1+s][j]=mat[i+k+2+s][j];
						}
				 	}	
					M--;
					k--;
				}
		}
	}	
/*j petljom prolazimo kroz kolone; u i petlji uporedjujemo clanove jedne kolone sa clanovima kolona desno od te kolone. Da bismo uporedili
jednu kolonu sa vise kolona uvodimo k petlju */		
	for(j=0; j<N-1; j++) {
		for(k=0; k<N-j-1; k++) {
			for(i=0; i<M; i++) {
				if(mat[i][j]!=mat[i][j+k+1]) 
				break;
			}	
/*Ako se i petlja ne prekine, znaci da su kolone jednake i vrsimo izbacivanje pomocu s petlje*/					
			if(i==M){
			 	for(l=0; l<M; l++) {
				 	for(s=0; s<N-j-k-1; s++) {
						mat[l][j+k+1+s]=mat[l][j+k+2+s];
					}
				 		
				}
				N--;
				k--;
			}
		}
	}	
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			printf("%5d", mat[i][j]);
		}
		printf("\n");
	}
		
	return 0;
}
