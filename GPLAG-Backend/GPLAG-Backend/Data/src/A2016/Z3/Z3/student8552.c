#include <stdio.h>

int main() {
	int m,n,i,j,k,mat[200][200],niz_red[200],niz_kolona[200],isti_red,br_reda=0,ista_kolona,br_kolone=0;
	do {
		printf ("Unesite brojeve M i N: ");
		scanf ("%d %d",&m,&n);
		if (m<1 || m>200 || n<1 || n>200)
			printf ("Brojevi nisu u trazenom opsegu.\n");
	} while (m<1 || m>200 || n<1 || n>200);
	printf ("Unesite elemente matrice: ");
	for (i=0; i<m; i++) {
		for (j=0; j<n; j++) {
			scanf ("%d",&mat[i][j]);
			if (i==0)
				niz_red[j]=mat[i][j];
			if (j==0)
				niz_kolona[i]=mat[i][j];
		}
	}
	
	for (i=0; i<m; i++) {
		isti_red=1;
		for (j=0; j<n; j++) {
			if (i!=br_reda && mat[i][j]!=niz_red[j]) {
				isti_red=0;
			}
		}
		if (i!=br_reda && isti_red==1) {
			for (j=0; j<n; j++) {
				for (k=i; k<m-1; k++) {
					mat[k][j]=mat[k+1][j];
				}
			}
			m--;
			i--;
		}
		if (i==m-1) {
			i=++br_reda;
			for (j=0; j<n; j++) {
				niz_red[j]=mat[i][j];
			}
		}
	}
	
	for (i=0; i<n; i++) {
		ista_kolona=1;
		for (j=0; j<m; j++) {
			if (i!=br_kolone && mat[j][i]!=niz_kolona[j]) {
				ista_kolona=0;
			}
		}
		if (i!=br_kolone && ista_kolona==1) {
			for (j=0; j<m; j++) {
				for (k=i; k<n-1; k++) {
					mat[j][k]=mat[j][k+1];
				}
			}
			n--;
			i--;
		}
		if (i==n-1) {
			i=++br_kolone;
			for (j=0; j<m; j++) {
				niz_kolona[j]=mat[j][i];
			}
		}
	}
	
	printf ("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for (i=0; i<m; i++) {
		for (j=0; j<n; j++) {
			printf ("%5d",mat[i][j]);
		}
		printf ("\n");
	}
	return 0;
}
