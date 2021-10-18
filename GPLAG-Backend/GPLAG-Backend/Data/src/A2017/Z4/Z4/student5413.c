/* Headers. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Macros. */
#define true 1
#define false 0

/* Prototypes. */
int provjeri(char *s);

/* Main. */
int main(void)
{
	/* ... */
	
	return 0;
}

int provjeri(char *s)
{
	/* How the program (mainly) works:  																 */ 
	/* It goes through *s (a piece of HTML code in this case). 											 */
	/* Whenever it encounters an opening tag, that tag's ID gets put on the stack. 						 */
	/* Whenever it encounters a closing tag, it compares that tag with the most recent one on the stack. */
	/* If the two tags are equal, then the tag on the stack gets removed from the stack. 				 */
	/* If the two tags aren't equal, then the program terminates right away. 							 */
	/* After having gone through the entirety of *s, the number of tags left in the stack gets checked.  */
	/* If it's equal to zero, then all the tags in *s are properly nested; if not, then they're not. 	 */
	
	char **stack = NULL;
	char *close_tag_ID;
	char *p;
	unsigned len_tag, i;
	unsigned n_tags = 0;
	
	while (*s != '\0')
	{
		if (*s == '<')
		{
			/* Encountered a tag candidate. */
			
			/* Two possibilites for the pointer p:   */          
			/* 1. p is pointing like this: "<_ ..."  */
			/*                              ^^       */
			/*                              ||       */
			/*                              sp       */
 			/*                                       */
			/* 2. p is pointing like this: "</_ ..." */
			/*                              ^ ^      */
			/*                              | |      */
			/*                              s p      */
  			/*                                       */
			p = s + (*(s + 1) == '/' ? 2 : 1);
			
			/* Deals with irregular HTML code... hopefully with all of it. */
			if (!isdigit(*p) && !isalpha(*p))
				if (n_tags > 0)
					/* Memory needs to be deallocated. */
					goto END;
				else if (n_tags == 0)
					/* No mememory needs to be deallocated. */
					return false;
			
			/* Gets the length of the tag's ID element. */
			len_tag = 0;
			while (isalpha(*p) || isdigit(*p))
			{
				len_tag++;
				p++;
			}
			 
			if (*(s + 1) == '/')
			{
				/* Encountered a closing tag. */
				/* Checks whether there are any open tags to be closed in the first place. */
				if (n_tags == 0)
					return false;
				
				/* Memory allocation. */
				close_tag_ID = (char*) malloc(sizeof(char) * len_tag + 1);
				
				/* Gets the closing tag's ID. */
				p = s + 2;
				len_tag = 0;
				while (isalpha(*p) || isdigit(*p))
				{
					*(close_tag_ID + len_tag) = toupper(*p);
					len_tag++;
					p++;
				}
				*(close_tag_ID + len_tag) = '\0';
				
				if (strcmp(*(stack + n_tags - 1), close_tag_ID) != 0)
				{
					/* Tags aren't properly nested, so the program terminates. */
					free(close_tag_ID);
					for (i = 0; i < n_tags; i++)
						free(*(stack + i));
					free(stack);
					return false;
				}
				else
				{
					/* A pair of tags is properly nested, so the last opening tag from the stack gets removed. */
					free(close_tag_ID);
					free(*(stack + n_tags - 1));
					n_tags--;
					stack = (char**) realloc(stack, sizeof(char*) * n_tags);
				}
			}
			else
			{
				/* Encountered an opening tag. */
				n_tags++;
				
				/* Memory allocation. */
				stack = (char**) realloc(stack, sizeof(char*) * n_tags);
				*(stack + n_tags - 1) = (char*) malloc(sizeof(char) * len_tag + 1);
				
				/* Gets the tag's ID. */
				p = s + 1;
				len_tag = 0;
				while (isalpha(*p) || isdigit(*p))
				{
					*(*(stack + n_tags - 1) + len_tag) = toupper(*p);
					len_tag++;
					p++;
				}
				*(*(stack + n_tags - 1) + len_tag) = '\0';
			}
		}
		
		s++;
	}
	
	END:
	if (n_tags == 0)
		return true;
	else
	{
		for (i = 0; i < n_tags; i++)
			free(*(stack + i));
		free(stack);
		return false;
	}
}