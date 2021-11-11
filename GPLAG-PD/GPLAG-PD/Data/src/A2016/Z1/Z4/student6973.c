#include <stdio.h>

int main() {
	int i, j, n;
	do {
		printf("Unesite broj n: ");
		scanf("%d", &n);
		if(n <= 0 || n > 50) printf("Pogresan unos\n");
	} while(n <= 0 || n > 50);
	if(n == 1) printf("**");
	for(i = 0; i < n; i++) {
		for(j = 0; j < ((2*n) - 2) * 2 + 1; j++) {
			if(i == j) printf("*");
			else if(j == 2 * n - 2 - i) printf("*");
			else if(i == j - 2 * n + 2) printf("*");
			else if(i == (((2*n) - 2) * 2) - j) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}
