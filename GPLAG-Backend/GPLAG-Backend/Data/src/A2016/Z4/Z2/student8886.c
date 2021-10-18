#include <stdio.h>

void sortiraj(int *niz, int *sortirani, int *indeks) {
	int i, j, pom;
	
	for (i=0; i<127; i++) {
		for (j=i; j<127; j++) {
			if (niz[i]<niz[j]) {
				pom=niz[i];
				niz[i]=niz[j];
				niz[j]=pom;
				pom=indeks[i];
				indeks[i]=indeks[j];
				indeks[j]=pom;
			}
			else if (niz[i]==niz[j] && indeks[i]>indeks[j]) {
				pom=indeks[i];
				indeks[i]=indeks[j];
				indeks[j]=pom;
			}
		}
	}
}

void konevertuj(char *s, char *sifrarnik) {
	char *p=s, *sifra=sifrarnik;
	int brojac;
	
	while (*p!='\0') {
		brojac=0;
		sifra=sifrarnik;
		while (*sifra!='\0') {
			if (*p==*sifra++) {
				*p=126-brojac;
				break;
			}
			brojac++;
		}
		p++;
	}
}

char* kodiraj(char *s, char *sifrarnik) {
	char *p=s, *q=sifrarnik;
	int i;
	int niz[127], sortirani[127], indeks[127];
	for (i=0; i<127; i++) {
		if (i<32) niz[i]=-1;
		else niz[i]=0;
	}
	for (i=0; i<127; i++) {
		if (i<32) indeks[i]=-1;
		else indeks[i]=i;
	}
	while (*p!='\0') {
		niz[*p+0]++;
		p++;
	}
	for (i=0; i<127; i++) 
	sortirani[i]=niz[i];
	sortiraj(niz, sortirani, indeks);
	for (i=0; i<127; i++)  {
		if (indeks[i]!=-1) {
			*q=indeks[i];
			q++;
		}
	}
	konevertuj(s, sifrarnik);
	return s;
}

char *dekodiraj(char *s, char *sifrarnik) {
	char *p=s;
	while (*p!='\0') {
		*p=sifrarnik[126-*p];
		p++;
	}
	return s;
}

int main () {
	char tekst[]="";
	char sifrarnik[100]="";
	kodiraj(tekst, sifrarnik);
	printf ("%s\n", tekst);
	dekodiraj(tekst, sifrarnik);
	printf ("%s\n", tekst);
	printf ("%s\n", sifrarnik);
	return 0;
}