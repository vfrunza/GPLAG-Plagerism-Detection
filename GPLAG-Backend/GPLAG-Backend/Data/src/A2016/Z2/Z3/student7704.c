#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, i, j, k, x[10], y[10], pisi = 0;
	for (; ;) {
		printf("Unesite broj tacaka: ");
	    scanf("%d", &n);
	    if (n < 1 || n > 10) printf("Pogresan unos\n");
	    	else break;
	}
	for (i = 0; i < n; i++) {
		for (; ;) {
			printf("Unesite %d. tacku: ",i+1);
			scanf("%d %d", &y[i], &x[i]);
			if (y[i] < 0 || y[i] > 19 || x[i] < 0 || x[i] > 19) printf("Pogresan unos\n");
				else break;
			}
		}
		for (i = 0; i < 20; i++) {
			for (j = 0; j < 20; j++) {
				pisi = 0;
				for (k = 0; k < n; k++) {
					if (x[k] == i && y[k] == j) {
						pisi = 1;
						break;
						
					}
			}
		if (pisi) printf("*");
			else printf(" ");
			
		}
		printf("\n");
		}	
	    return 0;
}
