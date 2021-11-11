#include <stdio.h>

int main()
{
	int i=0, j=0, m, n, a=0, b=0, k=0, brojac=0;
	int mat[100][100], mat2[100][100];
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &n, &m);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &b, &a);
	printf("Unesite clanove matrice B: ");
	for(i=0; i<a; i++) {
		for(j=0; j<b; j++) {
			scanf("%d", &mat2[i][j]);
		}
	}
	k=0;
	for(i=0; i<n; i++) {
		for(j=m-1; j>=0; j--) {
			if(mat2[i][j]==mat[i][k]) {
				brojac--;
			}
			k++;
		}
		k=0;
	}
	if(brojac==m*n) {
		printf("DA");
	} else printf("NE");

	return 0;
}
