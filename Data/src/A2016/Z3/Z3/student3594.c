#include <stdio.h>

int main() {
	int M, N, i, j, k, p, q, red, kolona;
	int matrica[200][200];
		
			/*Ulaz*/
		do{
		printf("\nUnesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
			if(M>200 || N>200 || M<0 || N<0) {
			printf("Brojevi nisu u trazenom opsegu.");
			}
		} while(M>200 || N>200 || M<0 || N<0);
		
	
		printf("Unesite elemente matrice: ");
		for(i=0; i<M; i++){
			for(j=0; j<N; j++){
				scanf("%d", &matrica[i][j]);
			}
		}
			
			/*Brisanje redova*/
		
		for(i=0; i<M-1; i++)
			
			for(j=i+1; j<M; j++){
				red=0;
				for(k=0; k<N; k++){
					if(matrica[i][k]!=matrica[j][k]){
						red=1; 
						break;
						}
					}
					
					if(red==0){
						for(p=j; p<M; p++){
							for(q=0; q<N; q++){
								matrica[p][q]==matrica[p+1][q];
							}
						}			
					M--;
					j--;
				}
			}
		
		
			/*Brisanje kolona*/
		
		for(i=0; i<N-1; i++)
			for(j=i+1; j<N; j++){
				
				kolona=0;
				for(k=0; k<M; k++){
					if(matrica[k][i]!=matrica[k][j]){
						kolona=1; 
						break;
						}
					}
					
					if(kolona==0){
						for(p=j; p<M; p++){
							for(q=0; q<N; q++){
								matrica[p][q]==matrica[p][q+1];
							}
						}			
					N--;
					j--;
				}
			}
		
	
	
		/*Izlaz*/
		
		printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
		for(i=0; i<M; i++){
			for(j=0; j<N; j++){ 
				
				printf("%5.d", matrica[i][j]);
			}
			printf("\n");
		}
		
		
	return 0;
}
