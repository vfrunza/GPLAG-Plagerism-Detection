#include <stdio.h>
int provjeri_duzine(char *tekst, int *niz, int duzina)
{
	int slova=0,rijeci=0,adr=0;
	while(*tekst!='\0')
	{
		if(*tekst>64 && *tekst<91 || *tekst>96 && *tekst<123)
		{
			tekst++;
			if(*tekst<65 || (*tekst>90 && *tekst<97) || *tekst>122)
			{
				rijeci=rijeci+1;
			}
			else
			{
				tekst--;
			}
		}
		tekst++;
		adr++;
	}
	if(rijeci!=duzina)
	{
		return 0;
	}
	tekst=tekst-adr;
	while(*tekst!='\0')
	{
		if(*tekst>64 && *tekst<91 || *tekst>96 && *tekst<123)
		{
			slova=slova+1;
		}
		if(*tekst<65 || *tekst>122 || *tekst>90 && *tekst<97)
		{
			if(slova==*niz)
			{
				niz++;
				slova=0;
			}
			else
			{
				return 0;
			}
		}
		tekst++;
	}
	return 1;
}

int main() {
	
	return 0;
}
