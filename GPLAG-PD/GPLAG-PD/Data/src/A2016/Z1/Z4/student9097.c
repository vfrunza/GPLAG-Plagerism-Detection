#include <stdio.h>

int main() {
	int n, i, j;
	printf("Unesite broj n: ");
	scanf ("%d", &n);
	while (n<=0 || n>50)
	{
		printf ("Pogresan unos\n");
		printf("Unesite broj n: ");
		scanf ("%d", &n);
	}
	if (n==1) {printf ("***");}
	else
	{
	for (j=1; j<=n; j++)
	{
		for (i=1; i<=(4*n-3); i++)
		{
			if (i==j||(i+j)==2*n||(i+j)==(4*n-2)||(i-j)==(2*n-2)) {printf ("*");}
			else {printf (" ");}
		}
		printf ("\n");
	}
	}
	return 0;
}
