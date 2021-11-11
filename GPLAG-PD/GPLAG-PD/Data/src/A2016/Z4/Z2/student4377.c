#include <stdio.h>

int redni_najveci(int br, char *s)
{
	int lokacije[95] = {0};
	int arg, i, j, max = 0, index = -1;
	char *pok = s;

	br--;
	
	while(*s != '\0')
	{
		arg = *s - 32;
		lokacije[arg]++;
		s++;
	}
	s = pok;
	
	for(i=0; i<=br; i++)
	{
		max=-1;
		index=0;
		for(j=0; j<=94; j++)
		{
			if(lokacije[j] > max)
			{
				max = lokacije[j];
				index = j;
			}
		}
		lokacije[index]=-1;
	}
	return index;
}

int daj_index(char slovo, char* s)
{
	int i=-1;
	while(1)
	{
		i++;
		if(slovo == *s)
		{
			return i;
		}
		s++;
	}
	return i;
}

char* kodiraj(char *tekst, char *sifrarnik)
{
	char *pok = tekst;
	char *sifpok = sifrarnik;
	int i;
	
	for(i=1; i<=95; i++)
	{
		*sifrarnik = redni_najveci(i, tekst) + 32;
		sifrarnik++;
	}

	*sifrarnik = '\0';
	sifrarnik = sifpok;
	
	while(*tekst != '\0')
	{
		*tekst = 126 - daj_index(*tekst,sifrarnik);
		tekst++;
	}
	return pok;
}

char daj_slovo(int i, char *sifrarnik)
{
	int j=0;
	while(j != i)
	{
		sifrarnik++;
		j++;
	}
	return *sifrarnik;
}

char *dekodiraj(char *tekst, char* sifrarnik)
{
	int i;
	char* pok = tekst;
	while(*tekst != '\0')
	{
		i=0;
		while(126 - i != *tekst)
		{
			i++;
		}
		*tekst = daj_slovo(i, sifrarnik);
		tekst++;
	}

	return pok;
}

int main() 
{

	return 0;
}
