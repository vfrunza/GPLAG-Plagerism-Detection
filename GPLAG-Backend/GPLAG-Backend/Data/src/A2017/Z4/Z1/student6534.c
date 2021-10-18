#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int velicina_broja(int broj)
{
	int velicina = 0;
	if(broj<=0) 
		velicina++;
	while(broj!=0)
	{
		broj/=10;
		velicina++;
	}
	return velicina;
}

char* ubaci_broj(char* tekst, int broj)
{
	int i, broj_pomocni, razmak;
	char* pom;
	char* kraj;
	char* p = tekst ;
	if(*p == ' ')
	{
		while(*tekst==' ')
			tekst++;
	}
	while(*tekst!='\0')
	{
		if(*tekst==' ')
		{
			kraj = tekst;
			while(*kraj == ' ')
				kraj++;
			if(*kraj=='\0')
				return p;
			razmak = 1;
			if(*(tekst+1)==' ')
				razmak = 0;
			pom = tekst;
			while(*tekst!='\0')
				tekst++;
			while(tekst!=pom)
			{
				*(tekst+velicina_broja(broj)+razmak) = *tekst;
				tekst--;
			}
			tekst++;
			if(broj<0)
			{
				*tekst = '-';
				tekst++;
			}
			broj_pomocni = abs(broj);
			for(i=0; i<velicina_broja(abs(broj)); i++)
			{
				int cifra = broj_pomocni/ round(pow(10,velicina_broja(broj_pomocni)-1));
				*tekst = cifra + '0';
				tekst++;
				broj_pomocni %= (int) round(pow(10,velicina_broja(broj_pomocni)-1));
			}
			if(razmak==1)
			{
				*tekst = ' ';
				tekst++;
			}
			while(*tekst==' ')
				tekst++;
		}
		tekst++;
	}
	return p;
}

int main() {
	char tekst[50] = "Ovo   je neki     primjer   teksta";
	printf("%s", ubaci_broj(tekst,-123));
	return 0;
}
