#include <stdio.h>

int main() {
	int n,i,j,x,y;
	char mat[20][20];
	do{
		printf("Unesite broj tacaka: ");
		scanf("%d",&n);
		if(n>10 || n<=0) {printf("Pogresan unos\n");  continue;}
		if(n<=10) break;

	}while(1);

	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			mat[i][j]=32;
		}
	}
	for(i=0;i<n;i++){
		while(1){
			printf("Unesite %d. tacku: ",i+1);
			scanf("%d %d",&x,&y);
			if(x>=20 || x<0 || y>=20 || y<0){ printf("Pogresan unos\n"); continue;}
			mat[y][x]=42;
			if(x<=20 || x>0 || y<=20 || y>0) break;
		}
		
	}
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			printf("%c",mat[i][j]);
	
		}
		printf("\n");
	}
	
	return 0;
}
