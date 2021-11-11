#include <stdio.h>
#include <math.h> /*ukljucena biblioteka math.h zbog koristenja f-je pow u nastavku koda*/
#include <stdlib.h> /*ukljucena biblioteka stdlib.h zbog koristenja f-je abs u nastavku koda*/

int izbaci_cifre(int brojevi[], int velicina1, int cifre[], int velicina2)
{
	int i,j,c,t;
	int novibr,br;
	int brojaci[10]= {0};

	/* provjeravanje da li niz cifara zadovoljava uvjete za nastavak zadatka, ako su neispravne vrati 0 */
	for (i=0; i<velicina2; i++) {
		if (cifre[i]<0 || cifre[i]>9) return 0;
	}

	for (i=0; i<velicina2; i++) {
		brojaci[cifre[i]]++;
	}

	/* ukoliko se clanovi niza cifara ponavljaju vrati 0 */
	for (i=0; i<velicina2; i++) {
		if (brojaci[cifre[i]]>1) return 0;
	}

	/* prolazak kroz elemente niza brojeva */
	for (i=0; i<velicina1; i++) {
		br=0;
		novibr=0;
		/* u narednoj petlji rastavljamo brojeve na cifre i provjeravamo da li se nalaze u drugome nizu, ukoliko da, modifikujemo dati broj */
		while(brojevi[i]!=0) {
			c=brojevi[i]%10;
			brojevi[i]/=10;
			t=1;
			for (j=0; j<velicina2; j++) {
				if(cifre[j]==abs(c)) t=0;
			}
			if(t) {
				novibr=novibr+c*pow(10,br);
				br++;
			}

		}
		brojevi[i]=novibr;
	}
	return 1;
}

int main()
{
	printf("Zadaća 3, Zadatak 3");
	return 0;
}
