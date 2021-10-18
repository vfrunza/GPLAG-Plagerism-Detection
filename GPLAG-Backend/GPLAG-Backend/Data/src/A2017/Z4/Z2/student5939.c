#include <stdio.h>

int uporedi_sa_nizom (int niz[], int vel, int index, int duzina) {
	
	if (niz[index] == duzina) return 1;
	return 0;
}

int prebroji (char* pocetak, char* kraj) {
	int rezultat = 0;
	while (pocetak < kraj) {
		rezultat++;
		pocetak++;
	}
	return rezultat;
}

int prebroji_rijeci(char* recenica) {
	int znak=1, broj_rijeci = 0;
	while (*recenica != '\0') {
		if ((*recenica < 'A' || *recenica > 'Z') && (*recenica < 'a' || *recenica > 'z')) znak = 1;
		else if(znak == 1) {
			znak = 0;
			broj_rijeci++;
		}
		recenica++;
	}
	return broj_rijeci;
}
int provjeri_duzine (char* recenica, int niz[], int vel) {
	int index_rijeci = -1;
	int duzina_rijeci = 0;
	int izvrsio_se = 0;
	char* pocetak_stringa = recenica;
	char* pocetak_rijeci = recenica;
	char* kraj_rijeci = recenica;
	if (vel > prebroji_rijeci(recenica) || vel < prebroji_rijeci(recenica)) return 0;
	while (*pocetak_stringa != '\0') {
		while (*pocetak_rijeci != '\0' && (*pocetak_rijeci < 'A' || *pocetak_rijeci > 'Z') && (*pocetak_rijeci < 'a' || *pocetak_rijeci > 'z')) {
			pocetak_rijeci++;
			izvrsio_se = 1;
		} 
		if (izvrsio_se) {
			kraj_rijeci = pocetak_rijeci;
			pocetak_stringa = pocetak_rijeci;
			izvrsio_se = 0;
		}
		if (*pocetak_stringa == '\0') break;
		if((*pocetak_stringa < 'A' || *pocetak_stringa > 'Z') && (*pocetak_stringa < 'a' || *pocetak_stringa > 'z')) {
			index_rijeci++;
			if (index_rijeci == vel) return 0;
			*kraj_rijeci = *pocetak_stringa;
			duzina_rijeci = prebroji(pocetak_rijeci, kraj_rijeci);
			if(!uporedi_sa_nizom(niz, vel, index_rijeci, duzina_rijeci)) return 0;
			if(*kraj_rijeci == ' ' || (*pocetak_rijeci < 'A' || *pocetak_rijeci > 'Z') || (*pocetak_rijeci < 'a' || *pocetak_rijeci > 'z')) pocetak_rijeci = kraj_rijeci;
		}
		pocetak_stringa++;
		kraj_rijeci++;
	}
	return 1;
}
int main() {
	printf("Zadaća 4, Zadatak 2");
	return 0;
}
