#include <stdio.h>
#define duzina 20

int main() 
{
	int mat[duzina][duzina]={0};
	int niz1[duzina], niz2[duzina];
	int n,i,j,k;
	
	
	printf ("Unesite broj tacaka: ");
	scanf ("%d", &n);
	
		for (j=0; j<duzina; j++)
 		{
 			for (k=0; k<duzina; k++)
 			{
 				mat[j][k]=32;
 			}
 		}
	
	while (n>10 || n<1)
	{
		printf ("Pogresan unos\n");
		printf ("Unesite broj tacaka: ");
		scanf ("%d", &n);
	}
	
	for (i=0; i<n; i++)
	{
		printf ("Unesite %d. tacku: ", i+1);
		scanf ("%d %d", &niz1[i], &niz2[i]);
		if(niz1[i]<0 || niz2[i]<0 || niz1[i]>19 || niz2[i]>19)
		{
			while (1)
			{
				printf ("Pogresan unos\n");
				printf ("Unesite %d. tacku: ", i+1);
				scanf ("%d %d", &niz1[i], &niz2[i]);
				
				if (niz1[i]<20 && niz1[i]>-1 && niz2[i]>=0 && niz2[i]<=19)
				break;
			}
		}
	}
	



	
	for (i=0; i<n; i++)
	{
		for (j=0; j<duzina; j++)
		{
			for (k=0; k<duzina; k++)
			{
				if (k==niz1[i] && j==niz2[i])
				{
					mat[j][k]=42;
				}
			}
		}
	}
	
 	for (j=0; j<duzina; j++)
 	{
		for (k=0; k<duzina; k++)
		{
			printf ("%c", mat[j][k]);
		}
		printf ("\n");
 	}
 	
 
	return 0;
}
