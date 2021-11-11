#include <stdio.h>

int main() {
	int i,j,n=0,x=0,y=0;
	char koo[20][20]={{'0'},{'0'}};
	
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			koo[i][j]=' ';
		}
	}
	do {
	printf("Unesite broj tacaka: ");
	scanf("%d",&n);
	if(n>0 && n<=10) 
		break;
	printf("Pogresan unos\n");
	} while(1);
	
	for(i=0;i<n;i++) {
		do{
			printf("Unesite %d. tacku: ",i+1);
			scanf("%d %d",&x,&y);
			if(x>=0 && x<20 && y>=0 && y<20)
				break;
			printf("Pogresan unos\n");
		} while(1);
		koo[y][x]='*';
	}
	for(i=0;i<20;i++) {
		for(j=0;j<20;j++){
		 	printf("%c",koo[i][j]);
		}
	printf("\n");
	}
	return 0;
}
