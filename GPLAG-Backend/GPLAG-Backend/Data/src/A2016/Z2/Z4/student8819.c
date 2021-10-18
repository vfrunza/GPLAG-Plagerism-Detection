#include <stdio.h>

int main() {
	//printf("Zadaća 2, Zadatak 4");
	
	int m, n, i, j, t, o, c[100][100];
	i=0;
	do {
		if (i) printf ("Pogresan unos!\n");
		printf ("Unesite M i N: ");
		scanf ("%d", &m);
		scanf ("%d", &n);
		i++;
	}	while (m<0 || m>100 || n<0 || n>100);

	printf ("Unesite elemente matrice: ");
	
	for (i=0; i<m; i++) {
		for (j=0; j<n; j++) {
			scanf ("%d", &c[i][j]);
		}
	}
	
	//ispitajmo cirkularnost matrice
	o=0;
	for (i=1; i<m; i++) {
		for (j=1; j<n; j++) {
			if (c[i][j]=!c[i-1][j-1]) o++;
		}
	}
	
	//teplicova matrica
	
	t=0;
	for (i=0; i<m-1; i++) {
		for (j=0; j<n-1; j++) {
			if (c[i][j]=!c[i+1][j+1]) t++;
		}
	}
	//
	if (o==0) printf ("Matrica je cirkularna ");
	else if (t==0) printf ("Matrica je Teplicova ");
	else printf ("Matrica nije ni cirkularna ni Teplicova ");
	
	return 0;
}
