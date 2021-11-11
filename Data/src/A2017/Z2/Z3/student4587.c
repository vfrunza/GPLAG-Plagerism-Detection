#include <stdio.h>

int main()
{
	int i, j;
	
	int mA = 0, nA = 0;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &nA, &mA);
	
	float A[100][100];
	printf("Unesite clanove matrice A: ");
	for (i = 0; i < mA; i++)
	{
		for (j = 0; j < nA; j++)
		{
			scanf("%f", &A[i][j]);
		}
	}
	
	int mB = 0, nB = 0;
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &nB, &mB);
	
	float B[100][100];
	printf("Unesite clanove matrice B: ");
	for (i = 0; i < mB; i++)
	{
		for (j = 0; j < nB; j++)
		{
			scanf("%f", &B[i][j]);
		}
	}
	
	if (mA != nB || nA != mB)
	{
		printf("NE");
		return 0;
	}
	
	float rotiranaA[100][100];
	for (i = 0; i < mA; i++)
	{
		for (j = 0; j < nA; j++)
		{
			rotiranaA[j][mA - i - 1] = A[i][j];
		}
	}
	
	for (i = 0; i < mB; i++)
	{
		for (j = 0; j < nB; j++)
		{
			if (B[i][j] != rotiranaA[i][j])
			{
				printf("NE");
				return 0;
			}
		}
	}
	
	printf("DA");
	return 0;
}
