#include <stdio.h>

int main() {
	int n, i, j;
	
	do{
		printf("Unesite broj n: ");
		scanf("%d", &n);
		if((n<=0)||(n>50)) printf("Pogresan unos\n");
	}while((n<=0)||(n>50));
	for(i=1;i<n+1;i++){
		for(j=1;j<=4*n-3;j++){
			if((j==i)||(i+j==2*n)||(j-i==2*n-2)||(i+j==4*n-2)) printf("*");
			
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}
