#include <stdio.h>
#define Y 20
#define X 20
int main () {
	int mat[Y][X]={0}, i, n, a, b, j;
	printf ("Unesite broj tacaka: "); 
	scanf ("%d", &n);
	while (n>10 || n<=0) {
		printf ("Pogresan unos\nUnesite broj tacaka: ");
		scanf ("%d", &n);
		}
	for (i=0; i<n; i++) {
		printf ("Unesite %d. tacku: ", i+1);
		scanf ("%d %d", &a,&b);
		if (a<0 || a>19 || b<0 || b>19) {
			printf ("Pogresan unos\n"); 
			i--; }
		else mat[b][a]=1;		
			
		
	}
	for (i=0; i<Y; i++)  {
		for (j=0; j<X; j++) {
			if (mat [i][j]==1) printf ("*");
			else printf (" ");
			
		}
		printf ("\n");
	}


	return 0;
}