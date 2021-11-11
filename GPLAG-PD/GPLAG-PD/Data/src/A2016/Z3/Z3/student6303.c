#include <stdio.h>

int pronadji_uljeza(int matrix[200][200], int m, int n) {
	int  j, k=0, l, t, s, pronasla=1;
	while(k<n) {
		j=k+1;
		while(j<n) {
			if(matrix[0][j]==matrix[0][k]) {
				pronasla=1;
				for(l=0; l<m; l++)	if(matrix[l][j]!=matrix[l][k]) pronasla=0;
			if(pronasla==1) {
				s=0;
				while(s<m) {
					t=j;
				while(t<n) {
				matrix[s][t]=matrix[s][t+1]; t++; } s++; }
				n--;
				j--;
				}
			}
			j++;
		}
		k++;
	}
	return n;
}

void obrni_okreni (int matrix[200][200], int m) {
	int i, j, temp;
	for(i=0; i<200; i++) {
		for(j=0; j<i; j++) {
			temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
		}
	}
}
int main() {
	
	int granice=1, m, n, i, j, matrix[200][200]={{0}};
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m, &n);
		if(m<1 || n>200 || m>200 || n<1)
		printf("Brojevi nisu u trazenom opsegu.\n");
		else granice=0;
	} while(granice==1);
	
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++) 
	for(j=0; j<n; j++)
	scanf("%d", &matrix[i][j]);
	n=pronadji_uljeza(matrix, m, n);
	obrni_okreni(matrix, m);
	m=pronadji_uljeza(matrix, n, m);
	obrni_okreni(matrix, n);
	
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++)
		printf("%5d", matrix[i][j]);
		printf("\n");
	}
	return 0;
}
