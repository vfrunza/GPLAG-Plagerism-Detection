#include <stdio.h>
#include <math.h>

int main() {
	int n, i, j, sirina = 3;
	while(1){
		printf("Unesite broj n: ");
		scanf("%d", &n);
		if(n <= 0 || n > 50) printf("Pogresan unos\n");
		else break;
	}
	if(n != 1) sirina = n * 4 - 3;
	
	for(i = 0; i < n; i++){
		for(j = 0; j < sirina; j++){
			if(j == i || j == sirina/2 + i || j == sirina/2 - i || j == sirina-i-1) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}
