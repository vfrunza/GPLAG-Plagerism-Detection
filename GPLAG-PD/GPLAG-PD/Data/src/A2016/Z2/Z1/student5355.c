#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
	int n, broj, cifra1, cifra2, i = 0, rjesenje = 0, razlika;
	printf ("Unesite broj: ");
	scanf ("%d", &n);
	if (n < 0) n*=-1;
	while (n > 9) {
		cifra1= n%10;
		n/=10;
		cifra2 = n%10;
		razlika = fabs(cifra1-cifra2);
		rjesenje += razlika * (pow(10, i));
		i++;
	}
	printf ("%d", rjesenje);
	return 0;
}
