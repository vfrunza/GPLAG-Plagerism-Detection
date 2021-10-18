#include <stdio.h>
#include <string.h>

struct Datum {
	int dan, mjesec, godina;
};
struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};
int broj_rijeci(char *s) { // Funkcija za prebrojavanje rijeci, TUT 9 Zadatak 5
	int brojac = 0;
	while (*s) {
		if (*s==' ' && *(s-1)!=' ')
			brojac++;
		s++;
		if (*s=='\0' && *(s-1)!=' ')
			brojac++;
	}
	return brojac;
}
int provjeri_prezime(struct Uposlenik kandidat, struct Uposlenik direktor) {
	char prvoprezimekand[50], drugoprezimekand[50], prvoprezimedir[50], drugoprezimedir[50];
	int brojrijecikand, brojrijecidir, brojprezimenadir=1, brojprezimenakand=1;
	brojrijecikand=broj_rijeci(kandidat.ime_prezime); // Sluzi da provjeravamo broj imena
	brojrijecidir=broj_rijeci(direktor.ime_prezime);
	char *pocetakPrvogPreziKand, *pocetakDrugogPreziKand, *pocetakPrvogPreziDir, *pocetakDrugogPreziDir, *pomocniPok;
	char *klizeciPrvogPreziKand, *klizeciDrugogPreziKand, *klizeciPrvogPreziDir, *klizeciDrugogPreziDir;
	pocetakPrvogPreziKand=prvoprezimekand;
	pocetakDrugogPreziKand=drugoprezimekand;
	pocetakPrvogPreziDir=prvoprezimedir;
	pocetakDrugogPreziDir=drugoprezimedir;
	klizeciPrvogPreziKand=prvoprezimekand;
	klizeciDrugogPreziKand=drugoprezimekand;
	klizeciPrvogPreziDir=prvoprezimedir;
	klizeciDrugogPreziDir=drugoprezimedir;
	
	pomocniPok=kandidat.ime_prezime;
	while(*pomocniPok!=' ')
		pomocniPok++;
	pomocniPok++;
	if (brojrijecikand==3) { // Ako je funkcija izbrojala tri rijeci, znaci da kandidat ima 2 imena, tako da pomjeramo pokazivac na kraj drugog imena, tj na pocetak prezimena
		while (*pomocniPok!=' ')
			pomocniPok++;
		pomocniPok++;
	}
	while(*pomocniPok!='-' && *pomocniPok!='\0')
		*klizeciPrvogPreziKand++=*pomocniPok++; // Upisuje prezime u pomocni string prvoprezimekand
	*klizeciPrvogPreziKand='\0';
	if(*pomocniPok=='-') {
		pomocniPok++;
		while(*pomocniPok!='\0')
			*klizeciDrugogPreziKand++=*pomocniPok++; // U slucaju da je naisao na znak -, znaci da kandidat ima 2 prezimena, tako da upisujemo drugo prezime u pomocni string drugoprezimekand
		*klizeciDrugogPreziKand='\0';
		brojprezimenakand++;
	}
	// Analogno se sve radi i za direktora
	pomocniPok=direktor.ime_prezime;
	while(*pomocniPok!=' ')
		pomocniPok++;
	pomocniPok++;
	if (brojrijecidir==3) {
		while (*pomocniPok!=' ')
			pomocniPok++;
		pomocniPok++;
	}
	while(*pomocniPok!='-' && *pomocniPok!='\0')
		*klizeciPrvogPreziDir++=*pomocniPok++;
	*klizeciPrvogPreziDir='\0';
	if(*pomocniPok=='-') {
		pomocniPok++;
		while(*pomocniPok!='\0')
			*klizeciDrugogPreziDir++=*pomocniPok++;
		*klizeciDrugogPreziDir='\0';
		brojprezimenadir++;
	}
	// If statementi koji za određen broj prezimena direktora i kandidata poredi prezimena, nije se moglo jednim if statementom jer za slucajeve jednog prezimena, stringovi drugoprezimekand i drugoprezimedir bi bili neinicijalizovani
	if(brojprezimenadir==1 && brojprezimenakand==1) {
		if(strcmp(pocetakPrvogPreziKand,pocetakPrvogPreziDir)!=0)
			return 1;
	}
	if(brojprezimenadir==1 && brojprezimenakand==2) {
		if(strcmp(pocetakPrvogPreziDir, pocetakPrvogPreziKand)!=0 && strcmp(pocetakPrvogPreziDir, pocetakDrugogPreziKand)!=0)
			return 1;
	}
	if(brojprezimenadir==2 && brojprezimenakand==1) {
		if(strcmp(pocetakPrvogPreziDir, pocetakPrvogPreziKand)!=0 && strcmp(pocetakDrugogPreziDir, pocetakPrvogPreziKand)!=0)
			return 1;
	}
	if(brojprezimenadir==2 && brojprezimenakand==2) {
		if(strcmp(pocetakPrvogPreziDir, pocetakPrvogPreziKand)!=0 && strcmp(pocetakPrvogPreziDir, pocetakDrugogPreziKand)!=0 && strcmp(pocetakDrugogPreziDir, pocetakPrvogPreziKand)!=0 && strcmp(pocetakDrugogPreziDir, pocetakDrugogPreziKand))
			return 1;
	}
	return 0;
}
int razlika_dana(struct Uposlenik kandidat, struct Uposlenik direktor) {
	// Funkcija radi tako sto broji koliko dana je proslo od 00/00/0000 
	int mjeseciUGodini[]={31,28,31,30,31,30,31,31,30,31,30,31};
	int godine, i;
	long brojdanakandidata, brojdanadirektora, razlikadana;
	brojdanakandidata=kandidat.datum_rodjenja.godina*365+kandidat.datum_rodjenja.dan; // Dodavanje godina i dana u mjesecu rodjenja
	for(i=0;i<kandidat.datum_rodjenja.mjesec-1;i++)
		brojdanakandidata+=mjeseciUGodini[i]; // Dodavanje preostalih mjeseci
	godine=kandidat.datum_rodjenja.godina;
	if (kandidat.datum_rodjenja.mjesec<=2)
		godine--; // U slucaju da je rodjen u januaru ili februaru, ne treba racunati prestupnu godinu
	brojdanakandidata+=godine/4-godine/100+godine/400; // Dodavanje prestupnih godina 
	// Analogno se radi  i za direktora
	brojdanadirektora=direktor.datum_rodjenja.godina*365+direktor.datum_rodjenja.dan;
	for (i=0;i<direktor.datum_rodjenja.mjesec-1;i++)
		brojdanadirektora+=mjeseciUGodini[i];
	godine=direktor.datum_rodjenja.godina;
	if (direktor.datum_rodjenja.mjesec<=2)
		godine--;
	brojdanadirektora+=godine/4-godine/100+godine/400;
	razlikadana=brojdanadirektora-brojdanakandidata;
	
	return razlikadana; // Vracamo razliku izmedju dva broja
}

int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana) {
	int i, razlikadana, j;
	for (i=0;i<vel;i++) {
		razlikadana=razlika_dana(kandidati[i], direktor);
		if(razlikadana>broj_dana) { // U slucaju da kandidat ne zadovoljava uslove direktora, prvo se provjerava da li je dio porodice, te onda ako nije se izbacuje iz liste
			if(provjeri_prezime(kandidati[i], direktor)) {
				for (j=i;j<vel-1;j++)
					kandidati[j]=kandidati[j+1];
				vel--;
				i--;
			}
		}
	}
	return vel;
}
int main() {
struct Uposlenik direktor = {"Mujo Mujic", {1, 9, 1980} };
struct Uposlenik kandidati[7] = {
    { "Meho Mehic", { 31, 1, 1980 } },
    { "Pero Peric", { 1, 2, 1980 } },
    { "Sara Sarac", { 3, 10, 1980 } },
    { "Fata Mujic", { 1, 2, 1976 } },
    { "Jozo Jozic", { 2, 10, 1980 } },
    { "Mijo Mijic", { 4, 3, 1979 } },
    { "Suljo Suljc", { 15, 1, 1982 } },
};

int novi_br = suzi_listu(kandidati, 7, direktor, -31);
int i;
printf("Nakon suzenja liste:\n");
for (i=0; i<novi_br; i++)
    printf("%s\n", kandidati[i].ime_prezime);

	return 0;
}
