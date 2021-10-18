#include <stdio.h>

int main() 
{
	/* Variables. */
	int rows, columns, width_of_column, i, j, row, characters;
	
	/* Prompts for the user. */
	do 
	{
		printf("Unesite broj redova: "); scanf("%d", &rows);
	} while (rows <= 0 || rows > 10);
	
	do 
	{
		printf("Unesite broj kolona: "); scanf("%d", &columns);
	} while (columns <= 0 || columns > 10);
	
	do 
	{
		printf("Unesite sirinu jedne kolone: "); scanf("%d", &width_of_column);
	} while (width_of_column <= 0 || width_of_column > 10); 	
	
	/* Calculates the total number of characters that need to be printed in one row (more precisely, one line). */
	characters = columns * width_of_column + columns + 1;
	
	/* Heart of the program: three nested for-loops. */
	
	/* The first for-loop keeps track of the number of rows (a row needing three lines of output to be fully drawn). 
	 * To illustrate:
	 *	
	 *	         			+----+---- 	
	 *	row = 0  			|    |     ... 
	 *           			+----+---- 
	 *  row = 1  			|    |     ...
	 *           			+----+---- 
	 *     .				.    .     	.
	 *     .				.    .		.
	 *     .    			.    .		.
	 *      				+----+---- 
	 *  row = rows - 1		|    |     ...
	 *                      +----+----
 	 */
	for (row = 0; row < rows; row++)
	{
		/* As you can see from the dreadful ASCII art above, the "floor" of the n-th row is the "roof" of the (n+1)-th row. */
		/* Therefore I've decided to (1) draw the roof of the current row and (2) then its middle, before moving on to the next row. 
		 * To illustrate: 
		 * 
		 *                 +----+----
		 *  row = 0        |    |     ...
		 *
		 *                 < Blank space left here to illustrate the workings of the for-loops below. >
		 *
		 *                 +----+---- 
		 *  row = 1        |    |     ...
		 *
	 	 *     .
	 	 *     .
	 	 *     .
		 */
		for (i = 0; i < 2; i++)
		{
			for (j = 0; j < characters; j++)
			{
				if (i == 0 && j % (width_of_column + 1) == 0)
					printf("+");
				else if (i == 0)
					printf("-");
				else if (i == 1 && j % (width_of_column + 1) == 0)
					printf("|");
				else if (i == 1)
					printf(" ");
			}
			
			printf("\n");
		}
	}
	
	/* Having adopted this alternating "roof-middle" drawing strategy, after the termination of the outer most for-loop above,
	   the last row has no "floor", so we need to add it, hence the need for this simple for-loop. */
	for (i = 0; i < characters; i++)
	{
		if (i % (width_of_column + 1) == 0)
			printf("+");
		else
			printf("-");
	}
	
	return 0;
}
