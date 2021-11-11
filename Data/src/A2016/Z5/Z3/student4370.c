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

int razmak_dva_casa(struct Vrijeme kraj, struct Vrijeme pocetak){
	int razmak;
	razmak = pocetak.sati*3600+pocetak.minute*60+pocetak.sekunde-kraj.sati*3600-kraj.minute*60-kraj.sekunde;
	return razmak;
}

int poredi_vremena(struct Vrijeme manje, struct Vrijeme vece){
	int manje_sec=manje.sati*3600+manje.minute*60+manje.sekunde;
	int vece_sec=vece.sati*3600+vece.minute*60+vece.sekunde;
	//printf("-vremena: %d %d", manje_sec, vece_sec);
	return manje_sec<vece_sec;
}

void ispisi_dan(struct Cas raspored[], int broj_casova, int dan){
	printf("Uneseni su casovi: \n");
	int i;
	int brojac;
	brojac=1;
	for (i=0; i<broj_casova;i++) {
		if (raspored[i].dan_u_sedmici==dan) {
			printf("%d) %s (%02d:%02d-%02d:%02d)\n",brojac, raspored[i].predmet, raspored[i].pocetak.sati, raspored[i].pocetak.minute, raspored[i].kraj.sati, raspored[i].kraj.minute);
	
			brojac++;
		}
	}
}

void obrisi_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj){
    	int i;
    	int izbirsati=-1;
    	int brojac;
    	brojac=0;
    	
    	for(i=0;i<broj_casova;i++){
    			if(raspored[i].dan_u_sedmici==dan){
    				brojac++;
    				if(brojac==redni_broj) izbirsati=i;
    			}
    	}
    	if (brojac<redni_broj || redni_broj<0) printf("Neispravan redni broj casa.");
    	for(i=izbirsati;i<broj_casova-1;i++){
    			raspored[i]=raspored[i+1];
    	}
    	
    }

int upisi_novi_cas(struct Cas raspored[], int broj_casova, const char* predmet,int dan, int sat, int min, int sec, int trajanje){
	strcpy(raspored[broj_casova].predmet,predmet);
	raspored[broj_casova].dan_u_sedmici=dan;
	raspored[broj_casova].pocetak.sati=sat;
	raspored[broj_casova].pocetak.minute=min;
	raspored[broj_casova].pocetak.sekunde=sec;
	raspored[broj_casova].kraj.sati=sat+trajanje;
	raspored[broj_casova].kraj.minute=min;
	raspored[broj_casova].kraj.sekunde=sec;	
	return 1;	
	}

int dodaj_cas(struct Cas raspored[], int broj_casova, const char* predmet, int trajanje){
	if (trajanje>10) return 0;
	int i, k, j;
	for (i=1;i<=6;i++){
		int pocetak[24];
		int kraj[24];
		int brCasova=0;
		for (k=0;k<24;k++) {pocetak[k]=-1;kraj[k]=-1;}
		for (k=0;k<broj_casova;k++){
		if (raspored[k].dan_u_sedmici==i) {
			brCasova++;
			pocetak[raspored[k].pocetak.sati]=raspored[k].pocetak.minute*60+raspored[k].pocetak.sekunde;
			kraj[raspored[k].kraj.sati]=raspored[k].kraj.minute*60+raspored[k].kraj.sekunde;
			}
		}
		//for (k=0;k<10;k++) {printf("%d ",pocetak[k]);}
		//printf("\n");
		//for (k=0;k<10;k++) {printf("%d ",kraj[k]);}
		//printf("\n");
		int poc=0;
		int kr=0;
		int br_poc=0;
		int br_kr=0;
		int nadjen=0;
		int sat;
		for (k=0;k<24;k++){
			if(pocetak[k]!=-1 && br_poc!=0) {br_poc++;poc=(k)*3600+pocetak[k];}
			if(kraj[k]!=-1 && br_kr!=brCasova) {br_kr++;kr=(k)*3600+kraj[k];sat=k;}
			//printf("k= %d\n", k);
			//printf("poc %d \n",br_poc);
			//printf("kr %d \n",br_kr);
			if((pocetak[k]!=-1 && br_poc==0) || brCasova==0) {
				br_poc++;
				if ((k)*3600+pocetak[k]-9*3600>=trajanje*3600){
					//printf("pocetak dana\n");
					return upisi_novi_cas(raspored,broj_casova,predmet,i,9,0,0,trajanje);
				}
			}
			if(kraj[k]!=-1 && br_kr==brCasova) {
				if (19*3600-(k)*3600-kraj[k]>=trajanje*3600){
					//printf("kraj dana\n");
					return upisi_novi_cas(raspored,broj_casova,predmet,i,k,kraj[k]/60,kraj[k]-(kraj[k]/60)*60,trajanje);
				}			
			}
			
			if(poc!=0 && kr!=0){
				if(poc-kr>=trajanje*3600) {
					//printf("Sredina %d %d ", br_poc, br_kr);
					return upisi_novi_cas(raspored,broj_casova,predmet,i,sat,kraj[sat]/60,kraj[sat]-(kraj[sat]/60)*60,trajanje);
				}
				poc=0;
				kr=0;			
			} 			
		}
	}
	
	return 0;
}

int preklapanje(struct Cas raspored[], int broj_casova,  struct Cas cas) {
		int pocetak[24];
		int kraj[24];
		int zauzeti[24];
		int brCasova=0;
		int k, i;
		k=0;
		for (k=0;k<24;k++) {pocetak[k]=-1;kraj[k]=-1;zauzeti[k]=-1;}
		for (k=0;k<broj_casova;k++){
		if (raspored[k].dan_u_sedmici==cas.dan_u_sedmici) {
			brCasova++;
			pocetak[raspored[k].pocetak.sati]=raspored[k].pocetak.minute*60+raspored[k].pocetak.sekunde;
			kraj[raspored[k].kraj.sati]=raspored[k].kraj.minute*60+raspored[k].kraj.sekunde;
			for(i=1;i<raspored[k].kraj.sati-raspored[k].pocetak.sati;i++){
				zauzeti[raspored[k].pocetak.sati+i]=0;		
			}
			}
		}/*
		for (k=0;k<24;k++) {printf("%2d ",k);}
		printf("\n");
		for (k=0;k<24;k++) {printf("%d ",pocetak[k]);}
		printf("\n");
		for (k=0;k<24;k++) {printf("%d ",kraj[k]);}
		printf("\n");
		for (k=0;k<24;k++) {printf("%d ",zauzeti[k]);}*/
		//printf("\n"); 
		if (brCasova==0) return 0;
		if (pocetak[cas.pocetak.sati]!=-1 || kraj[cas.kraj.sati]!=-1) return 1;
		for (i=cas.pocetak.sati;i<=cas.kraj.sati;i++) if (zauzeti[i]!=-1) return 1;
   		if (pocetak[cas.kraj.sati]!=-1 && pocetak[cas.kraj.sati]< cas.kraj.minute*60+cas.kraj.sekunde) return 1;
		if (kraj[cas.pocetak.sati]!=-1 && kraj[cas.pocetak.sati]> cas.pocetak.minute*60+cas.pocetak.sekunde) return 1;
	/*	
		if (pocetak[cas.kraj.sati]> cas.kraj.minute*60+cas.kraj.sekunde) return 1;
		if (kraj[cas.pocetak.sati]> cas.pocetak.minute*60+cas.pocetak.sekunde) return 1;
	*/	
		return 0;
}

void promijeni_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj, struct Cas promjena){
		int i;
    	int promjeniti=-1;
    	int brojac;
    	brojac=0;
    	
    	for(i=0;i<broj_casova;i++){
    			if(raspored[i].dan_u_sedmici==dan){
    				brojac++;
    				if(brojac==redni_broj) {
				promjeniti=i;
				}
    			}
    	}
    	if (brojac<redni_broj || redni_broj<0) {
		printf("Neispravan redni broj casa.");
		}
		/*struct Cas temp[KAPACITET];
		for (i=0;i<promjeniti;i++){
			temp[i]=raspored[i];
		}
		for (i=promjeniti;i<broj_casova-1;i++){
			temp[i]=raspored[i+1];
		}
		if(preklapanje(temp, broj_casova, promjena)==0) */
		raspored[promjeniti] = promjena;
		//else printf("Promjena nije moguca jer dovodi do preklapanja");
}


void ispis_rasporeda(struct Cas raspored[], int broj_casova) {
	printf("\n       PON       UTO       SRI       CET       PET       SUB\n");
	
	int i,j,k;
	int min, max;
	min=23;
	max=-1;	
	for (i=0;i<broj_casova;i++) {

		if(raspored[i].pocetak.sati<min) {
			min=raspored[i].pocetak.sati;
		}
		if(raspored[i].kraj.sati>max){
			if (raspored[i].kraj.minute>0 || raspored[i].kraj.minute>0) max=raspored[i].kraj.sati;
			else max=raspored[i].kraj.sati-1;
		}
	}
	for (j=min;j<=max;j++){
		if (j>=0 && j<10) printf("%1d:00   ",j);
		else printf("%2d:00  ", j);
			for (k=1;k<=6;k++){
				int postoji_cas;
				postoji_cas=0;
				for (i=0;i<broj_casova;i++){
				if ((raspored[i].pocetak.sati==j || (raspored[i].pocetak.sati<j && raspored[i].kraj.sati>j) || (raspored[i].kraj.sati==j && raspored[i].kraj.minute+raspored[i].kraj.sekunde>0) ) && raspored[i].dan_u_sedmici==k) {
					printf("%-10s",raspored[i].predmet);
					postoji_cas=1;
					
				}
			}
			if(postoji_cas==0) printf("          ");

		}
		printf("\n");
		}
}

//ucitavanje podataka iz datoteke
int ucitaj_datoteku(struct Cas raspored[]){
	
	FILE* dat = fopen("raspored.dat", "rb");
	if (dat == NULL) {
		//printf("Greska pri otvaranju datoteke.\n");
		return 0;
	}
	int ucitano;
	ucitano = fread(raspored, sizeof(struct Cas), KAPACITET, dat);
	fclose(dat);
	return ucitano;
}

int zapisi_datoteku(struct Cas raspored[], int broj_casova){

	FILE* dat = fopen("raspored.dat", "wb");
	if (dat == NULL) {
		//printf("Greska pri otvaranju datoteke.\n");
		return 0;
	}
	int zapisano; 
	zapisano = fwrite(raspored, sizeof(struct Cas),broj_casova, dat);
	if (ferror(dat)) {
		printf("Greska prilikom pisanja datoteke.\n");
		printf("Zapisano je samo %d osoba\n", zapisano);
		return 1;
	}
	fclose(dat);
	return 1;
}

int main() {
	
	struct Cas raspored[KAPACITET];
	//ucitavanje podataka iz datoteke
	int broj_casova;
	broj_casova=ucitaj_datoteku(raspored);
	int izbor;
	int preklp=2;
	izbor=0;
	int dan, rezultat;
	dan=0;
	int redni_broj;
	char naziv_predmeta[10];
	int trajanje;
	trajanje=0;
	struct Cas promjeni;
	
	int i;
    int promjeniti=-1;
    int brojac;
    brojac=0;
	
	do {
		
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
				printf("Unesite naziv predmeta: ");
				scanf("%9s", naziv_predmeta);
				naziv_predmeta[9]='\0';
				while ( getchar() != '\n' );
				printf("Unesite broj casova: ");
				scanf("%d", &trajanje);
				rezultat = dodaj_cas(raspored,broj_casova,naziv_predmeta, trajanje);
				if (rezultat==1) broj_casova++;
				else if (rezultat==0) printf("Nema dovoljno mjesta u rasporedu za %d casova. \n", trajanje);
				//printf("UNESEN JE NOVI CAS %s %d %d %d %d %d %d",raspored[broj_casova-1].predmet, raspored[broj_casova-1].pocetak.sati, raspored[broj_casova-1].pocetak.minute, raspored[broj_casova-1].pocetak.sekunde, raspored[broj_casova-1].kraj.sati, raspored[broj_casova-1].kraj.minute, raspored[broj_casova-1].kraj.sekunde);
				zapisi_datoteku(raspored,broj_casova);
				break;
			case 3: 
				do{
				preklp=1;
				printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
				scanf("%d", &dan);
				ispisi_dan(raspored, broj_casova, dan);
				printf("Izaberite koji cas zelite promijeniti: ");
				scanf("%d", &redni_broj);
				printf("Naziv predmeta: ");
				scanf("%9s", promjeni.predmet);
				promjeni.predmet[9]='\0';
				while ( getchar() != '\n' );
				printf("Vrijeme pocetka: ");
				scanf("%d:%d", &promjeni.pocetak.sati, &promjeni.pocetak.minute);
				printf("Vrijeme zavrsetka: ");
				scanf("%d:%d", &promjeni.kraj.sati, &promjeni.kraj.minute);
				promjeni.dan_u_sedmici=dan;
				

    	
    			for(i=0;i<broj_casova;i++){
    				if(raspored[i].dan_u_sedmici==dan){
    				brojac++;
    				if(brojac==redni_broj) {
					promjeniti=i;
					}
    				}
    			}
    			if (brojac<redni_broj || redni_broj<0) {
					printf("Neispravan redni broj casa.");
				}
				struct Cas temp[KAPACITET];
				for (i=0;i<promjeniti;i++){
					temp[i]=raspored[i];
				}
				for (i=promjeniti;i<broj_casova-1;i++){
					temp[i]=raspored[i+1];
				}
				if(preklapanje(temp, broj_casova, promjeni)==0) preklp=0;
				else if(preklp==1) printf("Promjena nije moguca jer dovodi do preklapanja\n");
				
				} while (preklp==1);
				promijeni_cas(raspored, broj_casova,dan,redni_broj,promjeni);
				zapisi_datoteku(raspored,broj_casova);
				break;
			case 4:
				printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
				scanf("%d", &dan);
				ispisi_dan(raspored, broj_casova, dan);
				printf("Izaberite koji cas zelite obrisati: ");
				scanf("%d", &redni_broj);
				obrisi_cas(raspored, broj_casova, dan, redni_broj);
				broj_casova--;
				printf("Cas obrisan \n");
				zapisi_datoteku(raspored,broj_casova);
				break;
			case 0:
				zapisi_datoteku(raspored,broj_casova);
				break;
			default: 
				while ( getchar() != '\n' );
				break;

		}
    } while (izbor!=0) ;
    	
	
	return 0;
}
