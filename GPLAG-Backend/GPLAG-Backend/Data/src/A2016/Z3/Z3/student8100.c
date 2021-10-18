#include <stdio.h>

int main() {
	int m, n, mat[200][200], i, j, k, l, p, valja=1, a=1;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m, &n);
		if(m<=0 || m>200 || n<=0 || n>200) printf("Brojevi nisu u trazenom opsegu.\n");
	}while(m<=0 || m>200 || n<=0 || n>200);
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++)
			scanf("%d", &mat[i][j]);
	}
	while(a<=2){
	for(j=0; j<n-1; j++){
		for(k=j+1; k<n; k++){
			if(mat[0][j] == mat[0][k]){
				for(i=0; i<m; i++){
					if(mat[i][j]!= mat[i][k]){
						valja=0;
						break;
					}
				}
				if(valja){
					for(l=k; l<n-1; l++)
						for(p=0; p<m; p++)
							mat[p][l] = mat[p][l+1];
					n--;
				}
			}
		}
	}
	valja = 1;
	for(i=0; i<m-1; i++){
		for(k=i+1; k<m; k++){
			if(mat[i][0] == mat[k][0]){
				for(j=0; j<n; j++){
					if(mat[i][j]!= mat[k][j]){
						valja=0;
						break;
					}
				}
				if(valja){
					for(l=k; l<m-1; l++)
						for(p=0; p<n; p++)
							mat[l][p] = mat[l+1][p];
					m--;
				}
			}
		}
	}
	a++;
	}
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++)
			printf("%5d", mat[i][j]);
		printf("\n");
	}
	return 0;
}
