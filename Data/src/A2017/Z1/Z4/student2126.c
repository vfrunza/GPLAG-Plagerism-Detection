#include <stdio.h>

int main() {
	int br, bk, sjk, i, j;
	do {
		printf ("Unesite broj redova: ");
		scanf ("%d", &br);
	} while (br<=0 || br>10);

	do {
		printf ("Unesite broj kolona: ");
		scanf ("%d", &bk);
	} while (bk<=0 || bk>10);
	
		do {
		printf ("Unesite sirinu jedne kolone: ");
		scanf ("%d", &sjk);
	} while (sjk<=0 || sjk>10);
	
	for (i=0; i<=br*2; i++) {
		for (j=0; j<=((bk*sjk)+bk); j++) {
			
			if (i%2==0 && j%(sjk+1)==0) printf ("+");
			else if (i%2==0) printf ("-");
			else if (j%(sjk+1)==0) printf ("|");
		
			else printf (" ");
			
		}
		printf ("\n");
	}
	return 0;
}
