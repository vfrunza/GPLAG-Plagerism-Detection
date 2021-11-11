#include <stdio.h>
#define DUZ 20

int main() {
	int i,j,br=1,brt,x,y,mat[DUZ][DUZ];
	do{
		printf("Unesite broj tacaka: ");
		scanf("%d", &brt);
		if(brt<=0 || brt>10)
		printf("Pogresan unos\n");
	}while(brt<=0 || brt>10);
	for(i=0; i<DUZ; i++){
		for(j=0; j<DUZ; j++){
			mat[i][j]=0;
		}
	}
	while(br<=brt){
		printf("Unesite %d. tacku: ", br);
		scanf("%d%d", &x,&y);
		if(x<0 || x>=20 || y<0 || y>=20){
			printf("Pogresan unos\n");
			continue;
		}
		else br++;
		mat[y][x]=1;
	}
	for(i=0; i<DUZ; i++){
		for(j=0; j<DUZ; j++){
		    if(mat[i][j]==1)
		    printf("*");
		    else
		    printf(" ");
		}
		printf("\n");
	}
	return 0;
}
