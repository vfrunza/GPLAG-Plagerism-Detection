#include <stdio.h>
#include <math.h>

int main() {
	char mat [20][20];
	int i,j,x,y,c;
	for (i=0;i<20;i++){
		for(j=0;j<20;j++){
			mat[i][j]=' ';
		}
	}
	printf("Unesite broj tacaka: ");
	scanf("%d", &c);
	while(c<1||c>10){
		printf("Pogresan unos\n");
	scanf("%d",&c);
		printf("Unesite broj tacaka: ");
	}
	for(i=0;i<c;i++){
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d" "%d" ,&y,&x);
		while(y<0||y>19||x<0||x>19){
			printf("Pogresan unos\n");
			printf("Unesite %d. tacku: ",i+1);
			scanf("%d" "%d" ,&y,&x);
		}
	mat[x][y]='*';
	}
		for (i=0;i<20;i++){
		for(j=0;j<20;j++){
			printf("%c" ,mat[i][j]);
		}printf("\n");
		}
	return 0;
}
