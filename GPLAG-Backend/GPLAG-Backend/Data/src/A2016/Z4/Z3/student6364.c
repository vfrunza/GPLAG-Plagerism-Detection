#include <stdio.h>
int razmak (char a) 
{
	if (a == ' ')
		return 1;
	return 0;
}
int razlika_vel (char* rijeci, char* zamjene) /* računam razliku u veličini između riječi koju treba zamijeniti i one kojom je treba zamijeniti */
{
	char* p = rijeci;
	char* q = zamjene;
	int razlika, i = 0, j = 0;
	while(!razmak(*p) && *p != '\0') 
	{
		i++;
		p++;
	}
	while(!razmak(*q) && *q != '\0')
	{
		j++;
		q++;
	}
	razlika = (i-j);
	return razlika;
}
int provjera_jednakosti (char* tekst, char* rijec)		/* tražim riječ u tekstu */
{
	while (*tekst != ' ' && *tekst != '\0' && *tekst == *rijec && *rijec != '\0')
	{
		tekst++;
		rijec++;
	}
	if ((*tekst == ' ' || *tekst == '\0') && *rijec == '\0')
		return 1;
	return 0;
}
void ubaci (char* izbaci, char* ubaciti)
{
	int razlika = razlika_vel(izbaci, ubaciti);
	char* kraj_rijeci = izbaci;
	char* p = izbaci;
	char* granica = izbaci;
	char* s = izbaci;
	char* q = ubaciti;
	char* jos_pokazivaca = izbaci;
	while(*kraj_rijeci != '\0')
		kraj_rijeci++;
	if(razlika > 0) 			/* ako je razlika > 0 riječ koju treba zamijeniti je duža od svoje zamjene pa moramo izbaciti "višak prostora" iz niza */
	{	jos_pokazivaca = p + razlika;
		while (*jos_pokazivaca != '\0')
		{
			*p = *jos_pokazivaca;
			p++;
			jos_pokazivaca++;
		}
		while(*p != '\0')
			*p = '\0';
	}
	else if(razlika < 0)		/* ako je razlika negativna znači da moramo proširiti niz */
	{
		while (kraj_rijeci > granica)
		*(kraj_rijeci - razlika) = *kraj_rijeci--;
	}
	while (*q != '\0')
		*s++ = *q++;
	
}
char* zamjena_rijeci (char* tekst, char** rijeci, char** zamjene, int broj_rijeci)
{
	int razlika = 0;
	char* p = tekst;
	char* q = rijeci;
	char* s = zamjene;
	char* restart = tekst;
	int i;
	while (*tekst != '\0')
	{
		while(razmak(*tekst) && *tekst != '\0')	
			tekst++;
		if (*tekst == '\0')
			break;
		p = tekst;
		for (i = 0; i < broj_rijeci; i++)
		{
			if(provjera_jednakosti(p, rijeci[i]))
				ubaci(p, zamjene[i]);
		}
		while(!razmak(*tekst) && *tekst != '\0')
			tekst++;

	}
	return restart;
}
int main() {
	printf("Zadaća 4, Zadatak 3");
	return 0;
}
