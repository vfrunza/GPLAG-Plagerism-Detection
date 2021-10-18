#include <stdio.h>


struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

int genijalci(struct Student* niz, int vel, float prosjek) {
	int i, j;
	float suma, prosjek1, max_prosjek;
	int p1=-1, p2=-1, p3=-1, indeks;
	
	for(i=0; i<vel; i++) {
		suma=0;
		for(j=0; j<niz[i].br_ocjena; j++) {
			if(niz[i].ocjene[j]==5) {
				suma=5*niz[i].br_ocjena;
				break;
			}
			else {
				suma+=niz[i].ocjene[j];
			}
		}
		if(niz[i].br_ocjena==0) prosjek1=5.0;
		else prosjek1=suma/niz[i].br_ocjena;
		if (prosjek1 < prosjek) {
			for(j=i; j<vel-1; j++) {
				niz[j]=niz[j+1];
			}
			vel--;
			i--;
		}
	}
	suma=0;
	for(i=0; i<niz[0].br_ocjena; i++) {
		if(niz[0].ocjene[i]==5) {
			suma=5*niz[0].br_ocjena;
			break;
		}
		else { suma+=niz[0].ocjene[i];
		}
	}
	if(niz[0].br_ocjena==0) max_prosjek=5.0;
	else max_prosjek=suma/niz[0].br_ocjena;
	if(vel>0) p1=0;
	
	for(i=0; i<vel; i++) {
		suma=0;
		for(j=0; j<niz[i].br_ocjena; j++) {
			if(niz[i].ocjene[j]==5) {
				suma=5*niz[i].br_ocjena;
				break;
			}
			else {
				suma+=niz[i].ocjene[j];
			}
		}
		if(niz[i].br_ocjena==0) prosjek1=5.0;
		else prosjek1=suma/niz[i].br_ocjena;
		if(prosjek1 > max_prosjek) {
			max_prosjek=prosjek1;
			p1=i;
		}
	}
	if(p1!=-1) printf("%s %s\n", niz[p1].prezime, niz[p1].ime);
	if(p1==0) indeks=1; else indeks=0;
	suma=0;
	for(i=0; i<niz[indeks].br_ocjena; i++) {
		if(niz[indeks].ocjene[i]==5) {
			suma=5*niz[indeks].br_ocjena;
			break;
		}
		else suma+=niz[indeks].ocjene[i];
	}
	
	if(niz[indeks].br_ocjena==0) max_prosjek=5.0;
	else max_prosjek=suma/niz[indeks].br_ocjena;
	if(vel>1) p2=indeks;
	for(i=0; i<vel; i++) {
		suma=0;
		for(j=0; j<niz[i].br_ocjena; j++) {
			if(niz[i].ocjene[j]==5) {
				suma=5*niz[i].br_ocjena;
				break;
			}
			else suma+=niz[i].ocjene[j];
		}
		if(niz[i].br_ocjena==0) prosjek1=5.0;
		else prosjek1=suma/niz[i].br_ocjena;
		if(i!=p1 && prosjek1>max_prosjek) {
			max_prosjek=prosjek1;
			p2=i;
		}
	}
	if(p2!=-1) printf("%s %s\n", niz[p2].prezime, niz[p2].ime);
	if(p2==indeks) indeks++;
	suma=0;
	for(i=0; i<niz[indeks].br_ocjena; i++) {
		if(niz[indeks].ocjene[i]==5) {
			
			suma=5*niz[indeks].br_ocjena;
			break;
		}
		else suma+=niz[indeks].ocjene[i];
	}
	if(niz[indeks].br_ocjena==0) max_prosjek=5.0;
	else max_prosjek=suma/niz[indeks].br_ocjena;
	if(vel>2) p3=indeks;
	for(i=0; i<vel; i++) {
		suma=0;
		for(j=0; j<niz[i].br_ocjena; j++) {
			if(niz[i].ocjene[j]==5) {
				suma=5*niz[i].br_ocjena;
				break;
			}
			else suma+=niz[i].ocjene[j];
		}
		
		if(niz[i].br_ocjena==0) prosjek1=5.0;
		else prosjek1=suma/niz[i].br_ocjena;
		if(i!=p1 && i!=p2 && prosjek1>max_prosjek) {
			max_prosjek=prosjek1;
			p3=i;
		}
	}
	if(p3!=-1) printf("%s %s\n", niz[p3].prezime, niz[p3].ime);
	return vel;
}
int main() {
	
	
	return 0;
}
