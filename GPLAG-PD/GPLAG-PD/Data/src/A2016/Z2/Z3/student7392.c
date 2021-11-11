#include <stdio.h>

int main() {
	int n;
	int j, i, x, y;
	char matrica[25][25];
	do{
		printf("Unesite broj tacaka: ");
		scanf("%d", &n);
		if(n<1 || n>10)printf("Pogresan unos\n");
	}while(n<1 || n>10);
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			matrica[i][j]=' ';
		}
	}
	for(i=1;i<=n;i++){
		do{
			printf("Unesite %d. tacku: ", i);
			scanf("%d %d", &x, &y);
			if(x<0 || y<0 || x>19 || y>19)printf("Pogresan unos\n");
		}while(x<0 || y<0 || x>19 || y>19);
		matrica[y][x]='*';
	}
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			printf("%c", matrica[i][j]);
		}
		printf("\n");
	}
	return 0;
}
