#include <stdio.h>

void unesi(char niz[], int velicina)
{
	// obicna funkcija unesi - svrha test-a u main-u
	char znak = getchar();
	if (znak == '\n') znak=getchar();
	int i = 0;
	while (i < velicina-1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}

char toUpper(char c)
{
	if (c>='a' && c<='z')
		return c - ('a' - 'A'); // prebaci c u veliko i vrati
	return c; // ako nije bilo malo slovo, ostaje nepromjenjeno
}

int isSlovo(char c)
{
	c = toUpper(c);
	// vrati 1 ako je c slovo, 0 ako nije
	return c>='A' && c<='Z';
}

int jesuLiIsti(char *s1, char *s2)
{
	int istina=1;
	while(isSlovo(*s1) && isSlovo(*s2)) {
		if(toUpper(*s1)==toUpper(*s2)) {
			istina=1;
		} else if(toUpper(*s1)!=toUpper(*s2)) return 0;

		s1++;
		s2++;
	}
	if(*s1=='\0' && isSlovo(*s2)) return 0;
	if(isSlovo(*s1) && *s2=='\0') return 0;
	return istina;
}


void izbaciRijec(char *pok, char *kraj)
{
	// izbacivanje rijeci tj. kopiranje 1za1
	while(*pok!='\0') {
		char *kraj1 = kraj;


		while (*pok != '\0') {

			*pok = *kraj1;
			if(*kraj1=='\0') {
				*pok='\0';
				break;

			}
			pok++;
			kraj1++;


		}
		if(*pok=='\0') pok--;
		pok++;
	}


}



char *izbaci_iz_kuce(char *s, char *rijec)
{
	char *reset =s;

	while (*s!='\0') {
		while(!isSlovo(*s)) ++s; // premotaj do rijeci
		char *kraj = s;
		while(!isSlovo(*kraj)) kraj++;
		while(isSlovo(*kraj)) kraj++;

		if (jesuLiIsti(s, rijec)==0) { // ukoliko nisu isti s treba premotati samo do naredne rijeci
			while(s<kraj) s++;
		} else if(jesuLiIsti(s, rijec)) izbaciRijec(s, kraj); // ukoliko jesu iste rijeci treba izbaciti

	}

	return reset;
}



int prebroji_rijeci(char *s, char *rijec)
{
	int brojac = 0;
	while (*s!='\0') {

		// premotaj na pocetak iduce rijeci
		while (!isSlovo(*s) && *s != '\0') ++s;
		if (*s=='\0') break;

		char* pom = rijec;
		while (isSlovo(*pom) && isSlovo(*s) && toUpper(*pom) == toUpper(*s)) {
			pom++;
			s++;
		}
		if (*pom=='\0') {
			// ako je pom dosao do \0, znaci da su mozda isti
			// treba jos provjeriti da li je rijec u glavnom stringu zavrsena

			if ((!isSlovo(*s)) == 1)
				brojac++;
		}

		// premotaj do kraja trenutne rijeci
		while (isSlovo(*s)) ++s;

		if (*s=='\0') break;
		++s;
	}
	return brojac;
}


char *izbaci_najcescu(char *s)
{
	int maximum=0, broj=0;
	char max_rijec[50000], trenutnonaredna[50000];
	char *maxR = max_rijec;
	char *maxR2 = max_rijec;

	char *trtn = trenutnonaredna;
	char *reset = s;


	if(*s=='\0' || (*s=='\n')) return s;

	while(*s==' ') s++; // motamo do pocetka stringa
	while(!isSlovo(*s) && *s!='\0') s++;
	char *prva = s;
	while(((*prva>='A' && *prva<='Z') || (*prva>='a' && *prva<='z')) && *prva!='\0') {
		*maxR=*prva;
		maxR++;
		prva++;
	}
	*maxR='\0'; // uzimamo prvu rijec i nju deklarisemo kao max-tu rijec



	if(*prva=='\0') prva--;

	char *naredna = prva; // uzimamo novi pokazivac za naredne rijeci

	maximum = prebroji_rijeci(s, max_rijec); // pomocu gornje funkcije dobivamo broj rijeci u stringu


	// vrtimo rijeci do kraja
	while(*naredna!='\0') {
		char *resetZaTrtn = trtn;
		if((*naredna>='A' && *naredna<='Z') || (*naredna>='a' && *naredna<='z')) {
			char *pom = naredna;
			char *kraj = naredna;

			while((*kraj>='A' && *kraj<='Z') || (*kraj>='a' && *kraj<='z')) kraj++;

			while(naredna<kraj) {
				*trtn = *naredna;
				trtn++;
				naredna++;
			}
			*trtn='\0';

			broj = prebroji_rijeci(s, trenutnonaredna); // brojimo svaku ponazasebno
			trtn = resetZaTrtn;



			if(broj>maximum) { // ako je ispunjen uslov da se neka rijec pojavljuje više puta ta riječ postaje max-ta rijec ponavljanja
				char *resetZaR2 = maxR2;
				while(pom<kraj) {
					*maxR2 = *pom;

					maxR2++;
					pom++;

				}
				*maxR2 ='\0';
				maxR2 = resetZaR2;

			}




			if(*naredna=='\0') naredna--; // moramo smanjiti jer se dole povecava naredna++;
		}

		naredna++;
	}

	izbaci_iz_kuce(s, max_rijec); // kada nadjemo max-tu rijec slijedi izbacivanje te max-te rijeci



	return reset;
}



int main()
{
	char a[1000];
	printf("Unesite tekst: ");
	unesi(a,1000);

	izbaci_najcescu(a);
	char *pok = a;
	while(*pok!='\0') {
		printf("%c", *pok);
		pok++;

	}

	return 0;
}
