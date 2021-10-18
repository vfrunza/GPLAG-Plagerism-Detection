#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int izbaci_cifre(int* brojevi, int velicina_niza, int* cifre, int broj_cifara)
{
	int t, broj, cifra, element, brojac, istina, *p, *q, *o;

	p=brojevi;
	q=cifre;

	/* provjerava da li je niz cifara dobro definisan, ne smiju se vrijednosti u nizu ponavljati i ne smiju vrijednosti biti manje od 0 i vece od 9 */
	t=1;
	while(q<cifre+broj_cifara) {
		if(*q<0 || *q>9) {
			t=0;
		}
		o=q+1;
		while(o<cifre+broj_cifara) {
			if(*q==*o) {
				t=0;
			}
			o++;
		}
		q++;
	}

	/* ako je dobro definisan niz cifara onda u nizu cijelih brojeva izbacuje vrijednostima cifre iz niza cifara */
	if(t) {
		while(p<brojevi+velicina_niza) {
			broj=*p;
			element=0;
			/* brojac koristimo da bi mogli znati na kojoj smo mjestu u broju npr. na mjestu jedinica ili desetica */
			brojac=0;

			/* rastavlja vrijednost na cifre */
			while(broj!=0) {
				cifra=broj%10;
				q=cifre;
				istina=1;

				/* provjerava da li je cifra jednaka nekoj iz niza cifara */
				while(q<cifre+broj_cifara) {
					if(abs(cifra)==*q) {
						istina=0;
						break;
					}

					q++;
				}

				/* ako cifra nije jednaka nekoj iz niza cifara onda je postavljamo na njeno mjesto u broju, npr. na mjesto jedinica */
				if(istina) {
					element+=cifra*pow(10, brojac);
					brojac++;
				}

				broj/=10;

			}

			/* vrijednost koju smo dobili izbacivanjem cifara dodjelimo elementu */
			*p=element;
			p++;
		}

	}

	return t;
}

int main()
{
	printf("Zadaća 3, Zadatak 3");
	return 0;
}
