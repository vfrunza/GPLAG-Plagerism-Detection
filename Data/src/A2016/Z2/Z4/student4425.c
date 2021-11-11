#include <stdio.h>

int main() {
	
	double matrica[100][100] = { 0 }, sum[100] = { 0 }; 
	int m, n, i, j, cirkularna = 1, teplicova = 1;
	
	do {
	    printf ("Unesite M i N: ");
	    scanf ("%d %d", &m, &n);
	    if (m<=0 || m>100 || n<=0 || n>100) printf ("Pogresan unos!\n");
	} while (m<=0 || m>100 || n<=0 || n>100);
	
	printf ("Unesite elemente matrice: ");
	for (i = 0; i < m; i++) {
	    for (j = 0; j < n; j++) {
	        scanf ("%lf", &matrica[i][j]);
	    }
	}
    
    for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			sum[i] += matrica[i][j];
		}
	}
    
	for (i = 0; i < m-1; i++) {
		for (j = 0; j < n-1; j++) {
			if (matrica[i][j] != matrica [i+1][j+1]) teplicova = 0;
	    }
	    if (sum[i] != sum [i+1]) cirkularna = 0;
	}

	if (teplicova == 0) printf ("Matrica nije ni cirkularna ni Teplicova");
	if (teplicova == 1 && cirkularna == 1) printf ("Matrica je cirkularna");
	if (teplicova == 1 && cirkularna == 0) printf ("Matrica je Teplicova");
	
	return 0;
}