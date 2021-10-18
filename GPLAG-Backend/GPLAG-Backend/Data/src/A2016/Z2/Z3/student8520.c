#include <stdio.h>

int main() {
	int mat[20][20];
	int i,j;
	
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			mat[i][j]=0;
		}
	}
	int brojTacaka;
	int prva,druga;
	printf("Unesite broj tacaka: ");
	scanf("%d",&brojTacaka);
	while(brojTacaka<=0 || brojTacaka>10){
		printf("Pogresan unos\n");
		printf("Unesite broj tacaka: ");
		scanf("%d",&brojTacaka);
	}
	/*unos tacaka */
	for(i=0;i<brojTacaka;i++){
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d %d",&prva,&druga);
		while(prva<0 || prva>19 || druga<0 || druga>19){
			printf("Pogresan unos\n");
			printf("Unesite %d. tacku: ",i+1);
			scanf("%d %d",&prva,&druga);
		}
		mat[prva][druga]=1;
	}
	/*ispis*/
	
	for(i = 0;i <20 ; i++){
		for(j=0;j<20;j++){
			if(mat[j][i]==1){
				printf("*");
			}
			else
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}
