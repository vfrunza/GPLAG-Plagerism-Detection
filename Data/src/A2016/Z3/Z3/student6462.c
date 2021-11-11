#include <stdio.h>

int main() {
	int mat[200][200], m, n, i, j, k, isti=1, s, t;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m, &n);
		if(m<=0 || n<=0 || m>200 || n>200) printf("Brojevi nisu u trazenom opsegu.\n");
		else{
			printf("Unesite elemente matrice: ");
			for(i=0; i<m; i++){
				for(j=0; j<n; j++){
					scanf("%d", &mat[i][j]);
				}
			}
			for(i=0; i<m; i++){
				for(j=i+1; j<m; j++){
					for(k=0; k<n; k++){
						if(mat[i][k]==mat[j][k]){
							isti=1;
						} 
						else if(mat[i][k]!=mat[j][k]){
							isti=0;
							break;
						}
					}
					if(isti==1 ){
						/*izbacivanje reda j*/
						if(j==m-1) m--;
						else{
						for(s=j; s<m-1; s++){
							for(t=0; t<n; t++){
								mat[s][t]=mat[s+1][t];
							}
						}
						m--;
						j--;
						}
					}
				}
			}
			isti=1;
			for(i=0; i<n; i++){
				for(j=i+1; j<n; j++){
					for(k=0; k<m; k++){
						if(mat[k][i]==mat[k][j]){
							isti=1;
						}
						else if(mat[k][i]!=mat[k][j]){
							isti=0; 
							break;
						}
					}
					if(isti==1){
						/*izbacivanje kolone j*/
						if(j==n-1) n--;
						else{
							for(s=0; s<m; s++){
								for(t=j; t<n-1; t++){
									mat[s][t]=mat[s][t+1];
								}
							}
							n--;
							j--;
						}
					}
				}
			}
			
		}
	} while(m<=0 || n<=0 || m>200 || n>200);
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			printf("%5d", mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}
