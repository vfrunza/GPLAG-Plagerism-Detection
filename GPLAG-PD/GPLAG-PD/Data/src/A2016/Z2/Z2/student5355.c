#include <stdio.h>
#define vel 500
#define PI 3.1415926
int main() {
	int n, i, j;
	float sekunde, minute, stepen;
	float niz[vel] = {};
	do {
		printf ("Unesite broj uglova: ");
	   scanf ("%d", &n);
	   if (n < 1 || n > 500) printf ("Pogresan unos\n");
	}	while (n < 1 || n > 500);
	for (i = 0; i < n; i++) scanf ("%d", &n);
	for (i = 0; i < n; i++) {
		niz[i] = niz[i]*180./PI;
	}
	for (i = 0; i < n; i++) {
		minute = ((niz[i]-(int)niz[i])*60);
		sekunde = (minute-(int)minute)*60;
		if (sekunde > 30) {
			for (j = i; j < n-1; j++) {
				niz[j] = niz[j+1];
			}
			i--;
			n--;
		}
	}
	printf ("Uglovi su: \n");
	for (i = 0; i < n; i++) {
		stepen = (int)niz[i];
		minute = ((niz[i]-(int)niz[i])*60);
		sekunde = (minute-(int)minute)*60;
		if (sekunde+0.5 > (int)sekunde+1) sekunde = (int)sekunde +1;
		printf ("%g stepeni %g minuta %g sekundi", stepen, minute, sekunde);
	}
	return 0;
}