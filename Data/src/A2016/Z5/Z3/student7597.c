#include <stdio.h>
#include<string.h>
#define KAPACITET 200

struct Vrijeme{
	int sati, minute, sekunde;
};
struct Cas{
	char predmet[10];
	int dan_u_sedmici;
	struct Vrijeme pocetak, kraj;
};
void unesi(char niz[]){ //unos stringa
char znak= getchar();
if(znak=='\n') znak=getchar();
int i=0;
while(i<9 && znak!='\n'){
	niz[i++]=znak;
	znak=getchar();
	
}
niz[i]='\0';
while(znak!='\n') //ocistimo spremnik ako se unese previse znakova
znak=getchar();
}

int ucitaj_datoteku(struct Cas raspored[]){ //ucitavanje binarne
FILE*dat=fopen("raspored.dat", "rb");
if(dat==NULL) return 0;
int ucitanih=fread(raspored, sizeof(struct Cas), KAPACITET, dat);
fclose(dat);
return ucitanih;
}
int zapisi_datoteku(struct Cas raspored[], int broj_casova){ //zapisivanje binarne
FILE*dat=fopen("raspored.dat", "wb");
int ucitano=fwrite(raspored, sizeof(struct Cas), broj_casova,dat);
fclose(dat);
if(ucitano>0) return 1;
return ucitano;
}

int MAX(struct Cas raspored[], int broj_casova){
	int i,j,max=0,indexmaxa=0;
	for(i=0;i<broj_casova;i++){
		if(raspored[i].kraj.sati>max){
			max=raspored[i].kraj.sati;
			indexmaxa=i;
		}
		
	}
	if(raspored[indexmaxa].kraj.minute==0) max=max-1;
	return max;
}
int MIN(struct Cas raspored[], int broj_casova){
	int i,j,min=25;
	for(i=0; i<broj_casova;i++){
		if(raspored[i].pocetak.sati<min)
		min=raspored[i].pocetak.sati;
	}
	return min;
}
void ispis_rasporeda(struct Cas raspored[], int broj_casova){
	int i,j,k;
	int max=MAX(raspored,broj_casova);
	int min=MIN(raspored,broj_casova);
	
	printf("\n       PON       UTO       SRI       CET       PET       SUB\n");
	for(i=min;i<=max;i++){
		if(i<10) printf("%d:00   ",i);
		else printf("%d:00  ",i);
		for(j=1;j<7;j++){
			for(k=0;k<broj_casova;k++)
			if( raspored[k].pocetak.sati<=i &&
			raspored[k].dan_u_sedmici==j && raspored[k].kraj.sati>=i){
				printf("%-10s",raspored[k].predmet);
				break;
			}
			if(k==broj_casova)
			printf("          ");
			}
			printf("\n");
		}
	}
	int preklapanje(struct Cas raspored[], int broj_casova, struct Cas cas){
		int i;
		int minpoc1,minpoc2,minkraj1,minkraj2;
		for(i=0;i<broj_casova;i++){ //pretvorimo u minute vrijeme
		minpoc1=raspored[i].pocetak.minute+raspored[i].pocetak.sati*60;
		minkraj1=raspored[i].kraj.minute+raspored[i].kraj.sati*60;
		minpoc2=cas.pocetak.minute+cas.pocetak.sati*60;
		minkraj2=cas.kraj.minute+cas.kraj.sati*60;
		//ako 2 casqa zavrsavaju u isto vrijeme i u isti dan, sigurno su se preklopila
		if(raspored[i].dan_u_sedmici==cas.dan_u_sedmici && (minpoc2==minpoc1 || minkraj1==minkraj2)) return 1;
		//ako su isti dan i ako se desi da se poklapa
		if(raspored[i].dan_u_sedmici==cas.dan_u_sedmici && (minpoc1<minpoc2 && minkraj1>minpoc2 || minpoc2<minpoc1 && minkraj2>minkraj1 || minpoc1<minkraj2 && minkraj1>minkraj2)) return 1;
		
		}
		return 0;
	}
	void ispisi_dan(struct Cas raspored[], int broj_casova, int dan){
		int i;
		printf("Uneseni su casovi: ");
		int k=1;
		for(i=0;i<broj_casova;i++){
			if(raspored[i].dan_u_sedmici==dan){
				printf("\n%d) %s (",k++,raspored[i].predmet); //morali ispitivati zbog dodavaja 0 pri ispisu
				if(raspored[i].pocetak.sati<10) printf("0");
				printf("%d:",raspored[i].pocetak.sati);
				if(raspored[i].pocetak.minute<10) printf("0");
				printf("%d-",raspored[i].pocetak.minute);
				if(raspored[i].kraj.sati<10) printf('0');
				printf("%d:", raspored[i].kraj.sati);
				if(raspored[i].kraj.minute<10) printf("0");
				printf("%d)",raspored[i].kraj.minute);
			}
		}
		
	}
	void obrisi_cas(struct Cas raspored[],int broj_casova, int dan, int redni_broj){
		int i; int k=0;
		for(i=0;i<broj_casova;i++){
			if(raspored[i].dan_u_sedmici==dan) k++;
			if(k==redni_broj){
				int j;
				for(j=i; j<broj_casova-1; j++){ //klasicno izbacivanje iz niza
				raspored[j]=raspored[j+1];
				}
				break;
		}
	}}
	struct Cas prekopiraj(int i, int k, int trajanje, char*predmet)
	{
		struct Cas cas;
		strcpy(cas.predmet,predmet);
		cas.dan_u_sedmici=i;
		cas.pocetak.sati=k;
		cas.kraj.sati=k+trajanje;
		cas.pocetak.minute=cas.kraj.minute=0;
		return cas;
	}
	int dodaj_cas(struct Cas raspored[], int broj_casova, const char*predmet, int trajanje){
		if(broj_casova==200 || trajanje>10) return 0;
		int i,k,pocetak,dan,moze=0;
		struct Cas cas;
		
		for(i=1;1<7;i++) //prodjemo kroz sedmicu
		for(k=9;k<=19-trajanje;k++){ //prodjemo kroz vrijeme
		cas=prekopiraj(i,k,trajanje,predmet);
		if(preklapanje(raspored,broj_casova,cas)==0){
			//trazimo prvo mjesto gdje se ne desi preklapanje
			raspored[broj_casova]=cas;
			return 1;
			
		}
	}
	return 0;
		
	}
	void promijeni_cas(struct Cas raspored[],int broj_casova,int dan, int redni_broj, struct Cas promjena){
		int i; int k=0;
		for(i=0;i<broj_casova;i++){
			if(raspored[i].dan_u_sedmici==dan) k++;
			if(k==redni_broj){
				raspored[i]=promjena; //samo dodijelimo novi cas
				return;
			}
		}
	}
int main() {
	struct Cas raspored[KAPACITET];
	int ucit=ucitaj_datoteku(raspored);
	int broj,br,dan,cs; char ime[100]; int zap;
	do{
		printf("1) Ispis rasporeda\n2) Dodavanje casa\n3) Promjena casa\n4) Brisanje casa\n0) Kraj rada\nIzaberite opciju: ");
		scanf("%d",&broj);
		switch(broj){
		case 1:
			ispis_rasporeda(raspored, ucit);
			break;
			
		case 2:
			printf("Unesite naziv predmeta: ");
			unesi(ime);
			printf("Unesite broj casova: ");
			scanf("%d",&br);
			int nema=dodaj_cas(raspored,ucit,ime,br);
			if(nema==0) printf("Nema dovoljno mjesta u rasporedu za %d casova.\n",br);
			else ucit++;
			break;
		case 3:
		    printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
		    scanf("%d", &dan);
		    ispisi_dan(raspored,ucit,dan);
		    printf("\nIzaberite koji cas zelite promijeniti: ");
		    scanf("%d",&cs);
		    printf("Naziv predmeta: ");
		    unesi(ime);
		    printf("Vrijeme pocetka: ");
		    int sat, min;
		    char z;
		    scanf("%d%c%d", &sat,&z,&min);
		    printf("Vrijeme zavrsetka: ");
		    int sat1,min1;
		    char z1;
		    scanf("%d%c%d", &sat1, &z1, &min1);
		    struct Cas casko={ime,dan,{sat,min,0},{sat1,min1,0}};
		    strcpy(casko.predmet,ime);
		    casko.dan_u_sedmici=dan;
		    casko.pocetak.sati=sat;
		    casko.pocetak.minute=min;
		    casko.kraj.sati=sat1;
		    casko.kraj.minute=min1;
		    promijeni_cas(raspored,ucit,dan,cs,casko);
		    break;
		    case 4:
		    printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
		    scanf("%d", &dan);
		    ispisi_dan(raspored,ucit,dan);
		    printf("\nIzaberite koji cas zelite obrisati: ");
		    scanf("%d", &cs);
		    obrisi_cas(raspored,ucit,dan,cs);
		    printf("Cas obrisan\n");
		    ucit--;
		    break;
		    case 0:
		    zap=zapisi_datoteku(raspored,ucit);
		    return 0;
		    }
	}while(broj!=0);
	return 0;
}
