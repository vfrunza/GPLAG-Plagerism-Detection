#include <stdio.h>

int main() {
	int m,n,i,j,mat[200][200],k,isti,z,r,l,tmp;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m, &n);
		if(m>200 || n>200 || m<1 || n<1)
			printf("Brojevi nisu u trazenom opsegu.\n");
	}while(m>200 || n>200 || m<1 || n<1);
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++)
		scanf("%d", &mat[i][j]);
	}
	for(i=0; i<m; i++){
			isti=0;
			for(k=i+1; k<m; k++){
				isti=0;
				if(mat[i][0]==mat[k][0]){
					isti=1;
					for(l=1; l<n;l++){
						if(mat[k][l]!=mat[i][l]){
							isti=0;
							break;
						}
					}
				}
				if(isti==1){
					for(z=k; z<m-1; z++){
						for(r=0; r<n;r++){
							mat[z][r]=mat[z+1][r];
						}
					}
					m--;
					k--;
				}
			}
		
	}
		for(j=0; j<n; j++){
			isti=0;
			for(k=j+1;k<n; k++){
				isti=0;
				if(mat[0][j]==mat[0][k]){
					isti=1;
					for(l=1;l<m;l++){
						if(mat[l][k]!=mat[l][j]){
							isti=0;
							break;
						}
					}
				}
				if(isti==1){
					for(z=k;z<n-1;z++){
						for(r=0;r<m;r++)
							mat[r][z]=mat[r][z+1];
					}
					n--;
					k--;
				}
			}
		}
	
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++)
		printf("%5d", mat[i][j]);
		printf("\n");
	}
	return 0;
}
