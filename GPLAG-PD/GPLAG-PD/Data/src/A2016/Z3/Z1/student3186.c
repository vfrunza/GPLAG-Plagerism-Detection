#include <stdio.h>

int daj_prost () {
	
	static int rbroj = 2;
	int i, brojac = 0, broj;

	for (i=1; i<=rbroj; i++) {
		if (rbroj%i==0)
			brojac ++ ;
	}
	
	broj = rbroj;
	rbroj++;
	
	if (brojac != 2)
		return daj_prost();
	else
		return broj;
}
int main() {
	int a, b;
	int suma = 0, prost=0;
	do {
	printf("Unesite brojeve A i B: ");
	scanf ("%d %d", &a, &b);
	
	if (a>=b) 
	printf ("A nije manje od B.\n");
	else if (a < 1)
	printf ("A nije prirodan broj.\n");
	} while (a>=b || a<1);
	
	while (prost < b) {
		prost = daj_prost();
		if (prost>a && prost<b)
		suma += prost;
	}
	
	printf ("Suma prostih brojeva izmedju %d i %d je %d.", a, b, suma);
	
	return 0;
}