#include <stdio.h>

int main() {
	char matrica[20][20];
	int n = 0, x, y, i = 0;
	
	for(y = 0; y < 20; y++)
		for(x = 0; x < 20; x++)
			matrica[y][x] = ' ';
	
	while(1){
		printf("Unesite broj tacaka: ");
		scanf("%d", &n);
		if(n < 1 || n > 10) printf("Pogresan unos\n");
		else break;
	}
	while(i < n){
		printf("Unesite %d. tacku: ", i + 1);
		scanf("%d%d", &x, &y);
		if(x < 0 || x > 19 || y < 0 || y > 19){
			printf("Pogresan unos\n");
		}
		else{
			matrica[y][x] = '*';
			i++;
		}
	}
	for(y = 0; y < 20; y++){
		for(x = 0; x < 20; x++)
			printf("%c", matrica[y][x]);
		printf("\n");
	}
	return 0;
}
