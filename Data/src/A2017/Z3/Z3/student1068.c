/* Headers. */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* Make-shift boolean type. */
typedef unsigned char _bool;
#define true 1
#define false 0

/* Macros. */
#define MAX 300

/* Prototypes. */
int izbaci_cifre(int* numbers, unsigned size_a, int* digits, unsigned size_digits);

/* Main. */
int main(void)
{
	/* ... */
	
	return 0;
}

int izbaci_cifre(int* numbers, unsigned size_numbers, int* digits, unsigned size_digits)
{
	int *pa, *pb, *temp;
	int int_temp;
	int digits_array[MAX];
	unsigned powers_array[MAX];
	unsigned i, j, number_of_digits;
	_bool negative = false;
	
	/* Checks whether the digits array is invalid (i.e., checks for duplicates and values that are below 0 or above 9). */
	for (pb = digits; pb != digits + size_digits ; pb++)
	{
		for (temp = pb; temp != digits + size_digits; temp++)
		{
			if (((*pb == *temp) || (*pb < 0 || *pb > 9 || *temp < 0 || *temp > 9)) && (pb != temp))
			{
				/* Failed execution signal. */
				return 0;
			}
		}
	}
	
	/* Removes target digits (target digits are in digits[]) from the values that are in numbers[]. */
	for (pa = numbers; pa != numbers + size_numbers; pa++)
	{
		for (pb = digits; pb != digits + size_digits; pb++)
		{
			/* Used at the end of the program to make the new value of *pa negative if need be. */
			if (*pa < 0)
					negative = true;
					
			int_temp = abs(*pa);
			
			if (int_temp != 0)
			{
				number_of_digits = 0;
				while (int_temp > 0)
				{
					/* The digits of a number get stored into digits_array[]. Ex: 12345 --> digits_array[5] = {5, 4, 3, 2, 1} */
					digits_array[number_of_digits] = int_temp % 10;
					/* Stores the powers of ten corresponding to each digit in digits_array[].  */ 
					/* For the above digits_array[] example: powers_array[5] = {0, 1, 2, 3, 4}. */
					/* So we get: 1 * 10^4 + 2 * 10^3 + 3 * 10^2 + 4 * 10^1 + 5 * 10^0 = 12345. */                                                     
					powers_array[number_of_digits] = number_of_digits;
					number_of_digits++;
					int_temp /= 10;
				}
				
				for (i = 0; i < number_of_digits; i++)
				{
					/* Removes a digit in digits_array[]. */
					if (digits_array[i] == *pb)
					{
						/* First it sets the value of that digit to 0.              */
						/* Let's say we remove the digit '3' from the number 12345. */
						/* After the removal: digits_array[5] = {5, 4, 0, 2, 1}.    */
						digits_array[i] = 0;
						/* Having lost one digit, i.e. one power to the ten, all the other non-zero powers that are greater */
						/* than the power of the digit that got removed, get lowered by one.                                */
						/* In line with the above exmaple, after the removal: power_arrays[5] = {0, 1, 2, 2, 3}.            */
						for (j = i; j < number_of_digits; j++)
						{
							if (powers_array[j] > 0)
								powers_array[j]--;
						}
					}
				}
				
				/* Calculates the new value of *pa using digits_array[] and powers_array[]. */
				*pa = 0;
				for (i = 0; i < number_of_digits; i++)
				{
					/* Skips zeros. */
					if (digits_array[number_of_digits - 1 - i] != 0)
					/* After removing the digit '3' from 12345, we have:                                    */
					/* digits_array[5] = {5, 4, 0, 2, 1} and power_arrays[5] = {0, 1, 2, 2, 3}.             */
					/* So now we just go: *pa = 1 * 10^3 + 2 * 10^2 + 4 * 10^1 + 5 * 10^0, and we get 1245. */                                      
					*pa += (digits_array[number_of_digits - 1 - i] * pow(10, powers_array[number_of_digits - 1 - i]));
				}
				
				/* In case *pa was negative at the beginning, makes the new value of *pa negative as well. */
				if (negative)
				{
					*pa = -(*pa);
					negative = false;
				}
			}
		}
	}
	
	/* Successful execution signal. */
	return 1;
}