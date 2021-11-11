#include <stdio.h>

int main() {
	int n, i, j;
	
	
	
	while(2>1){
		printf("Unesite broj n: ");
		scanf("%d", &n);
		if(n<=0 || n>50){
			printf("Pogresan unos\n");
		continue;
		}
		else break;
	}
	
	for(i=0; i<n; i++){
		for(j=0; j<4*n-3; j++){
			if(n==1){
				printf("***");
				break;
			}
			if(i==j)
				printf("*");
				
			else if(i+j==2*n-2 && j>n-1)
				printf("*");
			
			else if(j-i==2*n-2)
				printf("*");
				
			else if(i+j==2*(2*n-2))
				printf("*");
				
			else printf(" ");
			
			
		}
		printf("\n");
	}
	
	return 0;
}
