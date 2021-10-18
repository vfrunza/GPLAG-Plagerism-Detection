#include <stdio.h>

int provjeri  (char *s)
{
	int test = 1;
	char *poc, *kraj;
	while (*s != '\0')
	{
		if  ((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z') || (*s == '<' && *s == '>' && *s == ' <' && *s == ' >' && *s == ' ' && *s == '/' && *s == '=' && *s == '" "')) 
		{
			//poc = s;
			while ((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z') || (*s == '<' && *s == '>' && *s == ' <' && *s == ' >' && *s == ' ' && *s == '/' && *s == '=' && *s == '" "')) s++;
			//kraj = s;
			/*if (*poc == '<' && *kraj == '>')
			{
				test = 1;
				poc++;
			}*/ test = 1;
			s--;
		}
		else test = 0;
		s++;
	}
	
	return test;
}

int main() 
{
	
	return 0;
}
