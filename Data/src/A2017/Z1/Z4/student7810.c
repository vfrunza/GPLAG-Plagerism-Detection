#include <stdio.h>

int main() {

	int redovi, kolone, sirina,i,j;
	do{
		printf("Unesite broj redova: ");
		scanf("%d", &redovi);
		printf("Unesite broj kolona: ");
		scanf("%d", &kolone);
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &sirina);
	}while(redovi<=0 || redovi>10 || kolone<=0 || kolone>10 || sirina<=0 || sirina>10);
	for(i=1;i<=redovi*4+1;i++){
		for(j=1;j<=(((sirina+1)*kolone)+1);j++){
			if((i==1 && j==1) || (i==1 && j==(((sirina+1)*kolone)+1)) || (j==1 && i==redovi*4+1) || (i==redovi*4+1 && j==(((sirina+1)*kolone)+1)) || ) printf("+");
			
			else if( (j==1 && i==((redovi*4+2)/2))  || (j==(((sirina+1)*kolone)+1) && i==((redovi*4+2)/2)) ) printf("|");
			else if((i==1 && j!=1) || (i==1 && j!=(((sirina+1)*kolone)+1)) || (j!=1 && i==redovi*4+1) || (i==redovi*4+1 && j!=(((sirina+1)*kolone)+1))) printf("-");
			else printf(" ");
			
			
			
		}
		printf("\n");
	}

	return 0;
}
