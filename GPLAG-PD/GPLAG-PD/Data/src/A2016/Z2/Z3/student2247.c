#include <stdio.h>
#define SIRINA 20
#define VISINA 20

int main() {
int i, j, n, x, y, m=0;
int mat[SIRINA][VISINA]={{0},{0}};
	
again:
printf("Unesite broj tacaka: ");
scanf("%d", &n);
if(n<=0 || n>10) {printf("Pogresan unos\n"); goto again;}
	
for(i=1; i<=n; i++) {
	ponovo:
	printf("Unesite %d. tacku: ", i);
	scanf("%d %d", &x, &y);
	if((x<0 || x>19) || (y<0 || y>19)) {printf("Pogresan unos\n"); goto ponovo;}
	else {
		mat[x][y]=1;
	}
}
for(i=0; i<=19; i++) {
	for(j=0; j<=19; j++) {
		if(mat[j][i]==1) {printf("*"); m++;}
		else printf(" ");
	}
if(m==n) {return 0;}
printf("\n");
}
return 0;
}
