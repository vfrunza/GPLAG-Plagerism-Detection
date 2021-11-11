#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define KAPACITET 200

struct Vrijeme {
	
	int sati, minute, sekunde;
};

struct Cas {
	char predmet[10];
	int dan_u_sedmici;
	struct Vrijeme pocetak, kraj;
};

/*Prototipi potrebnih funkcija*/
int ucitaj_datoteku(struct Cas raspored[]);
int zapisi_datoteku(struct Cas raspored[], int broj_casova);
int dodaj_cas(struct Cas raspored[], int broj_casova, const char* predmet, int trajanje);
int preklapanje(struct Cas raspored[], int broj_casova, struct Cas cas);
void ispis_rasporeda(struct Cas raspored[], int broj_casova);
void ispisi_dan(struct Cas raspored[], int broj_casova, int dan);
void promijeni_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj, struct Cas promjena);
void obrisi_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj);

/*Dodatne funkcija*/
int dodavanje_casa(struct Cas raspored[], int brCasova);
void promjena_casa(struct Cas raspored[], int brCasova);
int brisanje_casa(struct Cas raspored[], int brCasova);
int ima_rupa_za_dan(struct Cas raspored[], int vel, int dan, int rupa, struct Vrijeme* kada);
void KopirajString(const char *iz, char *u);
int preklapaju_se_vremena(struct Vrijeme a, struct Vrijeme b, struct Vrijeme x, struct Vrijeme y);
int prije(struct Vrijeme a, struct Vrijeme b);
int poslije(struct Vrijeme a, struct Vrijeme b);

int main() {
	struct Cas raspored[KAPACITET];
	int brCasova;
	int n;
	
	brCasova = ucitaj_datoteku(raspored);
	for(;;) {
		printf("1) Ispis rasporeda\n");
		printf("2) Dodavanje casa\n");
		printf("3) Promjena casa\n");
		printf("4) Brisanje casa\n");
		printf("0) Kraj rada\n");
		printf("Izaberite opciju: ");
	
		if(scanf("%d", &n) == 1) {
		if(n == 0) break;
		if(n == 1) 
		{
			ispis_rasporeda(raspored, brCasova);
		}
		if(n == 2) {
			if(dodavanje_casa(raspored, brCasova)) {
				brCasova++;
			}
		}
		
		if(n == 3) promjena_casa(raspored, brCasova);
		if(n == 4) {
			if(brisanje_casa(raspored, brCasova)) {
				brCasova--;
			}
		}
	}
}
	zapisi_datoteku(raspored, brCasova);
	
}


int ucitaj_datoteku(struct Cas raspored[]) {
	struct Cas cas;
	FILE* dat = fopen("raspored.dat", "rb");
	if(!dat) return 0;
	int broj_ucitanih = fread(raspored, sizeof(cas), KAPACITET, dat);
	fclose(dat);
	
	return broj_ucitanih;
}

int zapisi_datoteku(struct Cas raspored[], int broj_casova) {
	struct Cas cas;
	int broj_zapisanih;
	FILE* dat = fopen("raspored.dat", "wb");
	if(!dat) return 0;
	broj_zapisanih = fwrite(raspored, sizeof(cas), broj_casova, dat);
	
	fclose(dat);
	
	if(broj_zapisanih == broj_casova) {
		return 1;
	} else {
		return 0;
	}
}

int dodaj_cas(struct Cas raspored[], int broj_casova, const char* predmet, int trajanje) {
	int i;
	for(i = 0; i <= 6; ++i) {
		struct Vrijeme kada;
		int ima = ima_rupa_za_dan(raspored, broj_casova, i, trajanje, &kada);
		if(ima) {
			struct Cas noviCas;
			struct Vrijeme pocetak = kada;
			struct Vrijeme kraj;
			
			kraj.sati = pocetak.sati + trajanje;
			kraj.minute = pocetak.minute;
			kraj.sekunde = pocetak.sekunde;
			
			noviCas.kraj = kraj;
			noviCas.pocetak = pocetak;
			noviCas.dan_u_sedmici = i;
			
			KopirajString(predmet, noviCas.predmet);
			raspored[broj_casova] = noviCas;
			
			return 1;
		}
	}
	
	return 0;
}

void KopirajString(const char* iz, char* u) {
	int i = 0;
	while(i < 9 && *iz != '\0') {
		*u = *iz;
		u++;
		iz++;
		i++;
	}
	*u = '\0';
}

int ima_rupa_za_dan(struct Cas raspored[], int vel, int dan, int rupa, struct Vrijeme* kada) {
	struct Vrijeme pocetak;
	int i;
	pocetak.sati = 9;
	pocetak.minute = 0;
	pocetak.sekunde = 0;
	
	for(i = 0; i < vel; ++i) {
		if(raspored[i].dan_u_sedmici == dan) {
			struct Vrijeme zavrsetak;
			zavrsetak.sati = pocetak.sati + rupa;
			zavrsetak.minute = pocetak.minute;
			zavrsetak.sekunde = pocetak.sekunde;
			
			if(preklapaju_se_vremena(pocetak, zavrsetak, raspored[i].pocetak, raspored[i].kraj)) {
				pocetak.sekunde++;
				if(pocetak.sekunde == 60) {
					pocetak.minute++;
					pocetak.sekunde = 0;
				}
				if(pocetak.minute == 60) {
					pocetak.sati++;
					pocetak.minute = 0;
				}
				
				if(pocetak.sati >= 19 - rupa) return 0;
				i = -1;
			}
		}
	}
	
	if(pocetak.sati + rupa > 19) return 0;
	if(pocetak.sati + rupa == 19) {
		if(pocetak.minute != 0) return 0;
	} 
	
	*kada = pocetak;
	return 1;
}

int preklapaju_se_vremena(struct Vrijeme pocetak1, struct Vrijeme kraj1, struct Vrijeme pocetak2,struct Vrijeme kraj2) {
	if(pocetak1.sati > pocetak2.sati && pocetak1.sati < kraj2.sati) return 1;
	if(kraj1.sati > pocetak2.sati && kraj1.sati < kraj2.sati) return 1;
	if(pocetak2.sati > pocetak1.sati && pocetak2.sati < kraj1.sati) return 1;
	if(kraj2.sati > pocetak1.sati && kraj2.sati < kraj1.sati) return 1;
	
	if(pocetak1.sati == pocetak2.sati && kraj1.minute == kraj2.minute) {
		if(pocetak1.minute > pocetak2.minute && pocetak1.minute < kraj2.minute) return 1;
		if(kraj1.minute > pocetak2.minute && kraj1.minute < kraj2.minute) return 1;
		
		if(pocetak2.minute > pocetak1.minute && pocetak2.minute < kraj1.minute) return 1;
		if(kraj2.minute > pocetak1.minute && kraj2.minute < kraj1.minute) return 1;
	}
	if(pocetak1.sati == pocetak2.sati && kraj1.sati == kraj2.sati) {
		if(pocetak1.minute < pocetak2.minute) return 1;
		if(pocetak1.minute == pocetak2.minute && kraj1.minute < kraj2.minute) return 1;
	}
	if(kraj1.sati == pocetak2.sati) {
		if(kraj1.minute > pocetak2.minute) return 1;
	}
	if(pocetak1.sati == pocetak2.sati && pocetak1.minute == pocetak2.minute && kraj1.sati == kraj2.sati && kraj1.minute == kraj2.minute) return 1;
	
	return 0;
}

int preklapanje(struct Cas raspored[], int broj_casova, struct Cas cas) {
	int i;
	for(i = 0; i < broj_casova; ++i) {
		if(raspored[i].dan_u_sedmici == cas.dan_u_sedmici) {
			if(preklapaju_se_vremena(raspored[i].pocetak, raspored[i].kraj, cas.pocetak, cas.kraj)) {
				return 1;
			}
		}
	}
	
	return 0;
}

void ispis_rasporeda(struct Cas raspored[], int broj_casova) {
	int trenutni_dan;
	int brIspisanihUOvomRedu = 0;
	int brIspisanih = 0;
	struct Vrijeme min = raspored[0].pocetak;
	int i;
	
	printf("      "); /*6 razmaka*/
	printf("PON       ");
	printf("UTO       ");
	printf("SRI       ");
	printf("CET       ");
	printf("PET       ");
	printf("SUB       \n");
	
	if(broj_casova == 0) return ;
	for(i = 0; i < broj_casova; ++i) {
		if(prije(raspored[i].pocetak, min)) min = raspored[i].pocetak;
	}
	
	while(1) {
		int ima_jos = 0;
		for(trenutni_dan = 0; trenutni_dan < 6; ++trenutni_dan) {
			int ima_za_ovaj_dan = 0;
			struct Cas cas_za_ovaj_dan;
			for(i = 0; i < broj_casova; ++i) {
				if(raspored[i].dan_u_sedmici == trenutni_dan && preklapaju_se_vremena(raspored[i].pocetak, raspored[i].kraj, min, min)) {
					if(ima_za_ovaj_dan == 0) {
						ima_za_ovaj_dan = 1;
						cas_za_ovaj_dan = raspored[i];
					} else {
						if(prije(raspored[i].pocetak, cas_za_ovaj_dan.pocetak)) cas_za_ovaj_dan = raspored[i];
					}
				}
			}
			if(ima_za_ovaj_dan) {
				printf("%10s", cas_za_ovaj_dan.predmet);
				brIspisanihUOvomRedu++;
				brIspisanih++;
			} else {
				printf("          ");
			}
		}
		if(brIspisanihUOvomRedu != 0) 
			printf("\n");
		
		brIspisanihUOvomRedu = 0;
		min.sati++;
		for(i = 0; i < broj_casova; ++i) 
			if(prije(raspored[i].pocetak, min)) ima_jos = 1;
			
			if(!ima_jos) break;
	}
}

int prije(struct Vrijeme a, struct Vrijeme b) {
	if(a.sati < b.sati) return 1;
	if(a.sati > b.sati) return 0;
	
	if(a.minute < b.minute) return 1;
	return 0;
}

int poslije(struct Vrijeme a, struct Vrijeme b) {
	if(prije(a,b)) return 0;
	return 1;
}

void ispisi_dan(struct Cas raspored[], int broj_casova, int dan) {
	int pom = 1, i;
	printf("Uneseni su casovi: \n");
	for(i = 0; i < broj_casova; ++i) {
		if(raspored[i].dan_u_sedmici == dan) {
			printf("%d) %s (%.2d:%.2d-%.2d:%.2d)\n", pom, raspored[i].predmet, raspored[i].pocetak.sati, raspored[i].pocetak.minute, raspored[i].kraj.sati, raspored[i].kraj.minute);
			pom++;
		}
	}
}

void promijeni_cas(struct Cas raspored[],  int broj_casova, int dan, int redni_broj, struct Cas promjena) {
	int brojac = 0;
	int i;
	for(i = 0; i < broj_casova; ++i) {
		if(raspored[i].dan_u_sedmici == dan) brojac++;
		
		if(brojac == redni_broj) {
			raspored[i] = promjena;
			break;
		}
	}
}

void obrisi_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj) {
	int brojac = 0;
	int i, j;
	for(i = 0; i < broj_casova; ++i) {
		if(raspored[i].dan_u_sedmici == dan) brojac++;
		
		if(brojac == redni_broj) {
			for(j = i; j < broj_casova - 1; ++j) {
				raspored[j] = raspored[j + 1];
			}
			break;
		}
	}
}

/*funkcije iz menija*/
int dodavanje_casa(struct Cas raspored[], int brCasova) {
	char c;
	int i = 0, br=0;
	char ime[10];
	
	printf("Unesite naziv predmeta: ");
	scanf("%c", &c);
	while(i < 9) {
		if(scanf("%c", &c) == 0) break;
		if(c == '\n') break;
		ime[i++] = c;
	}
	if(i == 9) {
		while(1) {
			scanf("%c", &c);
			if(c == '\n') break;
		}
	}
	ime[i] = '\0';
	
	printf("Unesite broj casova: ");
	scanf("%d", &br);
	if(!dodaj_cas(raspored, brCasova, ime, br)) {
		printf("Nema dovoljno mjesta u rasporedu za %d casova.\n", br);
		return 0;
	}
	return 1;
}

void promjena_casa(struct Cas raspored[], int brCasova) {
	int dan;
	int imaPreklapanja;
	int izbor;
	int i = 0;
	char c;
	struct Vrijeme pocetak, kraj;
	struct Cas izmjena;
	
	printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
	scanf("%d", &dan);
	/*printf("Uneseni su casovi: \n");*/
	ispisi_dan(raspored, brCasova, dan-1);
	
	printf("Izaberite koji cas zelite promijeniti: ");

	scanf("%d", &izbor);
	if(izbor < 0 || izbor > brCasova) {
		printf("Neispravan redni broj casa.\n");
		return;
	}
	char ime[10];
	printf("Naziv predmeta: ");
	scanf("%c", &c);
	while(i < 9) {
		if(scanf("%c", &c) == 0) break;
		if(c == '\n') break;
		ime[i++] = c;
	}
	if(i == 9) {
		while(1) {
			scanf("%c", &c);
			if(c == '\n') break;
		}
	}
	ime[i] = '\0';
	printf("Vrijeme pocetka: ");
	scanf("%d", &pocetak.sati);
	scanf("%c", &c);
	scanf("%d", &pocetak.minute);
	
	printf("Vrijeme zavrsetka: ");
	scanf("%d", &kraj.sati);
	scanf("%c", &c);
	scanf("%d", &kraj.minute);
	
	izmjena.pocetak = pocetak;
	izmjena.kraj = kraj;
	izmjena.dan_u_sedmici = dan;
	
	imaPreklapanja = preklapanje(raspored, brCasova, izmjena);
	if(imaPreklapanja) {
		printf("Promjena nije moguca jer dovodi do preklapanja");
		return;
	}
}

int brisanje_casa(struct Cas raspored[], int brCasova) {
	int dan;
	int izbor;
	
	printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
	scanf("%d", &dan);
	/*printf("Uneseni su casovi: \n");*/
	ispisi_dan(raspored, brCasova, dan-1);
	printf("Izaberite koji cas zelite obrisati: ");
	scanf("%d", &izbor);
	obrisi_cas(raspored, brCasova, dan, izbor);
}