#include <stdio.h>

int main() {
	int  n, i, j;
	do{
	printf("Unesite broj n: ");
	scanf("%d", &n);
	if(n<1 || n>50){
		printf("Pogresan unos\n");
	}
	}while(n<1 || n>50);
	
	for(i=0; i<n; i++){
		for(j=0; j<4*n-3; j++){
			if(n==1){
				printf("**");
			}
			if(i==j || j==i+2*n-2 || j==2*n-i-2 || j==4*n-i-4){
				printf("*");
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
