#include <stdio.h>
#define DUZINA 95
char* kodiraj(char* s, char *p)
{
	int niz[DUZINA]={0},i, najveci, pozicija,j;
	char *poc, *a, *b, *pom;
	poc=s;
	a=p;
	b=p;
	while(*s != '\0')
	{
		niz[*s-32]++;
		s++;
	}
	
	for(i=0; i<DUZINA; i++)
	{
		if(niz[i] > 0)
		{
			najveci= niz[i];
			pozicija=i;
			for(j=0; j<DUZINA; j++)
			{
				if(niz[j] > najveci)
				{
					najveci=niz[j];
					pozicija=j;
				}
			}
			*p= 32 + pozicija;
			p++;
			niz[pozicija]=-1;
		}
	}
	
	for(i=0; i<DUZINA; i++)
		if(niz[i] == 0)
		{
			*p=32+i;
			p++;
		}
		*p='\0';
		pom =a;
		s=poc;
		while(*s != '\0')
		{
			pom = a;
			while(*pom !='\0')
			{
				if(*s == *pom)
				{
					*s= 126-(pom-b);
					break;
				}
				pom++;
			}
			s++;
		}
		return poc;
}

char *dekodiraj (char *s, char *p)
{
	char *pom, *a, *b, *poc;
	int t;
	a=p;
	b=p;
	poc=s;
	while(*s != '\0')
	{
		pom=a;
		while(*pom != '\0')
		{
			if(*s == *pom)
			{
				t=126-32-(pom-b);
				*s= *(p+t);
				break;
			}
			pom++;
		}
		s++;
	}
	return poc;
	
}
int main()
{
	char tekst [40]=" nadi";
	char sifra[100];
	char *p= kodiraj (tekst, sifra);
	printf("%s \n %s \n", tekst, sifra);
	p= dekodiraj(tekst, sifra);
	printf("\n %s", tekst);
	return 0;
}