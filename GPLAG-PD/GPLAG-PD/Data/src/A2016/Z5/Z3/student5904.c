#include <stdio.h>
#include <string.h>
#define KAPACITET 200

struct Vrijeme {
		int sati, minute, sekunde;
	};
	
struct Cas {
	char predmet[10];
	int dan_u_sedmici;
	struct Vrijeme pocetak, kraj;
};



int poc_min (struct Cas sat) {
	int ukupno;
	ukupno = (sat.pocetak.sati*60) + sat.pocetak.minute;
	
	return ukupno;
}

int kraj_min (struct Cas sat) {
	int ukupno;
	ukupno = (sat.kraj.sati * 60) + sat.kraj.minute;
	
	return ukupno;
}

int koja_je_pozicija(struct Cas raspored[], int broj_casova, struct Cas cas) {
	int i,pozicija = 1;
	
	for (i=0; i<broj_casova; i++) {
		if (raspored[i].dan_u_sedmici == cas.dan_u_sedmici && poc_min(raspored[i]) < poc_min(cas)) 
			pozicija++;
	}
	return pozicija;
	
}


void promijeni_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj, struct Cas promjena) {
	int i;
	struct Cas* reset = raspored;
	//ispis_rasporeda(raspored, broj_casova);
	for (i=0; i<broj_casova; i++) {
		//printf("Redni (%s) broj je: %d\n", raspored[i].predmet, koja_je_pozicija(raspored, broj_casova, raspored[i]));
		if (raspored[i].dan_u_sedmici == dan && koja_je_pozicija(raspored, broj_casova, raspored[i]) == redni_broj){
			//printf("Usao (%s)\n",raspored[i].predmet);
			raspored[i] = promjena;
			break;
		}
	}
	
	
}


void obrisi_cas (struct Cas raspored[], int broj_casova, int dan, int redni_broj) {
	int i,j;
	struct Cas* reset=raspored;
	
	for(i=0; i<broj_casova; i++) {
		if (raspored[i].dan_u_sedmici == dan && koja_je_pozicija(reset, broj_casova, raspored[i]) == redni_broj) {
			for (j=i; j<broj_casova-1; j++) {
				raspored[j] = raspored[j+1];
			}
			broj_casova--;
			i--;
			return 0;
		}
	}
}

void ispisi_red (struct Cas raspored[], int broj_casova, int sat) {
	int dan, i, ima_ispisano = 0;
	
	if(sat==9)
		printf(" ");
	printf("  ");
	
	for(dan=1; dan<=6; dan++) {
		ima_ispisano = 0;
			
		for (i=0; i<broj_casova; i++) {
			if (raspored[i].dan_u_sedmici == dan &&	sat >= raspored[i].pocetak.sati && sat <= raspored[i].kraj.sati) {
					ima_ispisano = 1;
					printf ("%-10s", raspored[i].predmet);
					break;
			} 
			
		}
		
		if(!ima_ispisano){
			printf ("%-10s", "");
		}
	}
}

void ispis_rasporeda (struct Cas raspored[], int broj_casova) {
	struct Cas *reset = raspored;
	int sat,i;
	
	printf ("%7s%-10s%-10s%-10s%-10s%-10s%-10s\n", "", "PON","UTO","SRI","CET","PET","SUB");
		
	for (sat=9; sat<19; sat++) {
		for(i=0; i<broj_casova;i++) {
			if(sat >= raspored[i].pocetak.sati && sat <= raspored[i].kraj.sati) {
				printf("%d:00",sat);
				ispisi_red(reset,broj_casova,sat);
				if(sat<18)
					printf("\n");
				break;
			} 
		}
	
	}	
}

void sortiraj_za_dan_jedan (struct Cas* dnevni_raspored, int vel) {
	struct Cas tmp, *reset=dnevni_raspored;
	int i,j;
	
	for (i=0; i<vel; i++) {
		for (j=(i+1); j<(vel-i); j++) {
			if (poc_min(reset[j]) < poc_min(reset[i])) {
				tmp = dnevni_raspored[j];
				dnevni_raspored[j] = dnevni_raspored[i];
				dnevni_raspored[i] = tmp;
			}
		}
	}
}

void ispisi_dan (struct Cas raspored[], int broj_casova, int dan) {
	int i, vel=0;
	struct Cas dnevni_raspored[KAPACITET];
	
	for (i=0; i<broj_casova; i++) {
		if (raspored[i].dan_u_sedmici == dan) {
			dnevni_raspored[vel] = raspored[i];
			vel++;
		}
	}
	sortiraj_za_dan_jedan(dnevni_raspored,vel);
	
	printf("Uneseni su casovi: \n");
	for (i=0; i<vel; i++) {
		printf("%d) %s (%02d:%02d-%02d:%02d) ", i+1, dnevni_raspored[i].predmet, dnevni_raspored[i].pocetak.sati, dnevni_raspored[i].pocetak.minute, dnevni_raspored[i].kraj.sati, dnevni_raspored[i].kraj.minute);
		if(i<vel-1)
			printf("\n");
		
	}
}

int preklapanje(struct Cas raspored[], int broj_casova, struct Cas cas) {
	int i,logic=0;
	
	
	for (i=0; i<broj_casova; i++) {
		if(cas.dan_u_sedmici == raspored[i].dan_u_sedmici){
			if (kraj_min(cas) > poc_min(raspored[i]) && poc_min(cas) < kraj_min(raspored[i]))
				return 1;
		}
	}
	
	return 0;
}


int dodaj_cas(struct Cas raspored[], int broj_casova,	
			  const char* predmet, int trajanje) {
		  	
	struct Cas* reset=raspored;
	struct Cas cas={"",1,{9,0,0},{9,0,0}};
	cas.kraj.sati = 9+trajanje;
	
	strcpy(cas.predmet,predmet);

	while(1) {
		if(!preklapanje(reset, broj_casova, cas) && 
			!(cas.kraj.sati > 19 || (cas.kraj.sati == 19 && cas.kraj.minute > 0))) {
			raspored[broj_casova] = cas;
			return 1;
		}
		cas.pocetak.minute++;
		cas.kraj.minute++;
		
		if (cas.pocetak.minute == 60) {
			cas.pocetak.minute=0; 
			cas.pocetak.sati++;
		}
		
		if (cas.kraj.minute == 60) {
			cas.kraj.minute=0;
			cas.kraj.sati++;
		}	
		
		if(cas.kraj.sati > 19 || (cas.kraj.sati == 19 && cas.kraj.minute > 0)) {
			cas.dan_u_sedmici++;
			cas.pocetak.minute=0; 
			cas.kraj.minute=0;
			cas.pocetak.sati=9;
			cas.kraj.sati=9+trajanje;
		}
		if (cas.dan_u_sedmici == 7) {
			// printf ("Nema dovoljno mjesta u rasporedu za %d casova.", trajanje);
			return 0;
		}
	}
}


int zapisi_datoteku(struct Cas raspored[], int broj_casova){
	int zapisano;
	FILE* izlaz= fopen("raspored.dat", "wb");
	if(izlaz == NULL){
		printf("Greska ne moze se otvoriti");
		return -1;
	}
	
	zapisano = fwrite(raspored, sizeof(struct Cas), broj_casova, izlaz);
	
	
	fclose(izlaz);
	return zapisano;
}

int ucitaj_datoteku(struct Cas raspored[]){
	int ucitano;
	FILE* ulaz= fopen("raspored.dat", "rb");
	if(ulaz == NULL){
		printf("Greska ne moze se otvoriti");
		return -1;
	}
	
	ucitano = fread(raspored, sizeof(struct Cas), KAPACITET, ulaz);
	fclose(ulaz);
	return ucitano;
}
int main() {
	
struct Cas	pomocni_raspored[200];
	struct Cas mini_raspored[12];
	int ukupno_casova=0;
	//ispisat cemoA	//ispisujemo "O"
	dodaj_cas(mini_raspored, ukupno_casova++, "*********", 1);
	dodaj_cas(mini_raspored, ukupno_casova++, "*       *", 8);
	dodaj_cas(mini_raspored, ukupno_casova++, "*********", 1);
	dodaj_cas(mini_raspored, ukupno_casova++, " ", 10);
	
	ispisi_dan(mini_raspored, ukupno_casova, 1);
	//ispisujemo "R"
	dodaj_cas(mini_raspored, ukupno_casova++, "*********", 1);
	dodaj_cas(mini_raspored, ukupno_casova++, "*       *", 3);
	dodaj_cas(mini_raspored, ukupno_casova++, "*********", 1);
	dodaj_cas(mini_raspored, ukupno_casova++, "**", 1);
	dodaj_cas(mini_raspored, ukupno_casova++, "*  *", 1);
	dodaj_cas(mini_raspored, ukupno_casova++, "*   *", 1);
	dodaj_cas(mini_raspored, ukupno_casova++, "*     *", 1);
	dodaj_cas(mini_raspored, ukupno_casova++, "*       *", 1);
	
	ispisi_dan(mini_raspored, ukupno_casova, 3);
	//u konacnici ispisujemo casove
	ispis_rasporeda(mini_raspored,ukupno_casova);
	
	return 0;
}
