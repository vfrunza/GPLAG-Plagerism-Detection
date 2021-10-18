#include <stdio.h>

typedef int _bool;
#define true 1
#define false 0

#define MAX 100

int main(void)
{
	int matrix_A[MAX][MAX], matrix_B[MAX][MAX], matrix_C[MAX][MAX];
	int histogram_A[MAX * 2], histogram_B[MAX * 2], histogram_C[MAX * 2];
	int m, n; 
	int i, j, e; 
	int counter_A, counter_B, counter_C;
	int index_A, index_B, index_C;
	counter_A = counter_B = counter_C = index_A = index_B = index_C = 0;
	_bool add = true;
	_bool zero_set = false;
	_bool found_match = false;
	
	do
	{
		printf("Unesite brojeve M i N: "); scanf("%d %d", &n, &m);
	} while ((n < 0 || n > MAX) || (m < 0 || m > MAX));
	
	printf("Unesite clanove matrice A: ");
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			scanf("%d", &matrix_A[i][j]);
			
	printf("Unesite clanove matrice B: ");
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			scanf("%d", &matrix_B[i][j]);
			
	printf("Unesite clanove matrice C: ");
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			scanf("%d", &matrix_C[i][j]);
	
	/* Initializes all histograms (sets all their elements to zero). */
	for (i = 0; i < MAX * 2; i++)
	{
		histogram_A[i] = 0;
		histogram_B[i] = 0;
		histogram_C[i] = 0;
	}
	
	/* Checks whether Matrix A contains a zero. */
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			if (matrix_A[i][j] == 0)
			{
				index_A = 2;
				counter_A = 1;
				zero_set = true;
				break;
			}
			
		if (zero_set)
			break;
	}
	
	/* Gets the histogram data for the matrix A. */	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			for (e = 0; e < MAX * 2; e += 2)
				if (matrix_A[i][j] == histogram_A[e])
				{
					histogram_A[e + 1]++;
					add = false;
					break;
				}
				
			if (add)
			{
				histogram_A[index_A] = matrix_A[i][j];
				histogram_A[index_A + 1]++;
				index_A += 2;
				counter_A++;
			}
			
			add = true;
		}
	}
	
	add = true;
	zero_set = false;
	/* Checks whether Matrix B contains a zero. */
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			if (matrix_B[i][j] == 0)
			{
				index_B = 2;
				counter_B = 1;
				zero_set = true;
				break;
			}
			
		if (zero_set)
			break;
	}
	
	/* Gets the histogram data for the matrix B. */	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			for (e = 0; e < MAX * 2; e += 2)
				if (matrix_B[i][j] == histogram_B[e])
				{
					histogram_B[e + 1]++;
					add = false;
					break;
				}
				
			if (add)
			{
				histogram_B[index_B] = matrix_B[i][j];
				histogram_B[index_B + 1]++;
				index_B += 2;
				counter_B++;
			}
			
			add = true;
		}
	}
	
	add = true;
	zero_set = false;
	/* Checks whether Matrix C contains a zero. */
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			if (matrix_C[i][j] == 0)
			{
				index_C = 2;
				counter_C = 1;
				zero_set = true;
				break;
			}
			
		if (zero_set)
			break;
	}
	
	/* Gets the histogram data for the matrix C. */	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			for (e = 0; e < MAX * 2; e += 2)
				if (matrix_C[i][j] == histogram_C[e])
				{
					histogram_C[e + 1]++;
					add = false;
					break;
				}
				
			if (add)
			{
				histogram_C[index_C] = matrix_C[i][j];
				histogram_C[index_C + 1]++;
				index_C += 2;
				counter_C++;
			}
			
			add = true;
		}
	}
	
	if (counter_A != counter_B || counter_A != counter_C)
	{
		printf("NE\n");
		return 0;
	}
	else
	{		
		for (i = 0; i < counter_A * 2; i += 2)
		{
			for (j = 0; j < counter_B * 2; j += 2)
			{
				if (histogram_A[i] == histogram_B[j])
				{
					found_match = true;
					
					if (histogram_A[i + 1] != histogram_B[j + 1])
					{
						printf("NE\n");
						return 0;
					}
				}
			}
			
			if (!found_match)
			{
				printf("NE\n");
				return 0;
			}
			
			found_match = false;
		}
		
		for (i = 0; i < counter_A * 2; i += 2)
		{
			for (j = 0; j < counter_C * 2; j += 2)
			{
				if (histogram_A[i] == histogram_C[j])
				{
					found_match = true;
					
					if (histogram_A[i + 1] != histogram_C[j + 1])
					{
						printf("NE\n");
						return 0;
					}
				}
			}
			
			if (!found_match)
			{
				printf("NE\n");
				return 0;
			}
			
			found_match = false;
		}
	}
	
	printf("DA\n");
	return 0;
}