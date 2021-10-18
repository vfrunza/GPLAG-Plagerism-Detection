/* Headers. */
#include <stdio.h>
#include <math.h>

/* Make-shift boolean type. */
typedef unsigned char _bool;
#define true 1
#define false 0

/* Prototypes. */
char* ubaci_broj(char* s, int n);

/* Main. */
int main(void)
{
	/* ... */
	
	return 0;
}

char* ubaci_broj(char* s, int n)
{
	char* p_starting_string = s;
	unsigned abs_number = (n >= 0) ? n : (-n); /* Gets the absolute value of n. */
	unsigned len_word = 0;
	unsigned n_digits = 0;
	unsigned i;
	unsigned temp = abs_number;
	_bool negative = (n >= 0) ? false : true; /* Flag used for keeping track of the sign of n. */
	_bool reached_end; /* Flag used for keeping track of whether the last word in the string has been reached. */
	
	/* Gets the number of digits that n has. */
	do
	{
		n_digits++;
		temp /= 10;
	} while (temp != 0);
	temp = abs_number;
	
	
	/* Goes through the string one character at a time. */
	while (*s != '\0')
	{
		/* Encountered a blankspace character. */
		if (*s == ' ')
		{
			/* Checks whether the blankspace character, that has just been encountered, appears after a word or not. */
			if (len_word > 0)
			{	
				/* The blankspace character does in fact appear after a word, but that still doesn't mean that we can go on inserting n here, */
				/* because it could be the case that the previous word (the word who's length we used in the if-statement above) was the last */
				/* word in the string, and that the rest of the string is just composed of blankspace characters.                             */
				/* Ex: "______This___is_an_example__string._(n doesn't need to be inserted here)__________"                                   */
				reached_end = true;
				abs_number = temp;
				char *q = s;
				/* Gets q to point at the end of the string. */
				while (*q != '\0')
				{
					q++;
					/* Whilst moving towards the end of the string, check whether there are any words left. */
					if (*q != ' ' && *q != '\0')
						reached_end = false;
				}
				
				/* If it turns out that there are no more words to be found, then that means that we don't have to insert n anymore, */
				/* i.e., the program has done its job and it can terminate now.                                                      */
				if (reached_end)
					break;
				
				/* If the program reaches this point, then it means that n has to be inserted between two words. */
				/* To do that, we first have to create enough space for the value of n to be inserted:           */
				/* The case in which two words are seperated by two or more blankspaces.                         */
				if (*(s + 1) == ' ')
				{
					while (q > s)
					{
						*(q + (negative ? n_digits + 1 : n_digits)) = *q;
						q--;
					}
					q++;
				}
				/* The case in which two words are seperated by just one blankspace. */
				else
				{
					while (q > s)
					{
						*(q + (negative ? n_digits + 2 : n_digits + 1)) = *q;
						q--;
					}
					*(q + (negative ? n_digits + 2 : n_digits + 1)) = *q;
					q++;
				}
				
				/* Adds a minus to the string if the value of n is negative. */
				if (negative)
					*q++ = '-';
					
				/* Adds the digits (from left to right, i.e., from higher powers of ten to lower) of n to the string. */
				for (i = n_digits; i > 0; i--)
				{
					*q++ = abs_number / pow(10, i - 1) + '0';
					abs_number %= (unsigned) pow(10, i - 1);
				}
				
				len_word = 0;
				s = q;
			}
		}
		else
		{
			len_word++;
		}
		
		s++;
	}
	
	return p_starting_string;
}