#include <stdio.h>

int main() {
	int i, j, m, n, k, b, c=0, a;
	int mat[200][200];
	
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d%d", &m, &n);
		if(m<1 || m>200 || n<1 || n>200)
			printf("Brojevi nisu u trazenom opsegu.\n");
	}while(m<1 || m>200 || n<1 || n>200);
	
	printf("Unesite elemente matrice: ");
	
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			scanf("%d", &mat[i][j]);
		}
	}
	
	
	for(i=0; i<m-1; i++){
		
		for(j=i+1; j<m; j++){
			c=0;
			for(k=0; k<n; k++){
				if(mat[i][k]!=mat[j][k])
					c=1;
			}
			if(c==0 && n==1){
					for(b=j; b<m; b++){
						mat[b][0]=mat[b+1][0];
					}
					j--;
					m--;
					continue;
				}
			if(c==0){
					for(b=0; b<n; b++){
						for(a=j; a<m; a++){
							mat[a][b]=mat[a+1][b];
						}
						
					}
				j--;
				m--;
				
			}
			
		}
		
	}
	
	for(i=0; i<n-1; i++){
		
		for(j=i+1; j<n; j++){
			c=0;
			for(k=0; k<m; k++){
				if(mat[k][i]!=mat[k][j])
					c=1;
			}
				if(c==0 && m==1){
					for(b=j; b<n; b++){
						
						mat[0][b]=mat[0][b+1];
					}
					j--;
					n--;
					continue;
				}
				if(c==0){
					for(b=0; b<m; b++){
						for(a=j; a<n; a++){
							mat[b][a]=mat[b][a+1];
						}
					}
				j--;
				n--;
				
			}
			
		}
		
	}
	
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");	
	
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			printf("%5d", mat[i][j]);
		}
		printf("\n");
	}
		
		
			
	
	
	
	return 0;
}
