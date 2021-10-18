#include <stdio.h>

struct Datum { int dan, mjesec, godina };
struct Uposlenik {
		char ime_prezime[50];
		struct Datum datum_rodjenja;
};

int izracunaj_koliko_je_dana_od_pocetka_godine(int mjesec, int dan, int da_li_je_prestupna){
	
	int brojac = 0;
	int i = 0;
	for(i = 1; i < 13; i++){
		if(i==mjesec) break;
		if(i==2) brojac+=28;
		else if(i==1 || i== 3 || i== 5 || i== 7 || i== 8 || i== 10 || i== 12) brojac+=31;
		else brojac+=30;
	}
	brojac+=dan;
	if(i>2) brojac+=da_li_je_prestupna;
	return brojac;
}
int je_li_godina_prestupna(int godina){
	if((godina%4 == 0 && godina %100 !=0) || godina%400 == 0) return 1;
	return 0;
}
int vrati_broj_dana(struct Datum datum_direktora, struct Datum datum_uposlenika){
	int i;
	//ako je direktor stariji
	//if(datum_direktora.godina > datum_uposlenika.godina || (datum_direktora.godina == datum_uposlenika.godina && datum_direktora.mjesec > datum_uposlenika.mjesec) || (datum_direktora.godina == datum_uposlenika.godina && datum_direktora.mjesec == datum_uposlenika.mjesec && datum_direktora.dan > datum_uposlenika.dan)) return -1;
	
		 
		int danid = izracunaj_koliko_je_dana_od_pocetka_godine(datum_direktora.mjesec, datum_direktora.dan, je_li_godina_prestupna(datum_direktora.godina));
		int daniu = izracunaj_koliko_je_dana_od_pocetka_godine(datum_uposlenika.mjesec, datum_uposlenika.dan, je_li_godina_prestupna(datum_uposlenika.godina));
		for(i = 1700; i < datum_uposlenika.godina; i++){
			daniu+=365;
			if(je_li_godina_prestupna(i) == 1) {
				//printf("%d", i);
				daniu+=1;	
			}
		}
		for(i = 1700; i < datum_direktora.godina; i++){
			danid+=365;
			if(je_li_godina_prestupna(i) == 1) {
				//printf("%d", i);
				danid+=1;	
			}
		}
	
		
	
		return danid - daniu;
	
}
int da_li_je_isto_prezime(char *s1, char *s2){
	char *kraj1=s1;
	char *kraj2=s2;
	char *pomocni1 = s1;
	char *pomocni2 = s2;
	char *cita1;
	char *cita2;
	while(*kraj1 != '\0') {
		kraj1++;
		if(*kraj1 == '-') pomocni1 = kraj1+1;
	}
	while(*kraj2 != '\0') {
		kraj2++;
		if(*kraj2 == '-') pomocni2 = kraj2+1;
	}
	while(*kraj1 != ' ') kraj1--;
	while(*kraj2 != ' ') kraj2--;
	kraj1++;
	kraj2++;
	if(*kraj1 == *kraj2){
		cita1 = kraj1;
		cita2 = kraj2;
		while(*cita1 == *cita2 && *cita1 !='\0' && *cita2 !='\0'){
			cita1++;
			cita2++;
		}
		if((*cita1 == '\0' || *cita1 == '-') &&(*cita2 == '\0' || *cita2 == '-')) return 1;
	}
	if(pomocni2 != s2){
		if(*kraj1 == *pomocni2){
			cita1 = kraj1;
			cita2 = pomocni2;
			while(*cita1 == *cita2 && *cita1 !='\0' && *cita2 !='\0'){
				cita1++;
				cita2++;
			}
			if((*cita1 == '\0' || *cita1 == '-') &&(*cita2 == '\0' || *cita2 == '-')) return 1;
		
		}
	}
	if(pomocni1 != s1){
		
		
		if(*kraj2 == *pomocni1){
			
			cita1 = pomocni1;
			cita2 = kraj2;
			while(*cita1 == *cita2 && *cita1 !='\0' && *cita2 !='\0'){
				cita1++;
				cita2++;
			}
			if((*cita1 == '\0' || *cita1 == '-') &&(*cita2 == '\0' || *cita2 == '-')) return 1;
		
		}
	}
	return 0;
}
int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana){
	int i;	
	int j;
	int k;
	for(i=0; i < vel; i++){
		//printf("%d\n",vrati_broj_dana(direktor.datum_rodjenja,kandidati[i].datum_rodjenja));
		if(vrati_broj_dana(direktor.datum_rodjenja,kandidati[i].datum_rodjenja) > broj_dana){
			if(da_li_je_isto_prezime(direktor.ime_prezime, kandidati[i].ime_prezime) == 0){
				//printf("uslo %s",kandidati[i].ime_prezime);
				k=i;
				for(j=i+1; j < vel; j++){
					kandidati[k] = kandidati[j];
					k++;
				}
				vel--;
				i--;
			}
		}
	}
	return vel;
}
int main() {
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
};

int novi_br = suzi_listu(kandidati, 7, direktor, 3);
int i;
printf("Nakon suzenja liste:\n");
for (i=0; i<novi_br; i++)
    printf("%s\n", kandidati[i].ime_prezime);
	return 0;
}
