#include <stdio.h>

int main()
{
	int M = 0, N = 0;
	
	do
	{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
	}
	while (!(M >= 0 && M <= 100 && N >= 0 && N <= 100));
	
	int i = 0, j = 0;
	int A[100][100], B[100][100], C[100][100];
	
	printf("Unesite clanove matrice A: ");
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			scanf(" %d", &A[i][j]);
		}
	}
	
	printf("Unesite clanove matrice B: ");
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			scanf(" %d", &B[i][j]);
		}
	}
	
	printf("Unesite clanove matrice C: ");
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			scanf(" %d", &C[i][j]);
		}
	}
	
	int k = 0;
	int nizA[10000], nizB[10000], nizC[10000];
	
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			nizA[k] = A[i][j];
			nizB[k] = B[i][j];
			nizC[k] = C[i][j];
			k++;
		}
	}
	
	for (i = 0; i < M * N - 1; i++)
	{
		int zamijenjeni = 0;
		for (j = 0; j < M * N - 1; j++)
		{
			int privremena = 0;
			
			if (nizA[j] > nizA[j + 1])
			{
				privremena = nizA[j];
				nizA[j] = nizA[j + 1];
				nizA[j + 1] = privremena;
				zamijenjeni = 1;
			}
			
			if (nizB[j] > nizB[j + 1])
			{
				privremena = nizB[j];
				nizB[j] = nizB[j + 1];
				nizB[j + 1] = privremena;
				zamijenjeni = 1;
			}
			
			if (nizC[j] > nizC[j + 1])
			{
				privremena = nizC[j];
				nizC[j] = nizC[j + 1];
				nizC[j + 1] = privremena;
				zamijenjeni = 1;
			}
		}
		
		if (zamijenjeni == 0)
		{
			break;
		}
	}
	
	for (k = 0; k < M * N; k++)
	{
		if (nizA[k] != nizB[k] || nizA[k] != nizC[k])
		{
			printf("NE");
			return 0;
		}
	}
	printf("DA");
	return 0;
}
