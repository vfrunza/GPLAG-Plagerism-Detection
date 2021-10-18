#include <stdio.h>
#include <ctype.h>

void algoritam_za_upisivanje_podstringa (char* pocetak_najveceg_podstringa, char* s2) {
	char* kraj_najveceg_podstringa = pocetak_najveceg_podstringa;
	while (*kraj_najveceg_podstringa != ' ') {
		if (*kraj_najveceg_podstringa != '\0') kraj_najveceg_podstringa++;
		else break;
	}
	while (pocetak_najveceg_podstringa < kraj_najveceg_podstringa) {
		*s2 = *pocetak_najveceg_podstringa;
		pocetak_najveceg_podstringa++;
		s2++;
	}
	*s2 = '\0';
}

char* izbaci (char* kontejner, int vel) {
	char* pocetak = kontejner;
	char* p = kontejner;
	char* q = kontejner;
	while (p < kontejner + vel) {
		char tmp1 = *p;
		if (tmp1 >= 'A' && tmp1 <= 'Z') {
			tmp1 += 'a'-'A';
		}
		q = p + 1;
		while (q < kontejner + vel) {
			char tmp2 = *q;
			if(tmp2 >= 'A' && tmp2 <= 'Z') {
				tmp2 += 'a'-'A';
			}
			if (tmp1 == tmp2) {
				char* pom = q;
				while (pom <= kontejner + vel) {
					*pom = *(pom + 1);
					pom++;
				}
				vel--;
				q--;
			}
			q++;
		}
		p++;
	}
	return pocetak;
}

int vrati_max (int niz[], int vel, int index_rijeci) {
	int i, rezultat = 0;
	for (i = 0; i < vel; i++) {
		if(niz[i] > niz[index_rijeci]) rezultat = 1;
	}
	return rezultat;
}

int duzina_rijeci (char* pocetak_rijeci, char* kraj_rijeci) {
	int duzina = 0;
	while (pocetak_rijeci < kraj_rijeci) {
		duzina++;
		pocetak_rijeci++;
	}
	return duzina;
}

void najduzi_bp (const char* s1, char* s2) {
	
	char kopija_stvarnog_stringa[10000];
	const char* kopija1 = s1;
	char* kopija2 = kopija_stvarnog_stringa;
	while(*kopija1 != '\0') {
		
		// brojevi
		if (*kopija1 >= '0' && *kopija1 <= '9') 
		    *kopija2 = ' ';
		else *kopija2 = *kopija1;
		// brojevi
		
		kopija1++;
		kopija2++;
	}
	*kopija2 = '\0';
	int niz[10] = {0};
	int izvrsio_se = 0, index_rijeci = -1, duzina = 0, brojac_elemenata = 0, duzina_najveceg_podstringa = 0;
	char pomocni[1000];
	char* pocetak_prepravljenog_stringa = kopija_stvarnog_stringa;
	char* kraj_pomocnog1 = pomocni;
	char* kraj_pomocnog2 = pomocni;
	char* pocetak_stringa = kopija_stvarnog_stringa;
	char* pocetak_rijeci1 = kopija_stvarnog_stringa;
	char* pocetak_rijeci2 = kopija_stvarnog_stringa;
	char* kraj_rijeci = kopija_stvarnog_stringa;
	char* pokazivac_na_najveci_podstring = kopija_stvarnog_stringa;
	
	while (*pocetak_stringa == ' ' || (*pocetak_stringa >= 'A' && *pocetak_stringa <= 'Z') || (*pocetak_stringa >= 'a' && *pocetak_stringa <= 'z')) {
		pocetak_rijeci1 = pocetak_stringa;
		while (*pocetak_rijeci1 == ' ' || *pocetak_rijeci1 < 'A' || (*pocetak_rijeci1 > 'Z' && *pocetak_rijeci1 < 'a')) {
			pocetak_rijeci1++;
			izvrsio_se = 1;
		}
		if (izvrsio_se) {
			izvrsio_se = 0;
			pocetak_stringa = pocetak_rijeci1;
			kraj_rijeci = pocetak_rijeci1;
		}
		if (*pocetak_stringa != ' ' && *pocetak_stringa != '\0') {
			index_rijeci++;
			kraj_rijeci = pocetak_stringa;
			while(isalpha(*kraj_rijeci)) kraj_rijeci++;
			duzina = duzina_rijeci(pocetak_rijeci1, kraj_rijeci);
			niz[index_rijeci] = duzina;
			brojac_elemenata++;
			int tmp=duzina;
			kraj_pomocnog1 = izbaci(pocetak_rijeci1, duzina);
			while(tmp--) {
				*kraj_pomocnog2 = *kraj_pomocnog1;
				kraj_pomocnog2++;
				kraj_pomocnog1++;
			}
			*kraj_pomocnog2 = '\0';
		}
		pocetak_stringa++;
		while(isalpha(*pocetak_stringa)) pocetak_stringa++;
		kraj_rijeci++;
	}
	while (*pocetak_prepravljenog_stringa != '\0') {
		pocetak_rijeci1 = pocetak_prepravljenog_stringa;
		while(*pocetak_rijeci1 == ' ') {
			izvrsio_se = 1;
			pocetak_rijeci1++;
		}
		if(izvrsio_se) {
			izvrsio_se = 0;
			pocetak_prepravljenog_stringa = pocetak_rijeci1;
			kraj_rijeci = pocetak_rijeci1;
		}
		if(*pocetak_prepravljenog_stringa != ' ' && *pocetak_prepravljenog_stringa != '\0') {
			index_rijeci++;
			kraj_rijeci = pocetak_prepravljenog_stringa;
			while (isalpha(*kraj_rijeci)) kraj_rijeci++;
			duzina = duzina_rijeci(pocetak_rijeci1, kraj_rijeci);
			niz[index_rijeci] = duzina;
			brojac_elemenata++;
			if (duzina > duzina_najveceg_podstringa) {
				pokazivac_na_najveci_podstring = pocetak_rijeci1;
				duzina_najveceg_podstringa = duzina;
			}
			if(*kraj_rijeci == ' ') pocetak_rijeci1 = kraj_rijeci;
		}
		pocetak_prepravljenog_stringa++;
		while (isalpha(*pocetak_prepravljenog_stringa)) pocetak_prepravljenog_stringa++;
		kraj_rijeci++;
	}
	algoritam_za_upisivanje_podstringa(pokazivac_na_najveci_podstring, s2);
	izbaci(s2, duzina_najveceg_podstringa);
}
int main() {
	return 0;
}
