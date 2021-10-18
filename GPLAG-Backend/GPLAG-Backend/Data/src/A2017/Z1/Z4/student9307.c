#include <stdio.h>

int main()
{
	int i,j,k,n,t,p,q,r;
	do {
		printf ("Unesite broj redova: ");
		scanf ("%d", &i);
	} while (i<1 || i>10);

	do {
		printf ("Unesite broj kolona: ");
		scanf ("%d", &j);
	} while (j<1 || j>10);

	do {
		printf ("Unesite sirinu jedne kolone: ");
		scanf ("%d", &k);
	} while (k<1 || k>10);

	for (n = 1; n <=i; n++) {
		for (t = 1; t <= j; t++) {
			printf ("+");
			for (p = 1; p<=k; p++)
				printf ("-");
		}
		printf ("+");
		printf ("\n");
		for (q = 0; q <= j; q++) {
			printf ("|");
			for (r = 1; r <= k ; r++ )
				printf (" ");
		}
		printf ("\n");
	}

	for (n = 1; n <=1; n++) {
		for (t = 1; t <= j; t++) {
			printf ("+");
			for (p = 1; p<=k; p++)
				printf ("-");
		}
		printf ("+");
	}
	return 0;
}
