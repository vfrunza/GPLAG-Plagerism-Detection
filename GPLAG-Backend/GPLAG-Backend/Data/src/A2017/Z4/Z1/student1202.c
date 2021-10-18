#include <stdio.h>
#include <stdlib.h>

char getch(char *s, char *s1)
{
	if (s1 < s || !*s1)
		return ' ';
	return *s1;
}
char *ubaci_broj(char *tekst, int broj)
{
	int n = broj < 0, a = broj, br_raz;
	char *s = tekst, *t;
	do {
		a /= 10;
		n++;
	} while (a);
	while (*s) {
		if (getch(tekst, s-1) != ' ' && *s == ' ') {
			t = s;
			br_raz = 1;
			//Odredjivanje koliko je razmaka potrebno dodati
			while (*++s == ' ') br_raz = 0;
			if (!*s) break;
			while (*++s);
			//Stvaranje prostora za dodatne karaktere
			while (s >= t) {
				*(s + (n + br_raz)) = *s;
				s--;
			}
			s = (t += n+1);
			//Ubacivanje broja u string
			a = broj;
			do {
				*--t = abs(a % 10) + '0';
				a /= 10;
			} while (a);
			if (broj < 0) *--t = '-';
		}
		s++;
	}
	return tekst;
}

int main()
{
	return 0;
}