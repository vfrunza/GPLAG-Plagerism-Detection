#include <stdio.h>

int main() {
	
	int i, j, n;
	unos: 
	printf("Unesite broj n: ");
	scanf("%d", &n);
	if(n<=0 || n>50){
		printf("Pogresan unos\n"); goto unos;
	} 
	if(n==1){
		printf("**");
	}

		for(i=0; i<n; i++){
			for(j=0; j<4*n-1; j++){
				if(i==j && j<=n)
				printf("*");
				else if(j==2*n-2-i && j>=n && j<2*n)
				printf("*");
				else if(j==2*n-2+i && j>=2*n-1 && j<=3*n-3)
				printf("*");
				else if(j==4*n-4-i && j>=3*n-2 && j<=4*n)
				printf("*");
				else
				printf(" ");
				
			} printf("\n");
		}
	
	return 0;
}
