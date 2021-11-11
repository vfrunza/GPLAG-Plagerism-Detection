#include <stdio.h>
int main() {
	
	int M,N,i,j,g,br=0,k,l,v;
	int mat[100][100]={{0}};
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&M,&N);
		if(M<1 || N<1 || M>200 || N>200){
			printf("Brojevi nisu u trazenom opsegu.\n");
			g=1;
		} else g=0;
	} while(g==1);
	
	printf("Unesite elemente matrice: ");
	
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			scanf("%d",&mat[i][j]);
		}
	}
	i=0;
	do{
		for(j=i+1; j<M; j++){
			for(v=0; v<N; v++){
				if(mat[i][v]==mat[j][v]) br++;
				if(br==N){
					for(l=j; l<M-1; l++){
						for(k=0; k<N; k++){
						mat[l][k]=mat[l+1][k];
						}
					}
				j--;
				M--;
				}
			
			}
		br=0;		
		}
		i++;
		
	} while(i<M);
	
	i=0;
	do{
		for(v=i+1; v<N; v++){
			for(j=0; j<M; j++){
				if(mat[j][i]==mat[j][v]) br++;
				if(br==M){
					for(l=0; l<M; l++){
						for(k=v; k<N-1; k++){
						mat[l][k]=mat[l][k+1];
						}
					}
				v--;
				N--;
				}
			
			}
		br=0;		
		}
		i++;
		
	} while(i<N);
	
 printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			printf("%5d",mat[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
