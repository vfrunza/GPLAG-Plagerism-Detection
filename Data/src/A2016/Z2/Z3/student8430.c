#include <stdio.h>

int main() {
	int i, j, n, p, q;
	char mat[20][20];
	for(i=0; i<20; i++) {
		for(j=0; j<20; j++) {
			mat[i][j]=' ';
		}
	}
	while(2) {
		printf("\nUnesite broj tacaka: ");
		scanf("%d", &n);
		if(n<=0 || n>10) printf("Pogresan unos");
		else break;
	} 
	for(i=0; i<n; i++) {
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &q, &p);
		if(p<0 || p>19 || q<0 || q>19) { printf("Pogresan unos\n");
		i--;
		}
		mat[p][q]='*';
	}
	for(i=0; i<20; i++) {
		for(j=0; j<20; j++) {
			printf("%c", mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}