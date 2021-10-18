#include <stdio.h>

int main() {
	int r, k, s, i, j, n;
	
	do {
		printf("Unesite broj redova: ");
		scanf ("%d", &r);
	} while (r<=0 || r>10);
	
	do{
		printf("Unesite broj kolona: ");
		scanf ("%d", &k);
	} while (k<=0 || k>10);
		
	do {
		printf("Unesite sirinu jedne kolone: ");
		scanf ("%d", &s);
	} while (s<=0 || s>10);
		
	
	/*ispis prvog reda*/
		printf ("+");
		for (j=0; j<k; j++) {
			for (n=0; n<s; n++) {
				printf ("-");
			}
			printf ("+");
		}
		printf ("\n");
		
		/*ispis ostalih redova*/
		for (i=0; i<r; i++) {
			/*ispis redova s uspravnim crtama*/
			printf ("|");
			for (j=0; j<k; j++) {
				for (n=0; n<s; n++) {
					printf (" ");
				}
				printf ("|");
			}
			printf ("\n");
			
			
			/*ispis redova kao sto je prvi*/
			printf ("+");
			for (j=0; j<k; j++) {
				for (n=0; n<s; n++) {
					printf ("-");
			}
			printf ("+");
			}
			
		printf ("\n");
		}
	
	return 0;
}
