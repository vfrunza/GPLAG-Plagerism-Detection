#include <stdio.h>
#include <math.h>
#define Eps 1e-10

int main() {
	double a[10000];
	int m, n, i , j=0, k=0;
	do {
		printf ("Unesite M i N: ");
		scanf ("%d %d", &m, &n);
		if (m>100 || m<1 || n>100 || n<1) {
			printf ("Pogresan unos!\n");
		}
	} while (m>100 || m<1 || n>100 || n<1);
	printf ("Unesite elemente matrice: ");
	for (i=0; i<m*n; i++) {
		scanf ("%lf", &a[i]);
	}
	for (i=0; i<(m-1)*n; i++) {
		if (i%n==n-1) {
			if (fabs(a[i]-a[i+1])<=Eps) {
				j++;
			}
		} else {
			if (fabs(a[i]-a[i+n+1])<=Eps) {
				j++;
				k++;
			}
		}
	}
	if (j==(m-1)*n || (j==0 && (m<2 || n<2))) {
		printf ("Matrica je cirkularna");
	} else {
		if (k==(m-1)*(n-1)) {
			printf ("Matrica je Teplicova");
		} else {
			printf ("Matrica nije ni cirkularna ni Teplicova");
		}
	}
	return 0;
}