#include <stdio.h>
#include <math.h>

void unesi(char niz[], int velicina)
{
	char znak = getchar();
	if (znak=='\n') znak = getchar();
	int i = 0;
	while (i < velicina -1 && znak != '\n')
	{
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i] = '\0';
}

int rastavi_na_cifre (int broj)
{
	int brojac = 0;
	int pomocni_broj = fabs(broj);
	while (pomocni_broj > 0)
	{
		brojac *= 10;
		brojac += pomocni_broj%10;
		pomocni_broj /= 10;
	}
	return brojac;
}
int broj_razmaka (char *s)
{
	int brojac = 0;
	while (*s != '\0')
	{
		if (*s == ' ') brojac++;
		s++;
	}
	return brojac;
}

char* ubaci_broj (char* tekst, int broj)
{
	char *pocetak = tekst;
	char *pomocna = tekst;
	int povratni_broj = broj;
	int pomocni_broj;
	int pomocni_razmak = broj_razmaka(tekst);
	pomocni_broj = rastavi_na_cifre(broj);

	while (*tekst != '\0')
	{
		
		if (!((*tekst >= 'a' && *tekst <= 'z') || (*tekst >= 'A' && *tekst <= 'Z') || *tekst == '-' || *tekst == '.' || *tekst == '!'))
		{
			pomocni_broj = rastavi_na_cifre(broj);
			pomocna = tekst;
			povratni_broj = broj;
			
			if (broj < 0)
			{
				while (*pomocna != '\0') pomocna++;
				while (pomocna != tekst)
				{
					*(pomocna+1) = *pomocna;
					pomocna--;
				}
				*(++tekst) = '-';
			}
			
			
			//printf ("\npomocna: %s", pomocna); printf ("\ntekst: %s", tekst);
			
			while (pomocni_broj > 0) 
			{
				while (*pomocna != '\0') pomocna++;
				while (pomocna != tekst)
				{
					*(pomocna+1) = *pomocna;
					pomocna--;
				}
				*(++tekst)  = pomocni_broj%10 + '0';
				pomocni_broj /= 10;
			}
			
			//printf ("\npomocna: %s", pomocna); printf ("\ntekst: %s", tekst);
			
			while (*pomocna != '\0') pomocna++;
			while (pomocna != tekst)
			{
				*(pomocna+1) = *pomocna;
				pomocna--;
			}
			*(++tekst) = ' ';
			
			//printf ("\npomocna: %s", pomocna); printf ("\ntekst: %s", tekst);
			
			while (povratni_broj%10 == 0)
			{
				while(*pomocna != '\0') pomocna++;
				while (pomocna != tekst)
				{
					*(pomocna+1) = *pomocna;
					pomocna--;
				}
				*(++tekst) = '0';
				povratni_broj /= 10;
			}
			//printf ("\npomocna: %s", pomocna); printf ("\ntekst: %s", tekst);
		
		}
		tekst++;
		//printf ("\npomocna: %s", pomocna); printf ("\ntekst: %s", tekst);
	}
	return pocetak;
}

int main() 
{
	char string [1200];
	int vel;
	printf ("Unesite velicinu stringa: ");
	scanf ("%d", &vel);
	
	unesi(string, vel);
	
	printf ("%s", string);
	printf ("\n");
	
	printf ("%d ima rrazmaka u stringu: ", broj_razmaka(string));
	
	printf ("\n");
	printf ("Unesite broj koji zelite ubacitii u string: ");
	int broj;
	scanf ("%d", &broj);
	
	printf ("%s", ubaci_broj(string, broj));
	return 0;
}
