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

char unesi(char niz[], int velicina) {
    
	char znak = getchar();
	if(velicina<0) return znak;
	if (znak == '\n') znak = getchar();
	int i = 0,k=0;
	while (i < velicina-1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
		k++;
	}

	niz[k] = '\0';
	return znak;
}

void ocisti(char znak){
	while(znak!='\n')
		znak=getchar();
}

int ucitaj_datoteku(struct Cas raspored[]){
	FILE *ulaz=fopen("raspored.dat","rb+");
	if(ulaz==NULL)
		return 0;
	int kap=KAPACITET;
	int vel=sizeof (struct Cas);
	int ucitano;
	ucitano=fread(raspored,vel,KAPACITET,ulaz);
	fclose(ulaz);
	return ucitano;
}
int mmm(int d){
    if(d==0) return -1;
    else return 0;
}
int MAX(struct Cas raspored[], int broj_casova){
    int brojac=1;
      int i,j,max=0,indexmaxa=0;
    for (i=0; i<broj_casova;i++){
        brojac++;
            if (raspored[i].kraj.sati>max ){
                max=raspored[i].kraj.sati;
                indexmaxa=i;
}}
max=max-mmm(raspored[indexmaxa].kraj.minute);
return max;

}

int MIN(struct Cas raspored[], int broj_casova){
     int i,j,min=25;
    for (i=0; i<broj_casova;i++)
            if (raspored[i].pocetak.sati<min)
            	min=raspored[i].pocetak.sati;
    return min;
}
void ispisss(){
    printf("\n       PON       UTO       SRI       CET       PET       SUB\n");
}
void ispispr(char *pr){
    printf("%-10s",pr);
}
void ispispraz(int d){
     printf("          ");
}
void ispis_rasporeda(struct Cas raspored[], int broj_casova){
    int i,j, k;
   int max=MAX(raspored,broj_casova);
   int min=MIN(raspored,broj_casova);
       ispisss();
    for(i=min;i<=max;i++){
         if(i<10) printf("9:00   ");
             else printf("%d:00  ",i);
        for(j=1;j<7;j++){
			
                for(k=0;k<broj_casova;k++)
                    if ( raspored[k].pocetak.sati<=i && raspored[k].dan_u_sedmici==j  && raspored[k].kraj.sati>=i){
                            ispispr(raspored[k].predmet);
                            break;
                            ispispraz(10);
                    }
                    if (k==broj_casova)
                       ispispraz(10);
            }
        printf("\n");
    }
}


    void ispisi_dan(struct Cas raspored[], int broj_casova, int dan){
        int i;
    printf("Uneseni su casovi: ");
        int k=1;
        for(i=0;i<broj_casova;i++){
            if(raspored[i].dan_u_sedmici==dan){
            	int sat=raspored[i].pocetak.sati;
            	int min=raspored[i].pocetak.minute;
                printf("\n%d) %s (",k++,raspored[i].predmet);
                 if(sat<10) printf("0");
                 printf("%d:",sat);
                  if(min<10) printf("0");
                 printf("%d-",min);
                 if(raspored[i].kraj.sati<10) printf("0");
                 printf("%d:",raspored[i].kraj.sati);
                  if(raspored[i].kraj.minute<10) printf("0");
                 printf("%d)\n",raspored[i].kraj.minute);
            }
        }
    }


void obrisi_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj){
	int i,j=0;
	for(i=0; i<broj_casova; i++){
		if (raspored[i].dan_u_sedmici==dan) j++;
		if (redni_broj==j){
		    for(;i<broj_casova-1;i++)
			    raspored[i]=raspored[i+1];
		    break;
		}
	}
}

int PorediVrj(struct Vrijeme t1, struct Vrijeme t2,int i)
{
    int sat=t1.sati*3600;
    int sat1=t2.sati*3600;
    int min=t1.minute*60;
    int min1=t2.minute*60;
    int d1 = sat+min+ t1.sekunde;
    int d2 = sat1+min1+ t2.sekunde;
    if (d1 > d2)  return 1; 
    if (d1 < d2)  return -1; 
    if (d1 == d2)  return 0; 
    
}
int preklapanje (struct Cas raspored[], int broj_casova, struct Cas cas)
{

    int prekl = 0;
    int i;
    for (i = 0; i < broj_casova; i++) {
		int drugi=PorediVrj(cas.kraj, raspored[i].pocetak,i);
		if(i<0) return prekl;
        if (PorediVrj(raspored[i].kraj,cas.pocetak,i)== 1 && drugi==1 && (cas.dan_u_sedmici == raspored[i].dan_u_sedmici)) {
            prekl= 1; 
            break;
        }
    }
   if(i>-1) return prekl;
}
int prazan(struct Cas cas){
    if(cas.predmet=="") return 0;
    else return 1;
}


int dodaj_cas(struct Cas raspored[], int broj_casova, const char *predmet, int trajanje){
	if(broj_casova==200) return 0;
	if(trajanje<0 ||trajanje>200) return 0;
	int i,j,preklop;
	for (i=0; i<6; i++)
		for(j=9; j<=19-trajanje; j++){
			struct Cas cas={"",i+1,{j,0,0},{j+trajanje,0,0}};
		cas.pocetak.minute=0;
		cas.kraj.minute=0;
		cas.pocetak.sekunde=0;
		cas.pocetak.minute=0;
		strcpy(cas.predmet,predmet);
		int praz=prazan(cas);
		struct Cas pom={"",0,{0,0,0},{0,0,0}};
		strcpy(cas.predmet,predmet);
			preklop=preklapanje(raspored,broj_casova,cas);
			if (preklop==0){
				raspored[broj_casova]=cas;
				return 1;
			}
		}
	return 0;			
}

void promijeni_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj, struct Cas promjena){
	int i,redni=0;
	for(i=0; i<broj_casova; i++){
		if(raspored[i].dan_u_sedmici==dan) redni++;
		if(redni_broj==redni)
			raspored[i]=promjena;
	}
}

int zapisi_datoteku(struct Cas raspored[], int broj_casova){
	FILE *ulaz=fopen("raspored.dat","wb+");
	if(ulaz==NULL)
		return 0;
	int kap=broj_casova;
	int vel=sizeof (struct Cas);
	int zapisano=fwrite(raspored,vel, broj_casova,ulaz);
	fclose(ulaz);
 return 1;

}

int main() {
	int opcija,broj_casova=0;
	struct Cas raspored[KAPACITET];
	ucitaj_datoteku(raspored);
	do {
		printf("1) Ispis rasporeda\n");
	printf("2) Dodavanje casa\n");
	printf("3) Promjena casa\n");
	printf("4) Brisanje casa\n");
	printf("0) Kraj rada\n");
	printf("Izaberite opciju: ");

		scanf("%d",&opcija);
		if (opcija==2){
				int br_casova,dodan=0;
				char predmet[10];
				printf("Unesite naziv predmeta: Unesite broj casova: ");
				ocisti(unesi(predmet,10));
				scanf("%d",&br_casova);
				dodan=dodaj_cas(raspored,broj_casova,predmet,br_casova);
				switch(dodan){
				    case 1: broj_casova++; break;
				    default: 	printf("Nema dovoljno mjesta u rasporedu za %d casova.\n",br_casova);
				}
				
				
			}
		if (opcija==0) 
				zapisi_datoteku(raspored,broj_casova);
		if (opcija==1) 
				ispis_rasporeda(raspored,broj_casova);
		
		if (opcija==3 ){
				struct Cas promjena;
				int dan,redni;
				char predmet[10];
				printf("Unesite dan (1=ponedjeljak, ");
				printf("2=utorak..., ");
				printf("6=subota): ");
				scanf("%d",&dan);
				ispisi_dan(raspored,broj_casova,dan);
				promjena.dan_u_sedmici=dan;
				printf("Izaberite koji cas zelite promijeniti:  ");
				scanf("%d",&redni);
				if(redni>100 ||redni<0) goto preskok;
				printf("Naziv predmeta: ");
				ocisti(unesi(predmet,10));
				char *q;
				
				if(opcija!=0) q=promjena.predmet;
				char*p;
			  if(opcija!=0)	p=predmet;
				preskok:
				strcpy(q,p);
				char znak;
				printf("Vrijeme pocetka: Vrijeme zavrsetka: ");
				scanf("%d%c%d%d%c%d",&promjena.pocetak.sati,&znak,&promjena.pocetak.minute,&promjena.kraj.sati,&znak,&promjena.kraj.minute);
				promijeni_cas(raspored,broj_casova,dan,redni,promjena);
			}
			if (opcija==4){
				int dan,redni;
				printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
				
				scanf("%d",&dan);
				if(opcija!=0){
				ispisi_dan(raspored,broj_casova,dan);
				printf("Izaberite koji cas zelite obrisati: ");
				scanf("%d",&redni);
				obrisi_cas(raspored,broj_casova,dan,redni);
				broj_casova=broj_casova-1;
				printf(" Cas obrisan\n");
				}
			}
	} while (opcija!=0);
    
	return 0;
}
