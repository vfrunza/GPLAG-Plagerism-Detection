#include <stdio.h>
#include <math.h>

int main() {
	char mat[20][20];
	int i,j,n;
	int niz1[10],niz2[10];
	for(i = 0; i < 20; i++) {
		for(j = 0; j < 20; j++) {
			mat[i][j] = ' ';
		}
	}
	
	do {
		printf("Unesite broj tacaka: ");
		scanf("%d", &n);
		if(n <= 0 || n > 10) printf("Pogresan unos\n");
	} while(n <= 0 || n > 10);
	for(i = 0; i < n; i++) {
		printf("Unesite %d. tacku: ", i+1);
		for(j = i; j <= i; j++) {
			scanf("%d %d", &niz1[j], &niz2[j]);
			if(niz1[j] < 0 || niz1[j] > 19 || niz2[j] < 0 || niz2[j] > 19){
				printf("Pogresan unos\n");
				i--;
			} 
		}
	}
	/*for(i = 1; i < n; i++) printf("%d ", niz1[i]);
	printf("\n");
	for(i = 0; i < n; i++) {
		printf("%d ", niz2[i]);
	}*/
	for(i = 0; i < n; i++) {
		mat[niz2[i]][niz1[i]] = '*';
	}
	for(i = 0; i < 20; i++) {
		for(j = 0; j < 20; j++) {
			printf("%c", mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}
