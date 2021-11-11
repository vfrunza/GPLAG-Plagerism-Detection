#include <stdio.h>

int main() {
	int kor[20][20]={0};
	int k, i, j, brt, x, y, ymax=0;
	
	do {
	printf("Unesite broj tacaka: "); scanf("%d",&brt);
	if (brt<1 || brt>10) printf("Pogresan unos\n");
	}while (brt<1||brt>10);
	
	for (k=1; k<=brt; k++){
		printf("Unesite %d. tacku: ",k); scanf("%d %d",&x,&y);
		if (x>19 || x<0 || y>19 || y<0){
			printf("Pogresan unos\n"); k--;
		}else{
			kor[x][y]=1;
			if (y>ymax) ymax=y;
		}
	}
	for (j=0; j<20; j++){
		for (i=0; i<20; i++){
			if (kor[i][j]==1) {
				printf("*");
			}else{
				printf(" ");
			}
		}
		if (j==ymax) break;
		printf("\n");
	}
	return 0;
}