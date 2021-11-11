#include <stdio.h>

int main() 
{
	int A[100][100], B[100][100], C[100][100], mA, nA, mB, nB, i, j, iste = 1;
	printf ("Unesite sirinu i visinu matrice A: ");
	scanf ("%d %d", &mA, &nA);
	printf ("Unesite clanove matrice A: ");
	for (i=0; i<mA; i++)
	{
		for (j=0; j<nA; j++)
		{
			scanf ("%d", &A[i][j]);
		}
	}
	// for (i=0; i<m; i++)
	// {
	// 	for (j=0; j<n; j++)
	// 	{
	// 		printf ("%d ", A[i][j]);
	// 	}
	// 	printf ("\n");
	// }
	
	printf ("Unesite sirinu i visinu matrice B: ");
	scanf ("%d %d", &mB, &nB);
	printf ("Unesite clanove matrice B: ");
	for (i=0; i<mB; i++)
	{
		for (j=0; j<nB; j++)
		{
			scanf ("%d", &B[i][j]);
		}
	}
	// for (i=0; i<m; i++)
	// {
	// 	for (j=0; j<n; j++)
	// 	{
	// 		printf ("%d ", B[i][j]);
	// 	}
	// 	printf ("\n");
	// }
/*	for (i=0; i<m; i++)
	{
		for (j=0; j<n; j++)
		{
			if ((A[i][j] == B[j][m-1]) && (B[i][j] == A[n-1][i])) iste = 0;
		}
	}*/
	
	for(i=0; i<mB; i++)
	{
		for(j=0; j<nB; j++)
		{
			if (mA==mB && nA==nB) C[i][j] = A[mB-1-j][i];
			else
			{
				C[i][j] = A[j][nB-1-i];
			}
		}
	}
	/*printf ("Ni");
	for (i=0; i<mB; i++)
	{
		for (j=0; j<nB; j++)
		{
			printf ("%d ", C[i][j]);
		}
		printf ("\n");
	}*/
	
	for (i=0; i<mB; i++) {
		for (j=0; j<nB; j++) {
			if (C[i][j] != B[i][j]) 
			{
				iste = 0;
			}
		}
	}
	
	if (iste) printf ("DA");
	if (!iste) printf ("NE");
	
	printf("\n");
	return 0;
}
