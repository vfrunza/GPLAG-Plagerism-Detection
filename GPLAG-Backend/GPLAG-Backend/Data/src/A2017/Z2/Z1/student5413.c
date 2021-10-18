#include <stdio.h>

int main(void)
{
	int n, i, j;
	
	do
	{
		printf("Unesite broj N: ");
		scanf("%d", &n);
		
		if (n < 8 || n % 4 != 0)
			printf("Neispravno N!\n");
		
	} while (n < 8 || n % 4 != 0);
	
	printf("\n");
	/* Draws the top half of of the picture, i.e. the X and the top-right square. */
	for (i = 0; i < n / 2; i++) 
	{
		/* Draws the X. */
		for (j = 0; j < n / 2; j++)
		{
			if (j == 0 + i)
				printf("\\");
			else if (j == n / 2 - 1 - i)
				printf("/");
			else 
				printf(" ");
		}
		
		/* Draws the square. */
		for (j = n / 2; j < n; j++)
		{
			if (i == 0 || i == n / 2 - 1)
			{
				if (j == n / 2 || j == n - 1)
					printf("+");
				else
					printf("-");
			}
			else 
			{
				if (j == n / 2 || j == n - 1)
					printf("|");
				else
					printf(" ");
			}
		}
		
		printf("\n");
	}
	
	/* Draws the second half of the picture, i.e. the left-bottom square and the plus sign. */
	for (i = n / 2; i < n; i++)
	{
		/* Draws the square. */
		for (j = 0; j < n / 2; j++)
		{
			if (i == n / 2 || i == n - 1)
			{
				if (j == 0 || j == n / 2 - 1)
					printf("+");
				else
					printf("-");
			}
			else 
			{
				if (j == 0 || j == n / 2 - 1)
					printf("|");
				else
					printf(" ");
			}
		}
		
		/* Draws the plus sign. */
		for (j = n / 2; j < n; j++)
		{
			/* Checks whether it's in one of the two centre rows of the plus sign. */ 
			if (i == (n / 2) + (n / 4) || i == (n / 2) + (n / 4) - 1)
			{
				/* Checks whether it's in one of the two centre columns of the plus sign. */
				if (j == (n / 2) + (n / 4) || j == (n / 2) + (n / 4) - 1)
					printf("+");
				else
					printf("-");
			}
			else
			{
				if (j == (n / 2) + (n / 4) || j == (n / 2) + (n / 4) - 1)
					printf("|");
				else
					printf(" ");
			}
			
		}
		
		printf("\n");
	}
	
	return 0;
}