#include <stdio.h>

int main() {
	int n;
	int i,j;
	
	printf("Unesite broj n: ");
	scanf("%d",&n);
	while(n<=0 || n>50){
		printf("Pogresan unos \n");
		printf("Unesite broj n: ");
		scanf("%d",&n);
	}
	
	i = 0;
	
	while(i<n){
		j = 0;
		while(j < n*4-3){
			if(n==1){
				printf("**");
			}
			if(i==j){
			printf("*");
			}
			else if(j-i == n*2-2){
				printf("*");
			}
			else if(j+i == n*2-2){
				printf("*");
			}
			else if(j == n*4-4-i){
				printf("*");
			}
			else printf(" ");
			j++;
		}
		printf("\n");
		i++;
	}
	return 0;
}
