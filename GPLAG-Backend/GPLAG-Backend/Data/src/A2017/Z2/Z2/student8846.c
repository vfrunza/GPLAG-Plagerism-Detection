#include <stdio.h>
#include <math.h>

int main()
{
	int ulaz[100], izlaz[1000], i, j, n, broj, prva_cifra, broj_cifara, djeljitelj, trenutna, prosla, k, ponavljanje;

	printf("Unesite velicinu niza: ");
	scanf("%d", &n);

	printf("Unesite clanove niza: ");
	for (i = 0; i < n; i++) {
		scanf("%d", &ulaz[i]);
	}

	/* obrada */

	k = 0;
	

	for (i = 0; i < n; i++) {
		broj = ulaz[i];
		
		//do
		
		djeljitelj = 1;
		broj_cifara = log10(broj) + 1;
		
		for (j = 1; j < broj_cifara; j++) {
			djeljitelj *= 10;
		}
		prva_cifra = broj / djeljitelj;
		printf("\n%d: ", broj);
		
		for (j = 0; j < broj_cifara; j++) {
			
			trenutna = broj / djeljitelj;
			
			if (prva_cifra == trenutna) {
				k++;
			}
			
			prva_cifra = trenutna;
			broj %= djeljitelj;
			djeljitelj /= 10;
		}
		
/*
		    k = 0;
		do {
			pivot = ulaz[i++];
			k++;
		} while (pivot == ulaz[i] && i < n);

		izlaz[j++] = k;
		*/
	}

	printf("Finalni niz glasi:\n");

	for (i = 0; i < n; i++) {
		printf("%d ", izlaz[i]);
	}

	return 0;
}
