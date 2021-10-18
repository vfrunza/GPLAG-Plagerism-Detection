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
//
/*
	struct Cas raspored[200];
	int ukupno_casova=0;
//*/
//
int brojCasovaUDanu(struct Cas raspored[], int broj_casova, int dan);
int daLiJeIspravanBrojCasa(struct Cas raspored[], int broj_casova, int dan, int redni_broj);
void unesi(char niz[], int velicina);
int daLiJeVrijemeManje(struct Vrijeme t1, struct Vrijeme t2);
struct Vrijeme saberiVremena(struct Vrijeme t1, struct Vrijeme t2);
void kodiraj(char *string);
void dekodiraj(char *string);
int daLiJeVrijemeVece(struct Vrijeme t1, struct Vrijeme t2);
int ucitaj_datoteku(struct Cas raspored[]);
int zapisi_datoteku(struct Cas raspored[], int broj_casova);
int dodaj_cas(struct Cas raspored[], int broj_casova, const char* predmet, int trajanje);
int preklapanje(struct Cas raspored[], int broj_casova, struct Cas cas);
void promijeni_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj, struct Cas promjena);
void obrisi_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj);
void ispisi_dan(struct Cas raspored[], int broj_casova, int dan);
void ispis_rasporeda(struct Cas raspored[], int broj_casova);
void promjenaCasa(struct Cas raspored[], int broj_casova);
//
//PROGRAM
//
int main() {
//	printf("Zadaća 5, Zadatak 3");
//*
	int i, odabir, brojCasova, brojTermina, dan, promjenaTermina, obrisiOvajCas;
	struct Cas raspored[KAPACITET];
	char imePredmeta[10];
	struct Cas promjena;
	
	
	brojCasova= ucitaj_datoteku(raspored);
	do{
		printf("1) Ispis rasporeda\n2) Dodavanje casa\n3) Promjena casa\n4) Brisanje casa\n0) Kraj rada\nIzaberite opciju: ");
		scanf("%d", &odabir);
		switch(odabir){
			case 1:
			//ispis rasporeda
				ispis_rasporeda(raspored, brojCasova);
				break;
			case 2:
			//dodavanje casa
				printf("Unesite naziv predmeta: ");
				unesi(imePredmeta, 10);
				printf("Unesite broj casova: ");
				scanf("%d", &brojTermina);
				if(dodaj_cas(raspored, brojCasova, imePredmeta, brojTermina)){
					brojCasova++;
				}else{
					printf("Nema dovoljno mjesta u rasporedu za %d casova.", brojTermina);
				}
				break;
			case 3: 
			//promjena casa
			promjenaCasa(raspored, brojCasova);
/*				do{
					printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
					scanf("%d", &dan);
					ispisi_dan(raspored, brojCasova, dan);
					printf("\nIzaberite koji cas zelite promijeniti: ");
					scanf("%d", &promjenaTermina);
					printf("Naziv predmeta: ");
					unesi(promjena.predmet, 10);
					printf("Vrijeme pocetka: ");
					scanf("%d:%d", &promjena.pocetak.sati, &promjena.pocetak.minute);
					printf("Vrijeme zavrsetka: ");
					scanf("%d:%d", &promjena.kraj.sati, &promjena.kraj.minute);
					if(preklapanje(raspored, brojCasova, promjena)==1)
						printf("Promjena nije moguca jer dovodi do preklapanja\n");
				}while(preklapanje(raspored, brojCasova, promjena)==1);
				if(daLiJeIspravanBrojCasa(raspored, brojCasova, dan, promjenaTermina))
					promijeni_cas(raspored, brojCasova, dan, promjenaTermina, promjena);
*/
			break;

			case 4:
			//brisanje casa
				printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
				scanf("%d", &dan);
				ispisi_dan(raspored, brojCasova, dan);
				printf("Izaberite koji cas zelite obrisati: ");
				scanf("%d", &obrisiOvajCas);
				if(daLiJeIspravanBrojCasa(raspored, brojCasova, dan, obrisiOvajCas))
					obrisi_cas(raspored, brojCasova--, dan, obrisiOvajCas);
				break;
			case 0:
			//prekini program
				zapisi_datoteku(raspored, brojCasova);
				break;
		}
	}while(odabir!=0);
//*/

	return 0;
}

int ucitaj_datoteku(struct Cas raspored[]){
	int i=0;
	FILE *rasporedDat= fopen("raspored.dat","r");
	if(rasporedDat == NULL){
	//	fclose(rasporedDat);
		printf("Otvaranje datoteke raspored.dat nije uspjelo\n");
		return 0;
	}
	while (fscanf(rasporedDat, "%10s %d %d:%d:%d-%d:%d:%d\n", &raspored[i].predmet, &raspored[i].dan_u_sedmici, &raspored[i].pocetak.sati, &raspored[i].pocetak.minute, &raspored[i].pocetak.sekunde, &raspored[i].kraj.sati, &raspored[i].kraj.minute, &raspored[i].kraj.sekunde) == 8 && i < KAPACITET){
		dekodiraj(raspored[i].predmet);
		i++;
	}
	fclose(rasporedDat);
	return i;
}
int zapisi_datoteku(struct Cas raspored[], int broj_casova){
	int i;
	//raspored.dat
	FILE *rasporedDat= fopen("raspored.dat","w");
	if(rasporedDat == NULL){
		fclose(rasporedDat);
		printf("Otvaranje datoteke raspored.dat nije uspjelo");
		return 0;
	}
	for(i=0; i<broj_casova; i++){
		//eg. im1....... 1 10:0:10-12:0:1
		kodiraj(raspored[i].predmet);
		fprintf(rasporedDat, "%10s %d %d:%d:%d-%d:%d:%d\n",raspored[i].predmet, raspored[i].dan_u_sedmici, raspored[i].pocetak.sati, raspored[i].pocetak.minute, raspored[i].pocetak.sekunde, raspored[i].kraj.sati, raspored[i].kraj.minute, raspored[i].kraj.sekunde);
		if (ferror(rasporedDat)) {
			printf("Greska prilikom pisanja datoteke.\n");
			return 0;
		}
	}
	fclose(rasporedDat);
	return 1;
}
int dodaj_cas(struct Cas raspored[], int broj_casova, const char* predmet, int trajanje){
	int i=0;
	struct Vrijeme duzinaTrajanja={1*trajanje,0,0};
	struct Vrijeme pocetakDana={9,0,0};
	struct Vrijeme krajDana={19,0,0};
	struct Cas noviCas;
	//postaviti pocetak kursa u ponedjeljak u 9:00, kasnije provjeriti da li odgovara termin
	strcpy(noviCas.predmet, predmet);
	noviCas.dan_u_sedmici=1;
	noviCas.pocetak=pocetakDana;
	noviCas.kraj= saberiVremena(noviCas.pocetak, duzinaTrajanja);
	//kraj postavljanja
	for(i=0; i<broj_casova; i++){	//TODO: ako se preklapa termin => i=0;
		//ako je dan 7(nedjelja) u rasporedu nema mjesta za ovaj cas
		//vrati 0
		if(noviCas.dan_u_sedmici>6){
			return 0;
		}
		//if(p1>p2 && p1<k2)
		//da li pocetak casa ima koliziju sa necim u rasporedu
		if(noviCas.dan_u_sedmici==raspored[i].dan_u_sedmici && (daLiJeVrijemeVece(noviCas.pocetak, raspored[i].pocetak) && daLiJeVrijemeManje(noviCas.pocetak, raspored[i].kraj))){
			noviCas.pocetak=raspored[i].kraj;
			noviCas.kraj= saberiVremena(noviCas.pocetak, duzinaTrajanja);
			i=0;
			continue;
		}
		//if(p3<k1 && p1<k3)
		//Da li kraj casa ima koliziju sa necim u rasporedu
		if(noviCas.dan_u_sedmici==raspored[i].dan_u_sedmici && (daLiJeVrijemeManje(raspored[i].pocetak, noviCas.kraj) && daLiJeVrijemeManje(noviCas.pocetak, raspored[i].kraj))){
			noviCas.pocetak=raspored[i].kraj;
			noviCas.kraj= saberiVremena(noviCas.pocetak, duzinaTrajanja);
			i=0;
			continue;
		}
		//Da li kraj casa ide preko 19:00
	
		if(daLiJeVrijemeVece(noviCas.kraj, krajDana)){
			(noviCas.dan_u_sedmici)++;
			noviCas.pocetak=pocetakDana;
			noviCas.kraj= saberiVremena(noviCas.pocetak, duzinaTrajanja);
			i=0;
			continue;
		}
	}
	raspored[broj_casova]= noviCas;
	return 1;
}
int daLiJeVrijemeVece(struct Vrijeme t1, struct Vrijeme t2){
	int vrijeme1= t1.sati*3600+ t1.minute*60+ t1.sekunde;
	int vrijeme2= t2.sati*3600+ t2.minute*60+ t2.sekunde;
	return vrijeme1>vrijeme2 ? 1 : 0;
}
int daLiJeVrijemeManje(struct Vrijeme t1, struct Vrijeme t2){
	int vrijeme1= t1.sati*3600+ t1.minute*60+ t1.sekunde;
	int vrijeme2= t2.sati*3600+ t2.minute*60+ t2.sekunde;
	return vrijeme1<vrijeme2 ? 1 : 0;
}
int daLiJeStringJednak(char *rijec1, char *rijec2){
	while(*rijec2!='\0'){
		if(*rijec1!= *rijec2)	
			return 0;
		rijec1++;
		rijec2++;
	}
	if((*rijec2=='\0') && *rijec1!= '\0'){
		while(*rijec1 == ' ') {
			if(*rijec1 != ' ')
				return 0;
			rijec1++;
		}	
	}
	//rijeci su identicne
	return 1;
}
void kodiraj(char *string){
	//if it works it aint stupid
	while(*string){
		if(*string==' ')
			*string= (char) 25;
	string++;
	}
}
void dekodiraj(char *string){
	while(*string){
		if(*string== 25)
			*string= ' ';
	string++;
	}
}
struct Vrijeme saberiVremena(struct Vrijeme t1, struct Vrijeme t2){
	int vrijeme= t1.sati*3600+ t1.minute*60+ t1.sekunde + t2.sati*3600+ t2.minute*60+ t2.sekunde;
	struct Vrijeme temp;
	temp.sati= vrijeme/3600;
	vrijeme-= temp.sati*3600;
	temp.minute= vrijeme/60;
	vrijeme-= temp.minute*60;
	temp.sekunde= vrijeme;
	return temp;
}
int preklapanje(struct Cas raspored[], int broj_casova, struct Cas cas){
	int i;
	for(i=0; i<broj_casova; i++){
		//da li pocetak casa ima koliziju sa necim u rasporedu
		if(cas.dan_u_sedmici==raspored[i].dan_u_sedmici && (daLiJeVrijemeVece(cas.pocetak, raspored[i].pocetak) && daLiJeVrijemeManje(cas.pocetak, raspored[i].kraj))){
			return 1;
		}
		//Da li kraj casa ima koliziju sa necim u rasporedu
		if(cas.dan_u_sedmici==raspored[i].dan_u_sedmici && (daLiJeVrijemeManje(raspored[i].pocetak, cas.kraj) && daLiJeVrijemeManje(cas.pocetak, raspored[i].kraj))){
			return 1;
		}
	}
	return 0;
}
void ispisi_dan(struct Cas raspored[], int broj_casova, int dan){
	int i, j=1;
	printf("Uneseni su casovi:");
	for(i=0; i<broj_casova; i++){
		if(raspored[i].dan_u_sedmici == dan){
			printf("\n%d) %s (%.2d:%.2d-%.2d:%.2d)", j++, raspored[i].predmet, raspored[i].pocetak.sati, raspored[i].pocetak.minute, raspored[i].kraj.sati, raspored[i].kraj.minute);
		}
	}
}
void promijeni_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj, struct Cas promjena){
	int i, j=1;
	for(i=0; i<broj_casova; i++){
		if(raspored[i].dan_u_sedmici == dan){
			if(redni_broj==j++){
				raspored[i]= promjena;
				return;
			}
		}
	}
}
void obrisi_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj){
	int i, j=1;
	for(i=0; i<broj_casova; i++){
		if(raspored[i].dan_u_sedmici == dan){
			if(redni_broj==j++){
				raspored[i]= raspored[broj_casova-1];
				return;
			}
		}
	}
}
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
void ispis_rasporeda(struct Cas raspored[], int broj_casova){
	//TODO: uradi ovo debilu jedan
}

int daLiJeIspravanBrojCasa(struct Cas raspored[], int broj_casova, int dan, int redni_broj){
	int i, j=1;
	for(i=0; i<broj_casova; i++){
		if(raspored[i].dan_u_sedmici == dan){
			if(redni_broj==j++){
				return 1;
			}
		}
	}
	if((j-1)!=redni_broj){
		printf("Neispravan redni broj casa.");
		return 0;
	}
}
void promjenaCasa(struct Cas raspored[], int broj_casova){
	int dan, promjenaTermina;
	struct Cas promjena;
	do{
		printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
		scanf("%d", &dan);
		ispisi_dan(raspored, broj_casova, dan);
		promjena.dan_u_sedmici=dan;
		do{
		printf("\nIzaberite koji cas zelite promijeniti: ");
		scanf("%d", &promjenaTermina);
		if(brojCasovaUDanu(raspored, broj_casova, dan)>= promjenaTermina){
			printf("Neispravan redni broj casa.");
			continue;
		}
		}while(brojCasovaUDanu(raspored, broj_casova, dan)>= promjenaTermina);
		printf("Naziv predmeta: ");
		unesi(promjena.predmet, 10);
		printf("Vrijeme pocetka: ");
		scanf("%d:%d", &promjena.pocetak.sati, &promjena.pocetak.minute);
		printf("Vrijeme zavrsetka: ");
		scanf("%d:%d", &promjena.kraj.sati, &promjena.kraj.minute);
		
		if(preklapanje(raspored, broj_casova, promjena))
			printf("Promjena nije moguca jer dovodi do preklapanja\n");
	}while(preklapanje(raspored, broj_casova, promjena));
	if(daLiJeIspravanBrojCasa(raspored, broj_casova, dan, promjenaTermina))
		promijeni_cas(raspored, broj_casova, dan, promjenaTermina, promjena);
}
int brojCasovaUDanu(struct Cas raspored[], int broj_casova, int dan){
	int i, j=1;
	for(i=0; i<broj_casova; i++){
		if(raspored[i].dan_u_sedmici == dan){
			j++;
		}
	}
	return j;
}