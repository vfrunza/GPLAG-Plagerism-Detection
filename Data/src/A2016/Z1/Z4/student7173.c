#include <stdio.h>
#include <string.h>

int main() {
	int n;
	printf("Unesite broj n: ");
	scanf("%d", &n);
	while (n <= 0 || n > 50) {
		printf("Pogresan unos\n");
		printf("Unesite broj n: ");
		scanf("%d", &n);
	}
	
	if (n == 1) {
		printf("***");
	} else {
		int k = 2*(n - 1);
		int m = 2*k + 1; /*4n - 3*/
		int i, j;
		for (i = 0; i < n; i ++) {
			for (j = 0; j < m; j++) {
				if ((j - i)%k == 0 || (j + i)%k == 0) {
					printf("*");
				} else {
					printf(" ");
				}
			}
			if (i < n - 1) {
				printf("\n");
			}
			m -= 1;
		}
	}
	
	return 0;
}
