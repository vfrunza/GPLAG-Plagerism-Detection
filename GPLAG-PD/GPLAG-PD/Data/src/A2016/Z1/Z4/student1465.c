#include <stdio.h>

int main() {
	int i, j, n;
	
	printf("Unesite broj n: ");
	scanf("%d", &n);
	
	if(n==1) { printf("***"); }
	
	else if(n < 1 || n > 50) 
	{ 
		printf("Pogresan unos");
		printf("\nUnesite broj n: ");
		scanf("%d", &n);
		
		if(n==1) { printf("***"); }
		
		else {
			
		for(i=0; i<n; i++) {
			for(j=0; j <= 4*n - 4; j++)
			{
				if(i==j) { printf("*"); }
				else if(i + j == 2*n-2) { printf("*"); }
				else if(j - i == 2*n-2) { printf("*"); }
				else if(i + j == 4*n-4) { printf("*"); }
				
				
				else { printf(" "); }
			}
			
			printf("\n");
		}
	
		}
	}
	
	else 
	{
		for(i=0; i<n; i++) {
			for(j=0; j <= 4*n - 4; j++)
			{
				if(i==j) { printf("*"); }
				else if(i + j == 2*n-2) { printf("*"); }
				else if(j - i == 2*n-2) { printf("*"); }
				else if(i + j == 4*n-4) { printf("*"); }
				
				
				else { printf(" "); }
			}
			
			printf("\n");
		}
		
	}
	
	
	return 0;
}
