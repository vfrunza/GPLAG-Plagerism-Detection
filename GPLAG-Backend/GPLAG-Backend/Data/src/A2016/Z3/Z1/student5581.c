#include <stdio.h>
#include <math.h>

int daj_prost (){

	static int broj=1;
	int je_prost, i;

	do {
		broj++;
		je_prost=1;
		
		/*provjera da li je broj prost*/
		for (i=2; i<=sqrt(broj); i++) { 
			if (broj%i==0) {
				je_prost=0;
				break;
			}
		}
	} while (je_prost==0);

	return broj;
}

int main (){

	int a, b, prost;
	int suma=0;

	do {
		printf ("Unesite brojeve A i B: ");
		scanf ("%d %d", &a, &b);
		if (a<=0) {
			printf ("A nije prirodan broj.\n");
		} else if (a>=b) {
			printf ("A nije manje od B.\n");
		} else if (b<=0) {
			printf ("B nije prirodan broj.\n");
		}
	} while (a<=0 || b<=0 || a>=b);

	/*pozivanje funkcije*/
	do {
		prost=daj_prost();
		/*provjera da li je prost broj u zadatom interalu i ako jeste dodaje ga u sumu*/
		if (prost<=a || prost>=b) {
			continue;
		}
		suma=suma+prost;
	} while (prost<b);

	printf ("Suma prostih brojeva izmedju %d i %d je %d.", a,b,suma);
 
	return 0;
}