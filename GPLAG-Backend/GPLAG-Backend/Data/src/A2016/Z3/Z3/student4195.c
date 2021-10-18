#include <stdio.h>
#define max 200

int main() {
	int matrica[max][max],i,j,m,n,k,z,isti_red,ista_kolona;
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&m,&n);
		if(m<=0 || n<=0 || m>200 || n >200) {
			printf("Brojevi nisu u trazenom opsegu.\n");
		}
	}while(m<=0 || n<=0 || m>200 || n >200);
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%d",&matrica[i][j]);
		}
	}
	
	for(i=0; i<m-1; i++) {
		for(k=i+1; k<m; k++) {
			isti_red=1;
			for(j=0; j<n; j++) {
				if(matrica[i][j]!=matrica[k][j]) {
					isti_red=0;
					break;
				}
			}
			if(isti_red) {
				for(z=k; z<m-1; z++) { 
					for(j=0; j<n; j++) {
						matrica[z][j] = matrica[z+1][j];
					}
				}
				m--;
				k--;
			}
		}
	}
	
	for(j=0; j<n-1; j++) {
		for(k=j+1; k<n; k++) {
			ista_kolona=1;
			for(i=0; i<m; i++) {
				if(matrica[i][j]!=matrica[i][k]) {
					ista_kolona=0;
					break;
				}
			}
			if(ista_kolona) {
				for(z=k; z<n-1; z++) {
					for(i=0; i<m; i++) {
						matrica[i][z] = matrica[i][z+1];
					}
				}
				n--;
				k--;
			}
		}
	}
	
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			printf("%5d",matrica[i][j]);
		}
		printf("\n");
	}
	return 0;
}
