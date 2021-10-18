#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int i,j,n,x,y,k;
	int mat[20][20]={0};
	do{
	printf("Unesite broj tacaka: ");
	scanf("%d",&n);
	if(n<1||n>10) printf("Pogresan unos\n");}
	while (n<1||n>10);
	
	for(i=0;i<n;i++){
		do {
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d %d",&x,&y);
		if (x<0||x>19 ||y<0||y>19) printf("Pogresan unos\n");
		}
		while(x<0||x>19||y<0||y>19);
		mat[y][x]++;
	}
	

	for(j=0;j<20;j++){
		for(k=0;k<20;k++){
			if(mat[j][k]==0) printf(" ") ;
			else printf("*");
		}
		printf("\n");
	}


	return 0;
}
