#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int izbaci_cifre(int* brojevi, int dim1, int* cif, int dim2)
{
	int i, j, k, a;
	int lok_cifre[10] = {0}, n, znak = 1;
	//Provjera da li je niz cifara ispravan
	for (i = 0; i < dim2; i++) {
		if (cif[i] < 0 || cif[i] > 9)
			return 0;
		for (j = 0; j < i; j++)
			if (cif[j] == cif[i])
				return 0;
	}

	for (i = 0; i < dim1; i++) {
		if ((a = abs(brojevi[i])) == 0)
			continue;
		znak = brojevi[i] / a;
		//Pohranjivanje cifara u niz
		n = 0;
		while (a > 0) {
			lok_cifre[n++] = a % 10;
			a /= 10;
		}
		for (j = 0; j < dim2; j++) {
			//Izbacivanje cifara
			for (k = 0; k < n; k++)
				if (lok_cifre[k] == cif[j]) {
					n--;
					for (a = k; a < n; a++)
						lok_cifre[a] = lok_cifre[a + 1];
					k--;
				}
		}
		//Konstrukcija broja od preostalih cifara
		brojevi[i] = 0;
		for (k = 0; k < n; k++)
			brojevi[i] += lok_cifre[k] * pow(10, k);
		brojevi[i] *= znak;
	}
	return 1;
}

int main()
{
	return 0;
}
