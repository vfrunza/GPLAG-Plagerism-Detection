#include <stdio.h>

int main() {
	int n, dodajem, novi, cifraprev, cifranext, obrnuti, i;
	int vodeca_nula = 1, br_cifara = 0, br_vodecih_nula = 0;
	novi = obrnuti = 0;
	printf("Unesite broj: ");
	scanf("%d", &n);
	if (n < 0) n = -n;
	cifraprev = n % 10;
	n /= 10;
	while (n) {
		cifranext = n % 10;
		n /= 10;
		br_cifara++;
		if (cifranext - cifraprev > 0) dodajem = cifranext - cifraprev;
		else dodajem = cifraprev - cifranext;
		
		if (dodajem != 0) vodeca_nula = 0;
		if (dodajem == 0 && vodeca_nula) br_vodecih_nula++;
		novi = novi * 10 + dodajem;
		cifraprev = cifranext;
	}
	//printf("%d %d\n", novi, br_vodecih_nula);
	if (br_vodecih_nula == br_cifara) {
		printf("0\n");
		return 0;
	}
	while (novi) {
		obrnuti = obrnuti * 10 + (novi % 10);
		novi /= 10;
	}
	printf("%d", obrnuti);
	for (i = 0; i < br_vodecih_nula; i++) printf("0");
	printf("\n");
	return 0;
}
