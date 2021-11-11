#include <stdio.h>

int main() {
	int m,n,matrica[200][200],i,j,k,l,isti=1;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m, &n);
		if(n<=0 || m<=0 || m>200 || n>200) printf("Brojevi nisu u trazenom opsegu.\n");
	}while(n<=0 || m<=0 || m>200 || n>200);
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++)
		for(j=0;j<n;j++) 
			scanf("%d", &matrica[i][j]);
	
	for(i=0;i<m;i++) {
		for(j=i+1;j<m;j++) {
			isti=1;
			for(k=0;k<n;k++) {
				if(matrica[i][k]!=matrica[j][k]) {
					isti=0;
					break;
				} 
			}
			if(isti==1) {
				for(k=j;k<m-1;k++) {
					for(l=0;l<n;l++) {
						matrica[k][l]=matrica[k+1][l];
					}
				}
				m--;
				j--;
			}
		}
	}
	
	for(i=0;i<n;i++) {
		for(j=i+1;j<n;j++) {
			isti=1;
			for(k=0;k<m;k++) {
				if(matrica[k][i]!=matrica[k][j]) {
					isti=0;
					break;
				} 
			}
			if(isti==1) {
				for(k=j;k<n-1;k++) {
					for(l=0;l<m;l++) {
						matrica[l][k]=matrica[l][k+1];
					}
				}
				n--;
				j--;
			}
		}
	}
	
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0;i<m;i++) {
		for(j=0;j<n;j++) {
			printf("%5d", matrica[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
