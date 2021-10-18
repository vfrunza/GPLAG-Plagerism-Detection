/* Headers. */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Make-shift boolean type. */
typedef unsigned char _bool;
#define true 1
#define false 0

/* Prototypes. */
void najduzi_bp(char* s1, char* s2);

/* Main. */
int main(void)
{
	/* ... */
	
	return 0;
}

void najduzi_bp(char* s1, char* s2)
{
	char *p;
	char sub_string[26 + 1] = ""; /* There are 26 characters in the English alphabet, hence the maximum storage capacity of 26. */ 
	char temp_sub_string[26 + 1]; /* The '+1' is there to make sure that '\0' can be placed at the end of the string.           */
	unsigned sub_string_len = 0;
	unsigned temp_sub_string_len;
	unsigned i;
	_bool duplicate;
	
	/* Goes throught the string one character at a time. */
	while (*s1 != '\0')
	{
		/* Found a new candidate of the longest sub-string. */
		if (isalpha(*s1))
		{
			/* Resets values for this iteration. */
			strcpy(temp_sub_string, "");
			temp_sub_string_len = 0;
			
			/* Goes through the sub-string one character at a time. */
			p = s1;
			while (isalpha(*p))
			{
				/* Checks for duplicate characters. */
				duplicate = false;
				for (i = 0; i < temp_sub_string_len; i++)
				{
					/* toupper() is used because the program doesn't differentiate between uppercase and lowercase letters, i.e. 'A' == 'a'. */
					if (toupper(*p) == toupper(*(temp_sub_string + i)))
					{
						/* Duplicate found. */
						duplicate = true;
						break;
					}
				}
				
				/* Non-duplicate characters get inserted into the temporary sub-string. */
				if (!duplicate)
				{
					*(temp_sub_string + temp_sub_string_len) = *p;
					temp_sub_string_len++;
					*(temp_sub_string + temp_sub_string_len) = '\0';
				}
				/* Running into a duplicate character signifies the ending of this particular sub-string. */
				else
				{
					break;
				}
				
				p++;
			}
			
			/* Checks whether the newly acquired sub-string stored in temp_sub_string is longer than the current sub-string stored in sub_string. */
			if (temp_sub_string_len > sub_string_len)
			{
				/* If it is longer, than it becomes the new "main" sub-string. */
				strcpy(sub_string, temp_sub_string);
				sub_string_len = temp_sub_string_len;
			}
		}
		
		s1++;
	}

	strcpy(s2, sub_string);
}