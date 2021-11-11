#include <stdio.h>
#include <string.h>
#define KAPACITET 200
struct Vrijeme{
	int sati,minute,sekunde;
};
struct Cas{
	char predmet[10];
	int dan_u_sedmici;
	struct Vrijeme pocetak,kraj;
};
int ucitaj_datoteku(struct Cas raspored[]){
	FILE* datoteka = fopen("raspored.dat","rb");
	if(datoteka == NULL){
		return 0;
	}
	int brojelemenata = 0;
	fread(&brojelemenata,sizeof(int),1,datoteka);
	if(brojelemenata > 200) brojelemenata = 200;
	fread(raspored,sizeof(struct Cas),brojelemenata,datoteka);
	return brojelemenata;
}
int zapisi_datoteku(struct Cas raspored[],int broj_casova){
	if(broj_casova > 200) broj_casova = 200;
	FILE* datoteka = fopen("raspored.dat", "wb");
	if(datoteka == NULL) return 0;
	fwrite(&broj_casova,sizeof(int),1,datoteka);
	fwrite(raspored,sizeof(struct Cas),broj_casova,datoteka);
	return 1;
}

int preklapanjeCas(struct Cas prvi, struct Cas drugi){
	if(prvi.dan_u_sedmici != drugi.dan_u_sedmici) return 0;
	if(prvi.kraj.sati < drugi.pocetak.sati ||
	   (prvi.kraj.sati == drugi.pocetak.sati && prvi.kraj.minute < drugi.pocetak.minute) ||
	   (prvi.kraj.sati == drugi.pocetak.sati && prvi.kraj.minute == drugi.pocetak.minute && prvi.kraj.sekunde <= drugi.pocetak.sekunde) ||
	   (drugi.kraj.sati < prvi.pocetak.sati) ||
	   (drugi.kraj.sati == prvi.pocetak.sati && drugi.kraj.minute < prvi.pocetak.minute) ||
	   (drugi.kraj.sati == prvi.pocetak.sati && drugi.kraj.minute == prvi.pocetak.minute && drugi.kraj.sekunde <= prvi.pocetak.sekunde)
	   ) return 0;
	else return 1;
}

int preklapanje(struct Cas raspored[],int broj_casova,struct Cas cas){
	int i;
	for(i = 0; i < broj_casova;i++){
		if(preklapanjeCas(raspored[i],cas) == 1) return 1;
	}
	return 0;
}
int dodaj_cas(struct Cas raspored[],int broj_casova, const char* predmet, int trajanje){
	int i,preklop = 0,dan_u_sedmici = 1, pocetakSati = 9,preklapanjeTest = 0;
	struct Cas noviCas = {predmet,dan_u_sedmici,{pocetakSati,0,0},{pocetakSati+trajanje,0,0}};
	while(dan_u_sedmici <= 6){
		noviCas.dan_u_sedmici = dan_u_sedmici;
		pocetakSati = 9;
		while(pocetakSati + trajanje <= 19){
			noviCas.pocetak.sati = pocetakSati;
			noviCas.kraj.sati = pocetakSati+trajanje;
			preklapanjeTest = preklapanje(raspored, broj_casova,noviCas);
			pocetakSati++;
			if(preklapanjeTest == 0) {
				raspored[broj_casova] = noviCas;
				strcpy(raspored[broj_casova].predmet,predmet);
				return 1;
				
			}
		}
		dan_u_sedmici++;
	}
	return 0;
}
void ispis_rasporeda(struct Cas raspored[],int broj_casova){
	int dan = 0,pocetniSat = 19,zavrsnisat = 9, sat, i;
	for(i = 0; i < broj_casova; i++){
		if(raspored[i].pocetak.sati < pocetniSat)
			pocetniSat = raspored[i].pocetak.sati;
		sat = raspored[i].kraj.sati;
		if(raspored[i].kraj.minute > 0 || raspored[i].kraj.sekunde > 0)
			sat++;
		if(sat > zavrsnisat) zavrsnisat = sat;
	}
	printf("       PON       UTO       SRI       CET       PET       SUB       \n");
	while(pocetniSat < zavrsnisat){
		printf("%d:00  ",pocetniSat);
		if(pocetniSat < 10) printf(" ");
		for(dan = 1; dan <=6; dan++){
			for(i = 0; i < broj_casova; i++){
				if(raspored[i].dan_u_sedmici == dan){
					if(!(raspored[i].kraj.sati < pocetniSat || pocetniSat+1 <raspored[i].pocetak.sati))
					{
						printf("%-10s",raspored[i].predmet);
						break;
					}
				}
			}
		}
		printf("\n");
		pocetniSat++;
	}
	
}
void ispisi_dan(struct Cas raspored[], int broj_casova, int dan){
	int i,brojac = 1;
	printf("Uneseni su casovi: \n");
	for(i = 0; i < broj_casova; i++){
		if(raspored[i].dan_u_sedmici == dan){
			
			printf("%d) %s (",brojac,raspored[i].predmet);
			if(raspored[i].pocetak.sati < 10) printf("0%d:",raspored[i].pocetak.sati);
			else printf("%d:",raspored[i].pocetak.sati);
			if(raspored[i].pocetak.minute < 10) printf("0%d",raspored[i].pocetak.minute);
			else printf("%d",raspored[i].pocetak.minute);
			printf("-");
			if(raspored[i].kraj.sati < 10) printf("0%d:",raspored[i].kraj.sati);
			else printf("%d:",raspored[i].kraj.sati);
			if(raspored[i].kraj.minute < 10) printf("0%d)\n", raspored[i].kraj.minute);
			else printf("%d)\n",raspored[i].kraj.minute);
			brojac++;
			
		}
	}
}
void promijeni_cas(struct Cas raspored[], int broj_casova,int dan, int redni_broj,struct Cas promjena){
	int brojac = 1, i;
	for(i = 0; i < broj_casova; i++){
		if(dan == raspored[i].dan_u_sedmici ){
			if(redni_broj == brojac){
				raspored[i] = promjena;
				return;
			} else {
				redni_broj++;
			}			
		}
	}
}
void obrisi_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj){
	int i,brojac = 1;
	for(i = 0; i < broj_casova; i++){
		if(dan == raspored[i].dan_u_sedmici){
			if(brojac == redni_broj){
				raspored[i] = raspored[broj_casova -1];
				strcpy(raspored[i].predmet,raspored[broj_casova -1].predmet);
				break;
			} else {
				brojac++;
			}
		}
	}
}
int main() {
	struct Cas raspored[KAPACITET];
	int integer, i;
	char buffer[100],c,broj_casova = 0, unos_casova, rez, unosizbora, unosizbora2;
	int predmet[10];
	do{
		printf("1) Ispis rasporeda\n2) Dodavanje casa\n3) Promjena casa\n4) Brisanje casa\n0) Kraj rada\n");
		printf("Izaberite opciju: ");
		scanf("%d",&integer);
		if(integer == 1){
			printf("\n");
			ispis_rasporeda(raspored,broj_casova);
		} else if(integer == 2){
			c = getchar();
			printf("Unesite naziv predmeta: ");
			i = 0;
			while(1){
				c = getchar();
				if(c == '\n')
					break;
				if(i < 50)
					buffer[i++] = c;	
			}
			buffer[i] = '\0';
			if(strlen(buffer) >= 10){
				buffer[9] = '\0';
			}
			printf("Unesite broj casova: ");
			scanf("%d",&unos_casova);
			rez = dodaj_cas(raspored,broj_casova,buffer,unos_casova);
			broj_casova++;
		} else if(integer == 3) {
			
			printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
			scanf("%d",&unosizbora);
			ispisi_dan(raspored,broj_casova,unosizbora);
			printf("Izaberite koji cas zelite promijeniti: ");
			scanf("%d",&unosizbora2);
			printf("Naziv predmeta: ");
			i = 0;
			while(1){
				c = getchar();
				if(c == '\n')
					break;
				if(i < 50)
					buffer[i++] = c;	
			}
			buffer[i] = '\0';
			if(strlen(buffer) >= 10){
				buffer[9] = '\0';
			}
			
		} else if(integer == 4){
			printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
			scanf("%d",&unosizbora);
			ispisi_dan(raspored,broj_casova,unosizbora);
			printf("Izaberite koji cas zelite obrisati: ");
			scanf("%d",&unosizbora2);
			obrisi_cas(raspored,broj_casova,unosizbora,unosizbora2);
			printf("Cas obrisan\n");
			broj_casova--;
		}
		
		
	}while(integer != 0);
	zapisi_datoteku(raspored,broj_casova);
	return 0;
}
