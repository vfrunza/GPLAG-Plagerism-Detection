#include <stdio.h>

int main() {
	int broj, i, j;
	broj = 1;
	while (1) {
		printf("Unesite broj n: ");
		scanf("%d", &broj);
		if (broj <= 0 || broj > 50) printf("Pogresan unos\n");
		else break;
	} 
	int zvjezdica = 3;
	int razmakZ = 2 * broj - 3;
	int srednjiRazmak = 1;
	if (broj == 1) {
		printf("***\n");
		return 0;
	}
	for (i = 0; i < broj; i++) {
		
		if (i == broj - 1) {
			for (j = 0; j < i; j++) printf(" ");
			printf("*");
			for (j = 0; j < srednjiRazmak; j++) printf(" ");
			printf("*\n");
		}
		else if (i == 0) {
			for (j = 0; j < i; j++) printf(" ");
			printf("*");
			for (j = 0; j < razmakZ; j++) printf(" ");
			printf("*");
			for (j = 0; j < razmakZ; j++) printf(" ");
			printf("*\n");
			razmakZ -= 2;
		}
		else {
			zvjezdica = 4;
			
			for (j = 0; j < i; j++) printf(" ");
			printf("*");
			for (j = 0; j < razmakZ; j++) printf(" ");
			printf("*");
			for (j = 0; j < srednjiRazmak; j++) printf(" ");
			srednjiRazmak += 2;
			printf("*");
			for (j = 0; j < razmakZ; j++) printf(" ");
			printf("*\n");
			razmakZ -= 2;
			
		}
		
	}
	return 0;
}
