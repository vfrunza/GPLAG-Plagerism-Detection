#include <stdio.h>
char* izbaci_najcescu(char* s) {
	char* pocetnaRecenica = s;
	char recenicaSaIzbacenomRijeci[100];
	int brojPonavljanjaRijeci[100];
	char rijeci[100][100];
	int brojacRijeciUNizu = 0;
	char slovaIzRijeciKojuTrazimo[100];
	int brojac = 0;
	char temp;
	int i;
	int j;

	do{
		s++;
		if (*s >= 'A' && *s <= 'Z') {
			temp = *s + 32;
		}
		else {
			temp = *s;
		}
		if (temp >= 'a' && temp <= 'z') {
			slovaIzRijeciKojuTrazimo[brojac] = temp;
			brojac++;
		}
		else {
			slovaIzRijeciKojuTrazimo[brojac] = '\0';
			int rijecPostoji = 1;
			int index = 0;
			
			//provjera da li postoji rijec
			for (i = 0;i < brojacRijeciUNizu;i++)
			{
				rijecPostoji = 1;
				for (j = 0;j <= brojac;j++) {
					if (rijeci[i][j] != slovaIzRijeciKojuTrazimo[j])
					{
						rijecPostoji = 0;
						break;
					}
				}
				if (rijecPostoji == 1) {
					index = i;
					break;
				}
			}
			if (rijecPostoji == 1 && brojacRijeciUNizu !=0) {
				brojPonavljanjaRijeci[index]++;
			}
			else {
				for (i = 0;i <= brojac;i++){
					rijeci[brojacRijeciUNizu][i] = slovaIzRijeciKojuTrazimo[i];
				}
				brojPonavljanjaRijeci[brojacRijeciUNizu] = 1;
				brojacRijeciUNizu++;
			}
			brojac = 0;
		}
	} while (*s != '\0');


	int indexRijeciKojaSeNajvisePonavlja = 0;
	int maxBrojPonavljanja = 0;
	for (i = 0;i < brojacRijeciUNizu;i++) {
		if (maxBrojPonavljanja < brojPonavljanjaRijeci[i]) {
			indexRijeciKojaSeNajvisePonavlja = i;
			maxBrojPonavljanja = brojPonavljanjaRijeci[i];
		}
	}

	brojac = 0;
	int brojacFinalneRijeci = 0;
	while (*pocetnaRecenica != '\0') {
		if (*pocetnaRecenica >= 'A' && *pocetnaRecenica <= 'Z') {
			temp = *pocetnaRecenica + 32;
		}
		else {
			temp = *pocetnaRecenica;
		}
		if (temp >= 'a' && temp <= 'z') {
			slovaIzRijeciKojuTrazimo[brojac] = temp;
			pocetnaRecenica++;
			brojac++;
		}
		else {
			int pronasaoRijec = 1;
			slovaIzRijeciKojuTrazimo[brojac] = '\0';
			for (i = 0;i <= brojac;i++) {
				if (rijeci[indexRijeciKojaSeNajvisePonavlja][i] != slovaIzRijeciKojuTrazimo[i]) {
					pronasaoRijec = 0;
					break;
				}
			}
			if (pronasaoRijec == 0) {
				for (i = 0;i < brojac;i++) {
					pocetnaRecenica--;
				}
				for (i = 0;i <= brojac;i++) {
					recenicaSaIzbacenomRijeci[brojacFinalneRijeci] = *pocetnaRecenica;
					pocetnaRecenica++;
					brojacFinalneRijeci++;
				}
			}
			brojac = 0;
		}
	}
	recenicaSaIzbacenomRijeci[brojacFinalneRijeci] = '\0';
	s=recenicaSaIzbacenomRijeci;
	return s;
}


int main() {
	char t[]="SUNCE sunce SUnce radi Radi RADI je Radi";
	char* s = izbaci_najcescu(t);
	printf("%s", izbaci_najcescu(t));
	printf("%s", &t[0]);
	return 0;
}