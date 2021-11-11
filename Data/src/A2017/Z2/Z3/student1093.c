#include <stdio.h>

int main()
{
	int m1, m2, n1, n2, i, j;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &m1, &n1);
	printf("Unesite clanove matrice A: ");
	for(i = 0 ; i < m1; i++) {
		for(j = 0; j < n1; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &m2, &n2);
	printf("Unesite clanove matrice B: ");
	for(i = 0 ; i < m2; i++) {
		for(j = 0; j < n2; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
	if(m1 != m2 || n1 != n2) {
		printf("NE");
		return 0;
	}
	for(i = 0; i < m1; i++) {
		for(j = 0; j < n1; j++) {
				
		}
	}



	return 0;
}
