#include <stdio.h>
#include <string.h>
#define KAPACITET 200
struct Vrijeme {
	int sati,minute,sekunde;
};
struct Cas {
	char predmet[10];
	int dan_u_sedmici;
	struct Vrijeme pocetak,kraj;
};

void unesi(char niz[]){
	char znak=getchar();
	if(znak=='\n')znak=getchar();
	int i=0;
	while(i<9 && znak!='\n'){
		niz[i++]=znak;
		znak=getchar();
	}
	niz[i]='\0';
	while(znak!='\n')
	znak=getchar();
}
int ucitaj_datoteku (struct Cas raspored[]){
	FILE *ulaz=fopen("raspored.dat","rb+");
	int greska=0;
	FILE *ulaz1=fopen("raspored.dat","rb+");
	if(ulaz==NULL || ulaz1==NULL){
		greska = 1;
		return 0;
	}
	int ucitano,ucitano1;
	int vel=sizeof(struct Cas);
	ucitano=fread(raspored,vel,KAPACITET,ulaz);
	ucitano1=fread(raspored,vel,KAPACITET,ulaz1);
	fclose(ulaz);
	fclose(ulaz1);
	if(greska==0)
	return ucitano1;
	else return 0;
}
int zapisi_datoteku(struct Cas raspored[],int broj_casova){
	FILE *ulaz=fopen("raspored.dat","wb+");
	FILE *ulaz1=fopen("raspored.dat","wb+");
	if(ulaz==NULL||ulaz1==NULL){
		return 0;
	}
	int vel=sizeof(struct Cas);
	int nova=fwrite(raspored,vel,broj_casova,ulaz);
	int zapisano=fwrite(raspored,vel,broj_casova,ulaz1);
	fclose(ulaz);
	fclose(ulaz1);
	if(nova==zapisano) return 1;
	else
	return 0;
}
int MAX(struct Cas raspored[],int broj_casova){
	int i,j,max=0,indexmaxa=0,min;
	for(i=0;i<broj_casova;i++){
		if(raspored[i].kraj.sati>max){
			max=raspored[i].kraj.sati;
			indexmaxa=i;
			min=raspored[indexmaxa].kraj.minute;
		}
	}
	if(min==0) max=max-1;
	return max;
}
void ispis_rasporeda(struct Cas raspored[],int broj_casova){
	printf("\n       PON       UTO       SRI       CET       PET       SUB\n");
	int i,j,k;
	int max=MAX(raspored,broj_casova);
	int min=25;
	for(i=0;i<broj_casova;i++){
		if(raspored[i].pocetak.sati<min)
		min=raspored[i].pocetak.sati;
	}
	for(i=min;i<=max;i++){
		if(i<10)printf("9:00   ");
		else    printf("%d:00  ",i);
		for(j=1;j<7;j++){
			for(k=0;k<broj_casova;k++){
				int sa=raspored[k].kraj.sati;
				int dan=raspored[k].dan_u_sedmici;
				int poc=raspored[k].pocetak.sati;
				if(poc<=i && dan==j &&sa>=i){
					printf("%-10s",raspored[k].predmet);
					break;
				}
			}
			if(k==broj_casova) printf("          ");
		}
		printf("\n");
	}
}
int PorediVrj(struct Vrijeme t1,struct Vrijeme t2,int i) {
	int sat=t1.sati*3600,sat1=t2.sati*3600,min=t1.minute*60,min1=t2.minute*60;
	int d1=sat+min+t1.sekunde;
	int d2=sat1+min1+t2.sekunde;
	int ukpnosek=d1+d2;
	if(d1>d2) return 1;
	else if(d1<d2) return -1;
	else return 0;
}
int preklapanje(struct Cas raspored[],int broj_casova,struct Cas cas){
	int prekl=0;
	int i;
	int broj=broj_casova;
	int dan=cas.dan_u_sedmici;
	for(i=0; i < broj ;i++){
		int drugi=PorediVrj(cas.kraj,raspored[i].pocetak,i);
		int vr=PorediVrj(raspored[i].kraj,cas.pocetak,i);
		if(i<0) return prekl;
		if(dan==raspored[i].dan_u_sedmici && vr==1 && drugi==1){
			prekl=1;
			break;
		}
	}
	if(i>-1)return prekl;
}
void ispisi_dan(struct Cas raspored[],int broj_casova,int dan){
	int brojac=1,i;
	printf("Uneseni su casovi: ");
	for(i=0;i<broj_casova;i++){
		if(raspored[i].dan_u_sedmici==dan){
			printf("\n%d) %s (%02d:%02d-%02d:%02d)",brojac,raspored[i].predmet,raspored[i].pocetak.sati,raspored[i].pocetak.minute,raspored[i].kraj.sati,raspored[i].kraj.minute);
			brojac++;
		}
	}
}
void obrisi_cas(struct Cas raspored[],int broj_casova,int dan,int redni_broj){
	int i; int k=0; int j; int brojac=1;
	int obrisanih=0;
	for(i=0;i<broj_casova;i++){
		if(raspored[i].dan_u_sedmici==dan){
			k++;
			if(k==redni_broj){
				for(j=i;j<broj_casova-1;j++){
					raspored[j]=raspored[j+1];
					obrisanih++;
				}
				if(brojac>0 && obrisanih>0) break;
			}
			brojac++;
		}
	}
}
int dodaj_cas(struct Cas raspored[],int broj_casova,const char *predmet,int trajanje){
	int i,j,preklop,brojac=1;
	int ukupno=broj_casova;
	if(ukupno==200) return 0;
	for(i=0;i<6;i++)
		for(j=9;j<=19-trajanje;j++){
			struct Cas cas={"",i+1,{j,0,0},{j+trajanje,0,0}};
			strcpy(cas.predmet,predmet);
			struct Cas pom={"",i,{j,0,0},{j,0,0}};
			preklop=preklapanje(raspored,broj_casova,cas);
			int pom1=preklapanje(raspored,broj_casova,cas);
			if(preklop==0){
				raspored[broj_casova]=cas;
				return 1;
			}
			brojac++;
		}
		if (brojac>0) return 0; 
			
		}
		struct Cas pr(int dan,int sat,int min,int sat1,int min1, char*ime){
			struct Cas casko={"",dan,{sat,min,0},{sat1,min1,0}};
			strcpy(casko.predmet,ime);
			return casko;
		}
		void promijeni_cas(struct Cas raspored[],int broj_casova,int dan,int redni_broj,struct Cas promjena){
			int i; int k=0;
			for(i=0;i<broj_casova;i++){
				if(raspored[i].dan_u_sedmici==dan) k++;
				if(k==redni_broj)
				raspored[i]=promjena;
			}
		}

int main() {
	struct Cas raspored[KAPACITET];
	int ucit=ucitaj_datoteku(raspored);
	int broj,br,dan,cs,zap;
	char ime[100];
	do{
	printf("1) Ispis rasporeda\n2) Dodavanje casa\n3) Promjena casa\n4) Brisanje casa\n0) Kraj rada\nIzaberite opciju: ");
	scanf("%d",&broj);
	switch (broj){
	case 4:
		printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
		scanf("%d",&dan);
		ispisi_dan(raspored,ucit,dan);
		printf("\nIzaberite koji cas zelite obrisati: ");
		scanf("%d",&cs);
		ucit--;
		obrisi_cas(raspored,ucit,dan,cs);
		printf("Cas obrisan\n");
		break;
	case 1:
		ispis_rasporeda(raspored,ucit);
		break;
	case 2:
		printf("Unesite naziv predmeta: ");
		unesi(ime);
		printf("Unesite broj casova: ");
		int nema;
		scanf("%d",&br);
		nema=dodaj_cas(raspored,ucit,ime,br);
		if(nema==0) printf("Nema dovoljno mjesta u rasporedu za %d casova.\n",br);
		if(nema==1) ucit++;
		break;
	case 3:
		printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
		scanf("%d",&dan);
		ispisi_dan(raspored,ucit,dan);
		printf("\nIzaberite koji cas zelite promijeniti: ");
		scanf("%d",&cs);
		printf("Naziv predmeta: ");
		unesi (ime);
		printf("Vrijeme pocetka: Vrijeme zavrsetka: ");
		int sat,min,sat1,min1;
		char z,z1;
		scanf("%d",&sat);
		scanf("%c",&z);
		scanf("%d",&min);
		scanf("%d",&sat1);
		scanf("%c",&z1);
		scanf("%d",&min1);
		struct Cas casko=pr(dan,sat,min,sat1,min1,ime);
		promijeni_cas(raspored,ucit,dan,cs,casko);
		break;
		
		break;
		
		case 0: 
		zap=zapisi_datoteku(raspored,ucit);
		return 0;
	}
		

}
while(broj!=0);
return 0;

}
