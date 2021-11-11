#include <stdio.h>
#define RED 20
#define KOL 20


int main() {
	int matrica[RED][KOL] = {{0},{0}}, bt=0, i=0, j=0, a, x, y;

	unos:
	printf("Unesite broj tacaka: ");

	
	scanf("%d", &bt);
	if (bt > 10 || bt <= 0){
		printf("Pogresan unos\n");
		goto unos;
	}
	for(i=0; i<bt; i++){
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &x, &y);
		if (x < 0 || x>=20 || y < 0 || y>=20 ){
			printf("Pogresan unos\n");
			i--;
			continue;
		}
		
		matrica[x][y]++; 
	}
	for (i=0; i<RED; i++){
		for (j=0; j<KOL; j++){
		if( matrica[j][i] == 0){
			printf(" ");
		}
		else {
			printf("*");
		}
		
	}
		printf("\n");
	}
	
	
	
	return 0;
}
