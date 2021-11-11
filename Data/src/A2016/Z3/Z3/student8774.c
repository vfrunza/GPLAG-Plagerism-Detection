#include <stdio.h>

int main() {
	int i,j,k,l;
	int m,n,isti;
	int niz[200][200];
	
	do {
		printf ("Unesite brojeve M i N: ");
		scanf ("%d %d", &m,&n);
		if (m<=0 || m>200 || n<=0 || n>200)
		printf ("Brojevi nisu u trazenom opsegu.\n");
	}
	while (m<=0 || m>200 || n<=0 || n>200);
	
	printf ("Unesite elemente matrice: ");
	for (i=0;i<m;i++){
		for (j=0;j<n;j++){
			scanf ("%d", &niz[i][j]);
		}
	}
	//provjeravanje clanova matrice// 
	for (i=0;i<m;i++){
		for (j=i+1;j<m;j++){
			isti=1;
			for (k=0;k<n;k++){
				if (niz[i][k]!=niz[j][k]){
					isti=0;
				}
			}//kraj provjere//
			if (isti==1){
				for (k=j;k<n-1;k++){
					for (l=0;l<m;l++){
						niz[k][l]=niz[k+1][l];
					}
				}
				m--;
				j--;
			}
		}
	}//smanjivanje//
	//isti postupak,samo po drugom kriteriju//
	for (i=0;i<n;i++){
		for (j=i+1;j<n;j++){
			isti=1;
			for (k=0;k<m;k++){
				if (niz[k][i]!=niz[k][j]){
					isti=0;
				}
			}
		if (isti==1){
			for (k=j;k<n-1;k++){
				for (l=0;l<m;l++){
					niz[l][k]=niz[l][k+1];
				}
			}
			n--;
			j--;
		  }
		}
	}
	
	printf ("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for (i=0;i<m;i++){
		for (j=0;j<n;j++){
			printf ("%5d", niz[i][j]);
		}
		printf ("\n");
	}
	
	return 0;
}
