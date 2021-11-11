#include <stdio.h>

int main() {
int M,N,mat[200][200],i,j,k,x,kolona,red;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&M,&N);
		if(M<0 || M>=200 || N<0 || N>=200){
			printf("Brojevi nisu u trazenom opsegu.\n");
		}
	}while(M<0 || M>=200 || N<0 || N>=200);
	
printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			scanf("%d",&mat[i][j]);
		}
	}
	
	for(j=0; j<N-1; j++){
		for(k=j+1; k<N; k++){
			kolona=1;
			for(i=0; i<M; i++){
				if(mat[i][j]!=mat[i][k]){
					kolona=0;
					break;
				}
			}
			if(kolona==1){
				for(x=k; x<N-1; x++){
					for(i=0; i<M; i++){
						mat[i][x] = mat[i][x+1];
					}
				}
				N--;
				k--;
			}
		}
	}	
		
		for(i=0; i<M-1; i++){
			for(k=i+1; k<M; k++){
			red=1;
				for(j=0; j<N; j++){
				if(mat[i][j]!=mat[k][j]){
					red=0;
					break;
				}
			}
			if(red==1){
				for(x=k; x<M-1; x++){
					for(j=0; j<N; j++){
						mat[x][j] = mat[x+1][j];
					}
				}
				M--;
				k--;
			}
		}
	}	
printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			printf("%5d",mat[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
