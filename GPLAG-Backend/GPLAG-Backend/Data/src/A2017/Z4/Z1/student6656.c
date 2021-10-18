#include <stdio.h>

void unesi(char *s, int duzina)
{
	int znak = getchar();
	if(znak == '\n') znak = getchar();
	int i = 0;
	while(i < duzina - 1 && znak != '\n') {
		s[i] = znak;
		i++;
		znak = getchar();
	}
	s[i] = '\0';
}

int broj_rijeci(const char *s)
{
	int brojac = 0, razmak = 1;
	const char *p = s;

	while(*p != '\0') {
		if(*p == ' ')
			razmak = 1;
		else if(razmak) {
			razmak = 0;
			brojac++;
		}
		p++;
	}
	return brojac;
}

char* ubaci_broj(char *tekst, int broj)
{
	char sbroj[12];
	char *sb = sbroj, *t = tekst, *vracanje = tekst;
	int temp = broj, razmak = 1, duzina = 0,brojac = 0,rijeci = 0,br_rijec = 0;

	*sb++ = ' ';
	if(broj < 0) {
		broj = -broj;
		*sb++ = '-';
	}
	do {
		sb++;
		temp /= 10;
	} while(temp != 0);
	sb++;
	*sb-- = '\0';
	*sb-- = ' ';

	do {
		*sb-- = broj % 10 +'0';
		broj/=10;
	} while(broj != 0);



	char *provjera = sbroj;
	while(*provjera != '\0') {
		duzina++;
		provjera++;
	}

	rijeci = broj_rijeci(tekst);


	while(*t != '\0') {

		if(*t == ' ') {

			razmak = 1;
			if(brojac != 0 && br_rijec < rijeci) {
				char *kraj = t;
				while(*kraj != '\0') kraj++;
				char *sbr = sbroj;
				while(kraj > t) {
					*(kraj + duzina-1) = *kraj;
					kraj--;
				}

				while(*sbr != '\0')
					*t++ = *sbr++;
				t--;
				brojac = 0;
			}
		} else if(razmak == 1) {
			razmak = 0;
			brojac++;
			br_rijec++;
		}

		t++;

	}

	return vracanje;
}

int main()
{
	char tekst[1000];
	int broj;

	printf("Unesite neki tekst: ");
	unesi(tekst,500);

	printf("Unesi broj: ");
	scanf("%d",&broj);

	printf("Rez: %s",ubaci_broj(tekst,broj));

	return 0;
}
