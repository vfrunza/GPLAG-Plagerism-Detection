#include <stdio.h>

int main() {
	
	int mat[20][20]={{1}};
	int n, i, x, y, j;
	
	
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	while(n<=0 || n>10)
	 {
	 	printf("Pogresan unos\nUnesite broj tacaka: ");
	 	scanf("%d", &n);
	 }
	 
	 for(i=0; i<n; i++) {
	 	printf("Unesite %d. tacku: ", i+1);
	 	scanf("%d %d", &x, &y);
	 	if(x<0 || y<0 || x>19 || y>19) {
	 		printf("Pogresan unos\n");
	 		i--;
	 		continue;
	 	}
	 	mat[y][x]='*';
	 	
	 }
	 
	 for(i=0; i<20; i++) {
	 	for(j=0; j<20; j++) {
	 		if(mat[i][j]=='*')
	 			printf("*");
	 			else {
	 				printf(" ");
	 			}
	 	}
	 	printf("\n");
	 }
	return 0;
}
