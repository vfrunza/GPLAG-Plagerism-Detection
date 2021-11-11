#include <stdio.h>

int main() {
	int i,j, x, a, b;
	char mat[20][20]={'a'};
	printf("Unesite broj tacaka: ");
	scanf("%d", &x);
	while (x>10 || x<=0) {
		printf("Pogresan unos\nUnesite broj tacaka: ");
		scanf("%d", &x);
	}
	
	for(i=0; i<x; i++) {
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &a, &b);
		while(a<0 || b<0 || a>19 || b>19) {
			printf("Pogresan unos\nUnesite %d. tacku: ", i+1);
			scanf("%d %d", &a, &b);
		
		}
		
		mat[a][b]='*';
	}
	
	for(j=0; j<20; j++) {
		for (i=0; i<20; i++) {
			if(mat[i][j]!='*')
			printf(" ");
			else printf("*");
		
		}
		printf("\n");
	}
	
	return 0;
}
