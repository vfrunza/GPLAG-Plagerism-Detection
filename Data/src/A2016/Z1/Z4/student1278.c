#include <stdio.h>

int main() {
	int n,i,j;
	printf("Unesite broj n: ");
	scanf("%d",&n);
	while(n<1 || n>50){
		printf("Pogresan unos \n");
		printf("Unesite broj n: ");
		scanf("%d",&n);
	}
	if(n==1){
		printf("***");
		return 0;
	}
	for(i=1;i<=n-1;i++){
		for(j=1;j<=i-1;j++){
			printf(" ");
		}
		printf("*");
		for(j=1;j<((n-i)*2);j++){
			printf(" ");
		}
		printf("*");
		if(i<2){
				for(j=1;j<((n-i)*2);j++){
			printf(" ");
		}
		printf("*\n");
		}
		if(i>=2){
		for(j=1;j<2*i-2;j++){
			printf(" ");
		}
		printf("*");
		for(j=1;j<((n-i)*2);j++){
			printf(" ");
		}
		printf("*\n");
		}
	}
		if(i==n){
			for(j=1;j<=n-1;j++){
				printf(" ");
			}
			printf("*");
		for(j=1;j<2*n-2;j++){
			printf(" ");
		}
		printf("*\n");
		}
	return 0;
}
