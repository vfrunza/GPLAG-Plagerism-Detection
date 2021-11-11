#include <stdio.h>
#include <string.h>

struct Student {
	char ime[20], prezime[20];
	int ocjene [50];
	int br_ocjena;
};

void unesi(char niz[], int velicina) {
	char znak = getchar();
	if (znak == '\n') znak=getchar();
	int i = 0;
	while (i < velicina-1 && znak != '\n') {
		niz[i]=znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';	
}

int genijalci (struct Student niz[], int vel_niza, double prosjek) {
	int i=0, j=0, ocjena=0, suma=0, sadrzi_5=0, indeks_prvog=0, indeks_drugog=0, indeks_treceg=0;
	double prosjek2=0, trenutni_max=5.0, prvi_max=5.0, drugi_max=5.0, treci_max=5.0;
	
	for (i=0; i<vel_niza; i++) {
		for (j=0; j<niz[i].br_ocjena; j++) {
			if (niz[i].ocjene[j]==5) {   /*Ukoliko postoji ocjena 5, logička promjenljiva postaje 1.*/
				sadrzi_5=1;
			}
			suma = suma + niz[i].ocjene[j]; 
		}
		
		if (niz[i].br_ocjena != 0) prosjek2=(double)suma/niz[i].br_ocjena; /*Racunamo prosjek ocjena.*/
		else prosjek2=5.0;
		if (sadrzi_5==1) prosjek2=5.0; /*Ukoliko imamo ocjenu 5, prosjek je 5.0.*/
		
		/*Izbacivanje studenata ciji je prosjek manji od unesenog prosjeka.*/
		if (prosjek2<prosjek) {
			for (j=i; j<vel_niza-1; j++) {
				niz[j]=niz[j+1];
			}
			vel_niza--;
			i--;
		}
		
		suma=0;
		prosjek2=0;
		sadrzi_5=0;
	}
	
	for (i=0; i<vel_niza; i++) {
		for (j=0; j<niz[i].br_ocjena; j++) {
			if (niz[i].ocjene[j]==5) {
				sadrzi_5=1;
			}
			suma = suma + niz[i].ocjene[j];
		}
		
		if (niz[i].br_ocjena != 0) trenutni_max = (double)suma/niz[i].br_ocjena;
		else trenutni_max=5.0;
		if (sadrzi_5==1) trenutni_max=5.0;
		
		if (trenutni_max>prvi_max) {
			prvi_max=trenutni_max;
			indeks_prvog=i;
		}
		
		else if (trenutni_max==prvi_max) {    /*Ako su isti prosjeci, provjeravamo prezimena.*/
			char *p=niz[i].prezime;
			char *q=niz[indeks_prvog].prezime;
			
			if (strcmp(p, q)==0) {			  /*Ako su ista prezimena, provjeravamo imena.*/
				char *m=niz[i].ime;
				char *n=niz[indeks_prvog].ime;
				
				if (strcmp(m, n)<0) {
					prvi_max=trenutni_max;
					indeks_prvog=i;
				}
			}
				
			else if (strcmp(p, q)<0) {
				prvi_max=trenutni_max;
				indeks_prvog=i;
			}
		}
		
		suma=0;
		prosjek2=0;
	}	
	
	for (i=0; i<vel_niza; i++) {
		for (j=0; j<niz[i].br_ocjena; j++) {
			if (niz[i].ocjene[j]==5) {
				sadrzi_5=1;
			}
			suma = suma + niz[i].ocjene[j];
		}
		
		if (niz[i].br_ocjena != 0) trenutni_max = (double)suma/niz[i].br_ocjena;
		else trenutni_max=5.0;
		if (sadrzi_5==1) trenutni_max=5.0;
		
		if (trenutni_max>drugi_max && i != indeks_prvog) {  /*Trazimo drugog studenta po prosjeku.*/
			drugi_max=trenutni_max;                         /*Brojac i mora biti razlicit od indeksa najboljeg studenta, tj. njega preskacemo.*/
			indeks_drugog=i;  
		}
		
		else if (trenutni_max==drugi_max && i != indeks_prvog) {
			char *p=niz[i].prezime;
			char *q=niz[indeks_drugog].prezime;
			
			if (strcmp(p, q)==0) {
				char *m=niz[i].ime;
				char *n=niz[indeks_drugog].ime;
				
				if (strcmp(m, n)<0) {
					drugi_max=trenutni_max;
					indeks_drugog=i;
				}
			}
			
			else if (strcmp(p, q)<0) {
				drugi_max=trenutni_max;
				indeks_drugog=i;
			}
		}
		
		suma=0;
		prosjek2=0;
	}
	
	for (i=0; i<vel_niza; i++) {
		for (j=0; j<niz[i].br_ocjena; j++) {
			if (niz[i].ocjene[j]==5) {
				sadrzi_5=1;
			}
			suma = suma + niz[i].ocjene[j];
		}
	
		if (niz[i].br_ocjena != 0) trenutni_max = (double)suma/niz[i].br_ocjena;
		else trenutni_max=5.0;
		if (sadrzi_5==1) trenutni_max=5.0;
			
		if (trenutni_max>treci_max && i != indeks_prvog && i != indeks_drugog) {     /*Trazimo treceg studenta po prosjeku.*/
			treci_max=trenutni_max;                                                  /*Brojac i mora biti razlicit od indeksa najboljeg studenta*/
			indeks_treceg=i;                                                         /*i indeksa drugog studenta po prosjeku, tj. njih preskačemo.*/
		}
		
		else if (trenutni_max==treci_max && i != indeks_prvog && i != indeks_drugog) {
			char *p=niz[i].prezime;
			char *q=niz[indeks_treceg].prezime;
			
			if (strcmp(p, q)==0) {
				char *m=niz[i].ime;
				char *n=niz[indeks_treceg].ime;
				
				if (strcmp(m, n)<0) {
					treci_max=trenutni_max;
					indeks_treceg=i;
				}
			}
			else if (strcmp(p, q)<0) {
				treci_max=trenutni_max;
				indeks_treceg=i;
			}
		}
		
		suma=0;
		prosjek2=0;
	}
	
	if (vel_niza>=3) {                                                            /*Ukoliko imamo 3 ili vise studenata koji ispunjavaju uslove,*/
		printf ("%s %s\n", niz[indeks_prvog].prezime, niz[indeks_prvog].ime);     /*ispisujemo najboljeg studenta i sljedeca dva studenta po prosjeku.*/
		printf ("%s %s\n", niz[indeks_drugog].prezime, niz[indeks_drugog].ime);   /*Ako ne postoje tri studenta koji ispunjavaju ove uslove*/
		printf ("%s %s\n", niz[indeks_treceg].prezime, niz[indeks_treceg].ime);   /*ispisujemo samo najbolja dva ili samo najboljeg ili ne ispisujemo nista.*/
	}
	else if (vel_niza==2) { 
		printf ("%s %s\n", niz[indeks_prvog].prezime, niz[indeks_prvog].ime);
		printf ("%s %s\n", niz[indeks_drugog].prezime, niz[indeks_drugog].ime);
	}
	else if (vel_niza==1) {
		printf ("%s %s\n", niz[indeks_prvog].prezime, niz[indeks_prvog].ime);
	}
	return vel_niza;
}

int main() {
	/*printf("Zadaća 5, Zadatak 1");*/
	
	double prosjek=0;
	struct Student studenti[100];
	int i=0, j=0, br_studenata=0, a=0;
	
	scanf ("%d", &br_studenata);
	
	for (i=0; i<br_studenata; i++) {
		printf ("Unesite ime studenta: ");
		unesi(studenti[i].ime, 20);
		printf ("Unesite prezime studenta: ");
		unesi(studenti[i].prezime, 20);
		printf ("Unesite broj ocjena: ");
		scanf ("%d", &studenti[i].br_ocjena);
		for (j=0; j<studenti[i].br_ocjena; j++) {
			scanf ("%d", &studenti[i].ocjene[j]);
		}
	}
	
	printf ("Unesite prosjek: ");
	scanf ("%lf", &prosjek);
	
	a=genijalci (studenti, br_studenata, prosjek);
	printf ("Vel: %d", a);

	return 0;
}

