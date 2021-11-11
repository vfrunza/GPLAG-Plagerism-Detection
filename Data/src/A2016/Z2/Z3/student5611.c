#include <stdio.h>

int main() {
	char mat[20][20];
	int x=0,y=0,n=0,i=0,j=0;
	
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	if(n<=0 || n>10){
		printf("Pogresan unos\n");
		printf("Unesite broj tacaka: ");
		scanf("%d", &n);
		if(n<=0 || n>10){
			printf("Pogresan unos\n");
			printf("Unesite broj tacaka: ");
			scanf("%d", &n);
			if(n<=0 || n>10){
				printf("Pogresan unos\n");
				printf("Unesite broj tacaka: ");
				scanf("%d", &n);
				if(n<=0 || n>10){
					printf("Pogresan unos\n");
					printf("Unesite broj tacaka: ");
					scanf("%d", &n);
				}
			}
		}
	}
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			mat[i][j]=' ';
		}
	}
	for(i=0;i<n;i++){
		do{
			printf("Unesite %d. tacku: ", i+1);
			scanf("%d%d", &y,&x);
			
			if(x<0 || y<0 || x>19 || y>19){
				printf("Pogresan unos\n");
			}
			
		}
		while(x<0 || y<0 || x>19 || y>19);
		mat[x][y]='*';
	}
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			printf("%c", mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}
