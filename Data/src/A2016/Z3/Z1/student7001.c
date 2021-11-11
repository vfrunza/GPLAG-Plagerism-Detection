#include <stdio.h>
int daj_prost () {
	static int a=1;
	int i, broj_je_prost;
	a++;
	do {
		broj_je_prost=1;
		for (i=2; i<a; i++) {
			if (a%i==0) {
				broj_je_prost=0;
				break;
			}
		}
		if (broj_je_prost) return a;
		a++;
	} while (1);
}
int main () {
	int A, B, i, br, suma=0;
	do {
		printf ("Unesite brojeve A i B: ");
		scanf ("%d %d", &A, &B);
		if (A>=B) printf ("A nije manje od B.\n");
		else if (A<=1) printf ("A nije prirodan broj.\n");
	} while (A<=1 || A>=B);
	for (i=0; i<B; i++) {
		br=daj_prost();
		if (br>A && br<B)
			suma+=br;
	}
	printf ("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	return 0;
}