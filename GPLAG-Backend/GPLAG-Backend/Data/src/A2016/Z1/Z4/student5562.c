#include <stdio.h>

int main() {
	
	float n;
	int d;
	int i,j;
	
	
	do {
	
	printf("Unesite broj n: ");
	scanf("%f", &n);
	
	d = n;
	
	
	if (((n - d) != 0) || n > 50 || n <= 0){
		printf("Pogresan unos\n");
		}
		
	} while (((n - d) != 0) || n > 50 || n <= 0);

	if (n == 1){
		
		printf("***");
		return 0;
	}
	
	printf("*");
	
	for (i = 1; i < 3; i++)
	{
		for(j =1; j <= 2*n - 3; j ++){
			printf(" ");
		}
	
		printf("*");
	}
	
	printf("\n");
	
	for(i = 1; i <= n - 2; i++){
		
		for(j = 1; j <= i; j++){
			printf(" ");
		}
		
		printf("*");
		
		for(j = 1; j <= 2*(n - i) - 3; j++){
			
			printf(" ");
		}
		
		printf("*");
		
		for(j = 1; j <= 2*i - 1; j++){
			printf(" ");
		}
		
		printf("*");
			
		for(j = 1; j <= 2*(n - i) - 3; j++){
			printf(" ");
		}
		
		printf("*\n");
		
	}
	
	
	for(j = 1; j <= n - 1; j++){
		
		printf(" ");
	}
	printf("*");
	
	for(j = 1; j <= 2*n - 3; j++){
		
		printf(" ");
	}
	printf("*");
		
	return 0;
}
