#include <stdio.h>
#define brEL 100

int main()
{
	int m, n, m1, n1, i, j, iste=1;
	double A[brEL][brEL], B[brEL][brEL], Atr[brEL][brEL], Aobr[brEL][brEL];
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &m, &n);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%lf", &A[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &m1, &n1);
	printf("Unesite clanove matrice B: ");
	for(i=0; i<m1; i++) {
		for(j=0; j<n1; j++) {
			scanf("%lf", &B[i][j]);
		}
	}
	if(m == m1 || n == n1) {
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			Atr[i][j] = A[j][i];
		}
	}
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			Aobr[i][j] = Atr[i][n-j-1];
		}
	}
	for(i=0; i<m1; i++) {
		for(j=0; j<n1; j++) {
			if(B[i][j] != Aobr[i][j]) {
				iste = 0;
				break;
			}
		}
	}
	if(iste == 1) printf("DA");
	else printf("NE");
	}
	return 0;
}
