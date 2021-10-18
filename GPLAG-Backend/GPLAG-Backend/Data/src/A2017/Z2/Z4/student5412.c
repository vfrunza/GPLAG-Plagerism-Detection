#include <stdio.h>

int main() 
{
	int A[100][100], B[100][100], C[100][100], m, n, i, j, iste = 1;
	int brojacA[101]={0}, brojacB[101]={0}, brojacC[101]={0}, sumaA = 0, sumaB = 0, sumaC = 0;
	do
	{
		printf ("Unesite brojeve M i N: ");
		scanf ("%d %d", &m, &n);
	}while (m>100 || n>100);
	
	printf ("Unesite clanove matrice A: ");
	for (i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			scanf ("%d", &A[i][j]);
		}
	}
	printf ("Unesite clanove matrice B: ");
	for (i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			scanf ("%d", &B[i][j]);
		}
	}
	printf ("Unesite clanove matrice C: ");
	for (i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			scanf ("%d", &C[i][j]);
		}
	}
	for (i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			if(A[i][j] < 0) A[i][j] *= (-1);
			if(B[i][j] < 0) B[i][j] *= (-1);
			if(C[i][j] < 0) C[i][j] *= (-1);
		}
	}

	for (i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			if (A[i][j])
			{
				//brojacA[A[i][j]]++; 
				sumaA += A[i][j];
				//sumaA = sumaA + brojacA[A[i][j]];
				//printf ("brojacA = %d\n", brojacA[A[i][j]]); 
				//printf ("SumaA = %d\n", sumaA);
			}
		}
	}
	//printf ("\n");
	for (i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			if (B[i][j])
			{
				//brojacB[B[i][j]]++;
				sumaB += B[i][j];
				//sumaB += brojacB[B[i][j]];
				//printf ("brojacB = %d\n", brojacB[B[i][j]]);  
				//printf ("SumaB = %d\n", sumaB);
			}
		}
	}
    //printf ("\n");
	for (i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			if (C[i][j])
			{
				//brojacC[C[i][j]]++;
				sumaC += C[i][j];
				//sumaC += brojacC[C[i][j]];
				//printf ("brojacC = %d\n", brojacC[C[i][j]]); 
				//printf ("SumaC = %d\n", sumaC);
			}
		}
		
	}
    //printf ("\n");
//	for (i=0; i<m; i++)
//	{
//		for(j=0; j<n; j++)
//		{
			//if (brojacB[B[i][j]] != brojacA[A[i][j]] || brojacC[C[i][j]] != brojacA[A[i][j]]) iste = 0;
			if (sumaA != sumaB || sumaA != sumaC) iste = 0;
//		}
//	}
	// for (i=0; i<m; i++)
	// {
	// 	for(j=0; j<n; j++)
	// 	{
	// 		if (brojacC == brojacA) iste = 0;
	// 	}
	// }
	
	if (iste) printf ("DA");
	else printf ("NE");
	printf ("\n");
	return 0;
}
