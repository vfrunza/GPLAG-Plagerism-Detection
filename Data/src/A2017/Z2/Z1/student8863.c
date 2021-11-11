#include <stdio.h>

int main() {
	int i, j, n;
	do{
		printf("Unesite broj N: ");
		scanf("%d", &n);
		if(n % 4 != 0 || n < 8) printf("Neispravno N!\n");
	}while(n % 4 != 0 || n < 8);
	printf("\n");
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(i < n/2 && i == j) printf("\\");
			else if(i < n/2 && j == n/2 - i - 1) printf("/");
			else if(((i == 0 || i == n/2 - 1) && (j == n/2 || j == n - 1)) || ((i == n/2 || i == n - 1) && (j == 0 || j == n/2 - 1)) || ((i == n - n/4 || i == n - n/4 - 1) && (j == n - n/4 || j == n - n/4 - 1))) printf("+");
			else if(((i == n/2 - 1 || i == n - n/4 || i == 0 || i == n - n/4 - 1) && j >= n/2) || (j < n/2 && (i == n - 1 || i == n/2))) printf("-");
			else if((i < n/2 && (j == n-1 || j == n/2)) || (i >= n/2 && (j == n/2 - 1 || j == n - 1 - n/4 || j == 0 || j == n - n/4))) printf("|");
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}
