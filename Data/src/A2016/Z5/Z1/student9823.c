#include <stdio.h>
#include <string.h>

struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

double daj_prosjek(int niz[], int vel)
{
	// obicna funkcija koja vraca prosjek kao što je zadano u tekstu zadatka
	int i;
	double suma=0;
	if(vel==0) return 5.;
	for(i=0; i<vel; i++) {
		if(niz[i]==5) return 5.;
		suma+=niz[i];
	}

	return suma/vel;
}

int uporedi(char *ime1, char *ime2, char *prezime1, char *prezime2){
	// prvo gledamo prezime pa ime
	// kao što je zadano u zadatku
	
	while(*prezime1!='\0' && *prezime2!='\0' && *prezime1 == *prezime2) { prezime1++; prezime2++; }
	if((*prezime1!='\0' && *prezime2 == '\0') || ( *prezime1 > *prezime2)) return 1;
	else if ((*prezime1=='\0' && *prezime2 != '\0') || ( *prezime1 < *prezime2)) return 2;

	while(*ime1!='\0' && *ime2!='\0' && *ime1 == *ime2) { ime1++; ime2++; }
	if((*ime1!='\0' && *ime2 == '\0') || ( *ime1 > *ime2)) return 1;
	else if ((*ime1=='\0' && *ime2 != '\0') || ( *ime1 < *ime2)) return 2;
	
	return 0;
}



int genijalci(struct Student studenti[], int vel, double prosjek)
{
	// prvo izbacujemo se studente ciji je prosjek manji od zadanog prosjeka
	int i, j;
	for(i=0; i<vel; i++) {

		if(daj_prosjek(studenti[i].ocjene, studenti[i].br_ocjena) < prosjek) {
			for (j=i; j<vel-1; j++) {
				studenti[j] = studenti[j+1];
			}
			vel--;
			i--;
		}
	}
	// nakon toga prelazimo da nadjemo max 3 prosjeka u generaciji
	// ako ima 3, ako nema trazimo 2, ili 1, ili 0 
	int pomocna=0;
	i=0;
	double max1 = prosjek;
	double max2 = prosjek;
	double max3 = prosjek;
	int prvi=-1, drugi=-1, treci=-1; // ove varijable nam sluze kao pomoc prilikom određivanja postojanja max prosjeka

	for(i=0; i<vel; i++) {

		if(daj_prosjek(studenti[i].ocjene, studenti[i].br_ocjena) == max1 && i!=0 && prvi!=-1) { // i!=0 jer prvi student ne moze biti upoređen ni sa kim

			pomocna =uporedi(studenti[i].ime, studenti[prvi].ime, studenti[i].prezime, studenti[prvi].prezime);
			// ova nam funkcija sluzi kao pomoc prilikom gledanja da li postoje 2 studenta
			// sa istim prosjekom, ukoliko postoje prvo se gleda prezime, pa ako je to prezime isto onda se
			// gleda ime, ako je ime isto ispisujemo po redu kako god..

		}

		if(daj_prosjek(studenti[i].ocjene, studenti[i].br_ocjena)>=max1) {
			if(pomocna==1) { // ukoliko je 1 preskačemo petlju tj. povecavamo za 1
				continue;
			}
			max1 = daj_prosjek(studenti[i].ocjene, studenti[i].br_ocjena);
			prvi = i;
		}
	}

	pomocna=0;
	for(i=0; i<vel; i++) {

		if(daj_prosjek(studenti[i].ocjene, studenti[i].br_ocjena) == max2 && i!=0 && drugi!=-1) {

			pomocna =uporedi(studenti[i].ime, studenti[drugi].ime, studenti[i].prezime, studenti[drugi].prezime);
			// ova nam funkcija sluzi kao pomoc prilikom gledanja da li postoje 2 studenta
			// sa istim prosjekom, ukoliko postoje prvo se gleda prezime, pa ako je to prezime isto onda se
			// gleda ime, ako je ime isto ispisujemo po redu kako god..
		}

		if(daj_prosjek(studenti[i].ocjene, studenti[i].br_ocjena)>=max2 && i!=prvi) {
			if(pomocna==1) { // ukoliko je 1 preskačemo petlju tj. povecavamo za 1
				continue;
			}
			max2 = daj_prosjek(studenti[i].ocjene, studenti[i].br_ocjena);
			drugi = i;
		}
	}


	pomocna=0;
	for(i=0; i<vel; i++) {
		if(daj_prosjek(studenti[i].ocjene, studenti[i].br_ocjena) == max3 && i!=0 && treci!=-1) {

			pomocna =uporedi(studenti[i].ime, studenti[treci].ime, studenti[i].prezime, studenti[treci].prezime);
			// ova nam funkcija sluzi kao pomoc prilikom gledanja da li postoje 2 studenta
			// sa istim prosjekom, ukoliko postoje prvo se gleda prezime, pa ako je to prezime isto onda se
			// gleda ime, ako je ime isto ispisujemo po redu kako god..
		}

		if(daj_prosjek(studenti[i].ocjene, studenti[i].br_ocjena)>=max3 && i!=drugi && i!=prvi) {
			if(pomocna==1) { // ukoliko je 1 preskačemo petlju tj. povecavamo za 1
				continue;
			}
			max3 = daj_prosjek(studenti[i].ocjene, studenti[i].br_ocjena);
			treci = i;

		}

	}

	if(prvi!=-1) printf("%s %s", studenti[prvi].prezime, studenti[prvi].ime);
	if(drugi!=-1) printf("\n%s %s", studenti[drugi].prezime, studenti[drugi].ime);
	if(treci!=-1) printf("\n%s %s", studenti[treci].prezime, studenti[treci].ime);

	return vel; // vracamo velicinu
}

int main()
{
	struct Student studenti[] = {

		{"Meho", "Behic", {10, 9}, 2},
		{"Meho", "Beeic", {10, 9}, 2},
		{"Meho", "Cehic", {10, 9, 8, 7, 6}, 5},
		{"Meho", "Dehic", {6, 9}, 2},
		{"Meho", "Zehic", {10}, 1},
		{"Meho", "Oehic", {10, 9, 9, 9}, 4}
	};
	int vel = sizeof studenti / sizeof studenti[0], i;
	vel = genijalci(studenti, vel, 9.);
	printf("\nVel: %dStudenti:", vel);
	for (i = 0; i < vel; ++i) printf ("\n%s %s", studenti[i].prezime, studenti[i].ime);

	return 0;
}
