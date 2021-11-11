#include <stdio.h>

int main() {
//	printf("Zadaća 1, Zadatak 4");
	int r, k, s;
	do {
		printf ("Unesite broj redova: ");
		scanf ("%d", &r);
	} while (r<1 || r>10);
	do {
		printf ("Unesite broj kolona: ");
		scanf ("%d", &k);
	} while (r<1 || r>10);
	do {
		printf ("Unesite sirinu jedne kolone: ");
		scanf ("%d", &s);
		if (s<0) s=-s;
	} while (r<1 || r>10);
	
	int i, j, z;
	
	for (i=0; i<r*2+1; i++) {
		for (j=0; j<k; j++) {
			for (z=0; z<s+1; z++) {
				if (i%2==0) {
					if (z==0 ) printf ("+");
					else printf ("-");
				}
				else if (i%2!=0) {
					if (z==0) printf ("|");
					else printf (" ");
				}
				
			}
			if (j==k-1) {
					if (i%2==0) printf ("+");
					else printf ("|");
				}
		}
		printf ("\n");
	}


	return 0;
}
