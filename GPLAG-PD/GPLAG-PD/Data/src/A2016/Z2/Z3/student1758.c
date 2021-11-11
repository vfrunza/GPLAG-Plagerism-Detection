#include <stdio.h>

int main() {
	int mat[20][20]={{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0}}, n, i, j, c=0, k;
	for(i=0;; i++) {
		printf("Unesite broj tacaka: ");
		scanf("%d", &n);
		if(n<=0 || n>10) {
			printf("Pogresan unos\n");
			continue;
		}
		else {
			break;
		}
	}
	for(k=0; k<n; k++) {
		c++;
		printf("Unesite %d. tacku: ", c);
		scanf("%d %d", &j, &i);
		if(i<0 || i>=20 || j<0 || j>=20) {
			printf("Pogresan unos\n");
			k--;
			c--;
		}
		else {
			mat[i][j]='*';
		}
	}
	for(i=0; i<=19; i++) {
		for(j=0; j<=19; j++) {
			if(mat[i][j]=='*') {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
	
	return 0;
}
