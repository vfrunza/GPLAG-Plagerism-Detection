#include <stdio.h>
#include <string.h>
#include <math.h>
#define EPS 0.001

struct Student {
	char ime[20],prezime[20];
	int ocjene[50];
	int br_ocjena;
};

double prosjek_ocjena (int *ocjene, int vel) {
	float suma=0;
	int i;
	if (vel==0)
		return 5;
	for (i=0; i<vel; i++) {
		if (ocjene[i]==5)
			return 5;
		suma+=ocjene[i];
	}
	suma/=vel;
	return suma;
}

int genijalci (struct Student studenti[], int vel, double prosjek) {
	int j,i,prvi_indeks=0,drugi_indeks=0,treci_indeks=0,indeks_abecedni=0,indeks_abecedni_ime=0;
	double prvi_prosjek,drugi_prosjek,treci_prosjek;

	/*Izbacujemo studente ciji je prosjek ocjena manji nego zahtijevani prosjek.*/
	for (i=0; i<vel; i++) {
		if (prosjek_ocjena(studenti[i].ocjene, studenti[i].br_ocjena) < prosjek) {
			for (j=i; j<vel-1; j++) {
				studenti[j]=studenti[j+1];
			}
			vel--;
			i--;
		}
	}
	
	/*Ako nijedan student ne zadovoljavaju uslov,tj. ako smo izbacile sve studente iz niza, odmah vracamo velicinu 0.*/
	if (vel==0)
		return 0;
		
	/*Trazimo studenta sa najvecim prosjekom.*/
	prvi_prosjek=0;
	prvi_indeks=0;
	for (i=0; i<vel; i++) {
		if (prvi_prosjek <= prosjek_ocjena(studenti[i].ocjene,studenti[i].br_ocjena)) {
			prvi_prosjek=prosjek_ocjena(studenti[i].ocjene,studenti[i].br_ocjena);
			prvi_indeks=i;
		}
	}
	
	for (i=0; i<vel-1; i++) {
		for (j=i+1; j<vel; j++) {
			if (fabs(prvi_prosjek - prosjek_ocjena(studenti[j].ocjene,studenti[j].br_ocjena)) < EPS && j!=prvi_indeks) {
				indeks_abecedni =strcmp (studenti[prvi_indeks].prezime,studenti[j].prezime);
				if (indeks_abecedni < 0) {
					prvi_indeks=prvi_indeks;
					drugi_indeks=j;
					break;
				}
				else if (indeks_abecedni >0) {
					prvi_indeks=j;
					drugi_indeks=prvi_indeks;
					break;
				}
				else if (indeks_abecedni==0) {
					indeks_abecedni_ime=strcmp(studenti[prvi_indeks].ime,studenti[j].ime);
					if (indeks_abecedni_ime < 0) {
						prvi_indeks=prvi_indeks;
						drugi_indeks=j;
						break;
					}
					else if (indeks_abecedni_ime<0) {
						prvi_indeks=j;
						drugi_indeks=prvi_indeks;
						break;
					}
					break;
				}
				break;
			}
		}
	}
	printf ("%s %s\n",studenti[prvi_indeks].prezime,studenti[prvi_indeks].ime);
	if (vel==1) 
		return vel;
	
	/*Trazimo studenta sa 2.najboljim prosjekom, uz uslov da to nije vec pronadeni student sa najboljim prosjekom.*/
	drugi_prosjek=0;
	indeks_abecedni_ime=0;
	indeks_abecedni=0;
    
    if(drugi_indeks==0) {
		for (i=0; i<vel; i++) {
			if (drugi_prosjek <= prosjek_ocjena(studenti[i].ocjene, studenti[i].br_ocjena) && i!=prvi_indeks) {
				drugi_prosjek=prosjek_ocjena(studenti[i].ocjene,studenti[i].br_ocjena);
				drugi_indeks=i;
			}
		}
    }
	
	for (i=0; i<vel-1; i++) {
		for (j=i+1; j<vel; j++) {
			if (fabs(drugi_prosjek - prosjek_ocjena(studenti[j].ocjene,studenti[j].br_ocjena))<EPS && j!=prvi_indeks) {
				indeks_abecedni = strcmp(studenti[drugi_indeks].prezime,studenti[j].prezime);
				if (indeks_abecedni < 0) {
					drugi_indeks=drugi_indeks;
					treci_indeks=j;
					break;
				}
				else if (indeks_abecedni>0) {
					drugi_indeks=j;
					treci_indeks=drugi_indeks;
					break;
				}
				else if (indeks_abecedni==0) {
					indeks_abecedni_ime=strcmp(studenti[drugi_indeks].ime,studenti[j].ime);
						if (indeks_abecedni_ime<0) {
							drugi_indeks=drugi_indeks;
							treci_indeks=j;
							break;
						}
						else if (indeks_abecedni_ime>0) {
							drugi_indeks=j;
							treci_indeks=drugi_indeks;
							break;
						}
						break;
					}
					break;
				}
			}
		}
	printf ("%s %s\n",studenti[drugi_indeks].prezime,studenti[drugi_indeks].ime);
	indeks_abecedni_ime=0;
	indeks_abecedni=0;
	if (vel==2)
		return vel;

	/*Na kraju trazimo 3.najboljeg studenta,uslov da nije 2. ili 1. najbolji.*/
	treci_prosjek=0;

		for (i=0; i<vel; i++) {
			if (treci_prosjek <= prosjek_ocjena(studenti[i].ocjene,studenti[i].br_ocjena) && i!=prvi_indeks) {
				if (i!=drugi_indeks) {
					treci_prosjek=prosjek_ocjena(studenti[i].ocjene,studenti[i].br_ocjena);
					treci_indeks=i;
				}
			}
		}
	
	for (i=0; i<vel-1; i++) {
		for (j=i+1; j<vel; j++) {
			if (fabs(treci_prosjek-prosjek_ocjena(studenti[j].ocjene,studenti[j].br_ocjena))<EPS && j!=prvi_indeks && j!=drugi_indeks) {
				indeks_abecedni=strcmp(studenti[treci_indeks].prezime,studenti[j].prezime);
				if (indeks_abecedni < 0) {
					treci_indeks=treci_indeks;
					break;
				}
				else if (indeks_abecedni>0) {
					treci_indeks=j;
					break;
				}
				else if (indeks_abecedni==0) {
					indeks_abecedni_ime=strcmp(studenti[treci_indeks].ime,studenti[j].ime);
					if (indeks_abecedni_ime < 0) {
						treci_indeks=treci_indeks;
						break;
					}
					else if (indeks_abecedni_ime>0) {
						treci_indeks=j;
						break;
					}
					break;
				}
				break;
			}
		}
	}
	printf ("%s %s\n",studenti[treci_indeks].prezime,studenti[treci_indeks].ime);
	if (vel==3)
		return vel;
		
	return vel;
}

int main() {
	struct Student studenti[5] = {
		{"Mujo", "Mujic", {7,7,7,7,8},5},
		{"Pero", "Peric", {8,8,8,8,7},5},
		{"Beba", "Bebic", {6,6,6,6,6},5},
		{"Mujo", "Mujic", {7,7,7,7,8},5},
		{"Fata", "Fatic", {7,7,7,8,8},5},
	};
	int vel=sizeof studenti/sizeof studenti[0];
	vel=genijalci(studenti,5,6.5);
	printf ("Vel=%d",vel);
	return 0;
}