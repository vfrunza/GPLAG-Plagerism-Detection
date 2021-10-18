#include <stdio.h>

int main() {
	int i, j, k, l, m, br_R, br_C, sir_C;
	
	do{
		printf("Unesite broj redova: ");
		scanf("%d", &br_R);
	}
	
	while(br_R <= 0 || br_R > 10);
	
	do{
		printf("Unesite broj kolona: ");
		scanf("%d", &br_C);
	}
	
	while(br_C <= 0 || br_C > 10);
	
	do{
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &sir_C);
	}
	
	while(sir_C <= 0 || sir_C > 10);
	
	for(k = 0; k < br_R; k++){
		
		for(i=0; i<br_C; i++){
			printf("+");
			
			for(j=0; j<sir_C; j++){
				printf("-");
			}
			
			if(i == br_C - 1){
				printf("+");
			}
		}
		printf("\n");
		
		for(i=0; l<br_C; l++){
			printf("|");
			
			for(m=0; m<sir_C; m++){
				printf(" ");
			}
			
			if(l == br_C - 1){
				printf("|");
			}
		}
		printf("\n");
	}
	
	for(i=0; i<br_C; i++){
		printf("+");
		
		for(j=0; j<sir_C;j++){
			printf("-");
		}
		
		if(i == br_C - 1){
			printf("+");
		}
	}

	return 0;
}
