#include <stdio.h>

int main() {
	int n, i, j;
	int prvi = 1;
	
	do {
		if (!prvi)
			printf("Neispravno N!\n");
			
		prvi = 0;
		
		printf("Unesite broj N: ");
		scanf("%d", &n);
	} while (n < 8 || n % 4 != 0);
	
	printf("\n");
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i == j && i < n / 2)
				printf("\\");
			else if (i + j + 1 == n / 2 && i < n / 2)
				printf("/");
			else if ((i == 0 && j == n / 2) \
				  || (i == 0 && j == n - 1) \
				  || (i == n / 2 - 1 && j == n / 2) \
				  || (i == n / 2 - 1 && j == n - 1) \
				  || (i == n / 2 && j == 0) \
				  || (i == n / 2 && j == n / 2 - 1) \
				  || (i == n - 1 && j == 0) \
				  || (i == n - 1 && j == n / 2 - 1) \
				  || (i == 3 * n / 4 && (j == i || j == 3 * n / 4 - 1)) \
				  || (i == 3 * n / 4 - 1 && (j == i || j == 3 * n / 4)))
				printf("+");
			else if (((i == 0 || i == n / 2 - 1) && (j < n - 1 && j > n / 2)) \
				  || ((i == n / 2 || i == n - 1) && (j > 0 && j < n / 2 - 1)) \
				  || ((i == 3 * n / 4 || i == 3 * n / 4 - 1) && j > n / 2 - 1 && (j < 3 * n / 4 - 1 || j > 3 * n / 4)))
				printf("-");
			else if (((j == 0 || j == n / 2 - 1) && (i > n / 2 && i < n - 1)) \
				  || ((j == n / 2 || j == n - 1) && (i > 0 && i < n / 2 - 1)) \
				  || ((j == 3 * n / 4 || j == 3 * n / 4 - 1) && i > n / 2 - 1 && (i < 3 * n / 4 - 1 || i > 3 * n / 4)))
				printf("|");
			else
				printf(" ");
			
		}
		printf("\n");
	}
	
	return 0;
}