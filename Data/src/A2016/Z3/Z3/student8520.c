#include <stdio.h>

int main() {
	int matrica[100][100];
	int m,n;
	int i,j,k,q;
	int jelIsti;
	printf("Unesite brojeve M i N: ");
	scanf("%d %d",&m,&n);
	while(m<1 || m>200 || n<1 || n>200){
		printf("Brojevi nisu u trazenom opsegu.\n");
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&m,&n);
	}
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&matrica[i][j]);
		}
	}
	/* izbacivanje redova */
	for(i=0;i<m;i++){
		for(j=i+1;j<m;j++){
			jelIsti = 1;
			for(k=0;k<n;k++){
				if(matrica[i][k] != matrica[j][k]){
					jelIsti = 0;
					break;
				}
			}
			if(jelIsti){
				
				for(q=j;q<m-1;q++){
					for(k=0;k<n;k++){
						matrica[q][k] = matrica[q+1][k];
					}
				}
				m--;
				j--;
			}
		}
	}
	/* izbacivanje kolona */
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			jelIsti = 1;
			for(k=0;k<m;k++){
				if(matrica[k][i] != matrica[k][j]){
					jelIsti = 0;
					break;
				}
			}
			if(jelIsti){
				
				for(q=j+1;q<n;q++){
					for(k=0;k<m;k++){
						matrica[k][q-1] = matrica[k][q];
					}
				}
				n--;
				j--;
			}
		}
	}
	
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%5d",matrica[i][j]);
		}
		printf("\n");
	}
	return 0;
}
