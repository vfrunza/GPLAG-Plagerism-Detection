#include <stdio.h>

int main() {
	
	int n,i,j;
	for(;;) {
		printf("Unesite broj n: ");
		scanf("%d", &n);
		if(n > 0 && n <= 50) break;
		else {
			printf("Pogresan unos\n");
			continue;
		}
	}
	if(n==1) {
		printf("***");
		return 0;
	}
	for(i=0; i<n; i++) { 
		for(j=0; j<n*4-3; j++) {
			if(i==j || j==i+2*n-2 || j==2*n-2-i || j==4*n-4-i) {
				printf("*");
			} 
			else {
				printf(" ");
			}
			
		}
		printf("\n");
	}
	
	return 0;
}
