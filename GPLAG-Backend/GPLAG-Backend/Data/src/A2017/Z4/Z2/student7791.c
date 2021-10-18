# include <stdio.h>

int provjeri_duzine(char *s, int niz[], int velicina) 
{
	int duzina=0, index=0, broj_rijeci=0;
	do
	{
		if ((*s > 96 && *s< 123) || (*s> 64 && *s< 91))
		{
			duzina++;
		} 
		else 
		{
			if (duzina !=0)
			{
				if(niz[index] !=duzina)
				{
				 	return 0;
				}
				broj_rijeci=broj_rijeci+1;
				index=index + 1;
				duzina=0;
			}
		}
		s++;
	} while ( *s !='\0');
	if(duzina!=0)
	{
		broj_rijeci=broj_rijeci+1;
	}
	if (broj_rijeci !=velicina)
	{
		return 0;
	}
	return 1;
}

int main()
{
	char tekst[] = "Najvise ikada volimA;
	int radi[] = {7, 5, 5, 2};
	int ne_radi[] = {1, 2, 3, 4, 5};
	printf("%d ", provjeri_duzine(tekst, radi, 4));
	printf("%d ", provjeri_duzine(tekst, ne_radi, 5));
	return 0;
}
