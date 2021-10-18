#include <stdio.h>

typedef int _bool;
#define true 1
#define false 0

#define MAX 20

int main(void)
{
	int i, j, width_A, height_A, width_B, height_B, target_row, target_column;
	float matrix_A[MAX][MAX], matrix_B[MAX][MAX];
	float rotated[MAX][MAX];
	_bool equal = true;
	
	/* Gets Matrix A. */
	printf("Unesite sirinu i visinu matrice A: "); scanf("%d %d", &width_A, &height_A);
	printf("Unesite clanove matrice A: ");
	for (i = 0; i < height_A; i++)
		for (j = 0; j < width_A; j++)
			scanf("%f", &matrix_A[i][j]);
	
	/* Gets Matrix B. */
	printf("Unesite sirinu i visinu matrice B: "); scanf("%d %d", &width_B, &height_B);
	printf("Unesite clanove matrice B: ");
	for (i = 0; i < height_B; i++)
		for (j = 0; j < width_B; j++)
			scanf("%f", &matrix_B[i][j]);
	
	if (width_A != height_B || height_A != width_B)
		printf("NE\n");
	else
	{
		for (i = 0, target_column = width_B - 1; i < height_A; i++, target_column--)
		{
			for (j = width_A - 1, target_row = height_B - 1; j >= 0; j--, target_row--)
			{
				rotated[target_row][target_column] = matrix_A[i][j];
			}
		}
		
		for (i = 0; i < height_B; i++)
			for (j = 0; j < width_B; j++)
				if (rotated[i][j] != matrix_B[i][j])
				{
					equal = false;
					break;
				}
			
		if (equal)	
			printf("DA\n");
		else	
			printf("NE\n");
	}
	
	return 0;
}