#include <stdio.h>


int je_pocetak_rijeci(const char* tekst, int indeks){
	return indeks == 0 || tekst[indeks - 1] == ' ';
}

int duzina(const char* tekst){
	int duz = 0;
	
	while(*(tekst+duz)){
		duz++;
	}
	
	return duz;
}

void daj_rijec(const char* tekst, int indeks, char* izlazna_rijec){
	tekst += indeks;
	
	while(*tekst != 0 && *tekst != ' '){
		*izlazna_rijec++ = *tekst++;
	}
	
	*izlazna_rijec = 0;
}

int iste_rijeci(const char* prva_rijec, const char* druga_rijec){
	while(*prva_rijec == *druga_rijec && *prva_rijec && *druga_rijec){
		prva_rijec++;
		druga_rijec++;
		
	}
	
	return *prva_rijec == 0 && *druga_rijec == 0;
}

/* Pomice sav tekst iza indeksa desno */
void pomakni_desno(char* tekst, int duzina_teksta, int indeks, int broj_koraka){
	int i;
	int tren_poz;
	
	for(i = 0; i < broj_koraka; i++, duzina_teksta++){
		tren_poz = duzina_teksta;
		
		while(tren_poz > indeks){
			tekst[tren_poz+1] = tekst[tren_poz];
			tren_poz--;
		}
	}
}

// Pomice sav tekt lijevo
void pomakni_lijevo(char* tekst, int indeks, int broj_koraka){
	int i;
	int tren_indeks;
	
	if(broj_koraka < 0){
		pomakni_desno(tekst, duzina(tekst), indeks, -broj_koraka);
		return;
	}
	
	for(i = 0; i < broj_koraka; i++){
		tren_indeks = indeks;
		
		while(tekst[tren_indeks]){
			tekst[tren_indeks] = tekst[tren_indeks+1];
			tren_indeks++;
		}
	}
}

// Funkcija za zamjenu
void zamijeni(char* tekst, int indeks, const char* novi_tekst){
	int i; 
	
	for(i = indeks;	 novi_tekst[i - indeks]; i++){
		tekst[i] = novi_tekst[i-indeks];
	}
}

// Generalna funkcija za zamjenu rijeci
char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci){
	int duz = duzina(tekst);
	int i, j;
	char tren_rijec[100];
	
	if(!duz) return tekst;
	
	for(i=0;tekst[i];i++){
		if(je_pocetak_rijeci(tekst, i)){
			daj_rijec(tekst, i, tren_rijec);
			for(j = 0; j < broj_rijeci; j++){
				if(iste_rijeci(rijeci[j], tren_rijec)){
					pomakni_lijevo(tekst, i, duzina(tren_rijec) - duzina(zamjene[j]));
					zamijeni(tekst,i,zamjene[j]);
					break;
				}
			}
		}
	}
	
	return tekst;
}


int main() {
	 char* rijeci[2] = { "beli", "sneg" };
	char* zamjene[2] = { "bijeli", "snijeg" };
	char tekst[100] = "beli sneg je pokrio beli breg";
	printf("%s", zamjena_rijeci(tekst, rijeci, zamjene, 2));
	return 0;
}
