#include <stdio.h>

int main() {
	int i,j,A[100],B[100],C[100],m,n;
	
	printf("Unesite brojeve M i N: ");
	do {
		scanf("%d %d", &m, &n);
	} while(m>100 || n>100);
	
	printf("Unesite clanove matrice A: ");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%d", &A[i]);
		}
	}
	
	printf("Unesite clanove matrice B: ");
	return 0;
}
