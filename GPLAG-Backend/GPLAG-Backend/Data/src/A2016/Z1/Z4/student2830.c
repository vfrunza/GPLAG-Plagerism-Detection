#include <stdio.h>

int main() {
	int n,i,j;
	do{
		printf("Unesite broj n: ");
		scanf("%d", &n);
		if(n<1 || n>50){
			printf("Pogresan unos \n");
		}
	}while(n<1 || n>50);
	if(n==1){
		printf("***");
		return 0;
	}
	for(i=0;i<n;i++){
		for(j=0;j<i;j++){
			printf(" ");
		}
		printf("*");
		for(j=0;j<2*n-3-2*i;j++){
			printf(" ");
			if(j==2*n-4-2*i){
				printf("*");
			}
		}
	for(j=1;j<2*i;j++){
		printf(" ");
		if(j==2*i-1){
			printf("*");
		}
	}
	for(j=0;j<2*n-3-2*i;j++){
			printf(" ");
			if(j==2*n-4-2*i){
				printf("*");
			}
	}
	printf("\n");
	}
	return 0;
}
