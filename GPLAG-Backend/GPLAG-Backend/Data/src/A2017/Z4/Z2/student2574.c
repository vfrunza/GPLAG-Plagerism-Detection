/* Headers. */
#include <stdio.h>

/* Make-shift boolean type. */
typedef unsigned char _bool;
#define true 1
#define false 0

/* Prototypes. */
_bool provjeri_duzine(char* s, unsigned* lengths_words, unsigned size);

/* Main. */
int main(void)
{
	/* ... */
	
	return 0;
}

_bool provjeri_duzine(char* s, unsigned* lengths_words, unsigned size)
{
	unsigned len_word = 0;
	unsigned n_words = 0;

	/* Goes through the string one character at a time. */
	while (*s != '\0')
	{
		/* Encounters a non-letter character (punctuation mark, blankspace, etc.). */
		if (!(*s >= 'a' && *s <= 'z') && !(*s >= 'A' && *s <= 'Z'))
		{
			if (len_word > 0)
			{
				/* Keeps track of the number of words (used as an index). */
				n_words++;
				if (len_word != *(lengths_words + n_words - 1) || n_words > size)
					return false;
				
				/* Resets the value for the next possible iteration. */
				len_word = 0;
			}
		}
		/* Encounters a letter. */
		else
		{
			/* Keeps track of the length of words. */
			len_word++;
			/* Checks whether this letter is the last character in the string. */
			if (*(s + 1) == '\0')
			{
				/* Copy-paste code from above. */
				if (len_word > 0)
				{
					n_words++;
					if (len_word != *(lengths_words + n_words - 1) || n_words > size)
						return false;
					
					len_word = 0;
				}
			}
		}
		
		s++;
	}
	
	if (n_words < size)
		return false;
	
	return true;
}