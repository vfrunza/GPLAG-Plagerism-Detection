#include <stdio.h>
#define R 20
#define K 20

int main() {
	int n, x, y, z=0, mat[20][20], i, j;
	for (i=0;i<20;i++) {
		for (j=0;j<20;j++) {
			mat[i][j]=-1;
		}
	}
	printf ("Unesite broj tacaka: ");
	scanf ("%d", &n);
	while (n<1 || n>10) {
		printf ("Pogresan unos\n");
		printf ("Unesite broj tacaka: ");
		scanf ("%d", &n);
	}
	for (z=0;z<n;z++) { 
			printf ("Unesite %d. tacku: ", z+1);
			scanf ("%d %d", &x, &y);
			while ((x<0 || x>19) || (y<0 ||y>19)) {
			      printf ("Pogresan unos\n");
			      printf ("Unesite %d. tacku: ", z+1);
			      scanf ("%d %d", &x, &y);
			}
			mat[y][x]=1;
	}
	for (i=0;i<20;i++) {
		for (j=0;j<20;j++) {
	    if (mat[i][j]==1)  
	    printf ("*");
		
	    else printf (" ");
		}
		printf ("\n");
	}
	    
	return 0;
}
