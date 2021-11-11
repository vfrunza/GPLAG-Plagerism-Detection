#include <stdio.h>
#include <string.h>
#define KAPACITET 200

struct Vrijeme{
	int sati,minute,sekunde;
};

struct Cas {
	char predmet[10];
	int dan_u_sedmici;
	struct Vrijeme pocetak, kraj;
};

char unesi(char niz[], int velicina){
	char znak=getchar();
	int vel=velicina;
		int i = 0, k=0;
	if (znak== '\n')
		znak = getchar();
	while (i<vel && znak !='\n'){
		niz[i] = znak;
		i++;k++;
		znak=getchar();
	}
	niz[i]='\0';
	return znak;
}

void cln(char znak){
	while(znak!='\n')
		znak=getchar();
		
}

int ucitaj_datoteku(struct Cas raspored[]){
	FILE* dat = fopen("raspored.dat", "rb");
	if(dat==NULL) return 0;
	int ucitanih=fread(raspored,sizeof(struct Cas), KAPACITET,dat);
	fclose(dat);
	return ucitanih;
}
void isp(int vel){
	int x;
	int veli=vel/2;
	for(x=0;x<veli;x++)
		printf("  ");
		
}
void ispis_rasporeda(struct Cas raspored[], int broj_casova){
	int i,j,k,max=0,min=100;
	int indexmaxa=0;
	
	for (i=0;i<broj_casova;i++){
		if(raspored [i].pocetak.sati<min)
			min=raspored[i].pocetak.sati;
	} 
	printf("\n       PON       UTO       SRI"); //RAZMAK=7mjesta
	printf("       CET       ");
	printf("PET       SUB\n");
	
int mintt=0;
int indexpamtimo;
for (i=0; i<broj_casova;i++){
	if (raspored[i].kraj.sati>max){
		max=raspored[i].kraj.sati;
		mintt=raspored[i].kraj.minute;
		indexpamtimo=1;
	}
}

int x;
int s,dan,n;
if(mintt==0) max=max-1;
int poc=min;
int kraj=max;
int ukupno=broj_casova;
	for(i=poc;i<=kraj;i++){
		if(i<10) printf("%d:00   ",i); //4mjesta
	else printf("%02d:00  ",i);
		for(j=1;j<7;j++){
			
			for(k=0;k<ukupno;k++){
				if(max>0){
					dan=raspored[k].dan_u_sedmici;
					n=raspored[k].kraj.sati;
				if (raspored[k].pocetak.sati<=i && raspored[k].dan_u_sedmici==j && n>=i){
						printf("%-10s",raspored[k].predmet);
						break;
					}}}
					if(k==ukupno && ukupno>-1)
					isp(10);
		}
	printf("\n");
}
}

void pomispis(int k, char*s,int sat, int min, int sat1, int min1){
	printf("\n%d) %s (",k++,s);
	printf("%02d:%02d-",sat,min);
	printf("%02d:%02d)",sat1,min1);
}
void ispisi_dan(struct Cas raspored[], int broj_casova,int dan){
	int i,k=1;
		printf("Uneseni su casovi: ");
	for(i=0;i<broj_casova;i++){
		if(raspored[i].dan_u_sedmici==dan){
			int pocs=raspored[i].pocetak.sati;
			int pocm=raspored[i].pocetak.minute;
			int krajs=raspored[i].kraj.sati;
			int krajm=raspored[i].kraj.minute;
		pomispis(k++,raspored[i].predmet,pocs,pocm,krajs,krajm);
		
		}
	}
}


	
int zapisi_datoteku(struct Cas raspored[], int broj_casova){
	FILE *ulaz=fopen("raspored.dat","wb+");
	FILE *ulaz1=fopen("raspored.dat","wb+");
	if(ulaz==NULL || ulaz1==NULL)
		return 0;
	int nova=fwrite(raspored, sizeof (struct Cas), broj_casova,ulaz);
	int zapisano=fwrite(raspored,sizeof(struct Cas), broj_casova,ulaz1);
	if(nova!=zapisano) return 0;
	fclose(ulaz);
	fclose(ulaz1);
	if (nova>0) return 1;
	else
		return 0;
}


void obrisi_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj){
	int i,k=0,j;
	int bezzadnjeg=broj_casova-1;
	for(i=0;i<broj_casova;i++){
		if(raspored[i].dan_u_sedmici==dan){
			k++;
			if(k==redni_broj){
				for(j=i;j<bezzadnjeg;j++)
				raspored[j]=raspored[j+1];
				return;
			break;
			}
		}}}
int poredba(int p, int d){
	if (p > d) return 1;
	if (p < d) return -1;
	if (p == d) return 0;
}
int Poredi(struct Vrijeme t1, struct Vrijeme t2, int vel)
{
		int vr = t1.sati*vel*vel + t1.minute*vel + t1.sekunde, vr2 = t2.sati*vel*vel + t2.minute*vel + t2.sekunde;
		return poredba(vr,vr2);
		
}
int preklapanje (struct Cas raspored[],int broj_casova, struct Cas cas)
{
	
	int ima = 0;
	int i,prvi;
	for (i = 0; i < broj_casova; i++) {
		prvi=Poredi(raspored[i].kraj,cas.pocetak,60);
		if(prvi == 1 && Poredi(cas.kraj, raspored[i].pocetak,60)==1 && (cas.dan_u_sedmici==raspored[i].dan_u_sedmici))
		ima=1;
		break;
	}


return ima;
}


int dodaj_cas(struct Cas raspored[], int broj_casova, const char *predmet, int trajanje){
	if(broj_casova==200) return 0;
	int i,j,preklop;
	int ukupno=19-trajanje;
	for (i=0; i<6; i++){
		for(j=9; j<=ukupno; j++){
			struct Cas cas={"",i+1,{j,0,0},{j+trajanje,0,0}};
			char *q=cas.predmet,*p=(char*) predmet;
			struct Cas cc;
			while (*q++=*p++);
			preklop=preklapanje(raspored,broj_casova,cas);
			if(preklop==1) continue;
			else{
				raspored[broj_casova]=cas;
				goto jedan;
			}
		}
	}
	
	return 0;
	jedan:
	return 1;
}


void promijeni_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj,struct Cas promjena){
	int i, redni=0;
	for(i=0; i<broj_casova; i++){
		if(raspored[i].dan_u_sedmici==dan) redni++;
		if(redni_broj==redni)
			raspored[i]=promjena;
	}
}
void mjesto(int br){
	printf("Nema dovoljno mjesta u rasporedu za %d casova.\n",br);
}


int main() {
	int opcija, broj_casova=0;
	struct Cas raspored[KAPACITET];
	ucitaj_datoteku(raspored);
	do{
		printf("1) Ispis rasporeda\n");
		printf("2) Dodavanje casa\n3) Promjena casa\n");
		printf("4) Brisanje casa\n0) Kraj rada\n");
		printf("Izaberite opciju: ");
		scanf("%d",&opcija);
		
			if (opcija!=4 && opcija!=3 && opcija!=0 && opcija!=1){
				int br_casova,dodan=0;
				char predmet[10];
				printf("Unesite naziv predmeta: Unesite broj casova: ");
				cln(unesi(predmet,10));
				scanf("%d",&br_casova);
				
				dodan=dodaj_cas(raspored,broj_casova,predmet,br_casova);
				int vr=dodan;
				if(vr==0)
				mjesto(br_casova);
				if(vr==1)
				broj_casova++;
			}
			if (opcija!=0 && opcija!=3 && opcija!=2 && opcija!=1){
				int dan, redni;
				printf("Unesite dan ");
				printf("1=ponedjeljak, 2=utorak...,6=subota: ");
				scanf("%d",&dan);
				ispisi_dan(raspored,broj_casova,dan);
				printf("\nIzaberite koji cas zelite obrisati: ");
				scanf("%d",&redni);
				obrisi_cas(raspored,broj_casova,dan,redni);
					broj_casova--;
				printf("Cas obrisan\n");
			}
			if(opcija==0)
				zapisi_datoteku(raspored,broj_casova);
			if(opcija!=4 && opcija!=3 && opcija!=2 && opcija!=0);
				ispis_rasporeda(raspored,broj_casova);
			if(opcija!=4 && opcija!=0 && opcija!=2 && opcija!=1){
				struct Cas promjena;
				int dan,redni;
				char znak,predmet[10];
				printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota):");
				scanf("%d",&dan);
				ispisi_dan(raspored,broj_casova,dan);
				promjena.dan_u_sedmici=dan;
				printf("\nIzaberite koji cas zelite promijeniti: Naziv predmeta: ");
				scanf("%d",&redni);
				cln(unesi(predmet,10));
				char *q=promjena.predmet;
				char *p=predmet;
				while(*q++=*p++);
				int prvi=broj_casova;
				int drugi=dan;
				int treci=redni;
				printf("Vrijeme pocetka: Vrijeme zavrsetka: ");
				scanf("%d%c",&promjena.pocetak.sati,&znak);
				scanf("%d",&promjena.pocetak.minute);
				scanf("%d%c%d",&promjena.kraj.sati,&znak,&promjena.kraj.minute);
				promijeni_cas(raspored,prvi,drugi,redni,promjena);
			}
		
	} while(opcija!=0);
	return 0;
}