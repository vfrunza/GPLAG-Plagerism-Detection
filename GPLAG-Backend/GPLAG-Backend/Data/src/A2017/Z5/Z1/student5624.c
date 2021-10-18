#include <stdio.h>

struct Datum{
	int dan,mjesec,godina;
};

struct Uposlenik{
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};

int prestupna_godina(int godina){
	if((godina%4==0 && godina%100!=0) || godina%400==0)
	return 1;
return 0;	
}

int broj_dana(struct Datum datum){
	int ukupan_br=0;
	int i;
	for(i=1;i<datum.godina;i++){
		ukupan_br+=365+prestupna_godina(i);
	}
	
	int br_dana_mjesecu[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	if (prestupna_godina(datum.godina)) br_dana_mjesecu[2]++;
	
	for(i=1;i<datum.mjesec;i++){
		ukupan_br+=br_dana_mjesecu[i];
	}
	ukupan_br+=datum.dan;
	return ukupan_br;
}

int razlika_br_dana(struct Uposlenik kandidat,struct Uposlenik direktor){
	int razlika;
	razlika=broj_dana(direktor.datum_rodjenja) - broj_dana(kandidat.datum_rodjenja);
	return razlika;
	}

char *izdvoji_prezime(char* s){
	char*kraj=s;
	char *prezime;
	while (*kraj!='\0') {
		kraj++;
	}
	kraj++;
	char*poc_prezime=kraj;
	while (*poc_prezime!=' ') {
		poc_prezime--;
	}
	
	poc_prezime++;

	prezime=poc_prezime;
	
	return prezime;
}

int uporedi_stringove(char* kand_prez, char *dir_prez){
	int duzina_kand=0;
	int duzina_dir=0;
	char *kandidatovo=kand_prez;
	char *direktorovo=dir_prez;
	
	while (*kandidatovo!='\0') {
		duzina_kand++;
		kandidatovo++; 
	}

	while (*direktorovo!='\0') {
		direktorovo++;
		duzina_dir++;
	}
	
	if(duzina_kand!=duzina_dir) return 0;
	
	while(duzina_kand>0){
		if(*kand_prez!=*dir_prez) return 0;
		kand_prez++;
		dir_prez++;
		duzina_kand--;
	}

	return 1;
}

int uporedi_po_prezimenu(struct Uposlenik kandidati,struct Uposlenik direktor){
	int rez = 0;
	char *prezime_kandidata;
	char *prezime_direktor;
	int direktor_dva_prez = 0;
	int kandidat_dva_prez = 0;

	char *pomocni_kand;
	char *pomocni_dir;
	
	char *prvo_kandidat;
	char *drugo_kandidat;
	char *prvo_direktor;
	char *drugo_direktor;
	
	char prvo_niz_kand[100];
	char prvo_niz_dir[100];

	int i;

	prezime_kandidata=izdvoji_prezime (kandidati.ime_prezime);
	prezime_direktor=izdvoji_prezime(direktor.ime_prezime);

	pomocni_kand = prezime_kandidata;
	pomocni_dir = prezime_direktor;
	
	while(*pomocni_kand!='\0'){
		if(*pomocni_kand=='-') kandidat_dva_prez = 1;
		pomocni_kand++;
	}
	while(*pomocni_dir!='\0'){
		if(*pomocni_dir=='-') direktor_dva_prez = 1;
		pomocni_dir++;
	}
	
	pomocni_kand = prezime_kandidata;
	pomocni_dir = prezime_direktor;

	if(kandidat_dva_prez == 1){
		int duzina = 0;
		prvo_kandidat = pomocni_kand;
		while(*pomocni_kand!='-'){
			duzina++;
			pomocni_kand++;
		}
		char *pomocni = prvo_niz_kand;
		
		for(i = 0; i < duzina; i++){
			*pomocni = *prvo_kandidat;
			pomocni++;
			prvo_kandidat++;
		}
		*pomocni='\0';
		prvo_kandidat = prvo_niz_kand;
		pomocni_kand++;
		drugo_kandidat = pomocni_kand;
	}else{
		prvo_kandidat = pomocni_kand;
	}
	
	if(direktor_dva_prez == 1){
		int duzina = 0;
		prvo_direktor = pomocni_dir;
		while(*pomocni_dir!='-'){
			duzina++;
			pomocni_dir++;
		}
		char *pomocni = prvo_niz_dir;
		
		for(i = 0; i < duzina; i++){
			*pomocni = *prvo_direktor;
			pomocni++;
			prvo_direktor++;
		}
		*pomocni='\0';
		prvo_direktor = prvo_niz_dir;
		pomocni_dir++;
		drugo_direktor = pomocni_dir;
	}else{
		prvo_direktor = pomocni_dir;
	}
	/*
	
	printf("\n%s\n", prvo_kandidat);
	printf("%s\n", drugo_kandidat);
	printf("%s\n", prvo_direktor);
	printf("%s\n", drugo_direktor);
	
	*/
	
	if(!direktor_dva_prez && !kandidat_dva_prez){
		if(uporedi_stringove(prvo_kandidat,prvo_direktor) == 1){
			rez = 1;
		}
	}else if(!direktor_dva_prez && kandidat_dva_prez){
		if(uporedi_stringove(prvo_kandidat,prvo_direktor) == 1) rez = 1;
		else if(uporedi_stringove(drugo_kandidat,prvo_direktor) == 1) rez = 1;
	}else if(direktor_dva_prez && !kandidat_dva_prez){
		if(uporedi_stringove(prvo_kandidat,prvo_direktor) == 1) rez = 1;
		else if(uporedi_stringove(prvo_kandidat,drugo_direktor) == 1) rez = 1;
	}else if(direktor_dva_prez && kandidat_dva_prez){
		if(uporedi_stringove(prvo_kandidat,prvo_direktor) == 1) rez = 1;
		else if(uporedi_stringove(prvo_kandidat,drugo_direktor) == 1) rez = 1;
		else if(uporedi_stringove(drugo_kandidat,prvo_direktor) == 1) rez = 1;
		else if(uporedi_stringove(drugo_kandidat,drugo_direktor) == 1) rez = 1;
	}
	
	return rez;

}

int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana){
	
	int brojac=0;
	while (brojac<vel) {
		struct Uposlenik* novi_kandidati;
		int i;
		int razlika_u_danima;
		razlika_u_danima=razlika_br_dana(*kandidati,direktor);
		if(uporedi_po_prezimenu(*kandidati, direktor) == 0){
			
			if(razlika_u_danima>0){
				 if(razlika_u_danima>broj_dana){
				 	novi_kandidati=kandidati;
				 	// pomjeranje ostatka niza
				 	for(i=brojac;i<vel-1;i++){
				 		*novi_kandidati=*(novi_kandidati+1);
						 novi_kandidati++;
				 	}
				 	vel--;
				 	//kandidati++;
				 	continue;
				 	
				 }
			}
			 else{
			 	if((razlika_u_danima*(-1)) < broj_dana){
			 		novi_kandidati=kandidati;
			 		// pomjeranje  ostatka niza
			 		for(i = brojac;i<vel-1;i++){
			 			
			 			*novi_kandidati=*(novi_kandidati+1);
			 			novi_kandidati++;
			 		}
			 		vel--;
			 		continue;
			 		
			 	}
			 }
			 
		}
		 
		kandidati++;
		brojac++;
	}
	return vel;	
}


int main() {
	struct Uposlenik direktor={"Mujo Mujic-Peric", {3, 3, 1992} };
	struct Uposlenik kandidati[7]={
		{"Meho Mehic", {31, 1 ,1990} },
		{"Pero Peric", {1, 2, 1990} },
		{"Sara Sarac", {2,2, 1990} },
		{"Fata Mujic", {1, 2, 1986} },//ostaje
		{"Jozo Jozic", {1,10, 1990} },
		{"Mijo Mijic", {4,3,1989} },
		{"Suljo Suljic", {31,12,1991}}
	};
	int i;
	int novi_broj=suzi_listu(kandidati,5,direktor,2);
	printf("Novi broj: %d\n",novi_broj);
	
	//printf("%d\n", uporedi_po_prezimenu(kandidati[5], direktor));
	
	for(i=0;i<novi_broj;i++){
		printf("%s\n", kandidati[i].ime_prezime);
	}
	

	
	return 0;
}
