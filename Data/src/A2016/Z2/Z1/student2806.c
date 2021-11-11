#include <stdio.h>
#include <stdlib.h>

int main() {
    int broj, cifra1, cifra2, k=1, noviBroj=0;
   	printf ("Unesite broj: ");
	scanf ("%d", &broj);
	broj=abs(broj);
	while (broj>9) {
	    cifra1=broj%10;
	    broj/=10;
	    cifra2=broj%10;
	    noviBroj = noviBroj+abs(cifra2-cifra1)*k;
	    k*=10;
	}
	printf("%d", noviBroj);
	return 0;
}
