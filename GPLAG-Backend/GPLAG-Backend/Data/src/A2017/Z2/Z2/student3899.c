#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001

int main() {
	int n, unos[150];
	int res[1500] = {0};
	int count = 0, dgt;
	int i, tmp;
	
	do {

		printf("Unesite velicinu niza: ");
		scanf("%d", &n);
	}
	while(n <= 0 || n > 100);
	
	printf("Unesite clanove niza: ");
	for (i = 0; i < n; i++) {
		scanf("%d", &unos[i]);
		
		if (unos[i] < 0) {
			/* printf("Clan mora biti ili nula ili prirodan broj.\n"); */
			i--;
		}
	}
	
	/* Dijeljenje niza na njegove cifre odzada, pri tome testirajuci da li je
	   prethodna cifra jednaka trenutnoj, ukoliko je to moguce, ako jeste,
	   vratiti se natrag i dodati na counter prethodne cifre, time gledajuci
	   koliko istih cifara ima zaredom */
	for (i = n - 1; i >= 0; i--) {
		/* DO-WHILE jer unos moze biti 0 po definiciji u zadatku */
		do {
			dgt = unos[i] % 10;
			
			/* Ukoliko nije ovo prva cifra koju gledamo */
			if (count)
				if (res[count * 2 - 1] == dgt && res[count * 2 - 2])
					count--;
					
			res[count * 2 + 1] = dgt;
			res[count * 2]++;
			
			count++;
			unos[i] /= 10;
		}
		while (unos[i]);
	}
	
	/* Obrtanje niza cifara i njihovih uzastopnih brojaca koje smo dobili
	   gledajuci unatraske, te time dobivanjem finalnog niza */
	for (i = 0; i < count; i++) {
		tmp = res[i];
		res[i] = res[2 * count - 1 - i];
		res[2 * count - 1 - i] = tmp;
	}
	
	printf("Finalni niz glasi:\n");
	for (i = 0; i < count * 2; i++) {
		printf("%d ", res[i]);
	}
	printf("\n");
	
	return 0;
}
