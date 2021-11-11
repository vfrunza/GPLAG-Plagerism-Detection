#include <stdio.h>
#define A 100
#define B 100

int main() {
	int m=0,n=0, matA[A][B]={{0}}, matB[A][B]={{0}}, matC[A][B]={{0}}, i=0, j=0, brojacA=0, brojacB=0, brojacC=0, k=0, l=0, kolikoistih=0;
do{	printf("Unesite brojeve M i N: ");
	scanf ("%d %d", &m,&n);} while(m>100 || n>100 || n<0 || m<0);
		printf ("Unesite clanove matrice A: ");
	for (i=0; i<m; i++) {
		for (j=0; j<n; j++) {
	scanf ("%d", &matA[i][j]);
	
		} }
		printf ("Unesite clanove matrice B: ");
		for(i=0; i<m; i++) {
			for(j=0; j<n; j++) scanf("%d", &matB[i][j]);
		}
		printf ("Unesite clanove matrice C: ");
		for(i=0; i<m; i++) {
			for(j=0; j<n; j++) scanf("%d", &matC[i][j]);
		}
		for(i=0; i<m; i++) {
			for(j=0; j<n; j++) { 
				for(k=0; k<m; k++) {
					for(l=0; l<n; l++) {
						if(matA[i][j]==matA[k][l]) brojacA++;
					}
				}
				for(k=0; k<m; k++) {
					for(l=0; l<n; l++) if(matA[i][j]==matB[k][l]) brojacB++;
				} if(brojacB!=brojacA) break;
			 for(k=0; k<m; k++) {
			 	for(l=0; l<n; l++) if(matA[i][j]==matC[k][l])brojacC++;
			 } if(brojacC!=brojacA) break;
			 kolikoistih++;
			}
		} if(kolikoistih==m*n) printf("DA\n");
		else printf("NE\n");
	return 0;
}
