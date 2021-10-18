#include <stdio.h>
/*Trazimo broj rijeci u stringu,i ono sto ona vrati koristimo da uporedimo s velicinom niza koji se salje u funkciju provjeri_duzine.*/
/*Ako broj rijeci stringa i velicina niza nisu iste,funkcija vraca 0, jer nema smisla dalje uporedjivati*/
int broj_rijeci (char *s)
{
	int neslovo=1;
	int brojac=0;
	while (*s!='\0') {
		if (!((*s>='a' && *s<='z') || (*s>='A' && *s<='Z')))
			neslovo=1;
		else if (neslovo==1) {
			neslovo=0;
			brojac++;
		}
		s++;
	}
	return brojac;
}
int provjeri_duzine (char *s, int *niz, int vel)
{
	int neslovo=1;
	int brojac=0;
	if (broj_rijeci(s)!=vel)
		return 0;
	/*Uz pomoc logicke varijable neslovo trazimo rijec po definiciji rijeci iz postavke zadatka*/
	while (*s!='\0') {
		if (!((*s>='a' && *s<='z') ||  (*s>='A' && *s<='Z')))
			neslovo=1;
		else if (neslovo==1) {
			neslovo=0;
			/*Kad pronadjemo rijec,brojimo koliko slova ima*/
			while (*s!='\0' &&  ((*s>='a' && *s<='z') || (*s>='A' && *s<='Z'))) {
				brojac++;
				s++;
			}
			/*Broj slova prve rijeci uporedjujemo sa prvim clanom niza,tj. broj slova n-te rijeci poredimo sa n-tim clanom niza*/
			/*Kad pronadjemo prvi par koji se ne slaze,prekidamo funkciju*/
			if (brojac!=*niz) {
				return 0;
			}
			niz++;
			s--;
		}
		brojac=0;
		s++;
	}
	/*Ako se funkcija nije prekinula,znaci da su svi uslovi ispunjeni i vracamo 1*/
	return 1;
}

int main()
{

	return 0;
}
