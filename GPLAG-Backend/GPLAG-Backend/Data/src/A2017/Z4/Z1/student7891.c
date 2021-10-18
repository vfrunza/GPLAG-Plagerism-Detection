#include <stdio.h>
#include <math.h>

void unesite (char niz[], int velicina)
{
	char znak = getchar();
	if (znak == '\n') znak = getchar();
	int i = 0;
	while (i< velicina-1 && znak != '\n') {
		niz[i]=znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}
int broj_cifara (int broj)
{
	int br=0, cifra;
	while (broj!=0) {
		broj=broj/10;
		br++;
	}
	return br;
}

char* ubaci_broj (char* tekst , int broj)
{
	//varijable
	char* poc=tekst;
	char* s=tekst;
	char* pocetak_razmaka;
	char predznak='a';
	int temp, pomocniBrojacCifara=0;


	/* predznak broja*/
	if (broj<0) {
		broj=-broj;
		predznak='-';
	}
	temp=broj;
	//varijable
	int br=broj_cifara(broj);
	int cifra=pow(10,br-1);
	int tempCifra=cifra;
	int broj_razmaka=0, ostatak=0, i;
	int broj_rijeci=0, duzina_teksta=0;

	/* broj rijeci*/
	while (*s!='\0') {
		while (*s==' ') s++;
		while (*s!=' ' && *s!='\0') s++;
		while (*s==' ') s++;
		broj_rijeci++;
	}

	s=poc;
	
	if (*s=='\n' || *s=='\0') return poc;
	
	while (*tekst==' ') tekst++;

	if (broj_rijeci==1) return poc;

	/*pocetak glavnog bloka naredbi*/
	else {

		while (*tekst!='\0') {
			while (*tekst!=' ') tekst++;
			pocetak_razmaka=tekst;
			while (*pocetak_razmaka==' ') {
				broj_razmaka++;
				pocetak_razmaka++;
			}
			pocetak_razmaka=tekst;
			/* ako je broj razmaka jednak 1 */

			if (broj_razmaka==1) {
				char* kraj=tekst;
				while (*kraj != '\0') kraj++;

				/* ako je broj negativan */
				if (predznak=='-') {
					while (kraj > tekst) {
						*(kraj+br+2) = *kraj; //dodajemo 2 zbog dodatnog space-a i minusa
						kraj--;
					}
					*tekst=' ';
					tekst++;
					*tekst='-';
					tekst++;
					while (broj!=0) {
						*tekst = broj/cifra + '0';
						ostatak = broj%cifra;
						broj=ostatak;
						tekst++;
						cifra=cifra/10;
						pomocniBrojacCifara++;
					}
					broj=temp;
					cifra=tempCifra;
					if (pomocniBrojacCifara<br) {
						for (i=0; i<br-pomocniBrojacCifara; i++) {
							*tekst='0';
							tekst++;
						}
					}
					*tekst=' ';
					tekst++;
					broj_razmaka=0;
					pomocniBrojacCifara=0;
					while (*tekst!=' ' && *tekst!='\0') tekst++; //prelazimo preko rijeci
				}
				//pozitivan broj
				else {
					while (kraj > tekst) {
						*(kraj+br+1) =*kraj;
						kraj--;
					}
					*tekst=' ';
					tekst++;
					while (broj!=0) {
						*tekst = broj/cifra +'0';
						ostatak = broj% cifra;
						broj=ostatak;
						tekst++;
						cifra=cifra/10;
						pomocniBrojacCifara++;
					}
					broj=temp;
					cifra=tempCifra;
					if (pomocniBrojacCifara<br) {
						for (i=0; i<br-pomocniBrojacCifara; i++) {
							*tekst='0';
							tekst++;
						}
					}
					*tekst=' ';
					tekst++;
					broj_razmaka=0;
					pomocniBrojacCifara=0;
					while (*tekst!=' ' && *tekst!='\0') tekst++;
				}

			} //ako je razmak veci
			else if (broj_razmaka!=1 && broj_razmaka>0) {
				char* kraj=tekst;
				while (*kraj!='\0') kraj++;

				/*broj negativan*/
				if (predznak=='-') {
					while (kraj > tekst) {
						*(kraj+br)=*kraj;
						kraj--;
					}
					*tekst=' ';
					tekst++;
					*tekst='-';
					tekst++;
					while (broj!=0) {
						*tekst=broj/cifra +'0';
						ostatak=broj%cifra;
						broj=ostatak;
						tekst++;
						cifra=cifra/10;
						pomocniBrojacCifara++;
					}
					broj=temp;
					cifra=tempCifra;
					if (pomocniBrojacCifara<br) {
						for (i=0; i<br-pomocniBrojacCifara; i++) {
							*tekst='0';
							tekst++;
						}
					}
					for (i=0; i<broj_razmaka-1; i++) {
						*tekst=' ';
						tekst++;
					}
					broj_razmaka=0;
					pomocniBrojacCifara=0;
					while (*tekst!=' ' && *tekst!='\0') tekst++;
				}

				//broj pozitivan
				else {
					while (kraj > tekst) {
						*(kraj+br) = *kraj;
						kraj--;
					}
					*tekst=' ';
					tekst++;
					while (broj!=0) {
						*tekst = broj/cifra +'0';
						ostatak=broj % cifra;
						broj=ostatak;
						tekst++;
						cifra=cifra/10;
						pomocniBrojacCifara++;
					}
					broj=temp;
					cifra=tempCifra;
					if (pomocniBrojacCifara<br) {
						for (i=0; i<br-pomocniBrojacCifara; i++) {
							*tekst = '0';
							tekst++;
						}
					}
					pomocniBrojacCifara=0;
					for (i=0; i<broj_razmaka-1; i++) {
						*tekst=' ';
						tekst++;
					}
					broj_razmaka=0;
					while (*tekst!=' ' && *tekst!='\0') tekst++;
				}

			}

			char* pozicija=tekst;
			//ispitujemo da li recenica zavrsava sa razmacima
			while (*tekst==' ') {
				tekst++;
			}
			if (*tekst=='\0') return poc;
			else tekst=pozicija;
		}
		return poc;

	}

}
int main()
{
	char recenica[10000];
	int broj;
	unesite(recenica, 10000);
	scanf ("%d", &broj);
	printf ("Konacan niz glasi:%s\n", ubaci_broj(recenica, broj));
	return 0;
}
