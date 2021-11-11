#include <stdio.h>
#include <math.h>
#define epsilon 0.0000001

struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

/* Pomocna funkcija funkcije genijalci koja ispisuje leksikografski sort */
void leksikosort (char **prezimepok, char **imepok, double *niz, int vel) {
	
	/* kontrolna i brojaci, osnovne */
	int i = 0, j = 0, k = 0;
	int kontrolna, brojac = 0;
	
	/* Pomocne varijable */
	char TempPreIme1[42];
	char TempPreIme2[42];
	char* punoime1 = TempPreIme1;
	char* punoime2 = TempPreIme2;
	char* tempime1, *tempime2;
	char* temppr1, *temppr2;
	
	/* Za zamjenu */
	int swap;
	char *temp;
	double tempbroj;
	
	/* TEMP niz ZA redoslijed PROSJEKA */
	int vel2;
	double trenutnimax;
	double alterniz[200];
	double *alterpok = alterniz;
	
	for (i = 0; i < vel; i ++) {
		
		temppr1 = *(prezimepok + i);
		tempime1 = *(imepok + i);
		punoime1 = TempPreIme1;
		
		/* Kopiram prezime iz strukture */
		while (*temppr1 != '\0') {
			*punoime1 = *temppr1;
			punoime1++;
			temppr1++;
		}	punoime1--;
		
		/* I ime samo nastavljam */
		while (*tempime1 != '\0') {
			*punoime1 = *tempime1;
			punoime1++;
			tempime1++;
		}	*punoime1 = '\0';
		
		for (j = i+1; j < vel; j ++) {
			
			temppr2 = *(prezimepok + j);
			tempime2 = *(imepok + j);
			punoime2 = TempPreIme2;
			
			/* Kopiram prezime koje cu uporedjivat */
			while (*temppr2 != '\0') {
				*punoime2 = *temppr2;
				punoime2++;
				temppr2++;
			}	punoime2--;
			
			/* I ime koje uporedjujem */
			while (*tempime2 != '\0') {
				*punoime2 = *tempime2;
				punoime2++;
				tempime2++;
			}	*punoime2 = '\0';
			
			/* Sad uporedjujem !! */
			kontrolna = 0;
			punoime1 = TempPreIme1;
			punoime2 = TempPreIme2;
			while (*punoime1 != '\0' || *punoime2 != '\0') { /* Potencijalna greska za skriveni u zavisnosti da li uporedjuje do kraja imena oba clana ili do kraja najduzeg */
				
				if (*punoime1 < *punoime2) {
					kontrolna = 0;
					break;
				}
				else if (*punoime1 > *punoime2) {
					kontrolna = 1;
					break;
				}
				
				punoime1++;
				punoime2++;
			}
			
			
			if ((kontrolna)) {
				swap = j;
				
				/* Mijenjam odgovarajuce pokazivace prezime */
				temp = prezimepok[i];
				prezimepok[i] = prezimepok[swap];
				prezimepok[swap] = temp;
				
				/* Mijenjam odgovarajuce pokazivace ime */
				temp = imepok[i];
				imepok[i] = imepok[swap];
				imepok[swap] = temp;
				
				/* Mijenjam i niz prosjeka */
				tempbroj = *(niz + i);
				*(niz + i) = *(niz + swap);
				*(niz + swap) = tempbroj;
			}
		}
	}
	
	/* Kopiram niz u TEMPniz */
	for (i = 0; i < vel; i ++)
		*(alterpok + i) = *(niz + i);
	
	/* Prosjek od max do min sve u dublima */
	for (i = 0; i < vel; i ++) {
		trenutnimax = *(alterpok + i);
		for (j = i + 1; j < vel; j++) {
			if (*(alterpok + j) > trenutnimax) {
				trenutnimax = *(alterpok + j);
				
				tempbroj = *(alterpok + i);
				*(alterpok + i) = trenutnimax;
				*(alterpok + j) = tempbroj;
			}
		}
	}
	
	/* Izbacivanje duplih iz alterniz */
	vel2 = vel;
	for (i = 0; i < vel2; i ++) {
		tempbroj = *(alterpok + i);
		for (j = i+1; j < vel2; j ++) {
			trenutnimax = *(alterpok + j);
			if ( fabs (tempbroj - trenutnimax) < epsilon ) {
				for (k = j+1; k < vel2; k ++)
					*(alterpok + j) = *(alterpok + k); 
					--vel2;
					--j;
			}
		}
	}
	
	/* Fajnli ispisivanje redoslijedom */
	for (i = 0; i < vel2; i++) {
		
		trenutnimax = *(alterpok + i);
		for (j = 0; j < vel; j ++) {
			
			tempbroj = *(niz + j);
			if ( ( fabs( trenutnimax - tempbroj ) < epsilon ) && (brojac < 3) )	{
				printf ("%s %s", *(prezimepok + j), *(imepok + j));
				printf ("\n");
				brojac++;
			}
		}
	}
}

int genijalci (struct Student studenti[], int vel, double prosjek) {
	int i, j, kontrolna;
	int br_preostalih = 0, suma;
	double art_sred = 0, niz[200];
	char *pokprez[22], *pokime[22];
	
	for (i = 0; i < vel; i ++) {
		
		/* Racunanje prosjeka */
		suma = 0;	kontrolna = 0;
		for (j = 0; j < studenti[i].br_ocjena; j ++) {
			if (studenti[i].ocjene[j] == 5 || studenti[i].br_ocjena == 0)
			kontrolna = 1;
			suma += studenti[i].ocjene[j];
		}
		
		/* kontrol varijabla kao test petice */
		if (kontrolna)
		art_sred = 5;
		else
		art_sred = (float)suma/studenti[i].br_ocjena;

		/* Izbacivanje iz strukture ako je prosjek "else" */
		if (art_sred >= prosjek || (fabs(art_sred-prosjek) < epsilon) ) {
			/* Pokazivac na string i prezime i ime */
			pokprez[br_preostalih] = studenti[i].prezime;
			pokime[br_preostalih] = studenti[i].ime;
			niz[br_preostalih] = art_sred;
			
			br_preostalih++;
		}
		else {
			
			for (j = i; j < vel-1; j ++)
				studenti[j] = studenti[j+1];
				--vel;
				--i;
		}
	}
	
	leksikosort(pokprez, pokime, niz, br_preostalih);
	return br_preostalih;
}

int main() {
	printf("Zadaća 5, Zadatak 1\n");
	struct Student studenti[] = {

            {"Meho", "Behic", {10, 9}, 2}, // Behic, Aehic, Zehic, Oehic -> ove ispisuje !
            {"Meho", "Aehic", {10, 8}, 2},
            {"Meho", "Cehic", {10, 9, 8, 7, 6}, 5},
            {"Meho", "Dehic", {6, 9}, 2},
            {"Meho", "Zehic", {10}, 1},
            {"Meho", "Oehic", {10, 9, 9, 9}, 4}
        };
        int vel = sizeof studenti / sizeof studenti[0], i;
        vel = genijalci(studenti, vel, 9.);
        printf("Vel: %d Studenti:\n", vel);
        for (i = 0; i < vel; ++i)
            printf ("%s %s\n", studenti[i].prezime, studenti[i].ime);
	return 0;
}