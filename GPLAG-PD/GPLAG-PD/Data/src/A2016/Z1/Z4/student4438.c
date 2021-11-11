#include <stdio.h>

int main() {
	
	int n;
	printf("Unesite broj n: ");
	scanf("%d", &n);
	
	while(n > 50 || n <= 0) {
		printf("Pogresan unos\n");
		printf("Unesite broj n: ");
		scanf("%d", &n);
	}
	
	if(n == 1) {
		printf("***");
	}
	
	else {
		int i, j, br = 5, razmak = 0; 
		for(i = 1; i < n - 1; i++) br += 4;
		
		for(i = 0; i < n; i++) {
			for(j = 0; j < br; j++) {
				if(j == razmak) printf("*");
				else if(j == ((int)(br / 2)) - razmak) printf("*");
				else if(j == br - 1 - razmak) printf("*");
				else if(j == ((int)(br / 2)) + razmak) {
					if(i == 0 || i == n - 1) continue;
					printf("*");
				}
				else printf(" ");
			}
			printf("\n");
			razmak++;
		}
	}
	return 0;
}
