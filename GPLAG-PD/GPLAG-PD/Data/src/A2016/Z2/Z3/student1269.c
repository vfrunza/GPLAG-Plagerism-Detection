#include <stdio.h>
int main() {
	int mat[20][20]={{0},{0}}, x,y,i,j,n;
	for(i=0;i<1;i++){
		printf("Unesite broj tacaka: ");
		scanf("%d", &n);
		if (n>10 || n<=0) {
		printf("Pogresan unos\n");
		i--;
		}
	}
	for (i=0;i<n;i++) {
		printf ("Unesite %d. tacku: ", i+1);
		scanf ("%d %d", &x, &y);
		if (x<0 || x>=20 || y<0 || y>=20) {
			printf ("Pogresan unos\n");
		i--;
		continue;
		}
		mat[x][y]=1;
	}
	for(j=0;j<20;j++){
		for(i=0;i<20;i++){
			if(mat[i][j]==1) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}
	