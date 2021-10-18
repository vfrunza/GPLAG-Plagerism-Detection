#include <stdio.h>
#include <math.h>

typedef int _bool;
#define true 1
#define false 0

#define MAX_INPUT_ELEM 100
#define MAX_OUTPUT_ELEM 1000

int main(void)
{
	int input[MAX_INPUT_ELEM], tracker[MAX_OUTPUT_ELEM];
	int temp_int, n, i, n_digits, counter = 0;
	float temp_input;
	_bool input_done = false;
	
	/* Gets the size of the array. */
	do
	{
		/* Stores the user's input as a float, to be able to check whether the user entered a negative and/or floating-point number. */
		printf("Unesite velicinu niza: "); scanf("%f", &temp_input);
		temp_int = temp_input;
		
		if (temp_int <= 0 || temp_input - temp_int > 0)
			printf("Neispravna velicina!\n");
		else
			n = temp_int;
		
	} while (temp_int <= 0 || temp_input - temp_int > 0);
	
	/* Gets the elements of the input array. */
	do
	{
		printf("Unesite clanove niza: ");
		for (i = 0; i < n; i++)
		{
			/* Again, stores the user's input temporarily as a float to be able to check for invalid input. */
			scanf("%f", &temp_input);
			temp_int = temp_input;
			
			if (temp_int < 0 || temp_input - temp_int > 0)
			{
				printf("Neispravan clan!\n");
				break;
			}
			else
			{
				input[i] = temp_input;
				if (i == n - 1)
					input_done = true;
			}
		}
		
	} while (!input_done);
	
	/* Gets the array of digits. */
	for (i = 0; i < n; i++)
	{
		temp_int = input[i];
		n_digits = 0;
		
		if (temp_int == 0)
		{
				tracker[counter++] = 0;
		}
		else
		{
			while (temp_int != 0)
			{
				n_digits++;
				temp_int /= 10;
			}
			
			temp_int = input[i];
			while (n_digits > 0)
			{
				tracker[counter++] = temp_int / pow(10, n_digits - 1);
				temp_int = temp_int % (int) pow(10, n_digits - 1);
				n_digits--;
			}
		}
	}
	
	/* Prints out the tracker array. */
	printf("Finalni niz glasi:\n");
	for (i = 0; i < counter; i++)
	{
		/* Prints out the first newly encountered digit. */
		printf("%d ", tracker[i]);
		n_digits = 1;
		
		if (i == counter - 1)
			;
		else
		{
			/* Checks how many times does the digit appear in consecutive order. */
			while (tracker[i] == tracker[i + 1])
			{
				n_digits++;
				i++;
				
				/* Prevents the program from going beyond the bounds of the tracker array. */
				if (i + 1 >= counter)
					break;
			}
		}
		
		/* Prints out the number of consecutive appearances. */
		if (i == counter - 1)
			printf("%d", n_digits);
		else
			printf("%d ", n_digits);
	} 
	
	return 0;
}
