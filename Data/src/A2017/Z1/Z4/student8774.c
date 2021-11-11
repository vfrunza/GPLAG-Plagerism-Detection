#include <stdio.h>

int main() {
	int i,j,brredova,brkolona,sirina;
	do{
	printf("Unesite broj redova: ");
	scanf("%d",&brredova);
	}while(brredova<=0 || brredova >10);
	
	do{
	printf("Unesite broj kolona: ");
	scanf("%d",&brkolona);
    }while(brkolona<=0 || brkolona >10);
	
	do{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&sirina);
	}while(  sirina<=0 || sirina>10);
	
	for(i=0;i<brredova*2+1;i++){
		for(j=0;j<=brkolona*(sirina+1);j++){
			if(i%2==0 && j%(sirina+1)==0)
			printf("+");
			else if(i%2==1 && j%(sirina+1)==0)
			printf("|");
			else if(i%2==0)
			printf("-");
			else printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}
