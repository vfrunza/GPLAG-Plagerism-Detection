#include <stdio.h>

int main() {
	int polje[20][20]={{0}},brojac=0;
	int x=0,y=0,n=0,i=0,j=0;

	
	do {
		printf("Unesite broj tacaka: ");
		scanf("%d",&n);
		if(n>10||n<=0){ 
		printf("Pogresan unos\n");
		}
	} while(n<=0||n>10);
	
	for (i=0;i<n;i++){
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d %d",&x,&y);
		brojac++;
		if ((x>19||x<0)||(y>19||y<0)){
			printf("Pogresan unos\n");
			i--;
		} else {
			polje[y][x]=1;
		}
	}
	

	
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			if(polje[i][j]==1){
				printf("*");
			} else {
				printf(" ");
			}
	}
	printf("\n");
}
	return 0;
}
