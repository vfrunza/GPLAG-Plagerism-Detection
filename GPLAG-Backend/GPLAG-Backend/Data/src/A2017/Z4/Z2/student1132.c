#include <stdio.h>
// Funkcija koja vraca duzinu trenutne rijeci, uzimajuci u obzir da je rijec neprekinuti niz malih i velikih slova
int duzinarijeci (char* niz) {
	int brojac=0;
	while ((*niz>='a' && *niz<='z') || (*niz>='A' && *niz<='Z')) {
		brojac++;
		niz++;
	}
	return brojac;
}
// Funkcija koja prebrojava rijeci u stringu, uzimajuci u obzir da je rijec neprekinuti niz malih i velikih slova (TUT 10, Zadatak 4)
int prebrojirijeci(char* niz) {
	int brojac, brojrijeci=0;
	while (*niz) {
		brojac=0;
		while ((*niz>='A' && *niz<='Z') || (*niz>='a' && *niz<='z')) {
			brojac++;
			niz++;
		}
		if (brojac) {
			brojrijeci++;
			niz--;
		}
		niz++;
	}
	return brojrijeci;
}

int provjeri_duzine (char *niz, int *nizBrojeva, int velicinaNiza) {
	int brojrijeci = prebrojirijeci(niz);
	int i, duzinaTrenutneRijeci;
	if (brojrijeci!=velicinaNiza)
		return 0; // Provjerava da li se podudara broj rijeci u recenici sa brojem clanova niza brojeva
		
	for (i=0;i<velicinaNiza;i++) {
		while (!((*niz>='A' && *niz<='Z') || (*niz>='a' && *niz<='z'))) 
			niz++; // Pomjera pokazivac na pocetak rijeci
		duzinaTrenutneRijeci=duzinarijeci(niz); 
		if (duzinaTrenutneRijeci!=nizBrojeva[i])
			return 0; // Poredi duzinu trenutne rijeci sa odgovarajucim brojem u nizu brojeva, ako se ne podudaraju, vraca 0, ako se podudaraju, nastavlja provjeravanje
		while ((*niz>='A' && *niz<='Z') || (*niz>='a' && *niz<='z'))
			niz++; // Pomjera pokazivac na kraj trenutne rijeci, odnosno na pocetak prostora izmedju dvije rijeci
	}
	return 1;
}
int main() {
	int nizB[]={3, 2, 4, 6};
	int velicinaNiza=4;
	char nizS[]={"Ema je moja sestra"};
	int logicka;
	logicka=provjeri_duzine(nizS, nizB, velicinaNiza);
	printf("%d", logicka);
	return 0;
}