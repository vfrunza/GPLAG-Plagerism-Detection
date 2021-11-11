#include <stdio.h>

int main() {
	
	double clan[100][100];
	int x = 0, y = 0;
	int i, j;
	int teplic = 1;
	int cirk = 1;
	

	do{
	
	printf("Unesite M i N: ");
	scanf("%d %d", &y, &x);
	
	
	if (y <= 0 || y > 100 || x <= 0 || x > 100){
		
		printf("Pogresan unos!\n");
		
	}
	
	} while (y <= 0 || y > 100 || x <= 0 || x > 100);
	
	
	
	printf("Unesite elemente matrice: ");
	
	
	for (i = 1; i <= y; i++){
		
		for(j = 1; j <= x; j++){
			
			scanf("%lf", &clan[i][j]);
			
		}
		
	}
	
	for (i = 1; i < y; i++){
		
		for(j = 1; j < x; j++){
			
			if (clan[i][j] != clan[i + 1][j + 1]){
				
				teplic = 0;
				
			}
			else
			{
				
				if (j == x - 1){
					
					if (clan[i][j + 1] != clan [i + 1][1]){
						cirk = 0;
					}
					
				}
				
			}
			
			
		}
		
	}
	
	
	if (x == 1){
		
		teplic = 1;
			
		if (y > 1)
			cirk = 0;
	}
	
	
	if (teplic == 1){
		
		if (cirk == 1){
			printf("Matrica je cirkularna");
		}
		else
			printf("Matrica je Teplicova");
	}
	
	else
		printf("Matrica nije ni cirkularna ni Teplicova");
		
	
	
	return 0;
}
