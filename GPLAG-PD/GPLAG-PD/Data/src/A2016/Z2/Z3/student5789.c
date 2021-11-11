#include <stdio.h>


int main() {
	int mat[20][20]={{0}};
	
	int i,j,x,y,n;
	do{
	printf("Unesite broj tacaka: ");
	scanf("%d",&n);
		if(n<=0 || n>10)
			printf("Pogresan unos\n");
	}
	
	while(n<=0 || n>10);
		
		
	for (i=1; i<=n; i++ ) {
		printf("Unesite %d. tacku: ", i);
		scanf("%d %d", &x,&y);
		if((x>19 || x<0 ) || (y>19 || y<0)) {
			printf("Pogresan unos\n");
			i--;
		}
	
		else 
			mat[y][x]++;
		
	}
	for(i=0; i<20; i++){
		for(j=0; j<20; j++){
			if(mat[i][j]>=1) printf("*");
			else 
				printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}
