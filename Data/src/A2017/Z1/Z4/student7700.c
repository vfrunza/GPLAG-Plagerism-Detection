#include <stdio.h>

int main() {
	int i,j,z ;
	int brkolona,brredova, sirinakolone;
	do
	{
	printf("Unesite broj redova: ");
	scanf("%d", &brredova);
	}
	while(brredova<1 || brredova>10);
	do{
		printf("Unesite broj kolona: ");
		scanf("%d", &brkolona);
		
	}
		while(brkolona<1 || brkolona>10);
	do{
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &sirinakolone);
	}while(sirinakolone<1 || sirinakolone>10);
	
	for(z=0;z<brredova;z++){
		for(i=0;i<brkolona;i++){
	printf("+");
	for(j=0;j<sirinakolone;j++){
		printf("-");
	}
			
	}
	printf("+");
	printf("\n");
	for(i=0;i<brkolona;i++){
		printf("|");
		for(j=0;j<sirinakolone;j++){
			printf(" ");
		}
	}
	
	printf("|");
	printf("\n");
		
	}
	for(i=0;i<brkolona;i++){
		printf("+");
		for(j=0;j<sirinakolone;j++){
			printf("-");
		}
	}
		
		
	
	printf("+");
	return 0;
}
