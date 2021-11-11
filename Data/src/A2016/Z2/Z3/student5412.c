#include <stdio.h>
#define BROJ_EL 20

int main() 
{
	int n, i=0, k, kord1[10], kord2[10], j;
	
	printf ("Unesite broj tacaka: ");
	scanf ("%i", &n);
	if (n>10) printf("Pogresan unos!");
	
	do {
		printf ("Unesite %d. tacku: ", i+1);
		scanf ("%d %d", &kord1[i], &kord2[i]);
		if (kord1[i]<0 || kord1[i] > 19 || kord2[i] < 0 || kord2[i] > 19) 
		{
			printf ("Pogresan unos\n");
		}
		else
		i++;
	} while (i<n);
	
	for (k=0; k<n; k++)
	{
		for (i=0; i<20; i++)
		{
			for (j=0; j<20; j++)
			{
				if (kord1[k] == i && kord2[k] == j) printf ("*");
				else printf (" ");
			}
		printf ("\n");
		}
	}
	
	
	return 0;
}
