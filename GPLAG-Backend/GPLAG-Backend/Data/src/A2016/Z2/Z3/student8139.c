#include <stdio.h>
#define VISINA 20
#define SIRINA 20

int main() {
	
	int i, j, k, n, x, y;
	int mat[VISINA][SIRINA]={0};
	do{
		printf("Unesite broj tacaka: ");
		scanf("%d", &n);
		if(n<=0 || n>10) printf("Pogresan unos\n");
	} while(n<=0 || n>10);
	for(i=0; i<n; i++){
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &x, &y);
		if(x<0 || x>19 || y<0 || y>19){
			printf("Pogresan unos\n");
			i--;
			continue;
		}
		for(j=0; j<VISINA; j++){
			for(k=0; k<SIRINA; k++){
				if(j==y && k==x) mat[j][k]=1;
			}
		}
	}
	for (i=0; i<VISINA; i++) {
		for (j=0; j<SIRINA; j++){
		if(mat[i][j]==1) printf("*", mat[i][j]);
		else printf(" ", mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}