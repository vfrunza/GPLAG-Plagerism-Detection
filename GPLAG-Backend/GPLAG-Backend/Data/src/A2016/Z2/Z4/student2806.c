#include <stdio.h>

int main()
{
	double  MAT[100][100];
	int m, n, tp, ck, i, j;
	do {
		printf("Unesite M i N:");
		scanf ("%d %d", &m, &n);
		if (m>0 || m<=100 || n>0 || n<=100)
			printf ("\nPogresan unos!\n");
	} while (m>0 || m<=100 || n>0 || n<=100);

	printf("Unesite elemente matrice: ");
	for (i=0; i<m; i++) {
		for (j=0; j<n; j++) {
			scanf ("%lf", &MAT[i][j]);
		}
	}
	tp=1;
	for(i=1; i<m; i++) {
		for (j=1; j<m; j++) {
			if (MAT[i][j] != MAT[i-1][j-1])
				tp=0;
		}
	}
	if (tp)
		printf("Matrica je Teplicova");
	ck=1;
	return 0;
	for(i=1; i<m; i++) {
		for (j=1; j<m; j++) {
			if (MAT[i][0] != MAT[0][m-1])
				ck=0;
		}
	}
	if (ck)
		printf("Matrica je cirkularna");
	return 0;
	if (i<0|| i>100 || j<0 || j>100) printf ("Matrica nije ni cirkularna ni Teplicova");


	/* :( :( :( :( :( :) :) :) :) :) */
	return 0;
}
