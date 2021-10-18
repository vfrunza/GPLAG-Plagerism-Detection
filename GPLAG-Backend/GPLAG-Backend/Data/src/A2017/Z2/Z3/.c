#include <stdio.h>
#define dimenzija 20

int main() {
	int niz[dimenzija][dimenzija] = {0};
	int i, j, n, a ,b;
	printf ("Unesite broj tacaka: ");
	scanf ("%d", &n);
	while (n <= 0 || n >= 11) {
		printf ("Pogresan unos\n");
		printf ("Unesite broj tacaka: ");
	    scanf ("%d", &n);
	}
	
	for (i=0; i<n; i++){
		printf ("Unesite %d. tacku: ", i+1);
		scanf ("%d", &a);
		scanf ("%d", &b);
		while ((a <= -1 || a >= 20) || (b <= -1 || b >= 20)){
			printf ("Pogresan unos\n");
			printf ("Unesite %d. tacku: ", i+1);
			scanf ("%d", &a);
			scanf ("%d", &b);
		}
		niz[b][a]++;
	}
	for (i=0; i<dimenzija; i++){
		for (j=0; j<dimenzija; j++){
			if (niz[i][j] > 0){
				printf ("*");
			} else {
				printf (" ");
			}
		}
		printf ("\n");
	}
	return 0;
}