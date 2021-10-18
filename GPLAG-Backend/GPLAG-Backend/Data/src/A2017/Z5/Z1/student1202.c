#include <stdio.h>
#define min(a,b) ((a) < (b) ? (a) : (b))

struct Datum {
	int dan, mjesec, godina;
};
struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};
int dana_u_god(int g)
{
	return (g % 4 == 0 && g % 100) || g % 400 == 0 ? 366 : 365;
}
int dana_u_mj(int m, int g)
{
	int i[12] = {31,0,31,30,31,30,31,31,30,31,30,31};
	return m == 2 ? 28 + ((g % 4 == 0 && g % 100) || g % 400 == 0) : i[m-1];
}
int razlika(struct Datum a, struct Datum b)
{
	int g = min(a.godina, b.godina), i, rel1 = a.dan, rel2 = b.dan;
	for (i = g; i < a.godina; i++) rel1 += dana_u_god(i);
	for (i = g; i < b.godina; i++) rel2 += dana_u_god(i);
	for (i = 1; i < a.mjesec; i++) rel1 += dana_u_mj(i, a.godina);
	for (i = 1; i < b.mjesec; i++) rel2 += dana_u_mj(i, b.godina);
	return rel2 - rel1;
}
//Pohranjuje prezimena iz a (koji sadrzi ime i prezimena) u niz p
void prezime(char *a, char **p)
{
	while (*a && *a != '-') a++;
	*p = a;
	while (**p == ' ') (*p)--;
	while (*--(*p) != ' ');
	(*p)++;
	p[1] = !*a ? 0 : a+1;
}
//Provjerava da li su dva prezimena ista (prezime se zavrsava znakom ' ' ili '-')
int streq(char *a, char *b)
{
	if (!a || !b) return 0;
	while (*a && *a != '-' && *b && *b != '-')
		if (*a++ != *b++) return 0;
	return (!*a || *a == '-') && (!*b || *b == '-');
}
//Provjerava da li su bilo koja dva prezimena ista
int isto_prezime(char *a, char *b)
{
	char *a1[2], *b1[2];
	prezime(a, a1);
	prezime(b, b1);
	return streq(*a1, *b1) || streq(a1[1], b1[1]) || streq(*a1, b1[1]) || streq(a1[1], *b1);
}
int suzi_listu(struct Uposlenik *kandidati, int vel, struct Uposlenik direktor, int broj_dana)
{
	int i, j;
	for (i = 0; i < vel; i++) {
		int stariji = -razlika(direktor.datum_rodjenja, kandidati[i].datum_rodjenja);
		if (!isto_prezime(kandidati[i].ime_prezime, direktor.ime_prezime) && ((broj_dana > 0 && stariji > broj_dana) || (broj_dana < 0 && -stariji < -broj_dana))) {
			vel--;
			//Pomjeranje clanova ulijevo
			for (j = i; j < vel; j++)
				kandidati[j] = kandidati[j+1];
			i--;
		}
	}
	return vel;
}
int main()
{
	return 0;
}