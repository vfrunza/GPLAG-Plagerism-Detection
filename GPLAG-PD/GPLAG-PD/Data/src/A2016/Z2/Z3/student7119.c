#include <stdio.h>

int main() {
	int mat[20][20]={0},i,n,j,x,y;
	f:printf("Unesite broj tacaka: ");
	
	 scanf("%d",&n);
	if(n<=0 || n>10) {
		printf("Pogresan unos\n");
		goto f;}
		
	for(i=0;i<n;i++) {
	g: printf("Unesite %d. tacku: ",i+1);
			scanf("%d %d",&x,&y);
			
			if(x<0 || x>19 || y<0 || y>19 ) {
				printf("Pogresan unos\n"); goto g;
			}
			mat[y][x]=1;
		}
	for(i=0;i<20;i++) {
		for(j=0;j<20;j++) {
			if(mat[i][j]==1) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}
