#include <stdio.h>

int main() {
	int n,i,j;
	
	printf("Unesite broj n: ");
	scanf("%d",&n);
	
	if(n<=0 || n>50){
		printf("Pogresan unos");
		printf("\nUnesite broj n: ");
		scanf("%d",&n);
		if(n<=0 || n>50){
			printf("Pogresan unos");
			printf("\nUnesite broj n: ");
			scanf("%d",&n);
			if(n<=0 || n>50){
				printf("Pogresan unos");
				printf("\nUnesite broj n: ");
				scanf("%d",&n);
				if(n<=0 || n>50){
					printf("Pogresan unos");
					printf("\nUnesite broj n: ");
					scanf("%d",&n);
					if(n<=0 || n>50){
						printf("Pogresan unos");
						printf("\nUnesite broj n: ");
						scanf("%d",&n);
						if(n<=0 || n>50){
							printf("Pogresan unos");
							printf("\nUnesite broj n: ");
							scanf("%d",&n);
						}
					}
				}
			}
		}
	}
	if(n==1){
		for(i=0; i<n; i++){
			for(j=0; j<3; j++){
				printf("*");
			}
		}
	}
	else{
		for(i=0; i<n; i++){
			for(j=0; j<=(n-1)*4; j++){
				if(i==j || n==i+j-(n-2) || n==j-i-(n-2) || (n==(i+j)/2-(n-2) && (i+j)%2==0)){
					printf("*");
				}
				else{
					printf(" ");
				}
			}
			printf("\n");
		}
	}
	return 0;

}
