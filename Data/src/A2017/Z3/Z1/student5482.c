#include <stdio.h>

int dva_od_tri(int* niz1, int velicina1, int* niz2, int velicina2, int* niz3, int velicina3)
{
	int rez, istina, jednako, nejednako, *pokazivac1, *pokazivac2, *pokazivac3, *pomocni1, *pomocni2, *pomocni3;

	rez=0;

	/* brojimo koliko ima vrijednosti koje se pojavljuju u prvom i drugom nizu, ali ne i u trecem */
	pokazivac1=niz1;
	while(pokazivac1<niz1+velicina1) {
		istina=1;
		pomocni1=niz1;

		/* ispitujemo da li je vrijednost na pokazivac1 jednaka nekoj vrijednosti u nizu prije njega */
		while(pomocni1<pokazivac1) {
			if(*pokazivac1==*pomocni1) {
				istina=0;
			}
			pomocni1++;
		}

		/* ako nema iste vrijednosti prije one vrijednosti na pokazivacu1 onda provjerava da li postoji ta vrijednost u drugom nizu */
		if(istina) {
			jednako=0;
			pokazivac2=niz2;

			/* provjerava da li postoji vrijednost na pokazivac1 u drugom nizu */
			while(pokazivac2<niz2+velicina2) {
				if(*pokazivac1==*pokazivac2) {
					jednako=1;
					break;
				}
				pokazivac2++;
			}
			/* ako postoji vrijednost u drugom nizu kao na pokazivac1 onda provjerava da li postoji takva vrijednost u trecem nizu */
			if(jednako) {
				nejednako=1;
				pokazivac3=niz3;
				/* provjerava da li postoji u trecem nizu vrijednost kao na pokazivac1 */
				while(pokazivac3<niz3+velicina3) {
					if(*pokazivac1==*pokazivac3) {
						nejednako=0;
						break;
					}
					pokazivac3++;
				}
				/* ako ne postoji onda povecava broj vrijednosti koji se pojaljuju u dva od tri niza za 1 */
				if(nejednako) {
					rez++;
				}
			}
		}

		pokazivac1++;
	}

	/* analogno prebroji koliko se vrijednosti pojavljuje u drugom i trecem nizu, a koje se ne pojavljuju u prvom nizu */
	pokazivac2=niz2;
	while(pokazivac2<niz2+velicina2) {
		istina=1;
		pomocni2=niz2;
		while(pomocni2<pokazivac2) {
			if(*pokazivac2==*pomocni2) {
				istina=0;
			}
			pomocni2++;
		}

		if(istina) {
			jednako=0;
			pokazivac3=niz3;
			while(pokazivac3<niz3+velicina3) {
				if(*pokazivac2==*pokazivac3) {
					jednako=1;
					break;
				}
				pokazivac3++;
			}
			if(jednako) {
				nejednako=1;
				pokazivac1=niz1;
				while(pokazivac1<niz1+velicina1) {
					if(*pokazivac2==*pokazivac1) {
						nejednako=0;
						break;
					}
					pokazivac1++;
				}
				if(nejednako) {
					rez++;
				}
			}
		}

		pokazivac2++;
	}

	/* analogno prebroji koliko se vrijednosti pojavljuje u prvom i trecem nizu, a koje se ne pojavljuju u drugom nizu */
	pokazivac3=niz3;
	while(pokazivac3<niz3+velicina3) {
		istina=1;
		pomocni3=niz3;
		while(pomocni3<pokazivac3) {
			if(*pokazivac3==*pomocni3) {
				istina=0;
			}
			pomocni3++;
		}

		if(istina) {
			jednako=0;
			pokazivac1=niz1;
			while(pokazivac1<niz1+velicina1) {
				if(*pokazivac3==*pokazivac1) {
					jednako=1;
					break;
				}
				pokazivac1++;
			}
			if(jednako) {
				nejednako=1;
				pokazivac2=niz2;
				while(pokazivac2<niz2+velicina2) {
					if(*pokazivac3==*pokazivac2) {
						nejednako=0;
						break;
					}
					pokazivac2++;
				}
				if(nejednako) {
					rez++;
				}
			}
		}

		pokazivac3++;
	}

	return rez;
}

int main()
{
	int niz1[100], velicina1, niz2[100], velicina2, niz3[100], velicina3, i;

	printf("Unesite broj elemenata prvog niza: ");
	scanf("%d", &velicina1);

	printf("Unesite niz: ");
	for(i=0; i<velicina1; i++) {
		scanf("%d", &niz1[i]);
	}

	printf("Unesite broj elemenata drugog niza: ");
	scanf("%d", &velicina2);

	printf("Unesite niz: ");
	for(i=0; i<velicina2; i++) {
		scanf("%d", &niz2[i]);
	}

	printf("Unesite broj elemenata treceg niza: ");
	scanf("%d", &velicina3);

	printf("Unesite niz: ");
	for(i=0; i<velicina3; i++) {
		scanf("%d", &niz3[i]);
	}

	printf("\n%d", dva_od_tri(niz1, velicina1, niz2, velicina2, niz3, velicina3));
	return 0;
}
