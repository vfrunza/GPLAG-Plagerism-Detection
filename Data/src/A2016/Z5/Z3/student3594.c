#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define KAPACITET 200

void unesi_string(char niz[]){
	char znak = getchar();
	int i=0;
	if(znak == '\n') znak = getchar();
	
	while(znak != '\n' && i<9){
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i] = '\0';
	while(znak != '\n'){
		znak = getchar();
	}
}

struct Vrijeme{
	int sati, minute, sekunde;	
};

struct Cas{
	char predmet[10];
	int dan_u_sedmici;
	struct Vrijeme pocetak, kraj;
};

int preklapanje(struct Cas raspored[], int broj_casova, struct Cas cas){
	int i;
	
	for(i=0; i<broj_casova; i++){
		if(raspored[i].dan_u_sedmici == cas.dan_u_sedmici){
			if ((cas.pocetak.sati  < raspored[i].kraj.sati || cas.pocetak.sati > raspored[i].kraj.sati)) {
				return 1;
			}
		}
	}
	return 0;
}

int ucitaj_datoteku(struct Cas raspored []){
	
	int ucitano;
	
	FILE* ulaz = fopen("raspored.dat", "rb");
	
	
			if(ulaz == NULL){
			
				return 0;
			}
	ucitano = fread(raspored, sizeof(struct Cas), KAPACITET, ulaz);
		
	fclose(ulaz);
	
	return ucitano;
}

int zapisi_datoteku(struct Cas raspored[], int broj_casova){
	
	int zapisano;
	
	FILE* izlaz = fopen("raspored.dat", "wb");
		
		if(izlaz == NULL) {
			return 0;
		}
		zapisano = fwrite(raspored, sizeof(struct Cas), broj_casova, izlaz);
		
		fclose(izlaz);
		
		if(zapisano > 0) return 1;
		
		return zapisano;
}

void promijeni_cas(struct Cas raspored[], int broj_casova, int dan,  int redni_broj, struct Cas promjena){
	
	int i;
	
	for(i=0; i<broj_casova; i++){
		if(raspored[i].dan_u_sedmici == dan){
			strcpy(raspored[i].predmet, promjena.predmet);
			raspored[i].pocetak.sati = promjena.pocetak.sati;
			raspored[i].pocetak.minute = promjena.pocetak.minute;
			raspored[i].pocetak.sekunde = promjena.pocetak.sekunde;
			raspored[i].kraj.sati = promjena.kraj.sati;
			raspored[i].kraj.minute = promjena.kraj.minute;
			raspored[i].kraj.sekunde = promjena.kraj.sekunde;
			break;
			raspored[i] = raspored[i+1];
		}
	}
}

void ispisi_dan(struct Cas raspored[], int broj_casova, int dan){
	int i, broj=1;
	printf("Uneseni su casovi: \n");
	
		for(i=0; i<broj_casova; i++){
			if(raspored[i].dan_u_sedmici == dan){
				
					printf("%d) %s (", broj, raspored[i].predmet);
					
					if(raspored[i].pocetak.sati <= 9)
						printf("0");
					printf("%d:", raspored[i].pocetak.sati);
				
					if(raspored[i].pocetak.minute <= 9)
						printf("0");
					printf("%d-", raspored[i].pocetak.minute);
				
					if(raspored[i].kraj.sati <= 9)
						printf("0");
					printf("%d:", raspored[i].kraj.sati );
				
					if(raspored[i].kraj.minute <= 9)
						printf("0");
						
					printf("%d)\n", raspored[i].kraj.minute);
				broj++;
			}
		}
}

int dodaj_cas(struct Cas raspored[], int broj_casova, const char* predmet, int trajanje){
	int i, j, k;
	
		for(i=1; i<6; i++){
			for(j=9; j<20; j++){
				for(k=0; k<broj_casova; k++){
					
					if(raspored[k].dan_u_sedmici == i){
						j += raspored[k].kraj.sati - raspored[k].pocetak.sati;
					}
				}
					if(j+ trajanje < 20){
					strcpy(raspored[k].predmet, predmet);
					raspored[k].dan_u_sedmici = i;
					raspored[k].pocetak.sati = j;
					raspored[k].kraj.sati = j + trajanje;
					raspored[k].pocetak.minute = 0;
					raspored[k].pocetak.sekunde = 0;
					return 1;
				}	
			}
		}
	
	return 0;
}

void obrisi_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj){
	int i, zadnji = broj_casova-1;
	
		for(i=0; i<broj_casova; i++){
			if(raspored[i].dan_u_sedmici == dan && redni_broj == i+1){
				strcpy(raspored[i].predmet, raspored[zadnji].predmet);
				raspored[i].dan_u_sedmici = raspored[zadnji].dan_u_sedmici;
				raspored[i].pocetak.sati = raspored[zadnji].pocetak.sati;
				raspored[i].pocetak.minute = raspored[zadnji].pocetak.minute;
				raspored[i].pocetak.sekunde = raspored[zadnji].pocetak.sekunde;
				raspored[i].kraj.sati = raspored[zadnji].kraj.sati;
				raspored[i].kraj.minute = raspored[zadnji].kraj.minute;
				raspored[i].kraj.sekunde = raspored[zadnji].kraj.sekunde;
			}
		}
}

void ispis_rasporeda(struct Cas raspored[], int broj_casova){

	int i, j, k;
	int max = raspored[0].kraj.sati;
	int min = raspored[0].kraj.sati;
	int indeks = 0;
	if (broj_casova==0){
		printf("\n       PON       UTO       SRI       CET       PET       SUB          \n");
	}
	else{
		for(i=0; i<broj_casova; i++){
			if(raspored[i].kraj.sati > max){
				max = raspored[i].kraj.sati;
				indeks = i;
			}
		}
		
		
		
		for(i=0; i<broj_casova; i++){
			if(raspored[i].pocetak.sati < min){
				min = raspored[i].pocetak.sati;
			}
		}
			
		printf("\n       PON       UTO       SRI       CET       PET       SUB          \n");
		for(i=min; i<=max; i++){
			
			if(i >= 10){
				printf("%d:00  ", i);
			}
			else{
				printf("%d:00   ", i);
			}
			
			for(j=1; j<7; j++){
				for(k=0; k<broj_casova; k++){	
					
					if(raspored[k].kraj.sati >= i && raspored[k].pocetak.sati <= i && raspored[k].dan_u_sedmici == j){
						printf("%-10s", raspored[k].predmet);
						break;
					}
					if(k == broj_casova){
						printf("          ");
					}
				}
			}
			printf("\n");
		}
	}
	
	
}

struct Cas unesi_cas(const char* predmet, int dan, struct Vrijeme pocetak, struct Vrijeme kraj){
	
	struct Cas x;
	
	strcpy(x.predmet, predmet);
	x.dan_u_sedmici = dan;
	
	x.pocetak.sati = pocetak.sati;
	x.pocetak.minute = pocetak.minute;
	x.pocetak.sekunde = pocetak.sekunde;
	
	x.kraj.sati	= kraj.sati;
	x.kraj.minute = kraj.minute; 
	x.kraj.sekunde = kraj.sekunde;
	
	return x;
}

int main() {

	struct Cas raspored[KAPACITET];\
	int meni, broj_casova, dan, mijenjaj, brisi;
	int i=0, suma_casova=0;
	char dvotacka1, dvotacka2;
	char naziv2[30], naziv1[30];
	struct Vrijeme pocetak, kraj;
	struct Cas promjena;
	
	ucitaj_datoteku(raspored);
	
	do{
		
		printf("1) Ispis rasporeda\n2) Dodavanje casa\n3) Promjena casa\n4) Brisanje casa\n0) Kraj rada\n");
		printf("Izaberite opciju: ");
		scanf("%d", &meni);
		
		if(meni == 1){
			ispis_rasporeda(raspored,suma_casova);
		}
		
		if(meni == 2){
			printf("Unesite naziv predmeta: ");
			unesi_string(naziv1);
			printf("Unesite broj casova: ");
			scanf("%d", &broj_casova);
			dodaj_cas(raspored, suma_casova, naziv1, broj_casova);
				if(dodaj_cas(raspored, suma_casova, naziv1, broj_casova) == 0){
					printf("Nema dovoljno mjesta u rasporedu za %d casova.\n", broj_casova);
				}
				else{
					suma_casova++;
				}
		}
		
		if(meni == 3){
			
			printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
			scanf("%d", &dan);
			ispisi_dan(raspored, suma_casova, dan);
			printf("Izaberite koji cas zelite promijeniti: ");
			scanf("%d", &mijenjaj);
			printf("Naziv predmeta: ");
			unesi_string(naziv2);
			printf("Vrijeme pocetka: ");
			scanf("%d%c%d", &pocetak.sati, &dvotacka1, &pocetak.minute);
			printf("Vrijeme zavrsetka: ");
			scanf("%d%c%d", &kraj.sati, &dvotacka2, &kraj.minute);
			promjena = unesi_cas(naziv2, dan, pocetak, kraj);
			promijeni_cas(raspored, suma_casova , dan, mijenjaj, promjena );
			
		}
		
		if(meni == 4){
			printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
			scanf("%d", &dan);
			ispisi_dan(raspored, suma_casova, dan);
			printf("Izaberite koji cas zelite obrisati: ");
			scanf("%d", &brisi);
			obrisi_cas(raspored, suma_casova, dan, brisi);
			printf("Cas obrisan\n");
			suma_casova--;
			
		}
		
		i++;
	} while(meni != 0);
	
	if(meni == 0)
		zapisi_datoteku(raspored, suma_casova);
	
	
	return 0;
}
