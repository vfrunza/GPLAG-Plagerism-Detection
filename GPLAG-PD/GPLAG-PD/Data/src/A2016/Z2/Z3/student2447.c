#include <stdio.h>
#define VISINA 20
#define SIRINA 20

int main() {
	
	int i,j,mat[VISINA][SIRINA]={0},k,broj,x,y;
	
	printf("Unesite broj tacaka: ");
	scanf("%d",&broj);
	while(broj>10 || broj<=0){
		printf("Pogresan unos\n");
		printf("Unesite broj tacaka: ");
		scanf("%d",&broj);
	}
	
	for(k=0;k<broj;k++){
		printf("Unesite %d. tacku: ",k+1);
		scanf("%d %d",&x,&y);
		while(x<0 || y<0 || x>19 || y>19){
			printf("Pogresan unos\n");
			printf("Unesite %d. tacku: ",k+1);
			scanf("%d %d",&x,&y);
		}
		mat[y][x]='*';
		
	}
				for(i=0;i<VISINA;i++){
					for(j=0;j<SIRINA;j++){
						if(mat[i][j]=='*'){
							printf("*");
						}else {
							printf(" ");
						}
					}printf("\n");
				}
	
	
	
	
	return 0;
}
