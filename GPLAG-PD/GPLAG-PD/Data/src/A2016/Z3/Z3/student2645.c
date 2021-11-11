#include <stdio.h>


int main() {
	int m,n,i,j,k,br,g,h;
	int mat[200][200];
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m, &n);
		if(m<=0 || n<=0 || n>200 || m>200){
			printf("Brojevi nisu u trazenom opsegu.\n");
		}
	}while(m<=0 || n<=0 || n>200 || m>200);
	\
	
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			scanf("%d", &mat[i][j]);
		}
	}
	for(i=0; i<m-1; i++){
		for(k=i+1; k<m; k++){
			br=0;
			for(j=0; j<n; j++){
				if(mat[i][j]==mat[k][j])
					br++;
			}
			if(br==n){
				for(g=k; g<m-1; g++){
					for(h=0; h<n; h++){
						mat[g][h] = mat[g+1][h];
					}
				}
				m--;
				k--;
			}
			
		}
	}
	for(j=0; j<n-1; j++){
		for(k=j+1; k<n; k++){
			br=0;
			for(i=0; i<m; i++){
				if(mat[i][j]==mat[i][k])
					br++;
			}
			if(br==m){
				for(g=0; g<m; g++){
					for(h=k; h<n-1; h++){
						mat[g][h] = mat[g][h+1];
					}
				}
				n--;
				k--;
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
