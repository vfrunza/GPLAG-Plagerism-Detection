#include <stdio.h>
#include <stdbool.h>


int provjeri_duple(char *c, char *poredbeni_tekst, int trenutna_duzina)
{
	int i;
	int char_ascii_value=*c;
	if(char_ascii_value>96&&char_ascii_value<123) 
	{
		char_ascii_value = char_ascii_value-32;
	}
	for(i=0; i<trenutna_duzina; i++) 
	{
		int ascii_value=*(poredbeni_tekst+i);
		if(*(poredbeni_tekst+i)>96&&*(poredbeni_tekst+i)<123) 
		{
			ascii_value = ascii_value-32;
		}
		if(char_ascii_value==ascii_value) 
		{
			return 0;
		}
	}
	return 1;
}

void kopiraj(char *prvi, char *drugi, int velicina)
{
	int i;
	for(i=0;i<velicina;i++)
	{
		*(prvi+i)=*(drugi+i);
	}
	*(prvi+velicina)='\0';
}

int dajDuzinu(char *s1)
{
	char* pocetakPodniza;
	pocetakPodniza=s1;
	int duzina=0;
	while(*s1!='\0' && ((*s1 > 96 && *s1< 123) || (*s1> 64 && *s1< 91)) && provjeri_duple(s1,pocetakPodniza,duzina)  )
	{
		duzina++;
		s1++;
	}
	return duzina;
}

void najduzi_bp (char *s1, char *s2)
{
	char* pocetakPodniza;
	int max_duzina=0;
	do {
		int trenutna_duzina = dajDuzinu(s1);
		pocetakPodniza=s1;
		if(trenutna_duzina>max_duzina) 
		{
			max_duzina=trenutna_duzina;
			kopiraj(s2,pocetakPodniza,max_duzina);
		}
		s1++;
	} while(*s1!='\0');
}

int main()
{
char niz[10];
        najduzi_bp ("abcde etankera cdefg", niz);
        printf ("Niz: '%s'", niz);
	return 0;
}
