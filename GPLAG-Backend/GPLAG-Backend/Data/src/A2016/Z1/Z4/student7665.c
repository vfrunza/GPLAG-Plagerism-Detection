#include <stdio.h>
#include<stdlib.h>

int main() {
	int n, j, i;
	
	do{
		printf("Unesite broj n: "); scanf("%d", &n);
		if(n<=0 || n>50){
			printf("Pogresan unos\n");
		}
		
	}while(n<=0 || n>50);
	
	if(n==1){
		printf("***");
	}
	
	else{
		printf("*");
		for(i=0; i<2*n-3; i++){
			printf(" ");
		}
		printf("*");
		for(i=0; i<2*n-3; i++){
			printf(" ");
		}
		printf("*\n");
		
		
		
		for(i=0; i<=n-3; i++){
			printf(" ");
			for(j=0; j<=4*n-5; j++){
			if(j==i|| j==2*n-i-4 || j==4*n-i-6 || j==2*n-2+i ){
				printf("*");
			}
			else {
				printf(" ");
				}
			
			
			}
		printf("\n");
		}
		
		
	
	for(i=0;i<(2*n-2)/2; i++){
		printf(" ");
	}	
	printf("*");
	for (i=0; i<2*n-3; i++){
		printf(" ");
	}
	printf("*");
	}
	return 0;
}
