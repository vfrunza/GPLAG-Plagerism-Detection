#include <stdio.h>

int main() {
	int m,n,i,j,k,l,logpr;
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&m,&n);
		if(m<1 || m>200 || n<1 || n>200) printf("Brojevi nisu u trazenom opsegu. \n");
	} while(m<1 || m>200 || n<1 || n>200);
	int mat[200][200];
	/*Unos elemenata*/
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++) {
		for(j=0;j<n;j++) {
			scanf("%d",&mat[i][j]);
		}
	}
	/*Ispitivanje matrice po redovima*/
	for(i=0;i<m-1;i++) {
		for(k=i+1;k<m;k++) {
			logpr=1;
			for(j=0;j<n;j++) {
				if(mat[i][j]!=mat[k][j]) 
					logpr=0;
			}
			/*Izbacivanje reda koji zadovoljava uslov*/
			if(logpr==1) {
				for(l=k;l<m-1;l++) {
					for(j=0;j<n;j++) {
						mat[l][j]=mat[l+1][j];
					}
				}
				k--;
				m--;
			}
		}
	}
	/*Ispitivanje matrice po kolonama*/
	for(j=0;j<n-1;j++) {
		for(k=j+1;k<n;k++) {
			logpr=1;
			for(i=0;i<m;i++) {
				if(mat[i][j]!=mat[i][k])
					logpr=0;
			}
			/*Izbacivanje kolone koja zadovoljava uslov*/
			if(logpr==1) {
				for(l=k;l<n-1;l++) {
					for(i=0;i<m;i++) {
						mat[i][l]=mat[i][l+1];
					}
				}
				k--;
				n--;
			}
		}
	}
	/*Ispisuje se modificirana matrica*/
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0;i<m;i++) {
		for(j=0;j<n;j++) {
			printf("%5d",mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}
