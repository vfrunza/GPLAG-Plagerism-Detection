/*
#include <stdio.h>
#include <string.h>
#define KAPACITET 200

struct Vrijeme {
	int sati, minute, sekunde;
};

struct Cas {
	char predmet[10];
    int dan_u_sedmici; 
    struct Vrijeme pocetak,kraj;
};

char unesi(char niz[],int velicina) {
	char znak;
	znak=getchar();
	if(znak=='\n') znak=getchar();
	int i=0;
	while(i<velicina-1 && znak!='\n') {
		niz[i++]=znak;
		znak=getchar();
	}
	niz[i]='\0';
	return znak;
}

void ocisti(char znak) {
	while(znak!='\n') znak=getchar();
}

int ucitaj_datoteku(struct Cas raspored[]) {
	FILE *ulaz=fopen("raspored.dat","rb+");
	if(ulaz==NULL) return 0;
	int vel=KAPACITET;
	int velicina=sizeof(struct Cas);
	int ucitano=fread(raspored,velicina,vel,ulaz);
	fclose(ulaz);
	return ucitano;
}

void ispis_rasporeda(struct Cas raspored[],int broj_casova) {
	printf("\n       ");
	printf("PON       ");
	printf("UTO       ");
	printf("SRI       ");
	printf("CET       ");
	printf("PET       ");
	printf("SUB\n");
	int i,j,k;
	int max=0;
	int min=25;
	int indexmaxa;
	for(i=0;i<broj_casova;i++) {
		if(raspored[i].kraj.sati>max) {
			max=raspored[i].kraj.sati;
			indexmaxa=i;
		}
	}
	if(raspored[indexmaxa].kraj.minute==0) max=max-1;
	
	for(i=0;i<broj_casova;i++) {
		if(raspored[i].pocetak.sati<min) 
		min=raspored[i].pocetak.sati;
	}
	for(i=min;i<=max;i++) {
		if(i<10) printf("%d:00   ",i);
		else printf("%d:00  ",i);
		
		for(j=1;j<7;j++) {
			for(k=0;k<broj_casova;k++) {
				int sa=raspored[k].kraj.sati;
				int dan=raspored[k].dan_u_sedmici;
				int poc=raspored[k].pocetak.sati;
				
				if(poc<=i && dan==j && sa>=i) {
					printf("%-10s",raspored[k].predmet);
					break;
				}
			}
			if(k==broj_casova)
			printf("          ");
		}
		printf("\n");
	}
}

void ispisi_dan(struct Cas raspored[],int broj_casova,int dan) {
	int i;
	printf("Uneseni su casovi: ");
	int k=1;
	for(i=0;i<broj_casova;i++) {
		if(raspored[i].dan_u_sedmici==dan) {
			printf("\n%d) %s (",k++,raspored[i].predmet);
			printf("%02d:",raspored[i].pocetak.sati);
			printf("%02d-",raspored[i].pocetak.minute);
			printf("%02d:",raspored[i].kraj.sati);
			printf("%02d)",raspored[i].kraj.minute);
		}
	}

}

void obrisi_cas(struct Cas raspored[],int broj_casova, int dan, int redni_broj) {
	int i;
	int k=0;
	int j, brojac=1;
	
	for(i=0;i<broj_casova;i++) {
		if(raspored[i].dan_u_sedmici==dan) {
			k++;
			if(k==redni_broj) {
				for(j=i;j<broj_casova-1;j++) {
					raspored[j]=raspored[j+1];
				}
				if(brojac>0) break;
			}
			brojac++;
		}
	}
}	

int preklapanje(struct Cas raspored[], int broj_casova, struct Cas cas) {
	int i;
	for(i=0;i<broj_casova;i++) {
		int pocsat=raspored[i].pocetak.sati;
		int krajsat=raspored[i].kraj.sati;
		
		if(cas.dan_u_sedmici==raspored[i].dan_u_sedmici) {
			if(pocsat==cas.pocetak.sati || krajsat==cas.kraj.sati)
			return 1;
			
			if(pocsat==cas.kraj.sati && raspored[i].pocetak.minute<cas.kraj.minute)
			return 1;
			
			if(raspored[i].kraj.sati==cas.pocetak.sati && raspored[i].kraj.minute>cas.pocetak.minute)
			return 1;
			
			if(pocsat<cas.pocetak.sati && krajsat>cas.kraj.sati)
			return 1;
			
			if(pocsat>cas.pocetak.sati && krajsat<cas.kraj.sati)
			return 1;
			
			if(pocsat>cas.pocetak.sati && pocsat<cas.kraj.sati)
			return 1;
			
			if(krajsat>cas.pocetak.sati && krajsat<cas.kraj.sati)
			return 1;
			
			if(pocsat<cas.pocetak.sati && krajsat>cas.kraj.sati)
			return 1;
			
			if(pocsat>cas.pocetak.sati && krajsat<cas.kraj.sati)
			return 1;
			
			if(pocsat<cas.pocetak.sati && krajsat>cas.kraj.sati)
			return 1;
		}
	}
	return 0;
}
	
int dodaj_cas(struct Cas raspored[],int broj_casova, const char *predmet, int trajanje) {
	if(broj_casova==200 || trajanje>10) return 0;
	int i,k,pocetak,dan,moze=0;
	struct Cas cas;
	for(i=1;i<7;i++)
	for(k=9;k<=19-trajanje;k++) {
		moze=0;
		
		strcpy(cas.predmet,predmet);
		
		cas.dan_u_sedmici=i;
		cas.pocetak.sati=k;
		cas.kraj.sati=k+trajanje;
		cas.pocetak.minute=cas.kraj.minute=0;
		
		if(preklapanje(raspored,broj_casova,cas)==0) {
			moze=1;
			raspored[broj_casova]=cas;
			return 1;
		}
	}
	return 0;
}

void promijeni_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj, struct Cas promjena) {
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

int zapisi_datoteku(struct Cas raspored[],int broj_casova) {
	int vel,ucitano;
	FILE* dat=fopen("raspored.dat","wb");
	vel=sizeof(struct Cas);
	ucitano=fwrite(raspored,vel,broj_casova,dat);
	fclose(dat);
	
	if(ucitano>0) return 1;
	else return ucitano;
}

void ispis() {
	printf("1) Ispis rasporeda\n2) Dodavanje casa\n3) Promjena casa\n4) Brisanje casa\n0) Kraj rada\nIzaberite opciju: ");
	
}

int main () {
	int opcija,broj_casova=0;
	struct Cas raspored[KAPACITET];
	ucitaj_datoteku(raspored);
	do {
		ispis();
		scanf("%d",&opcija);
		
		if(opcija==3) {
			struct Cas promjena;
			int dan,redni;
			printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
			scanf("%d",&dan);
			
			ispisi_dan(raspored,broj_casova,dan);
			promjena.dan_u_sedmici=dan;
			printf("\nIzaberite koji cas zelite promijeniti: ");
			scanf("%d",&redni);
			printf("Naziv predmeta: ");
			char predmet[10];
			
			if(opcija!=0)
			ocisti(unesi(predmet,10));
			
			char *q=promjena.predmet, *p=predmet;
			
			strcpy(q,p);
			char znak;
			printf("Vrijeme pocetka: ");
			scanf("%d",&promjena.pocetak.sati);
			scanf("%c",&znak);
			
			scanf("%d",&promjena.pocetak.minute);
			printf("Vrijeme zavrsetka: ");
			
			scanf("%d%c",&promjena.kraj.sati,&znak);
			scanf("%d",&promjena.kraj.minute);
			
			if(opcija!=0)
			promijeni_cas(raspored,broj_casova,dan,redni,promjena);
			
		}
		if(opcija==0)
		zapisi_datoteku(raspored,broj_casova);
		
		if(opcija==1)
		ispis_rasporeda(raspored,broj_casova);
		
		if(opcija==2) {
			int br_casova,dodan=0;
			char predmet[10];
			printf("Unesite naziv predmeta: ");
			if(opcija!=0) ocisti(unesi(predmet,10));
			printf("Unesite broj casova: ");
			scanf("%d",&br_casova);
			
			if(opcija!=0) dodan=dodaj_cas(raspored,broj_casova,predmet,br_casova);
			if(dodan==0)
			printf("Nema dovoljno mjesta u rasporedu za %d casova.\n",br_casova);
			
			if(dodan==1) broj_casova++;
		}
		
		if(opcija==4) {
			int dan,redni;
			printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
			scanf("%d",&dan);
			
			if(opcija!=0)
			ispisi_dan(raspored,broj_casova,dan);
			printf("Izaberite koji cas zelite obrisati:  ");
			scanf("%d",&redni);
			obrisi_cas(raspored,broj_casova,dan,redni);
			broj_casova--;
			printf("Cas obrisan\n");
		}
		
	} while(opcija!=0);
	return 0;
}
*/


#include <stdio.h>
#include <math.h>
#define PI 3.14

struct Tacka {
	float x,y;
};
struct Kruznica {
	struct Tacka centar;
	float poluprecnik;
};

struct Pravougaonik {
	struct Tacka dl,gd;
};

struct Tacka unos_tacke() {
	struct Tacka t;
	printf ("Unesite koordinate tacke (x,y): ");
	scanf ("%f,%f", &t.x, &t.y);
	return t;
}

struct Kruznica unos_kruznice() {
	struct Kruznica k;
	printf ("Unesite centar kruznice:\n");
	k.centar = unos_tacke();
	printf ("Unesite poluprecnik kruznice: ");
	scanf("%f", &k.poluprecnik);
	return k;
}

struct Pravougaonik unos_pravouganika() {
	struct Pravougaonik p;
	printf("Unesi koordinate dl tacke: ");
	p.dl=unos_tacke();
	printf("Unesi koordinate gd tacke: ");
	p.gd=unos_tacke();
	return p;
}


float udaljenost(struct Tacka t1, struct Tacka t2) {
	return sqrt( (t1.x-t2.x)*(t1.x-t2.x) + (t1.y-t2.y)*(t1.y-t2.y) );
}

float obim_kruznice(struct Kruznica k) {
	float obim;
	obim=2*PI*k.poluprecnik;
	return obim;
}

float povrsina_kruznice(struct Kruznica k) {
	float povrsina;
	povrsina=k.poluprecnik*k.poluprecnik*PI;
	return povrsina;
}

float obim_pravouganika(struct Pravougaonik p) {
	float obimprav;
	obimprav=2*((p.gd.x-p.dl.x)+(p.gd.y-p.dl.y));
	return obimprav;
}

float povrsina_pravouganika(struct Pravougaonik p) {
	float povrsprav;
	povrsprav=(p.gd.x-p.dl.x)*(p.gd.y-p.dl.y);
	return povrsprav;
}

int pozicija_tacke(struct Tacka t, struct Pravougaonik p) {
	if (t.x >= p.dl.x && t.x <= p.gd.x && (t.y == p.dl.y || t.y == p.gd.y)) return 1;
	else if (t.y >= p.dl.y && t.y <= p.gd.y && (t.x == p.dl.x || t.x == p.gd.x)) return 1;
	else if (t.x < p.dl.x || t.y < p.dl.y || t.x > p.gd.x || t.y > p.gd.y) return 0;
	else return 1;
}

int main() {
	struct Kruznica k;
	struct Tacka t;
	float d,o,pp;
	struct Pravougaonik p; 
	printf ("Unesite kruznicu:\n");
	k = unos_kruznice();
	printf("Unesite pravougaonik: ");
	p=unos_pravouganika();
	printf ("Unesite neku tacku:\n");
	t = unos_tacke();
	d = udaljenost(t, k.centar);
	if (d<k.poluprecnik)
		printf("Tacka je unutar kruznice.");
	else if (d==k.poluprecnik)
		printf("Tacka je na kruznici.");
	else
		printf("Tacka je izvan kruznice.");
	o=obim_kruznice(k);
	pp=povrsina_kruznice(k);
	printf("Obim je %.2f a povrsina %.2f",o,pp);
	int dd;
	dd=pozicija_tacke(t,p);
	if(dd==0) printf("Izvan pravouganika");
	if(dd==1) printf("unutar");
	return 0;
}


