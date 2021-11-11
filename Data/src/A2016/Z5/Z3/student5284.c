#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KAPACITET 200
#define IZBRISAN 404
#define PROMJENJEN 201

typedef struct Cas Cas;
typedef struct Vrijeme Vrijeme;

int promjenjen = PROMJENJEN;

struct Vrijeme {
	int sati, minute, sekunde;
};

struct Cas {
	char predmet[10];
	int dan_u_sedmici;
	struct Vrijeme pocetak, kraj;
};


// prototipovi funkcija

int ucitaj_datoteku(Cas raspored[]);
int zapisi_datoteku(Cas raspored[], int);
int dodaj_cas(Cas raspored[], int, const char*, int);
int preklapanje(Cas raspored[], int, Cas);
void ispis_rasporeda(Cas raspored[], int);
void ispisi_dan(Cas raspored[], int, int);
void promijeni_cas(Cas raspored[], int, int, int, Cas);
void obrisi_cas(Cas raspored[], int, int, int);

/*unos stringa*/
void unesi(char * s){
	int brojac = 0;
	char * p = s;
	char c = getchar();
	while(c != '\n'){
		if(brojac < 9) {
			*s = c;
			s++;
		}
		c = getchar();
		brojac++;
	}
	*s = '\0';
	if(strlen(p) > 10) while(getchar() != '\n');
}

/* Unos vremena */

Vrijeme unos_vremena();

/*Izmjena casa*/

void izmijeniCas(Cas *cas, char *naziv, int pSati, int pMinute, int pSekunde, int kSati, int kMinute, int kSekunde) {
	!naziv ?(memset(cas->predmet, 0,0), cas->dan_u_sedmici=IZBRISAN) : strcpy(cas->predmet, naziv);
	cas->pocetak.sati=pSati;
	cas->pocetak.minute=pMinute;
	cas->pocetak.sekunde=pSekunde;
	cas->kraj.sati=kSati;
	cas->kraj.minute=kMinute;
	cas->kraj.sekunde=kSekunde;
}

/* Glavni meni */
void meni(Cas raspored[], int broj_casova){
	int izbor, temp, dan;
	char naziv_predmeta[10];
	int broj_casova_za_predmet;
	Cas cas;
	while(1){
		printf("1) Ispis rasporeda\n");
		printf("2) Dodavanje casa\n");
		printf("3) Promjena casa\n");
		printf("4) Brisanje casa\n");
		printf("0) Kraj rada\n");
		printf("Izaberite opciju: ");
		scanf("%d", &izbor);
		switch(izbor){
			case 1:
				ispis_rasporeda(raspored, broj_casova);
				break;
			case 2:
				while(getchar() != '\n');
				printf("Unesite naziv predmeta: ");
				unesi(naziv_predmeta);
			
				printf("Unesite broj casova: ");
				scanf("%d", &broj_casova_za_predmet);
				temp = dodaj_cas(raspored, broj_casova, naziv_predmeta, broj_casova_za_predmet);
				if(temp) broj_casova++;
				else if(!temp) printf("Nema dovoljno mjesta u rasporedu za %d casova.\n", broj_casova_za_predmet);
				/* Dodati uslov ako nije unesen cas */
				break;
			case 3:
				while(1){
					printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
					scanf("%d", &dan);
					ispisi_dan(raspored, broj_casova, dan);
					printf("Izaberite koji cas zelite promijeniti: ");
					scanf("%d", &temp);
					if(temp > broj_casova + 1){
						printf("Neispravan redni broj casa.\n");
						break;
					}
					while(getchar() != '\n');
					printf("Naziv predmeta: ");
					unesi(cas.predmet);
					printf("Vrijeme pocetka: ");
					cas.pocetak = unos_vremena();
					printf("Vrijeme zavrsetka: ");
					cas.kraj = unos_vremena();
					cas.dan_u_sedmici = dan;
					promijeni_cas(raspored, broj_casova, dan, temp, cas);
					if(promjenjen == PROMJENJEN) break;
					else printf("Promjena nije moguca jer dovodi do preklapanja\n");
				}
				break;
			case 4:
			printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
			scanf("%d", &dan);
			ispisi_dan(raspored, broj_casova, dan);
			printf("Izaberite koji cas zelite obrisati: ");
			scanf("%d", &temp);
			if(temp>broj_casova+1) {
				printf("Neispravan redni broj casa.\n");
				break;
			}
			obrisi_cas(raspored, broj_casova, dan, temp);
			printf("Cas obrisan\n");
			broj_casova--;
			break;
			case 0: 
				zapisi_datoteku(raspored, broj_casova);
				return;
		}
	}
}


int main() {
	Cas raspored[KAPACITET];
	int broj_casova = ucitaj_datoteku(raspored);
	meni(raspored, broj_casova);
	return 0;
}


Vrijeme unos_vremena(){
	char vakat[7];
	char * pokNaVakat = vakat;
	Vrijeme vrijeme;
	unesi(vakat);
	vrijeme.sati = 0;
	vrijeme.minute = 0;
	vrijeme.sekunde = 0;
	if(*pokNaVakat == '0') pokNaVakat++; /* izbjegavamo slucaj da je napisano 0x:yy */
	while(*pokNaVakat != ':'){
		vrijeme.sati += *pokNaVakat - '0';
		vrijeme.sati *= 10;
		pokNaVakat++;
	}
	vrijeme.sati /= 10; /* rjesavamo se viska nule */
	pokNaVakat++; /* pokazivac je sad na dvotacki, pomjeramo ga na sljedecu cifru/minute */
	if(*pokNaVakat == '0') pokNaVakat++; /* izbjegavamo slucaj da je napisano xx:0y */
	while(*pokNaVakat != '\0'){
		vrijeme.minute += *pokNaVakat - '0';
		vrijeme.minute *= 10;
		pokNaVakat++;
	}
	vrijeme.minute /= 10; /* rjesavamo se viska nule */
	return vrijeme;
}

int ucitaj_datoteku(Cas raspored[]) {
	/*dodaj slucajeve za greske*/
	FILE *ulazna=fopen("raspored.dat", "rb");
	int rezultat;
	if(ulazna == NULL) rezultat = 0;
	else rezultat=(int)fread(raspored, sizeof(Cas), KAPACITET, ulazna);
	if(ulazna != NULL) fclose(ulazna);
	return rezultat;
}

int zapisi_datoteku(Cas raspored[], int broj_casova){
	/*dodaj slucajeve za greske*/
	FILE *izlaz=fopen("raspored.dat", "wb");
	fwrite(raspored ,sizeof(Cas), broj_casova, izlaz);
	fclose(izlaz);
	return 1;
}

int dodaj_cas(Cas raspored[], int broj_casova, const char* predmet, int trajanje){
	if(broj_casova>200) return 0;
	int i,k,imaMjesta=0,dan=1,pocetak=9,kraj=pocetak+trajanje;
	Cas cas;
	for(i=1;i<=6;i++) {
		dan=i;
		for(k=9; k<=19;k++) {
			if(k + trajanje > 19){
				imaMjesta = 0;
				break;
			}
			izmijeniCas(&cas, predmet, k, 0, 0, k+trajanje, 0, 0);
			cas.dan_u_sedmici=dan;
			if(preklapanje(raspored, broj_casova, cas)) {
				imaMjesta=0;
			}
			else {
				imaMjesta=1;
				break;
			}
		}
		if(imaMjesta) break;
	}
	if(cas.kraj.sati == 19 && cas.kraj.minute > 0) imaMjesta = 0;
	if(imaMjesta) 
		raspored[broj_casova++]=cas;
	return imaMjesta;
}

int preklapanje(Cas raspored[], int broj_casova, Cas cas){
	int i, preklapa=0;
	for(i=0; i<broj_casova; i++) {
		if(cas.dan_u_sedmici==raspored[i].dan_u_sedmici) {
			if(cas.pocetak.sati <= raspored[i].kraj.sati) {
				if(cas.pocetak.sati < raspored[i].kraj.sati){
					preklapa = 1;
					break;
				}
			}
			else if(cas.kraj.sati >= raspored[i].pocetak.sati && cas.pocetak.sati<raspored[i].kraj.sati) {
				if(cas.kraj.sati == raspored[i].pocetak.sati){
					if(cas.kraj.minute >= raspored[i].pocetak.minute){
						preklapa = 1;
						break;
					}
				}
				else{
					preklapa=1;
					break;
				}
			}
		}
	}
	return preklapa;
}

void ispis_rasporeda(Cas raspored[], int broj_casova){
	int i,j,k,ispisan,ispisanoVrijeme, p;
	char broj[10];
	printf("\n%7.0s%-10s%-10s%-10s%-10s%-10sSUB\n", "" ,"PON", "UTO", "SRI", "CET", "PET");
	for(i=0;i<=23; i++) {
		ispisanoVrijeme = 0;
		for(j = 0; j < broj_casova; j++){
			if(i >= raspored[j].pocetak.sati && i < raspored[j].kraj.sati){
				sprintf(broj, "%d", i);
				printf(i < 10 ? "%s:00   " : "%s:00  ", broj);
				ispisanoVrijeme = 1;
				break;
			}
		}
		for(j=1;j<=6;j++) {
			ispisan=0;
			for(k=0; k<broj_casova; k++) {
				if(raspored[k].dan_u_sedmici==j && i>=raspored[k].pocetak.sati && i <= raspored[k].kraj.sati) {
					if(i == raspored[k].kraj.sati && raspored[k].kraj.minute > 0){
						if(!ispisanoVrijeme){
							sprintf(broj, "%d", i);
							printf(i < 10 ? "%s:00   " : "%s:00  ", broj);
							ispisanoVrijeme = 1;
							for(p = 1; p < j; p++) printf("%-10s", "");
						}
						printf("%-10s", raspored[k].predmet);
					}
					else if(i < raspored[k].kraj.sati) printf("%-10s", raspored[k].predmet);
					ispisan=1;
				}
			}
			if(!ispisan && ispisanoVrijeme) printf("%-10s", "");
		}
		if(ispisanoVrijeme) printf("\n");
	}	    
}

void ispisi_dan(Cas raspored[], int broj_casova, int dan){
	int i,j, brojacCasa=1;
	printf("Uneseni su casovi: \n");
		for(j=0; j<broj_casova; j++) {
			if(raspored[j].dan_u_sedmici==dan) {
				printf("%d) %s (%02d:%02d-%02d:%02d)\n", brojacCasa,raspored[j].predmet,raspored[j].pocetak.sati,raspored[j].pocetak.minute,raspored[j].kraj.sati,raspored[j].kraj.minute);
				brojacCasa++;
			}
		}
}

void promijeni_cas(Cas raspored[], int broj_casova, int dan, int redni_broj, Cas cas){
	promjenjen = 0;
	int brojacCasa=0, brojacCasa2, preklapa;
	int i,j;
	for(j=0;j<broj_casova;j++) {
		if(raspored[j].dan_u_sedmici==dan) {
			brojacCasa++;
			if(brojacCasa==redni_broj) {
				preklapa = 0;
				brojacCasa2 = 0;
				for(i=0; i<broj_casova; i++) {
					if(cas.dan_u_sedmici==raspored[i].dan_u_sedmici) {
						brojacCasa2++;
						if(brojacCasa2 == brojacCasa) continue;
						if(cas.pocetak.sati > raspored[i].pocetak.sati && cas.pocetak.sati < raspored[i].kraj.sati) {
							preklapa=1;
							break;
						}
						else if(cas.kraj.sati>=raspored[i].pocetak.sati && cas.pocetak.sati<raspored[i].kraj.sati) {
							if(cas.kraj.sati == raspored[i].pocetak.sati){
								if(cas.kraj.minute >= raspored[i].pocetak.minute){
									preklapa = 1;
									break;
								}
							}
							else{
								preklapa=1;
								break;
							}
						}
					}
				}
				if(!preklapa){
					izmijeniCas(&raspored[j], cas.predmet, cas.pocetak.sati, cas.pocetak.minute, 0, cas.kraj.sati, cas.kraj.minute, 0);
					promjenjen = PROMJENJEN;
					break;
				}
				
			}
		}
	}
}

void obrisi_cas(Cas raspored[], int broj_casova, int dan, int redni_broj){
	int brojacCasa=0;
	int j,i;
		for(j=0;j<broj_casova;j++) {
			if(raspored[j].dan_u_sedmici==dan) {
				brojacCasa++;
				if(brojacCasa==redni_broj) {
					for(i = j; i < broj_casova - 1; i++){
						izmijeniCas(&raspored[i], raspored[i+1].predmet, raspored[i+1].pocetak.sati, raspored[i+1].pocetak.minute, 0,
										raspored[i+1].kraj.sati, raspored[i+1].kraj.minute, 0);
					}
					break;
				}
			}
		}
}