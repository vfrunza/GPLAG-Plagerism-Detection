#include <stdio.h>

int main() {
	int n,i,j,k1,k2,mat[20][20];
	ponovo:
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	if(n<=0 || n>10) {
		printf("Pogresan unos\n");
		goto ponovo;
	}
	for (i=0;i<20;i++) {
		for(j=0;j<20;j++) {
			mat[i][j]=0;
		}
	}
	for(i=0;i<n;i++) {
		greska:
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &k1, &k2);
		if(k1<0 || k1>=20 || k2<0 || k2>=20) {
			printf("Pogresan unos\n");
			goto greska;
		} 
		mat[k2][k1]=1;
	}
	for(i=0;i<20;i++) {
		for(j=0;j<20;j++) {
			if(mat[i][j]==1) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
