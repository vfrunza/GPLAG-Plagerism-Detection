#include <stdio.h>

int main() {
	int br_tacaka,i,j,k,niz_x[10],niz_y[10];
	char mat[20][20]={{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0}};
	printf("Unesite broj tacaka: ");
	scanf("%d",&br_tacaka);
	while(br_tacaka<=0 || br_tacaka>10) {
		printf("Pogresan unos\nUnesite broj tacaka: ");
		scanf("%d",&br_tacaka);
	}
	for(i=0;i<br_tacaka;i++) {
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d %d",&niz_x[i],&niz_y[i]);
		while(niz_x[i]<0 || niz_x[i]>19 || niz_y[i]<0 || niz_y[i]>19) {
			printf("Pogresan unos\nUnesite %d. tacku: ",i+1);
			scanf("%d %d",&niz_x[i],&niz_y[i]);
		}
	}
	for(k=0;k<br_tacaka;k++) {
		for(i=0;i<20;i++) {
			for(j=0;j<20;j++) {
				if(i==niz_y[k] && j==niz_x[k]) {
					mat[i][j]='*';
				}
			}
		}
	}
	for(i=0;i<20;i++) {
		for(j=0;j<20;j++) {
			if(mat[i][j]=='*')
				printf("%c",mat[i][j]);
			else
				printf(" ");
		}
		printf("\n");
	}
	return 0;
} 
