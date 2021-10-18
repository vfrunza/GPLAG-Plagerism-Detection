#include <stdio.h>
#include <string.h>

void najduzi_bp(char *s1, char *s2)
{
	int max = 0;
	char *p = s1;
	char *pomocni;
	while(*s1 != '\0')
	{
		while((*s1 >= 'A' && *s1 <= 'Z') || (*s1 >= 'a' && *s1 <= 'z') && *s1 != '\0')
		{
			
		}
		s1++;
	}
}
int main()
{
	char niz[10];
     najduzi_bp ("Ovo je neki primjer teksta", niz);
     printf ("Niz: '%s'", niz);
	return 0;
}