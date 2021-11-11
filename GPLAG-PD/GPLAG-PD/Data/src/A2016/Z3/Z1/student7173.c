#include <stdio.h>

int daj_prost() {
	static long int n = 1;
	int i, prost;
	
	/* Prvo povecavamo n jer trazimo sljedeci prost broj */
	n++;
	do {
		prost = 1;
		for (i = 2; i < n; i++) {
			if (n % i == 0) {
				prost = 0;
				n ++;
			}
		}
	} while (!prost);
	
	return n;
}

int main() {
	long int a, b, c, pravilan, suma;
	
	/* Ponavlja unos integera A i B dok god nije 0 < A < B */
	pravilan = 0;
	while (!pravilan) {
		printf("Unesite brojeve A i B: ");
		scanf("%ld %ld", &a, &b);
		if (a >= b) {
			printf("A nije manje od B.\n");
		} else if (a < 1) {
			printf("A nije prirodan broj.\n");
		} else if (b < 1) {
			printf("B nije prirodan broj.\n");
		} else {
			/* Unos je pravilan */
			pravilan = 1;
		}
	}
	
	/* Naci prvi prost broj c veci od A */
	c = 0;
	while (c <= a) {
		c = daj_prost();
	}
	
	/* Naci sumu prostih brojeva u (A, B) */
	suma = 0;
	while (c < b) {
		suma += c;
		c = daj_prost();
	}
	
	printf("Suma prostih brojeva izmedju %ld i %ld je %ld.", a, b, suma);
	return 0;
}
