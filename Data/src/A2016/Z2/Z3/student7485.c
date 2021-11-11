#include <stdio.h>

int main() {
	int i,j,n,x,y,mx=0,my=0,a[20][20]={{0}};
	do{
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	if (n<1 || n>10) {
		printf("Pogresan unos\n");
		continue;}
	}while(n<1||n>10);
	for (i=0;i<n;i++){
		do{
		printf("Unesite %d. tacku: ",i+1 );
		scanf("%d %d", &x, &y);
		if (x<0||y<0||y>19||x>19) {
		printf("Pogresan unos\n");
		continue;}
		}while(x<0||y<0||y>19||x>19);
		if (y>my){
			my=y;
			mx=x;}
		else if (y==my && x>mx){
			mx=x;}
		a[y][x]=1;	
		}	
	for (i=0;i<=my;i++){
		for(j=0;j<20;j++){
			if (a[i][j]==1) printf("*");
			else printf(" ");
			if (i==my && j==mx) break;
		}
		printf("\n");
	}
	return 0;
}
