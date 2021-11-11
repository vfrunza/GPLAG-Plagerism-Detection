#include <stdio.h>

int main() {
	char mat[20][20];
	int n,a=20,i,j,b,c;
	do {
	printf("Unesite broj tacaka: ");
	scanf("%d",&n);
	if (n<1 || n>10) printf("Pogresan unos\n");
	} while (n<1 || n>10);
	for(i=0;i<a;i++) {
		for(j=0;j<a;j++) {
			mat[i][j]=' ';
		}
	}
	for(j=1;j<=n;j++) {
		do {
		printf("Unesite %d. tacku: ",j);
		scanf("%d %d",&b,&c);
		if(b<0 || b>19 || c<0 || c>19) printf("Pogresan unos\n");
		} while (b<0 || b>19 || c<0 || c>19);
		mat[b][c]='*';
		}
	
	for(i=0;i<a;i++) {
		for(j=0;j<a;j++) {
			printf("%c",mat[j][i]);
		}
		printf("\n");
	}
	return 0;
}
