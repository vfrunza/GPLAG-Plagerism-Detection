#include <stdio.h>
#define BROJ 20

int main() {
	int b,k,i,j;
	char niz[BROJ][BROJ];
	printf("Unesite broj tacaka: ");
	scanf("%d", &b);
	while(b<1 || b>10){
		printf("Pogresan unos \n");
		printf("Unesite broj tacaka: ");
		scanf("%d", &b);
	}for(i=0;i<BROJ;i++){
		for(j=0;j<BROJ;j++){
			niz[i][j]=' ';
			
		}
	}
	for(k=0;k<b;k++){
		printf("Unesite %d. tacku: ",k+1);
		scanf("%d", &i);
		scanf("%d", &j);
		while(i<0 || j<0 || j>19 || i>19){
			printf("Pogresan unos \n");
			printf("Unesite %d. tacku: ",k+1);
			scanf("%d",&i);
			scanf("%d",&j);
		}
		niz[i][j]='*';
	}
	for(i=0;i<BROJ;i++){
		for(j=0;j<BROJ;j++){
			printf("%c",niz[j][i]);
		}
		printf("\n");
	}


		
	
	return 0;
}
