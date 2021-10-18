#include <stdio.h>

int iste_rijeci(char *pok1, char *pok2)
{
	while(*pok1 != ' ' && *pok1 != '\0' || *pok2 != ' ' && *pok2 != '\0')
	{
		if(*pok1 != *pok2) return 0;
		pok1++;
		pok2++;
	}
	return 1;
}
int duzina_rijeci(char *s)
{
	int i = 0;
	while(*s != ' ' && *s != '\0')
	{
		i++;
		s++;
	}
	return i;
}

char *zamjena_rijeci(char *tekst, char **rijeci, char **zamjene, int broj_rijeci)
{
	char *pocetak = tekst, *setac1, *setac2, *kraj = tekst, *pomocni;
	int i, razlika;
	while(*tekst != '\0')
	{
		if(*tekst != ' ')
		{
			for(i = 0; i < broj_rijeci; i++)
				if(iste_rijeci(tekst, rijeci[i]))
				{
					razlika = duzina_rijeci(zamjene[i]) - duzina_rijeci(rijeci[i]); //razlika u duzinama rijeci u recenici i rijeci kojom trebamo zamijeniti ovu prvu
					setac1 = tekst;
					setac2 = tekst;
					while(*setac2 != ' ' && *setac2 != '\0') setac2++;				//ide na kraj rijeci
					if(razlika > 0)													//ako je rijec kojom trebamo da zamjenimo veca od one koja stoji u recenici
					{
						while(*kraj != '\0') kraj++;								//tjeramo na kraj
						while(kraj >= setac2)										//pravimo prostor za zamjensku rijec
						{
							*(kraj+razlika) = *kraj;
							kraj--;
						}
						pomocni = zamjene[i];
						while(*pomocni != '\0')										//upisujemo zamjensku rijec na njeno mjesto
							*setac1++ = *pomocni++;
					}
					else if(razlika < 0)											//ako je rijec kojom trebamo zamijeniti kraca od rijeci u recenici
					{
						while(*setac2 != '\0')										//smanjujemo duzinu recenice
						{
							*(setac2+razlika) = *setac2;
							setac2++;
						}
						*(setac2+razlika) = '\0';
						pomocni = zamjene[i];
						while(*pomocni != '\0')										//upisujemo zamjensku rijec na njeno mjesto
							*setac1++ = *pomocni++;
					}
					else															//ako je zamjenska rijec iste duzine kao i originalna
					{
						pomocni = &zamjene[i][0];
						while(*pomocni != '\0')										//samo prepisujemo zamjensku preko postojece rijeci, jer su iste duzine
							*setac1++ = *pomocni++;
					}
					break;
				}
				while(*tekst != ' ' && *tekst != '\0') tekst++;
				tekst--;
		}
		tekst++;
	}
	return pocetak;
}

int main() {
	printf("Zadaća 4, Zadatak 3");
	return 0;
}
