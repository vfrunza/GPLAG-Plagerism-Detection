#include <stdio.h>

char* ubaci_broj(char *tekst, int broj)
{
	char *s = tekst;
	char *pom;
	int brojac = 0;
	int broj2 = 0;
	int cifra, cifra2, pomocni_broj = broj;
	if(pomocni_broj < 0) brojac++;
	while(pomocni_broj != 0)
	{
		pomocni_broj /= 10;
		brojac++;
	}
	
	while(*s == ' ' && *s != '\0') s++;
	while(*s != '\0')
	{
		if(*s == ' ')
		{
			pom = s;
			while(*s == ' ' && *s != '\0') s++;
			if(*s == '\0') break;
			s = pom;
			s++;
			pom = s;
			while(*pom != '\0') pom++;
			while(pom >= s)
			{
				*(pom + brojac) = *pom;
				pom--;
			}
			pomocni_broj = broj;
			while(pomocni_broj != 0)
			{
				broj2 *= 10;
				cifra = pomocni_broj%10;
				broj2 += cifra;
				pomocni_broj /= 10;
			}
			if(broj2 < 0)
			{
				*s = '-';
				broj2 *= -1;
				s++;
			}
			while(broj2 != 0)
			{
				cifra2 = broj2%10;
				*s = cifra2 + '0';
				broj2 /= 10;
				s++;
			}
			if(*s != ' ')
			{
				while(*pom != '\0') pom++;
				while(pom > s)
				{
					*pom = *(pom - 1);
					pom--;
				}
				*s = ' ';
			}
		}
		s++;
	}
	return tekst;
}

int main()
{
	char s[77] = "Ovdje  izmedju    rijeci ima      po nekoliko   razmaka";
	printf("\"%s\"", ubaci_broj(s, 320));
	
	return 0;
}