#include <stdio.h>
int main() {
	int niz1[10], i=0, j=0, k=0, niz2[10], n;
	do { 
		printf ("Unesite broj tacaka: ");
		scanf ("%d", &n);
		if (n>10 || n<=0)
		printf ("Pogresan unos\n");
		}while (n>10 || n<=0);
		for (i=0; i<n; i++) {
			do {
		printf ("Unesite %d. tacku: ", i+1);
		scanf ("%d %d", &niz1[i],&niz2[i]);
		if (niz1[i]<0 || niz1[i]>19 || niz2[i]<0 || niz2[i]>19)
		printf ("Pogresan unos\n");
} while (niz1[i]<0 || niz1[i]>19 || niz2[i]<0 || niz2[i]>19);
}
		for (i=0; i<20; i++)
{
	for (j=0; j<20; j++)
	{
		for (k=0; k<n; k++)
		{
			if (niz1[k]==j && niz2[k]==i)
			{ printf ("*");
			break;
		}
	}
	if (k==n)
	printf (" ");
	}
	printf ("\n");
}
	return 0;
}
