#include <stdio.h>
#define BREL 1000
int dva_od_tri(int niz1[], int duzina1, int niz2[], int duzina2, int niz3[], int duzina3)
{

	int i, j, brojponavljanja, brojistih=0, kontrola=0; /* 'brojistih' je varijabla koja ce biti vracena */
	for(i=0; i<duzina1; i++) {
		for(j=0; j<i; j++) {
			if(niz1[i]==niz1[j]) /*Ovom petljom se ne provjeravaju isti brojevi jednog niza, sto je objasnjeno u sljedecem komentaru*/
				kontrola=1; /*Koristimo je kao kontrolnu promjenjivu*/
		}

		if (kontrola)
			continue; /*Ovdje vidimo da u slucaju ako smo imali 2 ista broja u nizu, nece doci do provjere jer nema potrebe dva ili vise puta
						provjeravati isti broj*/
		else {
			brojponavljanja=0; /*Svakim prolaskom kroz petlju restartujemo vrijednost kako bismo je mogli i dalje koristiti*/
			for(j=0; j<duzina2; j++) {
				if(niz1[i]==niz2[j]) {
					brojponavljanja++;
					break; /*Breakom postizemo momentalni prekid petlje jer ne zelimo da se brojponavljanja poveca u slucaju ponavljanja
							istih brojeva u drugom nizu, a identicno je ucinjeno ispod za treci niz*/
				}
			}

			for(j=0; j<duzina3; j++) {
				if(niz1[i]==niz3[j]) {
					brojponavljanja++;
					break;
				}
			}

			if(brojponavljanja==1)
				brojistih++;
		} 	/*Od linije 16 do 32 provjeravali smo da li se odredjeni clan prvog niza pojavljuje u ostala dva, te povecali varijablu 'brojistih'
			samo u slucaju ako je brojponavljanja==1, jer da je bio 2 to bi znacilo da se nalazi u sva tri niza*/
	}

	kontrola=0; /*Vracamo kontrolnu varijablu na pocetnu vrijednost da bi smo je mogli ponovo koristiti u nastavku u istu svrhu kao prvi put*/

	for(i=0; i<duzina2; i++) {
		for(j=0; j<i; j++) {
			if(niz2[j]==niz2[i])
				kontrola=1;
		}

		if(kontrola)

			continue;

		else {
			/*Sada cemo tek nakon sto utvrdimo da se neki od clanova drugog niza ne nalazi u prvom, provjeravati da li se taj clan
						nalazi u trecem nizu, naravno bez ponavljanja sto je uspostavljeno vec objasnjenom kontrolnom varijablom*/
			brojponavljanja=0;
			for(j=0; j<duzina1; j++) {
				if(niz2[i]==niz1[j]) {
					brojponavljanja++;
					break;
				}
			}

			if(brojponavljanja==0) {
				/*Sada ce se 'brojistih' povecavati jedino za brojeve drugog niza jednake brojevima treceg niza koji
										nisu jednaki brojevima prvog niza da ne bi bili uracunati brojevi koji se nalaze u sva 3 niza*/
				for(j=0; j<duzina3; j++) {
					if(niz3[j]==niz2[i]) {
						brojistih++;
						break; /*Break ponovo sprecava povecavanje broja istih za iste brojeve unutar treceg niza*/
					}
				}
			}
		}
	}
	return brojistih;
}

int main()   /*Kratki program za provjeru*/
{
	int i, niz1[BREL], niz2[BREL], niz3[BREL], n1, n2, n3;

	printf("Unesite velicinu prvog niza: ");
	scanf("%d", &n1);

	printf("Unesite velicinu drugog niza: ");
	scanf("%d", &n2);

	printf("Unesite velicinu treceg niza: ");
	scanf("%d", &n3);

	printf("Unesite prvi niz: ");
	for(i=0; i<n1; i++)
		scanf("%d", &niz1[i]);

	printf("Unesite drugi niz: ");
	for(i=0; i<n2; i++)
		scanf("%d", &niz2[i]);

	printf("Unesite treci niz: ");
	for(i=0; i<n3; i++)
		scanf("%d", &niz3[i]);

	printf("Broj elemenata koji se nalaze u dva od tri niza je: %d ", dva_od_tri(niz1, n1, niz2, n2, niz3, n3));
	return 0;

}