#include <stdio.h>

int main() {
	int a,b,n;
	printf("\nUnesite broj n: ");
	do{
		scanf("%d", &n);
		if(n<=0 || n>50){
			printf("Pogresan unos");
			printf("\nUnesite broj n: ");
		}
		}while (n <= 0 || n > 50);
			for(a=0; a<n; a++){
				for(b=0; b<4*n-3; b++){
					if(n==1) printf("**");
					if(a==b || 2*n-2-a==b ||2*n-2+a==b || 4*n-4-a==b ){
						printf("*");
					}
					else 
					printf(" ");
			}
		
						printf("\n");
			}
	return 0;
}
