#include <stdio.h>
#include <string.h>
#define KAPACITET 200
struct Vrijeme{
	int sati, minute, sekunde;
};

struct Cas{
	char predmet[10];
	int dan_u_sedmici;
	struct Vrijeme pocetak, kraj;
};


char unesi(char niz[], int velicina){
	char znak=getchar();
	int vr=znak;
	int i=0;
	while (znak=='\n') 
	znak=getchar();
	while (i<velicina-1 && znak!='\n' && vr>0){
		niz[i++]=znak;
		znak=getchar();
	}
	niz[i]='\0';
	return znak;
}
void ocisti(char znak){
	int ima=0;
	if(znak=='\0') return;
	while(znak!='\n')
	znak=getchar();
}
int ucitaj_datoteku(struct Cas raspored[]){
	FILE* ulaz=fopen("raspored.dat","rb+");
	FILE* ulaz1=fopen("raspored.dat","rb+");
	if(ulaz==NULL || ulaz1==NULL){
		return 0;
	}
	int ucitano=fread(raspored,sizeof(struct Cas), KAPACITET, ulaz);
	int ucitano1=fread(raspored, sizeof(struct Cas), KAPACITET, ulaz1);
	fclose(ulaz);
	fclose(ulaz1);
	if(ucitano==ucitano1) 
	return ucitano;
}

int MAX(struct Cas raspored[], int broj_casova){
	int nasao=0;
	
	int i,j,max=0,indexmaxa=0;
	
	for(i=0;i<broj_casova;i++){
		if(raspored[i].kraj.sati>max){
			nasao=1;
			max=raspored[i].kraj.sati;
			indexmaxa=i;
		}
	}
	if(raspored[indexmaxa].kraj.minute==0 && nasao==1) max=max-1;
	if(nasao == 1)return max;
}

int MIN(struct Cas raspored[],int broj_casova){
	int i, j, min=25;
	int nasao=0;
	
	for(i=0; i<broj_casova; i++){
		if(raspored[i].pocetak.sati<min) 
		nasao=1;
		min=raspored[i].pocetak.sati;
	}
	if(nasao==1)
	return min;
}

void ispis_rasporeda(struct Cas raspored[], int broj_casova){
	int i,j,k;
	
	printf("\n       ");
	printf("PON       ");
	printf("UTO       ");
	printf("SRI       ");
	printf("CET       ");
	printf("PET       ");
	printf("SUB\n");
	
	for(i=MIN(raspored,broj_casova);i<=MAX(raspored,broj_casova);i++){
		if(i<10) printf("9:00   ");
		else printf("%d:00  ",i);
		
		for(j=1;j<7;j++){
			for(k=0;k<broj_casova;k++)
			if (raspored[k].pocetak.sati<=i && raspored[k].dan_u_sedmici==j && raspored[k].kraj.sati>=i){
				printf("%-10s", raspored[k].predmet);
				break;
			}
			if(k==broj_casova)
			printf("          ");
		}
		printf("\n");
	}
	
}

void ispisi_dan(struct Cas raspored[], int broj_casova, int dan){
	int i;
	printf("Uneseni su casovi: ");
	int k=1;
	int brojac=0;
	for(i=0;i<broj_casova;i++){
		if(raspored[i].dan_u_sedmici==dan){
			printf("\n%d) %s (",k++,raspored[i].predmet);
			if(raspored[i].pocetak.sati<10) printf("0");
			printf("%d:",raspored[i].pocetak.sati);
			if(raspored[i].pocetak.minute<10) printf("0");
			printf("%d-",raspored[i].pocetak.minute);
			if(raspored[i].kraj.sati<10) printf("0");
			printf("%d:",raspored[i].kraj.sati);
			if(raspored[i].kraj.minute<10) printf("0");
			printf("%d",raspored[i].kraj.minute);
			printf(")");
		}
		
		brojac++;
	}
}

int zapisi_datoteku(struct Cas raspored[], int broj_casova){
	int zapisano; int nova;
	FILE* ulaz=fopen("raspored.dat","wb+");
	FILE* ulaz1=fopen("raspored.dat","wb+");
	if(ulaz==NULL || ulaz1==NULL){
		return 0;
	}
	
	nova=fwrite(raspored,sizeof(struct Cas),broj_casova,ulaz);
	zapisano=fwrite(raspored,sizeof(struct Cas),broj_casova,ulaz1);
	
	fclose(ulaz);
	fclose(ulaz1);
	
	if(zapisano>=1 && nova==zapisano) return 1;
	else
	return 0;
}

void obrisi_cas(struct Cas raspored[],int broj_casova,int dan, int redni_broj){
	
	int i,j=0,obrisan=0;
	
	for(i=0;i<broj_casova;i++){
		if(raspored[i].dan_u_sedmici==dan) j++;
		if(redni_broj==j){
			obrisan=1;
			for(;i<broj_casova-1;i++)
			raspored[i]=raspored[i+1];
			break;
		}
	}
}

int PorediVrj(struct Vrijeme t1, struct Vrijeme t2){
	int d1=t1.sati*3600 + t1.minute*60 + t1.sekunde;
	int d2=t2.sati*3600 + t2.minute*60 + t2.sekunde;
	
	if(d1>d2) return 1;
	if(d1<d2) return -1;
	if(d1==d2) return 0;
	
	return -2;
}

int preklapanje(struct Cas raspored[],int broj_casova, struct Cas cas){
	
	int flag=0;
	int i;
	for(i=0;i<broj_casova;i++){
		int prvi=PorediVrj(raspored[i].kraj,cas.pocetak);
		int drugi=PorediVrj(cas.kraj,raspored[i].pocetak);
		
		if(prvi==1 && drugi==1 && (cas.dan_u_sedmici==raspored[i].dan_u_sedmici)){
			flag=1;
			break;
		}
	}
	
	return flag;
}

int dodaj_cas(struct Cas raspored[],int broj_casova, const char* predmet, int trajanje){
	
	if(broj_casova==200) return 0;
	int i,j,preklop;
	int dokle=19-trajanje;
	
	for(i=0;i<6;i++)
	for(j=9;j<=dokle;j++){
		struct Cas cas={"",i+1,{j,0,0},{j+trajanje,0,0}};
		struct Cas cas1={"pom",2,{0,0,0},{0,0,0}};
		char*q=cas.predmet,*p=(char*)predmet;
		
		while(*q++=*p++);
		char*a=cas1.predmet;
		char*b=cas1.predmet;
		if(a==b)
		preklop=preklapanje(raspored,broj_casova,cas);
		if(preklop==0){
			raspored[broj_casova]=cas;
			return 1;
		}
	}
	return 0;
}

void promijeni_cas(struct Cas raspored[], int broj_casova,int dan,int redni_broj,struct Cas promjena){
	
	int i, redni=0;
	for(i=0;i<broj_casova;i++){
		if(raspored[i].dan_u_sedmici==dan) redni++;
		if(redni_broj==redni)
		raspored[i]=promjena;
	}
}

int main() {
	int opcija, broj_casova=0;
	struct Cas raspored[KAPACITET];
	ucitaj_datoteku(raspored);
	do{
		printf("1) Ispis rasporeda\n2) Dodavanje casa\n3) Promjena casa\n4) Brisanje casa\n0) Kraj rada\nIzaberite opciju: ");
		scanf("%d",&opcija);
		switch(opcija){
			case 0: 
			{
				zapisi_datoteku(raspored,broj_casova);
				break;
			}
			case 1:
			{
				ispis_rasporeda(raspored,broj_casova);
				break;
			}
			case 2:
			{
				int br_casova, dodan=0;
				char predmet[10];
				printf("Unesite naziv predmeta: Unesite broj casova: ");
				ocisti(unesi(predmet,10));
				scanf("%d",&br_casova);
				dodan=dodaj_cas(raspored,broj_casova,predmet,br_casova);
				int vr=dodan;
				if(vr==0)
				printf("Nema dovoljno mjesta u rasporedu za %d casova.\n",br_casova);
				if(vr==1)
				broj_casova++;
				
				break;
			}
			
			case 3:
			{
				struct Cas promjena;
				int dan, redni;
				char*q,*p;
				char znak, predmet[10];
				printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
				scanf("%d", &dan);
				int BROJ=broj_casova;
				ispisi_dan(raspored,BROJ,dan);
				promjena.dan_u_sedmici=dan;
				int dani=dan+7;
				printf("\nIzaberite koji cas zelite promijeniti:  Naziv predmeta: ");
				scanf("%d",&redni);
				ocisti(unesi(predmet,10));
				
				q=promjena.predmet;
				p=predmet;
				strcpy(q,p);
				printf("Vrijeme pocetka: Vrijeme zavrsetka: ");
				scanf("%d%c%d",&promjena.pocetak.sati,&znak,&promjena.pocetak.minute);
				scanf("%d%c%d",&promjena.kraj.sati,&znak,&promjena.kraj.minute);
				
				
				if(dani>0) promijeni_cas(raspored, BROJ, dan, redni, promjena);
				break;
			}
			
			case 4:
			{
				int dan, redni;
				printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
				scanf("%d", &dan);
				
				ispisi_dan(raspored,broj_casova,dan);
				
				printf("\nIzaberite koji cas zelite obrisati: ");
				scanf("%d", &redni);
				obrisi_cas(raspored,broj_casova,dan,redni);
				printf(" Cas obrisan\n");
				broj_casova--;
			}
			
			
			
		}
		
	}
	
	while(opcija!=0);
	
	return 0;
}
