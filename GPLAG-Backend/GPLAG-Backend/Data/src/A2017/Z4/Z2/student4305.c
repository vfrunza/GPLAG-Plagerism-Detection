#include <stdio.h>

/*prolazimo kroz string po rijecima i brojimo slova svake rijeci
nakon toga uporedimo trenutni broj rijeci sa odgovarajucim clanom niza*/
int provjeri_duzine(char *s, int duzine[], int vel_duzine)
{
	char *p, *q;
	int rbr_rijeci = 0, tr_duzina; /*rbr rijeci je redni broj rijeci do koje smo dosli, tr duzina je njena duzina*/

	p = s;
	while (*p != '\0') {
		/*prolazimo po rijecima, pa se pozicioniramo na rijec*/
		if (*p >= 'A' && *p <= 'Z' || *p >= 'a' && *p <= 'z') {
			/*potrebno je izbrojati trenutnu duzinu*/
			tr_duzina = 0;
			q = p;
			while (*q >= 'A' && *q <= 'Z' || *q >= 'a' && *q <= 'z') { /*dok je nniz znakova*/
				tr_duzina++;
				q++;
			}
			/*potrebno je provjeriti da li niz duzine ima manje elemenata od broja rijeci i to cemo uraditi ovako:*/
			/*provjeriti da li je rbr_rijeci + 1 vece od vel_duzine i ako jeste, vratimo 0*/
			if (rbr_rijeci + 1 > vel_duzine)
				return 0;

			/*provjerimo da li je izbrojana duzina ista kao broj na odgovarajucoj poziciji u nizu, ako nije vratimo nulu*/
			if (tr_duzina != duzine[rbr_rijeci])
				return 0;
			/*kada smo obradili rijec, moramo uvecati redni broj rijeci, te p prebaciti na q-1 kako bi se dalje prebacili na narednu rijec*/
			rbr_rijeci++;
			p = q - 1;
		}
		p++;
	}
	/*ako na kraju petlja ima manje rijeci(sto cemo procitati iz rbr_rijeci + 1) od broja elemenata u nizu duzine, potrebno je vratitit 0*/
	/*rbr_rijeci ce na kraju biti za jedan veci nego sto bi trebao pa ne treba pisati ispod rbr_rijeci + 1 < vel_duzine*/
	if (rbr_rijeci < vel_duzine)
		return 0;

	/*ako su petlja i uslov koji se nalaze iznad prosli, sve je u redu, stoga samo vratimo 1*/
	return 1;
}

int main()
{
	char tekst[] = "Ovo je neki primjer teksta";
	int duzine[] = { 3, 2, 4, 7, 6 };
	printf("%d (ocekivano 1)", provjeri_duzine(tekst, duzine, 5));

	return 0;
}
