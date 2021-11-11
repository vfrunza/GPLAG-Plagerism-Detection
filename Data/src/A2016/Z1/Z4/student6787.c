#include <stdio.h>

int main() {

int i = 0, j = 0, n, x;
for(;;)
	{
		printf("Unesite broj n: ");
		scanf("%d", &x);
		if(x <= 0 || x > 50){
			printf("Pogresan unos\n");
			continue;
		}
		else break;
	}
	if(x == 1){
		printf("***");
		return 0;
	}
	else {
		n = 4 * x - 3;     
	} 
	 
	for(i = 0; i < x; i++){ 
		for(j = 0; j < n; j++){ 
			if(i == (2 * x - j - 2)) printf("*");
			else if((i == j && j < x)) printf("*");
			else if((i + 2 * x - 2) == j && j <= (3 * x - 3)) printf("*");
			else if(i == n - j - 1) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}
