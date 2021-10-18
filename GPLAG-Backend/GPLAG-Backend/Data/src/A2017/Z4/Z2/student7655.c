#include <stdio.h>

int provjeri_duzine (char* s, int niz[], int vel)
{
	int brojac=0;
	int index=0;

	/* ukoliko je velicina niza duzina neispravna odmah vratiti 0*/
	if (vel<=index) return 0;

	while (*s!='\0') {

		/* ukoliko je znak slovo povecati brojac velicine */
		if((*s>='A' && *s<='Z') || (*s>='a'&& *s<='z')) brojac++;

		/* ako to nije slucaj tj ako je iza rijeci kraj stringa ili neslovo provjeriti brojac */
		if (*(s+1)=='\0' || ((!(*(s+1)>='A' && *(s+1)<='Z')) && (!(*(s+1)>='a'&& *(s+1)<='z')))) {

			/* ako sada niz velicna ima manje clanova od izbrojanih rijeci u stringu vratiti nulu */
			if (index>=vel) return 0;

			/* ako je brojac razlicit od clana niza duzina na odgovarajucem mjestu vratiti nulu */
			if(brojac!=niz[index]) return 0;

			/* u suprotnom vratiti brojac na 0 i povecati index niza velicina, tj preci na narednu rijec*/
			else if (brojac==niz[index]) {
				index++;
				brojac=0;
			}
		}
		s++;
	}

	/* ukoliko je u nizu velicina preostalo jos clanova pored pregledanih znaci da je on opet neispravan pa vacamo nulu*/
	if (vel-index!=0) return 0;
	return 1;
}
int main()
{
	printf("Zadaća 4, Zadatak 2");
	return 0;
}
