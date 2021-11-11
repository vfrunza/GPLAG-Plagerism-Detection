#include <stdio.h>

int main() {
	int redovi,kolone,sirinakolone, i, j, k;
	do{
		printf("Unesite broj redova: ");
			scanf("%d",&redovi);
	}while(redovi<=0||redovi>10);
	do{	
		printf("Unesite broj kolona: ");
			scanf("%d",&kolone);
	}while(kolone<=0||kolone>10);	
	do{	
		printf("Unesite sirinu jedne kolone: ");
			scanf("%d",&sirinakolone);
	}while(sirinakolone<=0||sirinakolone>10);
		
		for(i=0;i<redovi;i++){
			for(j=0;j<kolone;j++){
				printf("+");
				for(k=0;k<sirinakolone;k++){
					printf("-");
				}
			}	
			printf("+");
		printf("\n");
			for(j=0;j<kolone;j++){
				printf("|");
				for(k=0;k<sirinakolone;k++){
					printf(" ");
				}
			}	
			printf("|");
			printf("\n");
		}
		for(j=0;j<kolone;j++){
			printf("+");
			for(k=0;k<sirinakolone;k++){
				printf("-");
			}
		}
		printf("+");
	return 0;
}