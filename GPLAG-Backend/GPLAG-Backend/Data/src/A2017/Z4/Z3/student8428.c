#include <stdio.h>
#include <stdlib.h>

/*pronaci najduzi u kojem se ponavljaju slova, a zatim ga prepisati u novi*/
/*kako se trazi da se vrati prvi ukoliko ima vise sa istom, a najvecom duzinom, ukoliko je duzina ista necemo pamtiti novu poziciju*/

void najduzi_bp (char *s1, char *s2)
{
	char *p, *q, *r;
	char *max_poc;
	char zadnji_prethodni; /*ovdje cemo pamtiti posljednji simbol iz prethodne rijeci*/
	int tr_duzina, max_duzina = 0;
	int bez_ponavljanja, i, veliko_malo = 'a' - 'A';

	p = s1;
	while (*p != '\0') {
		/*ako smo na pocetku podstringa*/
		if (*p >= 'A' && *p <= 'Z' || *p >= 'a' && *p <= 'z') {
			tr_duzina = 0; /*trenutna duzina se mora vratiti uz uslov da nema ponavljanja slova (restaruje se za svaki novi podstring)*/
			bez_ponavljanja = 1;
			q = p;
			while ((*q >= 'A' && *q <= 'Z' || *q >= 'a' && *q <= 'z') && bez_ponavljanja) {
				q++;
				r = p;

				while (r != q) {
					if (*r == *q || *r + veliko_malo == *q || *r - veliko_malo == *q) {
						bez_ponavljanja = 0;
						break;
					}
					r++;
				}
				tr_duzina++;
			}
			if (tr_duzina > max_duzina) {
				max_duzina = tr_duzina;
				max_poc = p;
			}

			/*p sada moramo pomaknuti, ne do kraja stringa nego do prvog koji nas je izbacio, tj. do onog koji se ponavljao ili do razmaka*/
			/*ta informacija sadrzana je u q. Postavlja se p na q-1 jer ce se p uvecati na kraju glavne petlje, pa ce biti na q*/
			p = q - 1;
		}
		p++;
	}

	/*ovdje imamo pokazivac na pocetak najduzeg podstringa, te duzinu tog stringa, pa zato radimo prepisivanje*/
	p = s2;
	q = max_poc;
	for (i=0 ; i<max_duzina ; i++)
		*p++ = *q++;
	/*moramo na kraj s2 dodati \0 */
	*p = '\0';

}
int main()
{
	char test[100] = "abcde etankera cdefg";
	char novi[100], *p;
	najduzi_bp(test, novi);
	p = novi;
	while (*p != '\0')
		printf ("%c", *p++);

	return 0;
}
