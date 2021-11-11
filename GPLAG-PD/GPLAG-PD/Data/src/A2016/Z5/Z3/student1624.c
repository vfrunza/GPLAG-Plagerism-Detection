#include <stdio.h>
#include <string.h>
#define KAPACITET 200

struct Vrijeme{
	int sati, minute,sekunde;
};
struct Cas{
	char predmet[10];
	int dan_u_sedmici;
	struct Vrijeme pocetak, kraj;
};
void unesi(char niz[]){ //funkcija unesi sa predavanja
	char znak=getchar();
	int brojac=0;
	if(znak=='\n') 
	{
		znak=getchar();
		brojac++;
	}
	int i=0;
	while(znak!='\n' && i<9){
		brojac++;
		niz[i++]=znak;
		znak=getchar();
	}
	niz[i]='\0';
	while(znak!='\n')	//ako se unese vise , moramo ocistit spremnik
	znak=getchar();
}
int ucitaj_datoteku(struct Cas raspored[]){	//ucitavanje sablon
	FILE *ulaz;
	int velicina=sizeof(struct Cas);
	ulaz=fopen("raspored.dat","rb+");
	if(ulaz==NULL) return 0;
	int ucit;
	ucit=fread(raspored,sizeof(struct Cas),KAPACITET,ulaz);	//broj cuitanih to i vratimo
	fclose(ulaz);
	return ucit;
}
int zapisi_datoteku(struct Cas raspored[],int broj_casova){	//zapisujemo datoteku isto sabloon
	int zapisano;
	int nova;
	FILE*ulaz;
	FILE*ulaz1;		//mogli smo i smo 1 da otvaramo
	ulaz=fopen("raspored.dat","wb+");
	ulaz1=fopen("raspored.dat","wb+");
	if(ulaz==NULL) return 0;	//ako ijedna izbaci gresku 
	if(ulaz1==NULL) return 0;
	zapisano=fwrite(raspored,sizeof(struct Cas),broj_casova,ulaz);	//spasimo broj zapisanih i to vratimo
	nova=fwrite(raspored,sizeof(struct Cas),broj_casova,ulaz1);
	fclose(ulaz1);
	fclose(ulaz);
	if(nova>0) return 1;
	if(nova<1) return 0;
}

int minimal(struct Cas raspored[],int broj_casova){	//f vrati sate prvog casa
	int i;
	int j;
	int min=25;
	int brojac=1;
	for(i=0;i<broj_casova;i++){
		if(raspored[i].pocetak.sati<min)
			min=raspored[i].pocetak.sati;
		brojac++;
	}
	brojac=min;
 return brojac;
}
void dali(struct Cas raspored[],int i,int broj_casova){//ispis rasporeda
	int k;
	int j;
	int d;
	int o;
	for(j=1;j<7;j++){
		for(k=0;k<broj_casova;k++){
			d=i;
			o=raspored[k].dan_u_sedmici;
			if(raspored[k].pocetak.sati<=d && o==j && raspored[k].kraj.sati>=i){
				printf("%-10s",raspored[k].predmet);
				break;
			}
		}
			if(k==broj_casova){	//ispis praznih mjesta
				int n;
				for(n=0;n<10;n++)
				printf(" ");
			}
	}
}

void ispisi_dan(struct Cas raspored[], int broj_casova, int dan){
	int i;
	printf("Uneseni su casovi: ");
	int brojac=1;
	for(i=0;i<broj_casova;i++)
		if(raspored[i].dan_u_sedmici==dan){
		
		printf("\n");	//ako je dan u sedmici taj dan, printamo sve predmete na taj dan
		printf("%d) %s (%02d:%02d-%02d:%02d)",brojac++,raspored[i].predmet,raspored[i].pocetak.sati, raspored[i].pocetak.minute, raspored[i].kraj.sati,raspored[i].kraj.minute);
		}
}
void obrisi_cas(struct Cas raspored[],int broj_casova,int dan, int redni_broj){
	int i,j;
	int k=0;
	for(i=0;i<broj_casova;i++){
		if(raspored[i].dan_u_sedmici==dan){
			k++;
		}
		if(redni_broj==k){
			if(k==redni_broj)
				for(j=i;j<broj_casova-1;j++)
				raspored[j]=raspored[j+1]; //da ne gubi redoslijed
			break;
		}
	}
	for(i=0;i<broj_casova;i++){
		k++;
	}
}
void ispis_rasporeda(struct Cas raspored[],int broj_casova){	
	int k,i,j;
	int max=0; 
	int indexm=0;
	int brojac=0;
	printf("\n       PON       UTO       SRI       CET       PET       SUB\n");
	for(i=0;i<broj_casova;i++){
		if(raspored[i].kraj.sati>max){
			max=raspored[i].kraj.sati;
			brojac=brojac+1;
			indexm=i;
		}
	}
	if(raspored[indexm].kraj.minute==0) 
		max--;
	int min;
	int x;
	min=minimal(raspored,broj_casova);
	for(i=min;i<=max;i++){
	if(i<10) printf("%d:00   ",i);
	else printf("%d:00  ",i);
	dali(raspored,i,broj_casova);
	for(x=0;x<10;x++) brojac++;
	printf("\n");
}}
	int preklapanje(struct Cas raspored[],int broj_casova, struct Cas cas){
		int i;
		int pocsat;
		int krajsat;
		int br=1;
		for(i=0;i<broj_casova;i++) br++;
		if(br>0){
		for(i=0;i<broj_casova;i++){
			 pocsat=raspored[i].pocetak.sati;
			krajsat=raspored[i].kraj.sati;
			if(cas.dan_u_sedmici==raspored[i].dan_u_sedmici){
				if(pocsat==cas.pocetak.sati || krajsat==cas.kraj.sati) return 1;
				if(pocsat==cas.kraj.sati && raspored[i].pocetak.minute<cas.kraj.minute) return 1;
				if(raspored[i].kraj.sati==cas.pocetak.sati && raspored[i].kraj.minute>cas.pocetak.minute) return 1;
				if(pocsat<cas.pocetak.sati && krajsat>cas.kraj.sati) return 1;
				if(pocsat>cas.pocetak.sati&&krajsat<cas.kraj.sati) return 1;
				if(pocsat>cas.pocetak.sati&&pocsat<cas.kraj.sati) return 1;
				if(krajsat>cas.pocetak.sati && krajsat<cas.kraj.sati) return 1;
				if(pocsat<cas.pocetak.sati && krajsat>cas.kraj.sati) return 1;
				if(pocsat>cas.pocetak.sati && krajsat<cas.kraj.sati) return 1;
				if(pocsat<cas.pocetak.sati && krajsat>cas.kraj.sati) return 1;
		}
	}}
	return 0;
	
}
void promijeni_cas(struct Cas raspored[],int broj_casova,int dan,int redni_broj, struct Cas promjena){
	int i;
	int redni=0;
	for(i=0;i<broj_casova;i++){
		if(raspored[i].dan_u_sedmici==dan) redni=redni+1;
		if(redni_broj==redni)
			raspored[i]=promjena;
	}
}
int dodaj_cas(struct Cas raspored[],int broj_casova,const char*predmet,int trajanje){
	if(broj_casova==200) return 0;
	int i;
	int j;
	int preklapanjee;
	for(i=0;i<6;i++)
		for(j=9;j<=19-trajanje;j++){
			int dan=i+1;
			int sat=j;
			int zav=j+trajanje;
			struct Cas cas={"",dan,{sat,0,0},{zav,0,0}};
			cas.pocetak.sati=sat;
			cas.kraj.sati=zav;
			char *q=cas.predmet;
			char *p=(char*) predmet;
			strcpy(q,p);
			int ima=0;
			preklapanjee=preklapanje(raspored,broj_casova,cas);
			if(preklapanjee==0){
				ima =1;
				raspored[broj_casova]=cas;
				return 1;
			}
			if(preklapanjee==1) continue ;
		}
		return 0;
}
int main() {
	int op,broj_casova=0;
	struct Cas raspored[KAPACITET];
	ucitaj_datoteku(raspored);
	printf("1) Ispis rasporeda\n2) Dodavanje casa\n3) Promjena casa\n4) Brisanje casa\n0) Kraj rada\nIzaberite opciju: ");
	do{
		scanf("%d",&op);
		if(op==1) {ispis_rasporeda(raspored,broj_casova);
	 	if(op==1)	printf("1) Ispis rasporeda\n");
		if(op==1)	printf("2) Dodavanje casa\n");
		if(op==1)	printf("3) Promjena casa\n");
		if(op==1)	printf("4) Brisanje casa\n");
		if(op==1)	printf("0) Kraj rada\nIzaberite opciju: ");
		}
		if(op==2 && op!=0){
			int br_cas;
			int dod=0;
			printf("Unesite naziv predmeta: ");
		
			char predmet[10];
			unesi(predmet);
			printf("Unesite broj casova: ");
			scanf("%d",&br_cas);
			dod=dodaj_cas(raspored,broj_casova,predmet,br_cas);
			if (op==2){if(!dod)
				printf("Nema dovoljno mjesta u rasporedu za %d casova.\n",br_cas);
			if(dod)
				broj_casova=broj_casova+1;}
			  printf("1) Ispis rasporeda\n");
		      printf("2) Dodavanje casa\n");
	       		printf("3) Promjena casa\n");
	     		printf("4) Brisanje casa\n");
	    		printf("0) Kraj rada\nIzaberite opciju: ");
		}
		if(op==4 && op!=3 && op!=1){
			int dan;
			int redni;
			printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
			scanf("%d",&dan);
			ispisi_dan(raspored,broj_casova,dan);
			printf("\n");
			printf("Izaberite koji cas zelite obrisati: ");
			scanf("%d",&redni);
			obrisi_cas(raspored,broj_casova,dan,redni);
			printf("Cas obrisan\n");
			broj_casova=broj_casova-1;
		if(op==4)	printf("1) Ispis rasporeda\n");
		  if(op==4)  printf("2) Dodavanje casa\n");
		if(op==4)	printf("3) Promjena casa\n");
		if(op==4)	printf("4) Brisanje casa\n");
		if(op==4)	printf("0) Kraj rada\nIzaberite opciju: ");
			
		}
		if(op==0)  if(op!=1 && op!=3)zapisi_datoteku(raspored,broj_casova);
		if(op==3 && op!=0){
			int dan;
			int redni;
			char*p;
			char*q;
			char znak;
			char predmet[10];
			int broj=broj_casova;
			printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
			scanf("%d",&dan);
			ispisi_dan(raspored,broj,dan);
			printf("\nIzaberite koji cas zelite promijeniti: Naziv predmeta: ");
			scanf("%d",&redni);
			struct Cas prom;
			unesi(prom.predmet);
			/*q=prom.predmet;
			p=predmet;
			strcpy(q,p);*/
			printf("Vrijeme pocetka: Vrijeme zavrsetka: ");
			if(op==3){
			scanf("%d%c",&prom.pocetak.sati,&znak);
			scanf("%d%d",&prom.pocetak.minute,&prom.kraj.sati);
			scanf("%c%d",&znak,&prom.kraj.minute);}
			prom.dan_u_sedmici=dan;
			promijeni_cas(raspored,broj,dan,redni,prom);
			if(op==3){
			printf("1) Ispis rasporeda\n");
			printf("2) Dodavanje casa\n");
			printf("3) Promjena casa\n");
			printf("4) Brisanje casa\n");
			printf("0) Kraj rada\nIzaberite opciju: ");}
		}
			
		
	}while(op!=0);
	return 0;
}
