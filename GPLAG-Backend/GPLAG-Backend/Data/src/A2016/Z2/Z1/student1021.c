#include <stdio.h>
#include <stdlib.h>
int main () {
	int cifra1, cifra2, rezultat=0, n, k=1;
	
	printf ("Unesite broj: ");
	scanf ("%d", &n);

	while (abs(n)>=10) {
		
		cifra1=n%10;
		n=n/10;
		cifra2=n%10;
		rezultat+=(abs(cifra1-cifra2)*k);
		k*=10;
	}
	printf ("%d", rezultat);
	
	return 0;
}