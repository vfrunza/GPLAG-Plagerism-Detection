#include <stdio.h>
#include <string.h>
#define KAPACITET 200

struct Vrijeme{
	int sati, minute, sekunde;
};

struct Cas{
	char predmet[10];
	int dan_u_sedmici;
	struct Vrijeme pocetak,kraj;
};
char unesi(char niz[], int velicina){
	char znak=getchar();
	int i=0;
	if(znak=='\n') znak=getchar();
	
	while(i<velicina-1 && znak!='\n'){
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
	
	return znak;
}
void ocisti(char znak){
	while(znak!='\n')
	znak=getchar();
		
}
int ucitaj_datoteku(struct Cas raspored[]){
	FILE*ulaz=fopen("raspored.dat","rb+");
	if(ulaz==NULL){
		return 0;
	}
	int ucitano=fread(raspored,sizeof(struct Cas),KAPACITET,ulaz);
	fclose(ulaz);
	return ucitano;
}
void ispis_rasporeda(struct Cas raspored[],int broj_casova){
	int i,j,pocetak=9,kraj=0,k,ispisan=0;
	for(i=0;i<broj_casova;i++){
		if(raspored[i].kraj.sati>=kraj){
		kraj=raspored[i].kraj.sati;
			if(raspored[i].kraj.minute==0) kraj--;
		}
		if(raspored[i].pocetak.sati<pocetak)
		pocetak=raspored[i].pocetak.sati;
	}
	char dani[][4]={"PON", "UTO", "SRI", "CET", "PET", "SUB"};
	printf("\n");
	for(i=0; i<6;i++)
		printf("%10s", dani[i]);
	printf("\n");
	for(i=pocetak;i<=kraj; i++){
		if(i<10)
		printf("%d:00   ", i);
		else 
		printf("%d:00  ", i);
		
		for(j=0; j<6; j++){
			ispisan=0;
			for(k=0;k<broj_casova;k++){
				if(raspored[k].dan_u_sedmici==j+1 && raspored[k].pocetak.sati<=i && raspored[k].kraj.sati>=i){
					printf("%-10s", raspored[k].predmet);
					ispisan=1;
					break;
				}
			}
			if(ispisan==0)
			printf("          ");
		}
		printf("\n");
	}
}
void ispisi_dan(struct Cas raspored[], int broj_casova, int dan){
	int i=0;
	printf("Uneseni su casovi: ");
	int k=1;
	for(i=0; i<broj_casova; i++){
		if(raspored[i].dan_u_sedmici==dan){
			int sat=raspored[i].pocetak.sati;
			int min=raspored[i].pocetak.minute;
		
			printf("\n%d) %s (", k++, raspored[i].predmet);
			if(sat<10) printf("0");
			printf("%d:",sat);
			if(min<10) printf("0");
			printf("%d-", min);
			if(raspored[i].kraj.sati<10) printf("0");
			printf("%d:", raspored[i].kraj.sati);
			if(raspored[i].kraj.minute<10) printf("0");
			printf("%d)", raspored[i].kraj.minute);
			
		}
	}
}
void obrisi_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj){
	int i,j=0;
	for(i=0; i<broj_casova; i++){
		if(raspored[i].dan_u_sedmici==dan) j++;
		if(redni_broj==j){
			for(;i<broj_casova-1; i++)
			raspored[i]=raspored[i+1];
			break;
		}
		
	}
}
int preklapanje(struct Cas raspored[], int broj_casova, struct Cas cas){
	int i=0;
	for(i=0; i<broj_casova; i++){
		if(cas.dan_u_sedmici==raspored[i].dan_u_sedmici){
			if(raspored[i].pocetak.sati==cas.pocetak.sati || raspored[i].kraj.sati==cas.kraj.sati)
			return 1;
			if(raspored[i].pocetak.sati==cas.kraj.sati && raspored[i].pocetak.minute<cas.kraj.minute)
			return 1;
			if(raspored[i].kraj.sati==cas.pocetak.sati && raspored[i].kraj.minute>cas.pocetak.minute)
			return 1;
			if(raspored[i].pocetak.sati<cas.pocetak.sati && raspored[i].kraj.sati>cas.kraj.sati)
			return 1;
			if(raspored[i].pocetak.sati>cas.pocetak.sati && raspored[i].kraj.minute<cas.kraj.minute)
			return 1;
			if(raspored[i].pocetak.sati> cas.pocetak.sati && raspored[i].pocetak.sati<cas.kraj.sati)
			return 1;
			if(raspored[i].kraj.sati> cas.pocetak.sati && raspored[i].pocetak.sati < cas.kraj.sati)
			return 1;
			
		}
	}
	return 0;
}
int dodaj_cas (struct Cas raspored[], int broj_casova, const char*predmet, int trajanje){
	if(broj_casova==200) return 0;
	int i, j, preklop;
	for(i=0; i<6; i++)
	for(j=9; j<=19-trajanje; j++){
		struct Cas cas={"", i+1,{j,0,0},{j+trajanje,0,0}};
		char *q=cas.predmet, *p=(char*)predmet;
		while(*q++=*p++);
		preklop=preklapanje(raspored,broj_casova, cas);
		if(preklop==0){
		raspored[broj_casova]=cas;
		return 1;
	}
		
	}
	return 0;
	
}
void promijeni_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj, struct Cas promjena){
	int i, redni=0;
	for(i=0; i<broj_casova; i++){
		if(raspored[i].dan_u_sedmici==dan) redni++;
		if(redni_broj==redni) 
		raspored[i]=promjena;
	}
}
int zapisi_datoteku(struct Cas raspored[], int broj_casova){
	FILE*ulaz=fopen("raspored.dat","wb+");
	if(ulaz==NULL){
		printf("Otvaranje datoteke raspored nije uspjelo.");
		return 0;
	}
	int zapisano=fwrite(raspored, sizeof(struct Cas), broj_casova,ulaz);
	fclose(ulaz);
	if(zapisano>=1) return 1;
	else
	return 0;
}


int main() {
	int opcija,broj_casova=0;
	struct Cas raspored[KAPACITET];
	ucitaj_datoteku(raspored);
	do{
		printf("1) Ispis rasporeda\n2) Dodavanje casa\n3) Promjena casa\n4) Brisanje casa\n0) Kraj rada\nIzaberite opciju: ");
		scanf("%d", &opcija);
		if(opcija==0)
		zapisi_datoteku(raspored, broj_casova);
		if(opcija==1)
		ispis_rasporeda(raspored, broj_casova);
		if(opcija==2){
			int br_casova, dodan=0;
			char predmet[10];
			printf("Unesite naziv predmeta: ");
			ocisti(unesi(predmet, 10));
			printf("Unesite broj casova: ");
			scanf("%d",  &br_casova);
			dodan=dodaj_cas(raspored,broj_casova,predmet, br_casova);
			if(dodan==1)
			broj_casova++;
			else
			printf("Nema dovoljno mjesta u rasporedu za %d casova.\n", br_casova);
		}
		if(opcija==3){
			struct Cas promjena;
			int dan, redni;
		
			printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
			scanf("%d", &dan);
		
			ispisi_dan(raspored, broj_casova, dan);
			promjena.dan_u_sedmici=dan;
		
			printf("\nIzaberite koji cas zelite promijeniti:  ");
			scanf("%d", &redni);
		
			printf("Naziv predmeta: ");
		
			char predmet[10];
			ocisti(unesi(predmet, 10));
			char*q=promjena.predmet, *p=predmet;
			while(*q++=*p++);
			char znak;
			printf("Vrijeme pocetka: ");
			scanf("%d%c%d",&promjena.pocetak.sati, &znak, &promjena.pocetak.minute);
			
			printf("Vrijeme zavrsetka: ");
			scanf("%d%c%d",&promjena.kraj.sati, &znak, &promjena.kraj.minute);
			
			promijeni_cas(raspored,broj_casova,dan,redni,promjena);
			
			
		}
		if(opcija==4){
			int dan, redni;
			printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
			scanf("%d", &dan);
			ispisi_dan(raspored,broj_casova, dan);
			printf("\nIzaberite koji cas zelite obrisati: ");
			scanf("%d", &redni);
			obrisi_cas(raspored, broj_casova, dan, redni);
			printf(" Cas obrisan\n");
			broj_casova--;
			
		}
	}
	while(opcija!=0);
	
	return 0;
}
