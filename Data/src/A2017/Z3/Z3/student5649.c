#include <stdio.h>

int main() {
	int mat[200][200], M, N, brojac=0, i, j, k, s, d, br, kol;
	
	do{ brojac=0;
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
		if (M<=0 || M>=200 || N<=0 || N>=200){
			printf("Brojevi nisu u trazenom opsegu.\n");
			brojac++;
		}
	}
	while(brojac!=0);
	
	printf("Unesite elemente matrice: ");
	
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d", &mat[i][j]);
		}
	}
	
	for(i=0;i<M;i++){
		for(j=i+1;j<M;j++){
			br=0;
			for(k=0;k<N;k++){
				if(mat[i][k]==mat[j][k]){
				br++;}
				
			}
            if(br==N){
            	for(s=j;s<M-1;s++){
            		for(d=0;d<N;d++){
            			mat[s][d]=mat[s+1][d];
            			
            		}
            
            	}
            	M--;
            	j--;
           	}
            }
			}
		
		for(i=0;i<N;i++){
			for(j=i+1;j<N;j++){
				kol=0;
				for(k=0;k<M;k++){
					if(mat[k][i]==mat[k][j]){
						kol++;
					}
				}
					if(kol==M){
						for(s=j;s<N-1;s++){
							for(d=0;d<M;d++){
								mat[d][s]=mat[d][s+1];
							}
							
						}
						N--;
						j--;
					
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
