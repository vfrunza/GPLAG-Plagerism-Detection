#include <stdio.h>

int main() {
	int n, j, i;
	unos:
		printf("Unesite broj n: ");
		scanf ("%d", &n);
			if(n>50 || n<=0) {
				printf ("Pogresan unos\n"); 
				goto unos;
			}
	if (n==1) printf ("***");
	else{
	for (i=0; i<n; i++){
		for (j=0; j<n*4-3; j++){
			if (j==i || (j==((n*4-3)/2)-i)|| (j==((n*4-3)/2)+i)||(j==(n*4-4)-i)) printf("*");
			else printf (" ");
		}
		printf ("\n");
	}
	}
	return 0;
}
