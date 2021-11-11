#include <stdio.h>
#define VISINA 20
#define SIRINA 20

int main() {
	int sistem[VISINA][SIRINA]={{0}},i,j,n,x;
	do{
		printf("Unesite broj tacaka: ");
		scanf("%d",&n);
		if(n>10 || n<=0)printf("Pogresan unos\n");
	}
	while(n>10 || n<=0);
	for(x=0;x<n;x++){
		printf("Unesite %d. tacku: ",x+1);
		scanf("%d %d",&i,&j);
		if(i<VISINA && i>=0 && j<SIRINA && j>=0)
			sistem[i][j]=1;
		else {
			printf("Pogresan unos\n");
			x--;
		}
	}
	
	for(j=0;j<VISINA;j++){
		for(i=0;i<SIRINA;i++){
			if(sistem[i][j]==1){
				printf("*");
			}
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}
