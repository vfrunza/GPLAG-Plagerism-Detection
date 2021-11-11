#include <stdio.h>

/*3. (0,5 bodova) Napišite funkciju sa sljedećim prototipom:

char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci)

Prvi parametar funkcije je string koji sadrži neki tekst, a drugi i treći parametar su nizovi pokazivača tipa char (nizovi riječi) 
čija je veličina broj_rijeci. Funkcija treba pronaći u stringu sve riječi iz niza rijeci (sva njihova pojavljivanja u stringu) i zamijeniti 
ih odgovarajućim riječima iz niza zamjene. Pri tome trebate paziti da se zamijene samo kompletne riječi, a ne njihovi dijelovi. 
Riječ je omeđena znakovima razmaka ili početkom ili krajem stringa. Ako je string prazan ili ako su nizovi prazni, ne treba raditi ništa. 
Pretpostavite da je string tekst dovoljno velik da primi sve eventualne dodatne karaktere. Funkcija treba biti case-sensitive 
(razlikovati velika i mala slova). Radi lakšeg lančanog pozivanja, funkcija treba vratiti pokazivač na prvo slovo primljenog stringa.

Primjer upotrebe:
	char* rijeci[2] = { "beli", "sneg" };
	char* zamjene[2] = { "bijeli", "snijeg" };
	char tekst[100] = "beli sneg je pokrio beli breg";
	printf("%s", zamjena_rijeci(tekst, rijeci, zamjene, 2));
Treba ispisati 
bijeli snijeg je pokrio bijeli breg
(riječ breg nije prevedena sa ekavskog jer je nema na spisku zamjena).

Pri rješavanju zadatka nije dozvoljeno koristiti funkcije iz biblioteka string.h, stdlib.h kao ni funkcije sprintf i sscanf iz biblioteke stdio.h. */

int prebroji (char *s) {
	int i=0;
	while (*s != '\0') {
		s++;
		i++;
	}
	return i;
}


char* zamjena_rijeci (char* tekst, char** rijeci, char** zamjene, int broj_rijeci) {
	char* reset = tekst, *p, *q, *s=tekst, *kraj, *r, *k, *res;
	int razmak = 1, i=0, duzina = 0;
	
	while (*s != '\0') {
		
		/* Trazimo rijeci u stringu tekst */
		if (*s == ' ')
		razmak=1;
		else if (razmak == 1) {
			razmak=0;
			i=0;
			
			/* Pronasli smo rijec, sada provjerimo da li je trebamo zamijeniti */
			
			while (i< broj_rijeci) {
				p=s;
				r=*(zamjene+i);
				q=*(rijeci+i); /*adresa pokazivaca **rijeci*/
				
				kraj=s;
				while (*kraj != '\0') kraj++; /* Pokazivac na kraj stringa, mora biti ovdje, a ne prije petlje jer se adresa kraja mijenja!!*/
				
				while (*p++ == *q++) {
					res=p;
					if (*q == '\0' && (*p == '\0' || *p == ' '))
					{
						/* Kada pronadjemo rijec vrsimo zamjenu, provjerimo za koliko mjesta i kako trebamo pomjeriti string */
						p=s;
						
						duzina = prebroji (*(zamjene+i)) - prebroji(*(rijeci+i));
						
						/* Oslobodimo mjesto u stringu za zamjenu*/
						if (duzina>=0) {
							while (kraj > p) {
							*(kraj+duzina) = *kraj;
							kraj--;
						}
						/* Izvrsimo sada zamjenu*/
						
						while (*r != '\0') {
							*p = *r;
							p++;
							r++;
							/* Vrati pokazivac za zamjene!! */
						}
						}
						
						/* Ako je duzina <0, tj. ako je rijec u nizu rijec duza od rijeci u nizu zamjene*/
						else {
							 /* Pokazivac na kraj rijeci *k */
							 k=s;
							 while (*k != '\0' && *k != ' ') {
							 	k++;
							 }
							 
							while (*r != '\0') {
								*p = *r;
								p++;
								r++;
							}
							
							/* sada izbacimo ostatak */
							while (*p!= '\0') {
								*p= *k;
								p++;
								k++;
							}
							*p= '\0';
							k=k-duzina;
							
						}
						
					}
					p=res;
				}
				i++;
			}
		}
		s++;
	}
	
	return reset;
}


int main() {
	
	char* rijeci[2] = { "Prijestolonasljednikovica" };
	char* zamjene[2] = { "c" };
	char tekst[100] = "Prijestolonasljednikovica";
	printf("%s", zamjena_rijeci(tekst, rijeci, zamjene, 2));
	
	return 0;
}
