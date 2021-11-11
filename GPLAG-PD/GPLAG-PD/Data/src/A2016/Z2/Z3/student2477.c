#include <stdio.h>
#define Br 20

int main() {
	char mat[Br][Br]={{0}};
	int n, x, y, i, j;
	
	labela:
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	if(n>10 || n<=0) {
		printf("Pogresan unos\n");
		goto labela;
	}
	for(i=0; i<n; i++) {
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &x, &y);
		if(x>=20 || y>=20 || x<0 || y<0){
			printf("Pogresan unos\n");
			i--;
			continue;
		}
		mat[x][y]=1;
	}
	
	for(i=0; i<Br; i++) {
		for(j=0; j<Br; j++) {
			if(mat[j][i]==1) {
				printf("*");
			} else printf(" ");
		}
		printf("\n");
	}
	
	
	return 0;
}
