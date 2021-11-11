#include <stdio.h>

int main() {
	int brt,x,y,brojaci,brojacj;
	int mat[20][20]={0};
	printf("Unesite broj tacaka: ");
	scanf("%d",&brt);
		while ((brt>10)||(brt<=0)){
			printf("Pogresan unos\n");
		printf("Unesite broj tacaka: ");
		scanf("%d",&brt);
		}
		for (brojaci=0;brojaci<brt;brojaci++){
			printf("Unesite %d. tacku: ",brojaci+1);
			scanf("%d %d", &x,&y);
			while((x<0)||(x>19)||(y<0)||(y>19)){
					printf("Pogresan unos\n");
				printf("Unesite %d. tacku: ",brojaci+1);
			scanf("%d %d", &x,&y);
			}
			mat[y][x]=1;
		}
			
			for(brojaci=0;brojaci<20;brojaci++){
				for(brojacj=0;brojacj<20;brojacj++){
					if(mat[brojaci][brojacj]==1){
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
