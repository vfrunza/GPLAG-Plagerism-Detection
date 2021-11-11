#include <stdio.h>

int main() {
	
	int n, i, j;
	
	do{
		printf("Unesite broj N: ");
		scanf("%d", &n);
		
		if(n < 8 || n % 4 != 0)
			printf("Neispravno N!\n");
		
	}while(n < 8 || n % 4 != 0);
	
	int halfSize = (n / 2);
	
	printf("\n");
	
	/*Gornja polovina*/
	for(i = 0; i < halfSize; i++){
		
		for(j = 0; j < n; j++){
			
			/*Pravougaonik*/
			if(j > halfSize - 1){
				if(i == 0 || i == (halfSize - 1)){
					if(j == halfSize || j == (n - 1))
						printf("+");
					else
						printf("-");
				}else{
					if(j == halfSize || j == (n - 1))
						printf("|");
					else
						printf(" ");
				}
			}else{
				/*Dijagonale*/
				
				if(i == j || i + j == halfSize - 1){
					if(i == j) printf("\\");
					if(i + j == halfSize - 1) printf("/");
				}else
					printf(" ");
			}
			
		}
		
		printf("\n");
		
	}
	
	/*Donja polovina*/
	for(i = 0; i < halfSize; i++){
		
		for(j = 0; j < n; j++){
			
			/*Pravougaonik*/
			if(j < halfSize){
				if(i == 0 || i == (halfSize - 1)){
					if(j == 0 || j == (halfSize - 1))
						printf("+");
					else
						printf("-");
				}else{
					if(j == 0 || j == (halfSize - 1))
						printf("|");
					else
						printf(" ");
				}
			}else{
				
				/*Plusic?*/
				if(i == (halfSize / 2) || i == ((halfSize / 2) - 1)){
					if(j == halfSize + (halfSize / 2) || j == halfSize + ((halfSize / 2) - 1)){
						printf("+");
					}else{
						printf("-");
					}
				}else{
					if(j == halfSize + (halfSize / 2) || j == halfSize + ((halfSize / 2) - 1)){
						printf("|");
					}else{
						printf(" ");
					}
				}
				
				
			}

		}
		
		printf("\n");
		
	}
	
	return 0;
}
