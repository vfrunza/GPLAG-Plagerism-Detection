#include <stdio.h>

int main() {
	int mat[20][20]={{0}};
	int i, j, k,n , x, y;
	
	for(;;) {
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	
    if (n<=0 || n>10) printf("Pogresan unos\n");
    else break;
	}
	
	

	for(i=0; i<n; i++) {
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d%d", &x, &y);
	
		if(x<0 || y<0 || x>=20 || y>=20) {
			printf("Pogresan unos\n ");
			i--;
		}
	mat[y][x]=1;
			}


		for(i=0; i<20; i++) {
			for(j=0; j<20; j++) {
				if(mat[i][j]==1) printf("*");
				else printf(" ");
			}
			printf("\n");
		}
	
	
	return 0;
}
