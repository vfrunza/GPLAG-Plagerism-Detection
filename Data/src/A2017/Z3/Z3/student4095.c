#include <stdio.h>

int izbaci_cifre(int prviNiz[], int prviBrojac, int drugiNiz[], int drugiBrojac)
{
	int i, j;
	int cifra;
	int stepen = 1;
	int pomocniPrviNiz[100];

	for(i = 0 ; i < drugiBrojac ; i++) {
		for(j = i+1 ; j < drugiBrojac ; j++) {
			if(drugiNiz[i] == drugiNiz[j])
				return 0;
		}
	}

	for(i = 0 ; i < drugiBrojac ; i++) {
		if(drugiNiz[i] < 0 || drugiNiz[i] > 9)
			return 0;
	}

	for(i = 0 ; i < prviBrojac ; i++) {
		for(j = 0 ; j < drugiBrojac ; j++) {

			if(prviNiz[i] < 0) {
				pomocniPrviNiz[i] = -prviNiz[i];
				while( (pomocniPrviNiz[i] / stepen) != 0) {
					cifra = (pomocniPrviNiz[i] / stepen) % 10;
					if(drugiNiz[j] == cifra)
						pomocniPrviNiz[i] = ( (pomocniPrviNiz[i] - cifra ) / (stepen*10) ) * stepen + pomocniPrviNiz[i] % stepen;
					stepen *= 10;
					prviNiz[i] = -pomocniPrviNiz[i];

				}
			} else {
				while( (prviNiz[i] / stepen) != 0) {
					cifra = (prviNiz[i] / stepen) % 10;
					if(drugiNiz[j] == cifra)
						prviNiz[i] = ( (prviNiz[i] - cifra) / (stepen*10)) * stepen + prviNiz[i] % stepen;
					stepen *= 10;
				}
			}

			stepen = 1;

		}
	}
	return 1;
}


int main()
{
	int i;
	int prviNiz[100];
	int drugiNiz[100];
	int brojacPrvi = 0, brojacDrugi = 0;
	printf("Unesite prvi niz: ");
	for(i = 0 ; i < 100 ; i++) {
		scanf("%d", &prviNiz[i]);
		if(prviNiz[i] == -1) {
			i--;
			break;
		}
		brojacPrvi++;
	}
	printf("Unesite drugi niz: ");
	for(i = 0 ; i < 100 ; i++) {
		scanf("%d", &drugiNiz[i]);
		if(drugiNiz[i] == -1) {
			i--;
			break;
		}
		brojacDrugi++;
	}
	izbaci_cifre(prviNiz, brojacPrvi, drugiNiz, brojacDrugi);
	for(i = 0 ; i < brojacPrvi ; i++) {
		printf("%d ", prviNiz[i]);
	}
	return 0;
}
