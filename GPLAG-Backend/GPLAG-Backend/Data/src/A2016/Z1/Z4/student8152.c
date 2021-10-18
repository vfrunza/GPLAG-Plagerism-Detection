#include <stdio.h>

int main() {
	int i,j,n = 0;
	
	while(n <= 0 || n > 50) {
	printf("Unesite broj n: ");
	scanf("%d", &n);
	
	if(n <= 0 || n > 50) printf("Pogresan unos\n");
	}
	
	if(n == 1) { printf("***"); return 0; }
	for(i = 0; i < n; i++) {
	    for(j = 0; j <= 4 * n - 4; j++) {
	        
	        if(i == j || i + 1 == 2 * n - j - 1 || j == 2 * n + i - 2 || j + 1 == 4 * n - i - 3) printf("*");
	        else printf(" ");
	    } printf("\n");
	}
	
	return 0;
}
