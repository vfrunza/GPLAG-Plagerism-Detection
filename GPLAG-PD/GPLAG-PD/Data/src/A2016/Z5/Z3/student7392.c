#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define KAPACITET 200

/* STRUCTOVI Cas I Vrijeme KOJE SADRZE POTREBNE INFORMACIJE O VREMENU I CASOVIMA */

struct Vrijeme {
	int sati, minute, sekunde;
};
struct Cas {
	char predmet[10];
	int dan_u_sedmici;
	struct Vrijeme pocetak, kraj;
};

/* UNOS STRINGA */

void unesi(char niz[], int velicina){
	char znak=getchar();
	int i=0;
	while(znak==' ')znak=getchar();
    while(znak=='\n')znak=getchar();
    while(znak!='\n') {
    	if(i<velicina){
        	niz[i]=znak;
        	i++;
    	}
        znak=getchar();
    }
    niz[i]='\0';
}

/* UCITAVANJE IZ DATOTEKE TE VRACANJE BROJA UCITANIH CASOVA */

int ucitaj_datoteku(struct Cas raspored[]){
	FILE *ras=fopen("raspored.dat", "rb");
	if(ras==NULL)return -1;
	int a=fread(raspored, sizeof(struct Cas), KAPACITET, ras);
	fclose(ras);
	return a;
}

/* PISANJE U DATOTEKU I VRACANJE USPJESNOSTI PISANJA */

int zapisi_datoteku(struct Cas raspored[], int broj_casova){
	FILE *ras=fopen("raspored.dat", "wb");
	if(ras==NULL)return 0;
	int zapisano=fwrite(raspored, sizeof(struct Cas), broj_casova, ras);
	if(ferror(ras)){
		fclose(ras);
		return 0; 
	}
	fclose(ras);
	return 1;
}

/* VRACA VRIJEME U OBLIKU SEKUNDI */

int dajvrijeme(struct Vrijeme cas){
	int g=0;
	g=g+cas.sati*3600;
	g=g+cas.minute*60;
	g=g+cas.sekunde;
	return g;
}

/* PROVJERAVA DA LI SU CASOVI JEDNAKI */

int jesulisti(struct Cas a, struct Cas b){
	if(a.dan_u_sedmici!=b.dan_u_sedmici)return 0;
	int v1=dajvrijeme(a.pocetak);
	int v2=dajvrijeme(b.pocetak);
	if(v1!=v2)return 0;
	v1=dajvrijeme(a.kraj);
	v2=dajvrijeme(b.kraj);
	if(v1!=v2)return 0;
	int i=0;
	for(i=0;;i++){
		if(a.predmet[i]!=b.predmet[i])return 0;
		if(a.predmet[i]=='\0')break;
	}
	return 1;
}

/* PROVJERAVA DA LI SE CAS PREKLAPA SA NEKIM CASOVIMA IZ RASPOREDA */

int preklapanje(struct Cas raspored[], int broj_casova, struct Cas cas){
	int i;
	int pocetakt=dajvrijeme(cas.pocetak);
	int krajt=dajvrijeme(cas.kraj);
	int pocetaktemp, krajtemp;
	for(i=0;i<broj_casova;i++){
		if(cas.dan_u_sedmici==raspored[i].dan_u_sedmici && jesulisti(cas, raspored[i])==0){
			pocetaktemp=dajvrijeme(raspored[i].pocetak);
			krajtemp=dajvrijeme(raspored[i].kraj);
			if((krajt>pocetaktemp && krajt<krajtemp)||(pocetakt>pocetaktemp && pocetakt<krajtemp)){
				return 1;
			}
			if(pocetakt<=pocetaktemp && krajt>=krajtemp)return 1;
		}
	}
	return 0;
}

/* ISPISUJE RASPORED U SKLADU SA TEKSTOM ZADATKA */

void ispis_rasporeda(struct Cas raspored[], int broj_casova){
	int i, j, k;
	struct Cas temp;
	int ima=0;
	int najmanji[7][24];
	int mini=210;
	int maxi=-1;
	for(i=1;i<7;i++){
		for(j=0;j<24;j++){
			najmanji[i][j]=-1;
		}
	}
	printf("       PON       UTO       SRI       CET       PET       SUB\n");
	for(j=0;j<broj_casova;j++){
		int vrijeme1, vrijeme2;
		vrijeme1=raspored[j].pocetak.sati;
		vrijeme2=raspored[j].kraj.sati;
		if(raspored[j].kraj.minute==0 && raspored[j].kraj.sekunde==0)vrijeme2--;
		for(k=vrijeme1;k<=vrijeme2;k++){
			if(najmanji[raspored[j].dan_u_sedmici][k]==-1){
				if(k<mini)mini=k;
				if(k>maxi)maxi=k;
				najmanji[raspored[j].dan_u_sedmici][k]=j;
			} else {
				int vr1, vr2;
				vr1=dajvrijeme(raspored[najmanji[raspored[j].dan_u_sedmici][k]].pocetak);
				vr2=dajvrijeme(raspored[j].kraj);
				if(vr1==vr2)najmanji[raspored[j].dan_u_sedmici][k]=j;
			}
		}
	}
	for(i=mini;i<=maxi;i++){
		printf("%d:00  ", i);
		if(i<10)printf(" ");
		for(k=1;k<7;k++){
			if(najmanji[k][i]!=-1){
				if(k!=6){
					printf("%-10s", raspored[najmanji[k][i]].predmet);
				}else 
					printf("%s", raspored[najmanji[k][i]].predmet);
			} else printf("          ");
		}
		printf("\n");
	}
}

/* ISPISUJE CASOVE KOJI SE NALAZE U ODREDJENOM DANU */

void ispisi_dan(struct Cas raspored[], int broj_casova, int dan){
	printf("Uneseni su casovi: \n");
	int i, brojac=1;
	for(i=0;i<broj_casova;i++){
		if(raspored[i].dan_u_sedmici==dan){
			printf("%d) %s (%02d:%02d-%02d:%02d)\n", brojac, raspored[i].predmet, raspored[i].pocetak.sati, raspored[i].pocetak.minute, raspored[i].kraj.sati, raspored[i].kraj.minute);
			brojac++;
		}
	}
}

/* MIJENJA CAS SA ONIM CASOM KOJI IMA REDNI BROJ redni_broj PO ISPISU ispisi_dan */

void promijeni_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj, struct Cas promjena){
	int i, brojac=1, index=-1;
	struct Cas temp;
	for(i=0;i<broj_casova;i++){
		if(raspored[i].dan_u_sedmici==dan){
			if(brojac==redni_broj){
				index=i;
			}
			brojac++;
		}
	}
	if(index==-1){
		return;
	}
	raspored[index]=promjena;
	//printf("Cas promjenjen.\n");
}

/* BRISE CAS KOJI IMA REDNI BROJ redni_broj PO ISPISU ispisi_dan */

void obrisi_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj){
	int i, brojac=1;
	for(i=0;i<broj_casova;i++){
		if(raspored[i].dan_u_sedmici==dan){
			if(brojac==redni_broj){
				raspored[i]=raspored[broj_casova-1];
				raspored[broj_casova-1].dan_u_sedmici=-1;
			//	printf("Cas obrisan.\n");
				return;
			}
			brojac++;
		}
	}
}

/* PROVJERAVA DA LI IMA MJESTA ZA trajanje CASOVA TE STAVLJA CAS NA PRVO SLOBODNO MJESTO */

int dodaj_cas(struct Cas raspored[], int broj_casova, const char* predmet, int trajanje){
	int i, j, k;
	int najmanji[7][24];
	if(broj_casova==200)return 0;
	for(i=1;i<7;i++){
		for(j=0;j<24;j++){
			najmanji[i][j]=-1;
		}
	}
	for(j=0;j<broj_casova;j++){
		int vrijeme1, vrijeme2;
		vrijeme1=raspored[j].pocetak.sati;
		vrijeme2=raspored[j].kraj.sati;
		if(raspored[j].kraj.minute==0 && raspored[j].kraj.sekunde==0)vrijeme2--;
		for(k=vrijeme1;k<=vrijeme2;k++){
			if(najmanji[raspored[j].dan_u_sedmici][k]==-1){
				najmanji[raspored[j].dan_u_sedmici][k]=j;
			} else {
				int vr1, vr2;
				vr1=dajvrijeme(raspored[najmanji[raspored[j].dan_u_sedmici][k]].pocetak);
				vr2=dajvrijeme(raspored[j].kraj);
				if(vr1==vr2)najmanji[raspored[j].dan_u_sedmici][k]=j;
			}
		}
	}
	int vpocetak, vkraj;
	trajanje=trajanje*3600;
	for(i=1;i<7;i++){
		vpocetak=9*3600;
		while(1){
			int s=vpocetak/3600;
            if(s<21 && najmanji[i][s]!=-1){
            	int gg=dajvrijeme(raspored[najmanji[i][s]].pocetak);
            	if(vpocetak>=gg){
            		vpocetak=dajvrijeme(raspored[najmanji[i][s]].kraj);
            	}
            }
            if(s>=21)break;
			struct Cas cas;
			for(k=0;;k++){
				cas.predmet[k]=predmet[k];
				if(predmet[k]=='\0')break;
			}
			cas.dan_u_sedmici=i;
			struct Vrijeme vrij;
			int vpoc=vpocetak;
			vrij.sati=vpocetak/3600;
			vpocetak=vpocetak%3600;
			vrij.minute=vpocetak/60;
			vpocetak=vpocetak%60;
			vrij.sekunde=vpocetak;
			cas.pocetak=vrij;
			vpocetak=vpoc+trajanje;
			vrij.sati=vpocetak/3600;
			vpocetak=vpocetak%3600;
			vrij.minute=vpocetak/60;
			vpocetak=vpocetak%60;
			vrij.sekunde=vpocetak;
			cas.kraj=vrij;
			if(vpoc+trajanje>68400)break;
            if(preklapanje(raspored, broj_casova, cas)==0){
                raspored[broj_casova]=cas;
                return 1;
			} else {
                s=vpoc/3600;
                while(s<21 && najmanji[i][s]==-1){
                	s++;
                }
                if(s==21)break;
                vpocetak=dajvrijeme(raspored[najmanji[i][s]].kraj);
			}
		}
	}
	return 0;
}

int main() {

	struct Cas raspored[KAPACITET];
	struct Cas cas;
	int a;
	char ime[10];
	int broj, dan, i;
	int broj_casova=0;

    broj_casova=ucitaj_datoteku(raspored);
	if(broj_casova==-1){
		broj_casova=0;
	}

	do{
		printf("1) Ispis rasporeda\n2) Dodavanje casa\n3) Promjena casa\n4) Brisanje casa\n0) Kraj rada\nIzaberite opciju: ");
		scanf("%d", &a);
		if(a==1){
			printf("\n");
			ispis_rasporeda(raspored, broj_casova);
		}
		if(a==2){
			printf("Unesite naziv predmeta: ");
			unesi(ime, 9);
	        printf("Unesite broj casova: ");
	        scanf("%d", &broj);
	        int f=dodaj_cas(raspored, broj_casova, ime, broj);
			if(f==1)broj_casova++;
			if(f==0)printf("Nema dovoljno mjesta u rasporedu za %d casova.\n", broj);
		}
		if(a==3){
			do{
				printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
				scanf("%d", &dan);
				ispisi_dan(raspored, broj_casova, dan);
				printf("Izaberite koji cas zelite promijeniti: ");
				scanf("%d", &broj);
				int brojaccasova=0;
				int ind=-1;
				for(i=0;i<broj_casova;i++){
					if(raspored[i].dan_u_sedmici==dan){
						brojaccasova++;
						if(brojaccasova==broj){
							ind=i;
						}
					}
				}
				if(ind==-1)continue;
				printf("Naziv predmeta: ");
				unesi(ime, 9);
				cas.dan_u_sedmici=dan;
				for(i=0;;i++){
					cas.predmet[i]=ime[i];
					if(ime[i]=='\0')break;
				}
				printf("Vrijeme pocetka: ");
				scanf("%d:%d", &cas.pocetak.sati, &cas.pocetak.minute);
				printf("Vrijeme zavrsetka: ");
				scanf("%d:%d", &cas.kraj.sati, &cas.kraj.minute);
				cas.pocetak.sekunde=0;
				cas.kraj.sekunde=0;
				struct Cas temp=raspored[ind];
				raspored[ind]=raspored[broj_casova-1];
				if(preklapanje(raspored, broj_casova-1, cas)==0){
					raspored[broj_casova-1]=raspored[ind];
					raspored[ind]=temp;
					promijeni_cas(raspored, broj_casova, dan, broj, cas);
					break;
				} else {
					raspored[broj_casova-1]=raspored[ind];
					raspored[ind]=temp;
					printf("Promjena nije moguca jer dovodi do preklapanja\n");
				}
				
			}while(1);
		}
		if(a==4){
			printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
			scanf("%d", &dan);
			ispisi_dan(raspored, broj_casova, dan);
			printf("Izaberite koji cas zelite obrisati: ");
			scanf("%d", &broj);
			obrisi_cas(raspored, broj_casova, dan, broj);
			if(raspored[broj_casova-1].dan_u_sedmici==-1){
				printf("Cas obrisan\n");
				broj_casova--;
			}
		}
	}while(a!=0);
	int g=zapisi_datoteku(raspored, broj_casova);
	if(g==0)printf("Nije zapisano.");
	return 0;
}
