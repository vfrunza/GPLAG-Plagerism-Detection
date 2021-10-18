#include <stdio.h>
struct Datum { int dan, mjesec, godina; };
    struct Uposlenik {
        char ime_prezime[50];
        struct Datum datum_rodjenja;
    };
int datum2dani (struct Datum d)
{
	int dani[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int g = d.godina;
	dani[2] += g % 4 == 0 && (g % 100 != 0 || g % 400 == 0);
	int dana = 0, i;
	for (i = 0; i < d.mjesec; ++i)
		dana += dani[i];
	return g * 365 + g / 4 - g / 100 + g / 400 + dana + d.dan;
}
int razmak (struct Datum d1, struct Datum d2)
{
	return datum2dani(d2) - datum2dani(d1);
}
void daj_prezimena (const char *s, char *prezime1, char *prezime2)
{
	
	while (*s && *s != ' ') s++;
	const char *p = ++s;
	while (*s && *s != '-' && *s != ' ') s++;
	if (*s == ' ')
		{
			p = ++s;
			while (*s && *s != '-') s++;
		}
		
	while (p < s)
		*prezime1++ = *p++;
	if (*s == '-')
		while (*s)
			*prezime2++ = *++s;
	*prezime1 = *prezime2 = 0;
	
}
#include <string.h>
int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana)
{
	int i, j, bd = broj_dana < 0 ? -broj_dana : broj_dana;
	char p1[50], p2[50], d1[50], d2[50];
	daj_prezimena(direktor.ime_prezime, d1, d2);
	for (i = 0; i < vel; ++i)
	{
		daj_prezimena(kandidati[i].ime_prezime, p1, p2);
		if (!*p2 && !*d2)
			*p2 = '-';
		if (!strcmp (p1, d1) || !strcmp (p1, d2) || !strcmp (p2, d1) || !strcmp (p2, d2))
			continue;
		int r = razmak(kandidati[i].datum_rodjenja, direktor.datum_rodjenja);
		if (r > broj_dana && broj_dana > 0 || broj_dana < 0 && -r < -broj_dana)
		{
			for (j = i + 1; j < vel; ++j)
				kandidati[j - 1] = kandidati[j];
			vel--;
			i--;
		}

	}
	return vel;
}
int main() {
/* AT6: Negativna razlika dana */
struct Uposlenik direktor = {"Mujo Mujic", {1, 9, 1980} };
struct Uposlenik kandidati[7] = {
    { "Meho Mehic", { 31, 1, 1980 } },
    { "Pero Peric", { 1, 2, 1980 } },
    { "Sara Sarac", { 3, 10, 1980 } },
    { "Fata Mujic", { 1, 2, 1976 } },
    { "Jozo Jozic", { 2, 10, 1980 } },
    { "Mijo Mijic", { 4, 3, 1979 } },
    { "Suljo Suljc", { 15, 1, 1982 } },
};

int novi_br = suzi_listu(kandidati, 7, direktor, -31);
int i;
printf("Nakon suzenja liste:\n");
for (i=0; i<novi_br; i++)
    printf("%s\n", kandidati[i].ime_prezime);
}
