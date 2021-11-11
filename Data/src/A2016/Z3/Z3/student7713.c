#include <stdio.h>

int main() {
	
	int matrica[201][201],M,N,i,j,k,l,m,temp=1;
	while(1) {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
		if(M>200 || M<1 || N>200 || N<1) {
			printf("Brojevi nisu u trazenom opsegu.\n");
			continue;
		}
		else break;
	}
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++) {
		for(j=0;j<N;j++) {
			scanf("%d", &matrica[i][j]);
		}

	}
	
	for(i=0;i<M;i++) {
		for(j=i+1;j<M;j++) {
			temp=1;
			for(k=0;k<N;k++) {
				if(matrica[i][k]!=matrica[j][k]) {
					temp=0;
					break;
				}
			}
			if(temp==1) {
				for(l=j;l<M-1;l++) {
					for(m=0;m<N;m++) {
						matrica[l][m] = matrica[l+1][m];
					}
				}
				j--;
				M--;
			}
		}
	}
	
	
	for(i=0;i<N;i++) {
		for(j=i+1;j<N;j++) {
			temp=1;
			for(k=0;k<M;k++) {
				if(matrica[k][i]!=matrica[k][j]) {
					temp = 0;
					break;
				}
			}
			if(temp==1) {
				for(l=j;l<N-1;l++) {
					for(m=0;m<M;m++) {
						matrica[m][l] = matrica[m][l+1];
					}
				}
				j--;
				N--;
			}
		}
	}
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0;i<M;i++) {
		for(j=0;j<N;j++) {
			printf("%5d", matrica[i][j]);
		}
		printf("\n");
	}
	return 0;
}
