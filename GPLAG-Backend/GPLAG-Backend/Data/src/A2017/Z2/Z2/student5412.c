#include <stdio.h>

int main() 
{
	int n, i, j, brojac, broj, temp;
	int nizBrojeva[100], nizCifri[100] = {0}, brojaci[101] = {0};
	printf ("Unesite velicinu niza: ");
	scanf ("%d", &n);
	printf ("Unesite clanove niza: ");
	for (i=0; i<n; i++)
	{
	    do
	    {
	        scanf ("%d", &nizBrojeva[i]);
	    }while (nizBrojeva[i]<=0);
	}
	
	brojac = 0;
	for (i = n-1; i>=0; i--) 
	{
		broj = nizBrojeva[i];
		while (broj != 0) 
		{
			nizCifri[brojac] = broj%10;
			broj /= 10;
			brojac++;
    }
  }

  /* obrnem samo niz */
  for (i=0; i<brojac/2; i++) 
  {
    temp = nizCifri[i];
    nizCifri[i] = nizCifri[brojac-1-i];
    nizCifri[brojac-1-i] = temp;
  }

  //for (i=0; i<brojac; i++) 
  //{
    //printf ("%d ", nizCifri[i]);
  //}
	
	printf ("Finalni niz glasi: \n");

	for (i=0; i<brojac; i++)
	{
		for (j=0; j<=100; j++)
		{
			if (nizCifri[i] == j) 
			{
			    brojaci[j]++;
			    printf ("%d %d ", nizCifri[i], brojaci[j]);
			}
		}
	}
	
	return 0;
}
