#include <stdio.h>

int main() {
	int i,j,n;
	for (i=0; i<1;i++)
	{
		printf ("Unesite broj n: ");
		scanf ("%d", &n);
		if (n<1 || n>50)
		{
			printf ("Pogresan unos\n");
			i--;
		}
	}
	for (i=0; i<n; i++)
	{
		for (j=0; j<4*n-1; j++)
		{
			if (i==j || (i+j)==(2*n)-2 || (i+j)==(4*n)-4 || i+j==2*n-2+2*i || (n==1 && j%n==0)) printf("*");
			else printf(" ");
		}
		printf ("\n");
	}
	return 0;
}
