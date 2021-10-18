#include <stdio.h>

char* ubaci_broj(char *tekst, int broj)
{
	char *p, *q, *r;
	int br_cif = 0, br_razmaka = 0, pom_br, pomak; /*pomak ce sluziti da znammo za koliko cemo prosiriti string*/
	/*prije svega, potrebno je prebrojati cifre broja*/
	pom_br = broj;
	if (pom_br < 0)
		pom_br *= -1;
	while (pom_br > 0) {
		br_cif++;
		pom_br /= 10;
	}
	/*ako je broj negativan, potrebno nam je mjesto i za minus. Posmatramo minus kao jos jednu cifru*/
	/*pom br smo smanjili na nulu a cemo to provjeriti pomocu broja*/
	if (broj < 0)
		br_cif++;

	p = tekst;
	while (*p != '\0') {
		/*pozicioniranje na rijec*/
		if (*p >= 'A' && *p <= 'Z' || *p >= 'a' && *p <= 'z') {
			/*prije svega, pozicionirajmo se na prvi razmak*/
			q = p;
			while (*q != ' ' && *q != '\0')
				q++;
			/*sada, kako je moguce da imamo vise razmaka, potrebno ih je prebrojati*/
			br_razmaka = 0;
			r = q;
			while (*r == ' ') {
				br_razmaka++;
				r++;
			}
			/*ovdje ako je r na \0 onda smo brojali razmake na kraju i tada ne upisujemo broj nego prekinemo petlju*/
			if (*r == '\0')
				break;
			/*imamo dva slucaja, 1 razmak i vise od jednog razmaka*/
			/*ako imamo jedan razmak moramo napraviti mjesto i za drugi(taj prvi ostaje na pocetku, drugi dodajemo na kraj)*/
			pomak = br_cif;
			/*dakle ako je jedan razmak, pomak povecati za jos jedan*/
			if (br_razmaka == 1)
				pomak++;
			/*sada moramo prosiriti string*/
			/*postavimo r na kraj stringa*/
			r = q;
			while (*r != '\0')
				r++;
			/*sada se trebamo vratiti unazad i prepisivati elemente*/
			while (r != q) {
				*(r + pomak) = *r;
				r--;
			}
			/*ubacivanje broja*/
			/*postavimo r na r + pomak udaljenosti od q*/
			r = q + pomak;
			/*ako je broj razmaka 1 onda na to mjesto moramo upisati onaj novododani razmak*/
			if (br_razmaka == 1) {
				*r = ' ';
				r--;
			}
			/*konacno upisivanje broja*/
			/*idemo unazad i ubacujemo cifru po cifru*/
			pom_br = broj;
			if (pom_br < 0)
				pom_br *= -1;
			while (r != q && pom_br > 0) { /*drugi dio uslova je za slucaj kada je negativan broj. tada ce nas ovaj dio izbaciti na mjestu gdje treba biti minus*/
				*r = pom_br % 10 + 48; /*na odg mjesto upisujemo cifru, a 48 se dodaje kako bi se cifra iz int pretvorila u char*/
				pom_br /= 10;
				r--;
			}
			/*ako je broj negativan, petlja iznad je dosla do mjesta gdje treba ubaciti minus*/
			if (broj < 0)
				*r = '-';

			/*pomjerimo p na q - 1, nakon cega ce se ono na kraju petlje uvecati i biti na razmaku, te nastaviti dalje do naredne rijeci*/
			p = q - 1;
		}
		p++;
	}


	return tekst;
}


int main()
{

	char *s;
	char tekst[100] = "Ovo   je neki     primjer   teksta";
	ubaci_broj(tekst, -123);
	s = tekst;
	while (*s != '\0')
		printf("%c", *s++);

	return 0;
}
