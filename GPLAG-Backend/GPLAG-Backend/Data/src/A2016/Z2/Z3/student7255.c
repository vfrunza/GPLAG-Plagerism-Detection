#include <stdio.h>

int main() {
	int bt,n,i,j;
	int p,d;
	char niz[20][20];
	printf("Unesite broj tacaka: ");
	scanf("%d", &bt);
	while (bt<1 || bt>10){
		printf("Pogresan unos\n");
		printf("Unesite broj tacaka: ");
		scanf("%d", &bt);
	}
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			niz[i][j]=' ';
		}
	}
	
	for(i=0;i<bt;i++){
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d %d",&p,&d);
		while(p<0 || p>19 || d<0 || d>19){
			printf("Pogresan unos\n");
			printf("Unesite %d. tacku: ",i+1);
			scanf("%d %d",&p,&d);
		}
		niz[d][p]='*';
	}
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			printf("%c",niz[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
