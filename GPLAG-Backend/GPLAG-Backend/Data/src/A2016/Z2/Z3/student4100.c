#include <stdio.h>
#define size 20
int main() {
	int x[size], y[size], n, a = 0, b = 0, c = 0, t = 0, k;
	do {
		printf ("Unesite broj tacaka: ");
		scanf ("%d", &n);
		if (n > 10 || n <= 0){ printf ("Pogresan unos\n");}
	} while (n > 10 || n <= 0);
	for ( a = 0; a < n; a++){
		printf("Unesite %d. tacku: ", a+1);
		scanf("%d %d", &x[a], &y[a]);
		if (x[a] < 0 || x[a] >= 20 || y[a] < 0 || y[a] >= 20) {
			printf("Pogresan unos\n");
			a--;
		}
	}
	for ( a = 0; a < 20; a++){
	for (b = 0; b < 20; b++) {
		for ( k = 0; k < n; k++){
			if (x[k] == b && y[k] == a && c == 0){
				printf("*");
				c++;
			} else { t++;}
		} if ( t = (n - 1) && c == 0) { printf(" ");}
		c = 0;
		k = 0;
		t = 0;
	}
	printf ("\n");
	}
	return 0; 
}
	