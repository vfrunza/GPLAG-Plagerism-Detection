#include <stdio.h>

int main (){
	int red, kolona, sirina;
	int i,j,k;
	
	do{
		printf("Unesite broj redova: ");
		scanf("%d", &red);
	}while (red>10 || red <=0);
	do{
		printf("Unesite broj kolona: ");
		scanf("%d", &kolona);
	}while (kolona>10 || kolona <=0);

	do{
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &sirina);
	}while (sirina>10 || sirina <=0);
	
	
	for(i=0; i<red; i++){
		for (j=0; j<kolona; j++){
			printf("+");
			
			for (k=0; k<sirina; k++){
				printf("-");
		}
	}
			printf("+\n");
	for (k=0; k<kolona;k++){
		printf("|");
		for (j=0; j<sirina; j++){
			printf(" ");
		}
	}
	printf("|\n");
	}
	
	for(j=0;j<kolona; j++){
		printf("+");
		
		for (k=0; k<sirina; k++){
			printf("-");
		}
	}
	printf("+");
		
    
	return 0;
}