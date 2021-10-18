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
					}
				}
			}
		}
		
	}
	for(i=0; i<=n-1; i++){
		for(j=0; j<=(n-1)*4; j++){
			if(n==j+i-(n-2) || n==j-i-(n-2) || ((i+j)%2==0 && n==(i+j)/2-(n-2)) || j==i){
				printf("*");
			}
			else{
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
