#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina)
{
	int test;
	int i, j, k, l;
	for (i=0; i<visina; i++)
	{
		
		for (j=0; j<sirina; j++)
		{
			
		}
	}
	return br_pon;
}

int main() 
{
	int mat[100][100];
	int sirina, visina;
	int i, j;
	printf  ("Unesite sirinu i visinu: ");
	scanf ("%d %d", &sirina, &visina);
	for (i=0; i<visina; i++)
	{
		printf ("Unesite elemente %d. reda: ", i+1);
		for (j=0; j<sirina; j++)
		{
			scanf ("%d", &mat[i][j]);
		}
	}
	printf ("Matrica glasi:\n");
	for (i=0; i<visina; i++)
	{
		for (j=0; j<sirina; j++)
		{
			printf ("%d ", mat[i][j]);
		}
		printf ("\n");
	}
	
	int minimum;
	minimum = max(mat[100][100], visina, sirina);
	printf ("Nakon 1. prolaza matrica glasi: %d", minimum);
	
	return 0;
}
