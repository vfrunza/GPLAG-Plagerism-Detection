#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Datum { int dan, mjesec, godina; };
struct Uposlenik {char ime_prezime[50]; struct Datum datum_rodjenja;};

	int prestupna(int godina) {
		if ((godina%4==0 && godina%100!=0) || godina%400==0)
		return 1;
		return 0;
	}


int broj_dana_dat(struct Datum datum) {
	
	
	int ukupno=0, i;
	int br_dana[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	
		for (i=1; i<datum.godina; i++)
			ukupno+=365+prestupna(i);
	
		if (prestupna(datum.godina)) br_dana[2]++;
		
		for (i=1; i<datum.mjesec; i++)
		ukupno+=br_dana[i];
		
		ukupno+=datum.dan;
	return ukupno;
}

int Razlika_datuma(struct Datum datum1, struct Datum datum2){
	int razlika=broj_dana_dat(datum1)-broj_dana_dat(datum2);
	return razlika;
}

/*struct Datum Saberi_dane(struct Datum datum, int x){
	int br_dana[12]={31,28,31,30,31,30,31,31,30,31,30,31},i=0;
	int prestupna=0;
	
	if (x>0) {
		for (i=1;i<=x;i++){
			prestupna=0;
			if ((datum.godina%4==0) && (datum.godina%100!=0) && (datum.godina%400==0) && datum.mjesec==2) {
				prestupna=1;
			}
			if (datum.dan<br_dana[datum.mjesec]+prestupna){
				datum.dan=datum.dan+1;
			} else {
				datum.dan=1;
				if (datum.mjesec<12) {
					datum.mjesec=datum.mjesec+1;
				} else {
					datum.mjesec=1;
					datum.godina=datum.godina+1;
				}
				
			}
		}
	}
	return datum;
}*/

char* Daj_Prezime(char* ime_prezime) {
	char* pp=ime_prezime;
	int i=0, duz=0;
	for (i=0; ; i++) {
		if (ime_prezime[i]=='\0') break;
		duz++;
		pp++;
	}
	for (i=duz; ; i--){
		if (ime_prezime[i]==' ') break;
		pp--;
	}
	pp++;
	/*printf("%s",ime_prezime[pocetak]);*/
	return pp;
}

int Nadji_Prezime(const char *s1, const char *s2) {
	const char* poc=s1;
	while (*s1!='\0') {
		const char* p=s1;
		const  char* q=s2;
		while (*p++ == *q++)
			if (*q=='\0' &&
			   (s1 == poc || *(s1-1)==' ') &&
			   (*p== ' ' || *p=='\0')) return 1;
		s1++;
	}
	return 0;
}

int Uporedi_Prezime (const char* s1, const char* s2) {
	while (*s1!='\0' && *s2!= '\0') {
		if (*s1 < *s2) return -1;
		if (*s1 > *s2) return 1;
		s1++;
		s2++;
	}
	if (*s1!='\0') return 1;
	if (*s2!='\0') return -1;
	return 0;
}

int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana) {

	struct Uposlenik* p=kandidati;
	struct Uposlenik temp;
	/*struct Uposlenik Preostali[vel];	*/
		int brojac=0, razlika, duz=0;
		int j=0;
		
		for (brojac=0; brojac<vel; brojac++) {
			
			razlika=Razlika_datuma(direktor.datum_rodjenja,kandidati[brojac].datum_rodjenja);
/*			if (razlika>=0) {
				printf("\n %d",razlika);
			}
			
			else 
			printf("\n %d",razlika);*/
			
			if ((Uporedi_Prezime(Daj_Prezime(direktor.ime_prezime),Daj_Prezime(kandidati[brojac].ime_prezime))==0) || 
			   ((broj_dana>0)&&(razlika<=broj_dana)&&razlika>0) ||
			   ((broj_dana>0)&&razlika<0) ||
			   ((broj_dana<0)&&(abs(razlika)>=abs(broj_dana))&&razlika<0));
			   
			   
			   /*(abs(razlika)>=broj_dana)*/
			   /*((broj_dana<0)&&()razlika>0));*/
			 
			   /*printf("\n %d", razlika);*/

/*				printf("Ostaje \n %s",kandidati[brojac].ime_prezime);}	*/
				else {
						
				for (j=brojac; j<vel-1; j++) {
					kandidati[j]=kandidati[j+1];
				
				}
				vel--;
				brojac--;
				duz++;
				}
			}
		return brojac;
		
}

int main() {
	
	/*printf("Zadaća 5, Zadatak 1");*/
	char podaci[50]="Ana Kovacevic";
	char* prezime_dir;
	char* prezime_kand;
	struct Datum datum1={2,5,2014}, datum2={11,5,2014};
	int i,rezultat;
	int broj_kand=0;
	
	struct Uposlenik direktor = {"Mujo Mujic", {1, 1, 1992} };
	struct Uposlenik kandidati[7] = {
    { "Meho Mehic", { 31, 1, 1990 } },
    { "Pero Peric", { 1, 2, 1990 } },
    { "Sara Sarac", { 2, 2, 1990 } },
    { "Fata Mujicic", { 1, 2, 1986 } },
    { "Jozo Jozic", { 1, 10, 1990 } },
    { "Mijo Mijic", { 4, 3, 1989 } },
    { "Suljo Suljic", { 15, 1, 1992 } },
};
	
/*	prezime_dir=Daj_Prezime(direktor.ime_prezime);
	printf("%s",prezime_dir);

	for (i=0; i<7; i++) {
	prezime_kand=Daj_Prezime(kandidati[i].ime_prezime);
	if (Nadji_Prezime(prezime_dir,prezime_kand)) {
		printf("\n %s", kandidati[i].ime_prezime);
		printf("%d",Nadji_Prezime(prezime_dir,prezime_kand));
	}
	}*/
	

	
	broj_kand=suzi_listu(kandidati,7,direktor,15);
/*	printf("\n %d",broj_kand);*/
	
	printf("Nakon suzenja liste:\n");
	for (i=0; i<broj_kand; i++)
    printf("%s\n", kandidati[i].ime_prezime);


	
	
	return 0;
}
