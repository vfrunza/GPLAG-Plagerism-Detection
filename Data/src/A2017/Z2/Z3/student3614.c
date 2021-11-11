#include <stdio.h>

int main() {
	//int n1, m1, n2, m2;
	int n, m;
	int i, j;
	int A[100][100], B[100][100];
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &n, &m);
	printf("Unesite clanove matrice A: "); 
	for(i=0; i<n; i++) {
		for(j=0; j<m; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	/*printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &n2, &m2);*/
	printf("Unesite clanove matrice B: ");
	for(i=0; i<n; i++) {
		for(j=0; j<m; j++) {
			scanf("%d", &B[i][j]);
		}
	}
	int s=0; 
	//if(m1==n2 && n1==m2) {
		for(i=0; i<n; i++) {
			for(j=0; j<m; j++) {
				if(B[i][j]==A[j][n-i-1]) s=1;
			}
		}
	//}
	if(s) printf ("DA");
	else printf ("NE"); 
	return 0;
}
