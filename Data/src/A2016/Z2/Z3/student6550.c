#include <stdio.h>


int main() {
	
	int n, x, y, i, j, k;
	char A[20][20];
	
	printf("Unesite broj tacaka: ");
	
	scanf("%d", &n);
	while (n <= 0 || n > 10){ 
		printf("Pogresan unos ");
		printf("\nUnesite broj tacaka: ");
		scanf("%d",&n);
		
	}
	
	for(i = 0; i < 20; i++)
		for(j = 0; j < 20; j++) A[i][j] = ' ';
	
	
	for(k = 0; k < n; k++) { 
		printf("Unesite %d. tacku: ", k+1);
		scanf("%d%d", &x, &y);
		while(x < 0 || x > 19 || y < 0 || y > 19){
			printf("Pogresan unos\n");
			printf("Unesite %d. tacku: ", k+1);
			scanf("%d%d", &x, &y);
			}
		A[y][x] = '*';
	}
	
	for(i = 0; i < 20 ; i++) {
		for(j = 0; j < 20 ; j++) printf("%c", A[i][j]);
		printf("\n");
	}
		

	return 0;
}