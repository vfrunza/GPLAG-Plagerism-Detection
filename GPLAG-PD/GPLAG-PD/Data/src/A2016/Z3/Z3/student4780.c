#include <stdio.h>

int main()
{
	int i=0,j=0,m=0,n=0,k=0,l=0,p=0,brojacr=0,brojack=0;
	int mat[200][200]= {0};
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m,&n);
		if(m<=200 && n<=200 && m>0 && n>0)
			break;
		else
			printf("Brojevi nisu u trazenom opsegu.\n");
	} while(m>200 || n>200 || m<=0 || n<=0 );
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%d",&mat[i][j]);
		}
	}

	for(i=0; i<m-1; i++) {
		for(j=1; j<m-i; j++) {
			for(p=0; p<n; p++) {
				if(mat[i][p]==mat[i+j][p])
					brojacr++;
			}
			if(brojacr==n) {
				if(j==m-1) {
					m--;
					brojacr=0;
				} else {
					for(k=j; k<m-1; k++) {
						for(l=0; l<n; l++) {
							mat[k+i][l]=mat[k+i+1][l];
						}
					}
					m--;
					brojacr=0;
					
				j=m-i;
						i--;
				}
			} else brojacr=0;
		}

	}

	for(i=0; i<n-1; i++) {
		for(j=1; j<n-i; j++) {
			for(p=0; p<m; p++) {

				if(mat[p][i]==mat[p][i+j])
					brojack++;
			}
			if(brojack==m) {
				if(i+j==n-1) {
					n--;
					brojack=0;
				} else {
					for(k=j; k<n-1; k++) {
						for(l=0; l<m; l++) {
							mat[l][k+i]=mat[l][k+i+1];
						}

					}
					n--;
					brojack=0;
					j--;
				}
			} else brojack=0;
		}
	}
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			printf("%5d", mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}
