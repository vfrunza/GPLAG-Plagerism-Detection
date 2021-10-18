#include <stdio.h>



int main() {
	int mat[500][500], M, N;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
		if(M>0 && M<=200 && N>0 && N<=200)
			break;
		printf("Brojevi nisu u trazenom opsegu.\n");
	}while(1);
	int i, j;
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d", &mat[i][j]);
		}
	}
	//redovi
	int a, b, c, temp, brojac ;
	for(i=0;i<M;i++){
		for(j=i+1;j<M;j++){
			brojac=0;
			for(a=0;a<N;a++){
				if(mat[i][a]==mat[j][a])
					brojac++;
				
				if (brojac==N){
					for(b=j;b<M;b++){
						for(c=0;c<N;c++){
							temp=mat[b][c];
							mat[b][c]=mat[b+1][c];
							mat[b+1][c]=temp;
						}
						
					}
					M--;
					j--;
				}
			}
		}
	}
	//kolone
	for(i=0;i<N;i++){
		for(j=i+1;j<N;j++){
			brojac=0;
			for(a=0;a<M;a++){
				if(mat[a][i]==mat[a][j])
					brojac++;
				
				if (brojac==M){
					for(b=j;b<N;b++){
						for(c=0;c<M;c++){
							temp=mat[c][b];
							mat[c][b]=mat[c][b+1];
							mat[c][b+1]=temp;
						}
						
					}
					N--;
					j--;
				}
			}
		}
	}
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			printf("%5d", mat[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
