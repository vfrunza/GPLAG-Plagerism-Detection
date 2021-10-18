#include <stdio.h>

enum TipOblika { TACKA, KRUZNICA, PRAVOUGAONIK, TROUGAO };

int obuhvata(void* oblik1, enum TipOblika to1, void* oblik2, enum TipOblika to2) {
	
}


int main() {
	int n, option, i = 0;
	printf("Unesite broj oblika: ");
	scanf("%d", &n);
	do {
		printf("Odaberite tip %d. oblika (1 - tacka, 2 - kruznica, 3 - pravougaonik, 4 - trougao): ", i+1);
		scanf("%d", &option);
		if(option < 1 || option > 4) printf("Nepoznat tip oblika %d!", option);
		if(option == 1) {
			printf("Unesite tacku: ");
			
		}
	}while(i < n);
	return 0;
}
