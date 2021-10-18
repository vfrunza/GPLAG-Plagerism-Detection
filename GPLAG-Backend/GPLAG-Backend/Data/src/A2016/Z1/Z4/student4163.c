#include <stdio.h>

int main() {
	int i, j;
	int n;
	printf("Unesite broj n: ");
	scanf("%d", &n);
	while(n<=0 || n>50){
		printf("Pogresan unos\n");
		printf("Unesite broj n: ");
		scanf("%d", &n);
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<=((2*n-2)*2);j++){
			if(n==1) {
			printf("***");
			return 0;
			}
			if(i==j) printf("*");
			else if(i+j==((2*n)-2)*2) printf("*");
			else if(j-i==(2*n)-2) printf("*");
			else if((i+j)==(2*n)-2) printf("*");
			
			else printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}
