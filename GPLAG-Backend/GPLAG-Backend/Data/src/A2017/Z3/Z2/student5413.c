/* Headers. */
#include <stdio.h>
#include <math.h>

/* Macros. */
#define MAX 100

/* Prototypes. */
void zaokruzi1(float* array, unsigned size);
void preslozi(float* array, unsigned size, unsigned k);

/* Main. */
int main(void)
{
	/* ... */
	
	return 0;
}

void zaokruzi1(float* array, unsigned size)
{
	float *p;
	float float_part;
	int int_part;
	
	/* Rounds each element of the array to one decimal place. */
	for (p = array; p != array + size; p++)
	{
		/* Gets the whole part of the number. */
		int_part = *p;
		/* Gets the floating-point part of the number. */
		float_part = *p - int_part;
		/* Rounds the floating-point part to one decimal place by first multiplying it with 10, */
		/* then using the round() function, and then finally by dividing it with 10.            */
		/* For example: 0.234 -- (x * 10) --> 2.34 -- (round(x)) --> 2.0 -- (x / 10) --> 0.2    */
		float_part *= 10;
		float_part = round(float_part);
		float_part /= 10;
		/* Adds the whole part and the new floating-point part to get the new element of the array. */
		*p = int_part + float_part;
	}
}

void preslozi(float* array, unsigned size, unsigned k)
{
	float *p;
	float temp_array[MAX];
	int int_part;
	float float_part;
	unsigned i, counter, sum_of_digits;
	counter = sum_of_digits = 0;
	
	/* Rounds all the elements of the array to one decimal place. */
	zaokruzi1(array, size);
	
	/* Stores all the elements of the array whose sum of digits is greater or equal to the parameter k into temp_array[]. */
	for (p = array; p != array + size; p++)
	{
			/* Gets the whole and floating-point part of a number. */
			int_part = fabs(*p);
			float_part = fabs(*p) - int_part;
			/* This part here is to assure that the floating-point part is something like 0.20000 and not 0.19997. */
			float_part *= 10;
			float_part = round(float_part);
			float_part /= 10;
			
			/* Checks whether the whole part of the number is zero or not. */
			if (int_part != 0)
			{
				/* If it isn't zero, then it adds its digits to the sum of digits. */
				while (int_part > 0)
				{
					sum_of_digits += int_part % 10;
					int_part /= 10;
				}
			}
			
			/* Adds the floating-point digit to the sum of digits. */
			sum_of_digits += float_part * 10;
			
			/* Checks whether the current value of *p should be stored into temp_array[]. */
			if (sum_of_digits >= k)
			{
				temp_array[counter++] = *p;
			}
			
			sum_of_digits = 0;
	}
	
	/* Copy-paste code from above; the only difference is that this part of the program stores all of the elements of the array              */
	/* whose sum of digits is less than the parameter k into the temp_array behind the elements whose sum of digits is greater or equal to k. */
	for (p = array; p != array + size; p++)
	{
			int_part = fabs(*p);
			float_part = fabs(*p) - int_part;
			float_part *= 10;
			float_part = round(float_part);
			float_part /= 10;
			
			if (int_part != 0)
			{
				while (int_part > 0)
				{
					sum_of_digits += int_part % 10;
					int_part /= 10;
				}
			}
			
			sum_of_digits += float_part * 10;
			
			if (sum_of_digits < k)
			{
				temp_array[counter++] = *p;
			}
			
			sum_of_digits = 0;
	}
	
	/* The elements of temp_array[] get assigned to the original array that got passed to the function (thus modifying that array). */
	for (i = 0, p = array; i < size; i++, p++)
	{
		*p = temp_array[i];
	}
		
}