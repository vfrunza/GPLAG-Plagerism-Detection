#include <stdio.h>

int main() {
	int i, j, l, m, n, o;
	do {
		printf ("Unesite broj redova: ");
		scanf ("%d", &m);
	}
	while (m<=0 || m>10);
	do {
		printf ("Unesite broj kolona: ");
		scanf ("%d", &n);
	}
	while (n<=0|| n>10);
	do {
		printf ("Unesite sirinu jedne kolone: ");
		scanf ("%d", &o);
	}
	while (o<=0 || o>10);
	m=m*2+1;
	n=(o+1)*n+1;
	for (i=0; i<m; i++) {
		l=o+1;
		for (j=0; j<n; j++) {
			if (i%2==0 && (j==0 || j==l)) {
				printf ("+");
				if (j==l) l+=o+1;
			}
			else if (i%2==0 && j!=l) {
				printf ("-");
			}
			if (i%2!=0 && (j==0 || j==l)) {
				printf ("|");
				if (j==l) l+=o+1;
			}
			else if (i%2!=0 && j!=l && j!=0) {
				printf (" ");
			}
		}
		printf ("\n");
	}
	return 0;
}
