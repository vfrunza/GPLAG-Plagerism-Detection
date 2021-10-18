#include <stdio.h>
#include <string.h>

struct Datum {
	int dan, mjesec, godina;
};

struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};

char* FunkcijaZaPrezime(char *naziv){
	
	char *s=NULL;
	while(*naziv!='\0'){
		if(*naziv==' '){
			naziv++;
			s=naziv;
			while(*s!='\0' && *s!=' ' && *s!=' ' && *s!='-') s++;
			if(*s=='-' || *s=='\0') return naziv;
		}
		naziv++;
	}
	return naziv;
}

int jeLiPrestupna(int godina)
{
	// vraca 0 ili 1 u zavisnosti je li prestupna
	return (godina % 400 == 0 || (godina % 4 == 0 && godina % 100 != 0));
}

int pretvoriMjesecUDane(struct Datum datum)
{
	int broj = 0;
	// provjera je li prestupna godina
	if(jeLiPrestupna(datum.godina)) ++broj;

	if(datum.mjesec == 2) return 31; //broj proteklih dana
	else if(datum.mjesec == 3) return 59 + broj;
	else if(datum.mjesec == 4) return 90 + broj;
	else if(datum.mjesec == 5) return 120 + broj;
	else if(datum.mjesec == 6) return 151 + broj;
	else if(datum.mjesec == 7) return 181 + broj;
	else if(datum.mjesec == 8) return 212 + broj;
	else if(datum.mjesec == 9) return 243 + broj;
	else if(datum.mjesec == 10) return 273 + broj;
	else if(datum.mjesec == 11) return 304 + broj;
	else if(datum.mjesec == 12) return 334 + broj;

	return broj;
}


// funkcija za vracanje razlike u danima
int dajBrojDane(struct Datum prvi, struct Datum drugi)
{
	int brojDana1 = 0, brojDana2 = 0;
	brojDana1 = prvi.godina/4 - prvi.godina/100 + prvi.godina/100;
	brojDana2 = drugi.godina/4 - drugi.godina/100 + drugi.godina/100;
	if(jeLiPrestupna(drugi.godina)) brojDana2--;
	if(jeLiPrestupna(prvi.godina)) brojDana1--;

	brojDana1 += prvi.godina * 365;
	brojDana1 += pretvoriMjesecUDane(prvi);
	brojDana1 += prvi.dan;

	brojDana2 += drugi.godina * 365;
	brojDana2 += pretvoriMjesecUDane(drugi);
	brojDana2 += drugi.dan;

	return brojDana1 - brojDana2;

}


int PrezimePoredjenje(char *direktor, char *radnik){
	
	char *prviD=FunkcijaZaPrezime(direktor), *prviR=FunkcijaZaPrezime(radnik);
	char *drugiD=prviD, *drugiR=prviR;
	char *temp1= NULL, *temp2=NULL;
	
	while(*drugiD!='\0' && *drugiD!='-'){
		drugiD++;
	}
	
	if(*drugiD=='-'){
		temp1=drugiD;
		while(*temp1!='\0') temp1++;
	}
	
	while(*drugiR!='\0' && *drugiR!='-'){
		drugiR++;
	}
	
	if(*drugiR!='\0' && *drugiR!='-') {
		temp2=drugiR;
		while(*temp2!='\0') temp2++;
	}
	
	
	if(strncmp(prviD,prviR, drugiD-prviD)==0 && drugiD-prviD==drugiR-prviR) return 1;
	
	return 0;
	
}



int suzi_listu(struct Uposlenik *kandidati, int vel, struct Uposlenik direktor, int broj_dana)
{
	int i, j;

	for(i=0; i < vel; ++i) {
		if((dajBrojDane(direktor.datum_rodjenja, kandidati[i].datum_rodjenja)> broj_dana && !PrezimePoredjenje(direktor.ime_prezime, kandidati[i].ime_prezime))
		        || (dajBrojDane(direktor.datum_rodjenja, kandidati[i].datum_rodjenja) == 0 && strcmp(direktor.ime_prezime, kandidati[i].ime_prezime) == 0)) {

			for(j = i+1; j< vel; ++j) kandidati[j-1] = kandidati[j];
			vel--;
			--i;
		}

	}
	int h;
	for(i =0; i < vel; ++i) {
		for(j = i+1; j< vel; j++) {
			if(dajBrojDane(kandidati[i].datum_rodjenja, kandidati[j].datum_rodjenja) == 0 &&
			        strcmp(kandidati[i].ime_prezime, kandidati[j].ime_prezime) == 0) {

				for(h = j+1; h < vel; ++h) {
					kandidati[h-1] = kandidati[h];
				}
				--j;
				--vel;
			}
		}
	}

	return vel;

}


int main()
{
	/* AT11: Varijante sa dva prezimena (samo direktor) */
	struct Uposlenik direktor = {"Mujo Mujic-Peric", {3, 3, 1992} };
	struct Uposlenik kandidati[7] = {
		{ "Meho Mehic", { 31, 1, 1990 } },
		{ "Pero Peric", { 1, 2, 1990 } },
		{ "Sara Sarac", { 2, 2, 1990 } },
		{ "Fata Mujic", { 1, 2, 1986 } },
		{ "Jozo Jozic", { 1, 10, 1990 } },
		{ "Mijo Mijic", { 4, 3, 1989 } },
		{ "Suljo Suljic", { 31, 12, 1991 } },
	//	{"Ilma Peric-Cizmic", {25,8,1997}}
	};

	int novi_br = suzi_listu(kandidati, 7, direktor, 3);
	int i;
	printf("Nakon suzenja liste:\n");
	for (i=0; i<novi_br; i++)
		printf("%s\n", kandidati[i].ime_prezime);
	return 0;
}
