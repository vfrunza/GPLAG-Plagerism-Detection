#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define epsilon 0.00000001


struct Datum {
	int dan, mjesec, god;
};

struct Student {
  struct Datum d;
  char ime[20], prezime[20];
};

struct Student unos_studenta () {
	struct Student st;
	printf("Unesi ime i prezime studenta: ");
	scanf("%s %s",st.ime, st.prezime);
	printf("Unesi datum rodjenja: ");
	scanf("%d %d %d",&st.d.dan, &st.d.mjesec, &st.d.god);
	return st;
}

void ispis (struct Student st) {
	printf("%s %s %d %d %d",st.ime,st.prezime,st.d.dan,st.d.mjesec,st.d.god);
}

struct Student funkcija (struct Student* niz, int vel, int broj) {
	int i,j;
	
	for (i=0; i<vel; i++) {
		for (j=i+1; j<vel; j++) {
			if ((abs(niz[i].d.dan-niz[j].d.dan))==broj) {
				ispis(niz[i]);
				ispis(niz[j]);
			}
		}
	}
	
}


int main() {
	int i,n;
	struct Student niz[30];
	printf("unesi n: ");
	scanf("%d",&n);
	for (i=0; i<n; i++) {
		niz[i]=unos_studenta();
	}
	printf("poziv fje: \n");
	

	return 0;
}
