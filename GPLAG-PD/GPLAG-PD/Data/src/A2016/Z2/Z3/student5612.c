#include <stdio.h>
#include<stdlib.h>
int main() {
	/*Deklaracija matrice sa svim nulama*/
	int M[20][20] = {0}; 
	int x;
	int y;
	int c;
	int i;
	int j;
	/*Unos tacaka*/
	printf("Unesite broj tacaka: ");
	scanf("%d", &x);
	/*Opseg unosa tacaka je ogranicen*/
	while(x < 1 || x > 10){
		printf("Pogresan unos");
		printf("\n");
		printf("Unesite broj tacaka: ");
		scanf("%d", &x);
	}
		for (i = 0; i < x; i++){
			printf("Unesite %d. tacku: ", i+1);
			/*Unos koordinata*/
			scanf("%d %d", &y, &c);
			/*Kordinate u intervalu [0,19]*/
			while(y < 0 || y > 19 || c < 0 || c > 19){
				printf("Pogresan unos");
				printf("\n");
				printf("Unesite %d. tacku: ", i+1);
				scanf("%d %d",&y, &c);
			}
			/*Povecanje vrijednosti elemenata(sa unesenim koordinatama) sa 0 na 1*/
			M[c][y]++;
			/*Prvi index je kolona a drugi red, jer je ishodiste u gornjem lijevom uglu*/
		}
		for (i = 0; i < 20; i++){
			for(j = 0; j < 20; j++){
			if(M[i][j] == 0){
				printf(" ");/*Ako je elemenat jednak nuli(0) potrebno je ispisati razmak.*/
			}else {
				printf("*"); /*Ako je elemenat matrice jednak jedinici(1) potrebno je ispisati zvjezdicu(*)*/
			}
			}
			printf("\n");
		}
	return 0;
}
