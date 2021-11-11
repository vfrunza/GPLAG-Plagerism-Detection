#include <stdio.h>

int main() {
	int i,n,j;
	for (;;) {
			printf("Unesite broj n: ");
		scanf ("%d", &n);
		if (n<=0 || n>50) {
			printf ("Pogresan unos");
			printf("\n");
		}
		else{
			if (n==1) {
				printf ("***");
				return 0;
			}
			else {
	for (i=1; i<=n; i++)
	{ 
		for (j=1; j<=n*4-3; j++)
		{
			if (i==j || i+j==n*2 || j==2*n-2+i || j+i==n*4-2) 
			printf ("*");
			else printf (" ");
	}
	printf ("\n");
	}
	break;
		}
	}
	}
	return 0;
}
