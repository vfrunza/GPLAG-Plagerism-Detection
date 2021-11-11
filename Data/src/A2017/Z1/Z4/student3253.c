#include <stdio.h>

int main() {
	int i, j, k;
	int brRed, brKol, sirina_kol;
	
	do {
		printf("Unesite broj redova: ");
		scanf("%d", &brRed);
	} while ( !(brRed > 0 && brRed <= 10) );
	do {
		printf("Unesite broj kolona: ");
		scanf("%d", &brKol);
	} while ( !(brKol > 0 && brKol <= 10) );
	do {
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &sirina_kol);
	} while ( !(sirina_kol > 0 && sirina_kol <= 10) );

	
	for(i=1; i<=brRed+1; i++){

		for (j=1; j<=brKol+1; j++) {
			printf("+");
			if (j != brKol+1) {
				for (k=1; k<=sirina_kol; k++) {
					printf("-");
				}
			}
		}
		
		printf("\n");
		
		if (i != brRed + 1) {
			for (j=1; j<=brKol+1; j++) {
				printf("|");
				if (j != brKol+1) {
					for (k=1; k<=sirina_kol; k++) {
						printf(" ");
					}
				}
			}
		}
		
		printf("\n");
	
	}

	return 0;
}
