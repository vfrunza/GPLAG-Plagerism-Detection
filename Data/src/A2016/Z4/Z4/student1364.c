#include <stdio.h>
#define EPSILON 0.0001

/*4. (0,5 bodova) Dat je niz tačaka u 2D koordinatnom sistemu pri čemu je svaka tačka opisana sa dvije koordinate koje su realni brojevi 
(pozitivni ili negativni). Potrebno je napraviti funkciju obuhvat koja prima niz tačaka te iz njega izbacuje sve tačke koje se nalaze unutar neke 
pravougaone površine.
 
No ulaz u ovu funkciju je u formi stringa koji izgleda ovako:

	"(0,-3.1),(-15.09,4),(2.,2),(-1.1,217)"

(bez navodnika). U ovom stringu se ne nalaze razmaci, odnosno string se sastoji isključivo od: cifara, znaka minus, zareza, tačke, otvorenih 
i zatvorenih malih zagrada. Unutar zagrada se nalaze dva realna broja razdvojena zarezom. U sklopu broja se može nalaziti znak tačka koji predstavlja
decimalnu tačku, a ako se iza tačke ne nalazi cifra podrazumijeva se cifra nula.  Ovakvi parovi koordinata se nalaze u zagradama koje su razdvojene 
zarezom s tim što se nakon posljednjeg i prije prvog para ne nalazi znak zarez. Ako primljeni string nije ispravno formatiran tj. ne zadovoljava bilo 
koji od nabrojanih uslova, funkcija treba da vrati NUL pokazivač, no prazan string "" je ispravan string koji ne sadrži niti jednu tačku. 
Pretpostavite da se svi realni brojevi mogu predstaviti tipom float (ovo ne morate provjeravati).

Napisati funkciju obuhvat koja prima ovako formiran C string i četiri realna broja x1, y1, x2 i y2 koji predstavljaju koordinate donjeg-lijevog i 
gornjeg-desnog ugla pravougaonika, zatim string modificira tako da iz njega izbacuje tačke koje se ne nalaze unutar pravougaonika, a da pri tome 
string ostaje ispravno formatiran kao u gornjem primjeru. Npr. za gornji string, ako su parametri -3, -3, 3, 3 funkcija treba modificirati primljeni 
string tako da on glasi:
	"(2.,2)"
(bez navodnika). Unutar pravougaonika (-3,-3) - (3,3) nalazi se tačka (2,2), a tačke (0,-3.1), (-15.09,4) i (-1.1,217) se ne nalaze u njemu.

Radi lakše upotrebe funkcija treba vraćati pokazivač na početak primljenog stringa. Ako se niti jedna od tačaka ne nalazi u pravougaoniku, 
rezultat treba biti prazan string "". Kod poređenja realnih brojeva koristiti =0.0001.

U zadatku NIJE dozvoljeno koristiti funkcije iz biblioteke string.h, stdlib.h niti funkcije sprintf i sscanf iz biblioteke stdio.h. */

void unesi(char niz[], int velicina) {
	char znak = getchar();
	int i = 0;
	if (znak == '\n') znak=getchar();
	while (i < velicina-1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}

char* obuhvat (char *s, float x1, float y1, float x2, float y2 ) {
	char* reset=s, *q=s;
	char* tacke[10]={"0"};
	float niz_tacaka = {0};
	
	/*Provjera da li je string ispravno formatiran */
	
	while (*s != '\0') {
		
		s++;
	}
	
	/* Zadatak funkcije koja je ispravno formatirana*/
	
	s= reset;
	while (*s != '\0') {
		/* Pretvaranje chara u float (koordinate tacke) */
		if (*s=='(') {
			while (*s != ')') {
				
			}
		}
	}
	
	
	return reset;
}
int main() {
	printf("Zadaća 4, Zadatak 4");
	return 0;
}
