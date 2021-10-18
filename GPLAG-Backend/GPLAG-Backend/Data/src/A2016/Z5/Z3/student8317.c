#include <stdio.h>
#include <stdlib.h>
#define KAPACITET 200

struct Vrijeme {
	int sati, minute, sekunde;
};

struct Cas {
	char predmet[10];
	int dan_u_sedmici;
	struct Vrijeme pocetak, kraj;
};

void unesi(char niz[], int velicina){
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}

int zapisi_datoteku(struct Cas raspored[], int broj_casova){
	FILE* ispis;
	int i;
	ispis=fopen("raspored.dat", "wb");
	if(ispis==NULL){
		printf("Otvaranje datoteke raspored.dat nije uspjelo!");
		exit(1);
	}
	
	int zapisano = fwrite(raspored, sizeof(struct Cas), broj_casova, ispis);
	
	if(ferror(ispis)){
		return 0;
	}
	
	fclose(ispis);
	
	return 1;
}/*radi*/

int ucitaj_datoteku(struct Cas raspored[]){
	
	FILE* ulaz;
	ulaz=fopen("raspored.dat", "rb");
	if(ulaz==NULL){
		printf("Otvaranje datoteke raspored.dat nije uspjelo!");
		exit(1);
	}
	
	int ucitano= fread(raspored, sizeof(struct Cas), KAPACITET, ulaz);
	fclose(ulaz);
	

	return ucitano;
} /*radi*/

void ispisi_dan(struct Cas raspored[], int broj_casova, int dan){
	
	int broj=1;
	int i;
	printf("Uneseni su casovi: ");
	for(i=0;i<broj_casova;i++){
		
		if(raspored[i].dan_u_sedmici==dan){
			printf("\n%d) %s (%02d:%02d-%02d:%02d)", broj, raspored[i].predmet, raspored[i].pocetak.sati,raspored[i].pocetak.minute, raspored[i].kraj.sati,raspored[i].kraj.minute);
			broj++;
		}
	}
}/*radi*/

void obrisi_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj){

int brojac=0,i,j;

for(i=0;i<broj_casova;i++){
	
	if(raspored[i].dan_u_sedmici==dan){
		brojac++;
		if(brojac==redni_broj){
			for(j=i;j<broj_casova-1;j++){
				raspored[j]=raspored[j+1];
			}
			i--;
			broj_casova--;
		}
	}
	
}
	
}/*radi*/

void promijeni_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj, struct Cas promjena){
	
	int i, brojac=0;
	
	for(i=0;i<broj_casova;i++){
	
		if(raspored[i].dan_u_sedmici==dan){
			brojac++;
			if(brojac==redni_broj){
				raspored[i]=promjena;
				break;
			}
		}
	}
}/*radi*/

int preklapanje (struct Cas raspored[], int broj_casova, struct Cas cas){
	
	int prek=0;
	int i;
	
	for(i=0;i<broj_casova;i++){
		
		if(raspored[i].dan_u_sedmici==cas.dan_u_sedmici){
			
			if(cas.pocetak.sati<raspored[i].kraj.sati&&cas.kraj.sati>raspored[i].pocetak.sati){
				return 1;
			}
			else if(cas.pocetak.sati==raspored[i].kraj.sati){
				if(cas.pocetak.minute<raspored[i].kraj.minute){
					return 1;
				}
			}
			else if(cas.pocetak.sati==raspored[i].pocetak.sati){
				if(cas.pocetak.minute==raspored[i].pocetak.minute)
					return 1;
					else if(cas.pocetak.minute<raspored[i].kraj.minute)
						return 1;
			}
			
		}
		
		
	}
	
	
return 0;	
}/*radi!!!*/

int dodaj_cas(struct Cas raspored[], int broj_casova, const char* predmet, int trajanje){/*radi nesto*/
	
	struct Cas novi;
	int br=0,j,i;
	
	if(trajanje>10) return 0;
	
	
	while(*predmet!='\0'&&br!=10){
		novi.predmet[br]=*predmet;
		br++;
		predmet++;
	}
	novi.predmet[br]='\0';
	
	novi.pocetak.minute=0;	
	novi.pocetak.sekunde=0;
	novi.kraj.minute=0;
	novi.kraj.sekunde=0;
	
	
	for(i=1;i<7;i++){
		novi.dan_u_sedmici=i;
		for(j=9;j<=18;j++){
			novi.pocetak.sati=j;
			if(j+trajanje>19) return 1;
			novi.kraj.sati=j+trajanje;
			
			if( preklapanje( raspored, broj_casova, novi) ==1) continue;
			else {raspored[broj_casova]=novi; return 1;}
		}
	}
	
	return 0;
}

void ispis_rasporeda(struct Cas raspored[], int broj_casova){
	
	printf("%10s %9s %9s %9s %9s %9s", "PON","UTO","SRI","CET","PET","SUB");
	int i,j,k;
	int isp=0;
	for(i=9;i<=18;i++){
		
		printf("\n%02d:%02d  ", i,0);
		for(j=1;j<7;j++){
			isp=0;
			for(k=0;k<broj_casova;k++){
			if(i>=raspored[k].pocetak.sati&&i<=raspored[k].kraj.sati&&j==raspored[k].dan_u_sedmici){
				printf("%-10s", raspored[k].predmet);
				isp=1;
			}	
				
			}
			if(isp==0)
			printf("%10s","");
		}
		
		
	}
	
}


int main(){
	

	
	int opcija;
	int rb_dana;
	struct Cas raspored[KAPACITET];
	int cas;
	int broj_casova=0;
	char pocetak[6], zavrsetak[6];
	int br_casa;
	
	do{
		printf("1) Ispis rasporeda\n2) Dodavanje casa\n3) Promjena casa\n4) Brisanje casa\n0) Kraj rada\nIzaberite opciju: ");
		scanf("%d", &opcija);
		
		if(opcija==0){
			zapisi_datoteku(raspored, broj_casova);
		}
		else if(opcija==1){
			//ispisi raspored
			ispis_rasporeda(raspored, broj_casova);
		}
		else if(opcija==2){
			
			char predmet[10];
			printf("Unesite naziv predmeta: ");
			unesi(predmet,10);
			printf("Unesite broj casova: ");
			scanf("%d", &br_casa);
			
			if(dodaj_cas(raspored,broj_casova, predmet, br_casa)==1){
				broj_casova++;
			}
			else printf("Nema dovoljno mjesta za %d casova", br_casa);
			
		}
		else if(opcija==3){
			struct Cas novi2;
			printf("Unesite dan (1=ponedjeljak, 2=utorak, 3=srijeda, 4=cetvrtak, 5=petak, 6=subota): ");
			scanf("%d", &rb_dana);
			ispisi_dan(raspored, broj_casova, rb_dana);
			printf("Izaberite koji cas zelite promjeniti: ");
			scanf("%d", &cas);
			printf("Naziv predmeta: ");
			unesi(novi2.predmet,10);
			printf("Vrijeme pocetka: ");
			unesi(pocetak,6);
			printf("Vrijeme zavrsetka: ");
			unesi(zavrsetak,6);
			
			novi2.dan_u_sedmici=rb_dana;
			novi2.pocetak.sati=(pocetak[0]-'0')*10+pocetak[1]-'0';
			novi2.pocetak.minute=(pocetak[3]-'0')*10+pocetak[4]-'0';
			novi2.kraj.sati=(zavrsetak[0]-'0')*10+zavrsetak[1]-'0';
			novi2.kraj.minute=(zavrsetak[3]-'0')*10+zavrsetak[4]-'0';
			
			if(preklapanje(raspored, broj_casova, novi2)){
				printf("Promjena nije moguca jer dovodi do prekpalanja\n");
			}
			
			else promijeni_cas(raspored, broj_casova, rb_dana, cas, novi2);
		}
		
		else if(opcija==4){
			printf("Unesite dan (1=ponedjeljak, 2=utorak, 3=srijeda, 4=cetvrtak, 5=petak, 6=subota): ");
			scanf("%d", &rb_dana);
			ispisi_dan(raspored, broj_casova, rb_dana);
			printf("Izaberite koji cas zelite obrisati: ");
			scanf("%d", &cas);
			obrisi_cas(raspored, broj_casova, rb_dana, cas);
			printf("Cas obrisan");
			broj_casova--;
			
			//Brisanje casa
		} /*brisanje casa*/
		
	}
	while(opcija!=0);
	
	
	
	return 0;
}
