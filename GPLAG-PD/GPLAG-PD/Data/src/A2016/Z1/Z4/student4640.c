#include <stdio.h>

int main() {
	int n,i,j;
	
	printf ("Unesite broj n: ");
	scanf ("%i",&n);
	if (n<=0 || n>50) {
		while (n<=0 || n>50) {
	    printf ("Pogresan unos");
		printf ("\nUnesite broj n: ");
	    scanf ("%i",&n);
		}
	} if (n==1)
	printf("***");
	else {
	for (i=0;i<n;i++) {
		
		for (j=0;j<=4*n-4;j++) {
			if ((i==j) || (j-i)==(2*n-2) || (i+j)==(4*n-4) || (i+j)==(2*n-2))
			printf ("*");
			else printf(" ");
		}
		printf ("\n");
		}
	}
	return 0;
}
	
