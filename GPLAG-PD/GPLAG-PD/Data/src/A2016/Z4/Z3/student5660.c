#include <stdio.h>

int DaLiJeZnak(char s)
{
	if (s < 'A' || (s > 'Z' && s < 'a') || s > 'z')
		return 1;
	return 0;
}

int DajBrojSlovaUrijeci (char* rijec)
{
    int brojac = 0;
    while (*rijec != '\0')
    {
        brojac++;
        rijec++;
    }
    return brojac;
}

int DaLiSuJednake (char* prva, char* druga)
{
	while (*prva != ' ' && *prva == *druga && *prva != '\0')
        {
            prva++;
			druga++;
		}
	if ((*prva == ' ' || *prva == '\0') && *druga == '\0')
		return 1;
	return 0;
}

void izbaci(char* trenutna)
{
    char* pocetak, *kraj;
    pocetak = trenutna;
    while (*trenutna != ' ' && *trenutna != '\0')
        trenutna++;
    kraj = trenutna;
    while (*kraj != '\0')
        *pocetak++ = *kraj++;
    while (*pocetak != '\0')
        *pocetak++ = '\0';
}

void ubaci (char* trenutna, char* ubaca)
{
    char* kraj = trenutna;
    int brojSlova = DajBrojSlovaUrijeci(ubaca);
    while (*kraj != '\0')
        kraj++;
    while (kraj > trenutna)
        *(kraj+brojSlova) = *kraj--;
    *(kraj+brojSlova) = *kraj;   
    if (*kraj != '\0')
    *kraj = ' ';
    while (*ubaca != '\0')
        *trenutna++ = *ubaca++;
}
char* zamjena_rijeci (char* tekst, char** rijeci, char** zamjene, int broj_rijeci)
{
	int i;
	char* pocetakTeksta = tekst, *trenutna;
	while (*tekst != '\0')
	{
		while (*tekst == ' ' && *tekst != '\0')
			tekst++;
		/* Ako se rijec zavrsava sa nekoliko razmaka i \0 treba provjeriti jer trenutna postaje tekst, da ne bi bilo frke */
        if (*tekst == '\0') break;
		trenutna = tekst;
		for (i = 0; i < broj_rijeci; i++)
			if (DaLiSuJednake(trenutna, rijeci[i]))
			{
			    izbaci(trenutna);
			    ubaci (trenutna, zamjene[i]);
            }
		if (*tekst != ' ')
        {
            while (*tekst != ' ' && *tekst != '\0')
				tekst++;
        }
		else tekst++;
	}
	return pocetakTeksta;
}

int main()
{

    char* rijeci[2] = { "beli", "sneg" };
char* zamjene[2] = { "bijeli", "snijeg" };
char tekst[100] = "beli sneg je pokrio beli breg";
printf("%s", zamjena_rijeci(tekst, rijeci, zamjene, 2));


	return 0;
}
