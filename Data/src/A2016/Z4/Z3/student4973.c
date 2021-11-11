#include <stdio.h>

void izbaciRijec(char* pocetak, char* kraj){
	while(*kraj != '\0'){
		*pocetak = *kraj;
		pocetak++;
		kraj++;
	}
	*pocetak = *kraj;
}
void ubaciRijec(char* pozicija,char* rijec){
	int velicina = 0;
	char* pok = rijec;
	while(*pok != '\0'){
		pok++;
		velicina++;
	}
	
	pok = pozicija;
	while(*pok != '\0'){
		pok++;
	}
	while(pok != pozicija){
		pok[velicina] = *pok;
		pok--;
	}
	pok[velicina] = *pok;
	pok--;
	int i = 0;
	for(i = 0; i < velicina; i++){
		pok[i+1] = rijec[i];
	}
	return;
}
int isteRijeci(char* pocetak, char* kraj, char* rijec){
	int iste = 1;
	while(pocetak != kraj && rijec!='\0'){
		if(*pocetak != *rijec){
			iste = 0;
			break;
		}
		pocetak++;
		rijec++;
	}
	if(iste == 0 || pocetak != kraj || *rijec != '\0') return 0;
	return 1;
}
char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci){
	if(*tekst == '\0') return tekst;
	if(broj_rijeci == 0) return tekst;
	char* pocetakRijeci = NULL,*krajRijeci = NULL, *pok = tekst;
	int i = 0;
	while(*pok != '\0'){
		pok++;
	}
	while(pok != tekst){
		if( (pok - 1) != tekst && *(pok - 1) == ' ') {
			pok--;
		}
		krajRijeci = pok;
		while(pok != tekst && *(pok - 1) != ' '){
			pok --;
		}
		pocetakRijeci = pok;
		for(i = 0; i < broj_rijeci; i++){
			if(isteRijeci(pocetakRijeci,krajRijeci,rijeci[i])){
				izbaciRijec(pocetakRijeci,krajRijeci);
				ubaciRijec(pocetakRijeci,zamjene[i]);
				break;
			}
		}
		if(pok == tekst) break;	
		pok--;
	}
	
	return tekst;
}

int main() {
	char* rijeci[2] = { "beli", "sneg" };
	char* zamjene[2] = { "bijeli", "snijeg" };
	char tekst[100] = "beli sneg je pokrio beli breg";
	printf("%s", zamjena_rijeci(tekst, rijeci, zamjene, 2));
	/* Da li je promijenjen i polazni string? */
	printf("%s", tekst);
	return 0;
}
