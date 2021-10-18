#include <stdio.h>
#define max 10
#define maxm 20

int main() {

	char mat[20][20];
	int t=1, x, y, i, j, bt, p=0, p1=0;

	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			mat[i][j]=' ';
		}
	}
do{
	if(p>0)printf("Pogresan unos\n");
	printf("Unesite broj tacaka: ");
	scanf("%d", &bt);
	p++;
}while(bt<=0 || bt>10);
		
	for(i=0;i<bt;i++){
		do{
		
		printf("Unesite %d. tacku: ", t);
		scanf("%d %d", &x, &y);
		if(x<0 || x>=20 || y<0 || y>=20){p1++;}
		if(p1>0){printf("Pogresan unos\n"); p1=0;}
		}while(x<0 || x>=20 || y<0 || y>=20);
		p1=0;
		mat[x][y]='*';
		t++;
		
	}
	
	for(i=0;i<=19;i++){
		for(j=0;j<=19;j++){
			printf("%c", mat[j][i]);
		}
		printf("\n");
	}

	return 0;
}
