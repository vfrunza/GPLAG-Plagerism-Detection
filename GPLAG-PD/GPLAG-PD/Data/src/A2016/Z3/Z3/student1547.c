#include <stdio.h>

int main() {
	int i, j, M, N, mat[200][200], a, b, c, x;
	do{
	printf("Unesite brojeve M i N: ");
	scanf("%d %d", &M, &N);
	if(M<=0 || M>200 || N<=0 || N>200)
	printf("Brojevi nisu u trazenom opsegu.\n");
	}
	while(M<=0 || M>200 || N<=0 || N>200);
	printf("Unesite elemente matrice: ");
		for(i=0;i<M;i++){
			for(j=0;j<N;j++){
				scanf("%d", &mat[i][j]);
			}
		}
	/*Poredjenje po redovima*/
	for(i=0; i<M; i++){
		for(j=i+1;j<M;j++){
			a=1;
			for(x=0;x<N;x++){
				if(mat[i][x]!=mat[j][x]){
				a=0;
				break;
				}
			}
			if(a==1){
				for(b=j+1;b<M;b++){
					for(c=0;c<N;c++){
						mat[b-1][c]=mat[b][c];/*U pronadjeni isti red upisuje red ispod*/
					}
				}
			j--;
			M--;	
			}
		
		}
	}
	/*Poredjenje po kolonama*/
	for(i=0; i<N; i++){
		for(j=i+1;j<N;j++){
			a=1;
			for(x=0;x<M;x++){
				if(mat[x][i]!=mat[x][j]){
				a=0;
				break;
				}
			}
			if(a==1){
				for(b=j+1;b<N;b++){
					for(c=0;c<M;c++){
						mat[c][b-1]=mat[c][b];
					}
				}
			j--;
			N--;	
			}
		
		}
	}
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			printf("%5d", mat[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
