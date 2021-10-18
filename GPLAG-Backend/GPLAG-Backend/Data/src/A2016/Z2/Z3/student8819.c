#include <stdio.h>

int main() {
	//printf("Zadaća 2, Zadatak 3");
	
	
	int n, i, j, br;
	unos1:
		printf ("Unesite broj tacaka: ");
		scanf ("%d", &n);
		if (n<1 || n>10 ) {
			printf ("Pogresan unos\n");
			goto unos1;
		}
	
	int niz[20][20] = {0};
	
	for (i=0; i<n; i++) {
		unos2:
			printf ("Unesite %d. tacku: ", i+1);
			int a, b;
			scanf ("%d", &a);
			scanf ("%d", &b);
			if (a<0 || a>19 || b<0 || b>19) {
				printf ("Pogresan unos\n");
				goto unos2;
			}
		niz[a][b]=1;
	}
	
	br=0;
	for (i=0; i<20; i++) {
		if (br<n) {
			for (j=0; j<20; j++) {
				if (niz[j][i]==1) {printf ("*"); br++;}
				else printf (" ");
			}
			printf ("\n");
		}
	}
	
//	printf ("\n");
	
	return 0;
}
