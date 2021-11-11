#include <stdio.h>
#include <stdlib.h>

void ubaci(int *niz, int br_elemenata) {
	int i, j, temp = br_elemenata, broj, novi;
	for(i = 0; i < 2*br_elemenata; i+=2) {
		broj = abs(niz[i]);
		novi = 0;
		while(broj != 0) {
			novi += broj % 10;
			broj /= 10;
		}
		for(j = temp-1; j > i; j--) 
			niz[j+1] = niz[j];
		temp++;
		niz[i+1] = novi;
	}
}

int izbaci(int *niz, int br_elemenata) {
	int i, j, fibonacijev = 0, fibonacijev_prethodni, temp, test;
	for(i = 0; i < br_elemenata; i++) {
		fibonacijev = 1;
		fibonacijev_prethodni = 1;
		test = niz[i];
		for(;;) {
			if(fibonacijev == niz[i]) {
				for(j = i; j < br_elemenata-1; j++) 
					niz[j] = niz[j+1];
				br_elemenata--;
				i--;
				break;
			}
			temp = fibonacijev;
			fibonacijev = fibonacijev + fibonacijev_prethodni;
			fibonacijev_prethodni = temp;
			if(fibonacijev > niz[i]) break;
		}
	}
	return br_elemenata;
}

int main() {
	int niz[20], i, br_elemenata = 20;
	printf("Unesite niz od 10 brojeva: ");
	for(i = 0; i < 10; i++)
		scanf("%d", &niz[i]);
	ubaci(niz, br_elemenata/2);
	br_elemenata = izbaci(niz, br_elemenata);
	printf("Modificirani niz glasi: ");
	if(br_elemenata == 0)
		printf("Prazan niz.");
	else {
		for(i = 0; i < br_elemenata - 1; i++)
			printf("%d, ", niz[i]);
		printf("%d.", niz[br_elemenata-1]);
	}
	return 0;
}
