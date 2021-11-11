#include <stdio.h>

int main () {
	int n, niz_poc[100], niz_kraj[1000], i;
	
	do {
		printf ("Unesite velicinu niza: ");
		scanf ("%d", &n);
	} while (n<1 || n>100);
	
	printf ("Unesite clanove niza: ");
	for (i=0;i<n;i++) {
		scanf ("%d", &niz_poc[i]);
		if (niz_poc[i]<0) {
			printf ("Neispravan unos!");
			i--;
		}
	}
	
	for (i=0;i<n;i++) {
		while (niz_poc[i]!=0) {
			x = niz_poc[i] % 10;
		}
	}
}