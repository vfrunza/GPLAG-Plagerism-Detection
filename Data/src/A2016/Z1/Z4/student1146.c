#include <stdio.h>

#define ponovi(n) for(j = 0; j < (n); j++)

int main() {
	int n, i, j;
	
	while (1) {
		printf("Unesite broj n: ");
		scanf("%d", &n);
		if (n > 0 && n <= 50) break;
		printf("Pogresan unos\n");
	}
	
	if (n == 1) {
		printf("***\n");
		return 0;
	}
	
	for(i = 0; i < n; i++) {
		ponovi(i) printf(" ");
		if(i!=n-1) 	printf("*");
		ponovi(2*(n - i) - 3) printf(" ");
		if(i!=0) printf("*");		
		ponovi(2*i - 1) printf(" ");
		if(i!=n-1) printf("*");		
		ponovi(2*(n - i) - 3) printf(" ");
		printf("*\n");
	}
	
	return 0;
}