#include <stdio.h>

int main()
{

	int k,l,i,j,a,b,c,d;
	int mat[200][200];
	int M,N;
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
		if(M<=0 || M>200 || N<=0 || N>200) 
		printf("Brojevi nisu u trazenom opsegu.\n");
		
	
	} while(M<=0 || M>200 || N<=0 || N>200); 
printf("Unesite elemente matrice: ");

	for(k=0; k<M; k++) {
		for(l=0; l<N; l++) {
			
			scanf("%d", &mat[k][l]);
		}
	}
	int desiosebreak=0;
	for(i=0; i<M; i++) {
		for(j=i+1; j<M; j++) {
			desiosebreak=0;
			for(k=0; k<N; k++) {
				if(mat[i][k]!=mat[j][k]) {
					desiosebreak=1;
					break;
				}
			}

				if(!desiosebreak){
					for(a=j; a<M; a++) {
						for(b=0; b<N; b++) {
							if((a+1)<M) {
								mat[a][b]=mat[a+1][b];
							}
						}
					}
				M--;
				j--;
			}
		}
	}

desiosebreak=0;
for(i=0; i<N; i++){
	for(j=i+1;j<N;j++){
		desiosebreak=0;
		for(k=0;k<M;k++){
			if(mat[k][i]!=mat[k][j]){
				desiosebreak=1;
				break;
			}
		}
		if(!desiosebreak){
			for(a=j;a<N;a++){
				for(b=0;b<M;b++){
					if((a+1)<N){
						mat[b][a]=mat[b][a+1];
					}
				}
			}
			N--;
			j--;
		}
	}
}

	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");

	for(c=0; c<M; c++) {
		for(d=0; d<N; d++) {
		
			printf("%5d", mat[c][d]);
		}
		printf("\n");
	}
	return 0;
}
