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

void unesi(char niz[]) {
	char znak=getchar();
	if(znak=='\n') znak=getchar();
	int i=0;
	while(i<9 && znak!='\n') {
		niz[i++]=znak;
		znak=getchar();
	}
	niz[i]='\0';
	while(znak!='\n')
	znak=getchar();
}


int ucitaj_datoteku(struct Cas raspored[]) {
	FILE *ulaz=fopen("raspored.dat", "rb+");
	int greska=0;
	FILE *ulaz1=fopen("raspored.dat", "rb+");
	if(ulaz==NULL || ulaz1==NULL) {
		greska=1;
		return 0;
	}
  
   int ucitano=fread(raspored, sizeof(struct Cas), KAPACITET, ulaz);
   int ucitano1=fread(raspored, sizeof(struct Cas), KAPACITET, ulaz1);
   fclose(ulaz);
   fclose(ulaz1);

return ucitano1                      ;
}

int zapisi_datoteku(struct Cas raspored[], int broj_casova) {
	FILE* dat=fopen("raspored.dat", "wb");
	int vel=sizeof(struct Cas);
    int ucitano=fwrite(raspored,vel,broj_casova,dat);
	fclose(dat);
	if(ucitano>0) return 1;
	return ucitano;
	}

void ispis_rasporeda(struct Cas raspored[], int broj_casova) {
	int i, j, k, x, s, min=100, max=0;
	int indexmaxa=0;
	for(i=0;i<broj_casova;i++) {
		if(raspored[i].pocetak.sati<min) min=raspored[i].pocetak.sati;
		if(raspored[i].kraj.sati>max) {
			max=raspored[i].kraj.sati;
			indexmaxa=i;
		}
	}
	if(raspored[indexmaxa].kraj.minute==0) max=max-1;
	printf("\n       PON       UTO       SRI");
	printf("       CET       PET       SUB\n");
	for(i=min;i<=max;i++) {
		if(i<10) printf("%d:00   ",i);
		else printf("%d:00  ", i);
		
		for(j=1;j<7;j++) {
			for(k=0;k<broj_casova;k++) {
				s=raspored[k].pocetak.sati; 
				if(s<=i && raspored[k].dan_u_sedmici==j && raspored[k].kraj.sati>=i) {
					printf("%-10s", raspored[k].predmet);
					break;
					x=i;
				}
			}
			if(k==broj_casova)
			for(x=0;x<10;x++)
			printf(" ");
		}
		printf("\n");
	}
	//printf("\n");
}

int preklapanje(struct Cas raspored[], int broj_casova, struct Cas cas) {
	int i;
	for(i=0;i<broj_casova;i++) {
		
		if(raspored[i].dan_u_sedmici==cas.dan_u_sedmici &&
		(cas.pocetak.minute+cas.pocetak.sati*60==raspored[i].pocetak.minute+raspored[i].pocetak.sati*60
		|| raspored[i].kraj.minute+raspored[i].kraj.sati*60==cas.kraj.minute+cas.kraj.sati*60)) return 1;
		
		if(raspored[i].dan_u_sedmici==cas.dan_u_sedmici && 
		(raspored[i].pocetak.minute+raspored[i].pocetak.sati*60<cas.pocetak.minute+cas.pocetak.sati*60 &&
		raspored[i].kraj.minute+raspored[i].kraj.sati*60>cas.pocetak.minute+cas.pocetak.sati*60 || 
		cas.pocetak.minute+cas.pocetak.sati*60<raspored[i].pocetak.minute+raspored[i].pocetak.sati*60 &&
		cas.kraj.minute+cas.kraj.sati*60>raspored[i].kraj.minute+raspored[i].kraj.sati*60 ||
		raspored[i].pocetak.minute+raspored[i].pocetak.sati*60<cas.kraj.minute+cas.kraj.sati*60 &&
		raspored[i].kraj.minute+raspored[i].kraj.sati*60>cas.kraj.minute+cas.kraj.sati*60)) return 1;
		
	}
	return 0;
}

void ispisi_dan(struct Cas raspored[], int broj_casova, int dan) {
	int brojac=1;
	int i;
	printf("Uneseni su casovi: ");
	for(i=0;i<broj_casova;i++) {
		if(raspored[i].dan_u_sedmici==dan) {
			printf("\n%d) %s (%02d:%02d-%02d:%02d)", brojac,
			raspored[i].predmet, raspored[i].pocetak.sati,
			raspored[i].pocetak.minute,raspored[i].kraj.sati,
			raspored[i].kraj.minute);
			brojac++;
		}
	}
}

void obrisi_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj) {
	int i, j;
	int k=0;
	int n=1;
	for(i=0;i<broj_casova;i++) {
		if(raspored[i].dan_u_sedmici==dan) { k++; n++; }
		if(k==redni_broj) {
			for(j=i;j<broj_casova-1;j++) {
				raspored[j]=raspored[j+1];
			}
			if(n>0) break;
			return;
		}
	}
}

int dodaj_cas(struct Cas raspored[], int broj_casova, const char *predmet, int trajanje) {
	if(broj_casova==200 || trajanje>10) return 0;
	int i, k, pocetak, dan, poc, moze=0;
	struct Cas cas;
	
	for(i=1;i<7;i++) 
	  for(k=9;k<=19-trajanje;k++) {
	  	dan=i;
	  	poc=k;
	  	strcpy(cas.predmet,predmet);
	  	cas.dan_u_sedmici=dan;
	  	cas.pocetak.sati=poc;
	  	cas.kraj.sati=k+trajanje;
	  	cas.pocetak.minute=cas.kraj.minute=0;
	  	if(preklapanje(raspored,broj_casova,cas)==0) {
	  	raspored[broj_casova]=cas;
	  	return 1;
	  }
}
  return 0;
}

void promijeni_cas(struct Cas raspored[], int broj_casova, int dan,int redni_broj, struct Cas promjena) {
	int i;
	int k=0;
	int index=0;
	for(i=0;i<broj_casova;i++) {
		if(raspored[i].dan_u_sedmici==dan) k++;
		if(k==redni_broj) {
			index=i;
			break;
		}
}
  raspored[index]=promjena;
}

int poziv(struct Cas raspored[], int ucit, char* ime, int br) {
	int vr=dodaj_cas(raspored,ucit,ime,br);
	return vr;
}

struct Cas zamj(struct Cas casko, int dan, int sat, int min, int sat1, int min1) {
	casko.dan_u_sedmici=dan;
	casko.pocetak.sati=sat;
	casko.pocetak.minute=min;
	casko.kraj.sati=sat1;
	casko.kraj.minute=min1;
	return casko;
	
}
int main() {
	struct Cas raspored[KAPACITET];
	int ucit=ucitaj_datoteku(raspored);
	int broj, br, rez, dan, cs, zap, m;
	char ime[100];
	for (m=0;m<KAPACITET;m++)
	{
		raspored[m].pocetak.sati=0;
		raspored[m].kraj.sati=0;
		raspored[m].dan_u_sedmici=1;
		raspored[m].pocetak.minute=0;
		raspored[m].kraj.minute=0;
		raspored[m].pocetak.sekunde=0;
		raspored[m].kraj.sekunde=0;
	}
	poc:
	printf("1) Ispis rasporeda\n");
	printf("2) Dodavanje casa\n");
	printf("3) Promjena casa\n");
	printf("4) Brisanje casa\n");
	printf("0) Kraj rada\n");
	printf("Izaberite opciju: ");
	scanf("%d", &broj);
	switch(broj) {
		case 1:
		ispis_rasporeda(raspored,ucit);
		if(broj==0) return 0;
		break;
		
		case 2:
		printf("Unesite naziv predmeta: ");
		unesi(ime);
		printf("Unesite broj casova: ");
		scanf("%d", &br);
		if(broj==0) return 0;
		rez=poziv(raspored,ucit,ime,br);
		if(rez==0) printf("Nema dovoljno mjesta u rasporedu za %d casova.\n", br);
		if(rez==1) ucit++;
		break;
	
       case 4:
     printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
     scanf("%d", &dan);
     ispisi_dan(raspored,ucit,dan);
     printf("\nIzaberite koji cas zelite obrisati: ");
     scanf("%d", &cs);
     obrisi_cas(raspored,ucit,dan,cs);
     if(broj==0) return 0;
     printf("Cas obrisan\n");
     ucit--;
     break;
     
     case 3:
     printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
     scanf("%d", &dan);
     int sat, min;
     char z;
     int sat1, min1;
     char z1;
     ispisi_dan(raspored,ucit,dan);
     if(broj==0) return 0;
     printf("\nIzaberite koji cas zelite promijeniti: ");
     scanf("%d", &cs);
     printf("Naziv predmeta: ");
     unesi(ime);
     printf("Vrijeme pocetka: ");
     scanf("%d", &sat);
     scanf("%c", &z);
     scanf("%d", &min);
     printf("Vrijeme zavrsetka: ");
     scanf("%d", &sat1);
     scanf("%c", &z1);
     scanf("%d", &min1);
     struct Cas casko={ime,dan,{sat,min,0},{sat1,min1,0}};
     strcpy(casko.predmet,ime);
     casko=zamj(casko,dan,sat,min,sat1,min1);
     promijeni_cas(raspored,ucit,dan,cs,casko);
     break;
     
     case 0:
     zap=zapisi_datoteku(raspored,ucit);
     return 0;
	}
	if(broj!=0) goto poc;
	return 0;
}
