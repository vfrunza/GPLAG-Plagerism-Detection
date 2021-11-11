#include <stdio.h>

int main() {
	
	int brojTacaka,i,j;
	char tacka[20][20] = {0};
	int x, y;
	
	while(1) {
	printf("Unesite broj tacaka: ");
	scanf("%d", &brojTacaka);
	
	if(brojTacaka >= 1 && brojTacaka <= 10) break;
	else printf("Pogresan unos\n");
	
	}
	for(i = 0; i < brojTacaka; i++) {
		opet:
		printf("Unesite %d. tacku: ", i + 1);
		scanf("%d %d", &x, &y);
		
		if(x > 19 || x < 0 || y < 0 || y > 19) { printf("Pogresan unos\n"); goto opet; }
		
		tacka[y][x] = '*';
	}
	
	for(i = 0; i < 20; i++) {
		
		for(j = 0; j < 20; j++) {
		
		if(tacka[i][j] != '*') printf(" ");
		else printf("*");
	} printf("\n");
	}

	return 0;
}
