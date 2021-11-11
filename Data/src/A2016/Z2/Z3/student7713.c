#include <stdio.h>

int main() {
	
	int matrica[20][20]={{0}};
	int x,j,k,i;
	while(1) {
		printf("Unesite broj tacaka: ");
		scanf("%d", &x);
		if(x<=0 || x>10) {
			printf("Pogresan unos\n");
			continue;
		} else break;
	}
	
	for(k=0;k<x;k++) {
		greska: printf("Unesite %d. tacku: ", k+1);
		scanf("%d %d", &i, &j);
		if(i>19 || j>19 || i<0 || j<0) {
			printf("Pogresan unos\n");
			goto greska;
		}
		matrica[i][j]++;
	}
	for(i=0;i<20;i++) {
		for(j=0;j<20;j++) {
			if(matrica[j][i]!=0) printf("*");
			else printf(" ");
		}
	printf("\n");
	}
	
	return 0;
}
