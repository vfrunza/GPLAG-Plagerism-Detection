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

int ucitaj_datoteku(struct Cas raspored[]){ //ucitavanje binarne 
    FILE* dat=fopen("raspored.dat","rb");
    if(dat==NULL) return 0;
    int ucitanih;
    ucitanih=fread(raspored,sizeof(struct Cas),KAPACITET,dat);
    if(ucitanih>-1) fclose(dat);
    if(ucitanih>-1) return ucitanih;
}

void ispismain(){
    printf("1) Ispis rasporeda\n2) Dodavanje casa\n3) Promjena casa\n4) Brisanje casa\n0) Kraj rada\nIzaberite opciju: ");
}

void unesi(char niz[]){ //unos stringa
    char znak=getchar();
    while(znak=='\n') znak=getchar();
    int i=0;
    while(i<9 && znak!='\n'){
        niz[i++]=znak;
        znak=getchar();
    }
    niz[i]='\0';
    
    while(znak!='\n') //ocistimo spremnik, ako se unese previse znakova
    znak=getchar();
}

struct Cas prekopiraj(struct Cas cas, int i, int k, int trajanje, char* predmet){
    int ukupno=k+trajanje; //funkcija upise sadrzaj u nas cas
    int dan=i;
    cas.kraj.sati=ukupno;
    cas.pocetak.minute=cas.kraj.minute=0;
    cas.dan_u_sedmici=dan;
    cas.pocetak.sati=k;
    if(cas.pocetak.minute==0);
    return cas;
}

int prekl(int minpoc1, int minkraj1, int minpoc2, int minkraj2){ //saljemo dva intervala i vidimo da li se preklapa
    return(minpoc1<minpoc2 && minkraj1>minpoc2 || minpoc2<minpoc1 && minkraj2>minkraj1 || minpoc1<minkraj2 && minkraj1>minkraj2);
    }

int minute (int min, int sati){ //funkcija koja pretvara u min
    return min+sati*60;
}

int preklapanje(struct Cas raspored[], int broj_casova, struct Cas cas){
    int i;
    int minpoc1, minpoc2, minkraj1, minkraj2;
    for(i=0;i<broj_casova;i++){ //nadjemo pocetak i kraj oba casa
        int minpoc1=minute(raspored[i].pocetak.minute, raspored[i].pocetak.sati);
        int minkraj1=minute(raspored[i].kraj.minute,raspored[i].kraj.sati);
        int minpoc2=minute(cas.pocetak.minute, cas.pocetak.sati);
        int minkraj2=minute(cas.kraj.minute,cas.kraj.sati);
        int vr=prekl(minpoc1,minkraj1,minpoc2,minkraj2);
        
        if(raspored[i].dan_u_sedmici==cas.dan_u_sedmici&&(minpoc2==minpoc1 || minkraj1==minkraj2)) return 1;
        if(raspored[i].dan_u_sedmici==cas.dan_u_sedmici && vr==1) return 1;
    }
    return 0;
}
int dodaj_cas(struct Cas raspored[], int broj_casova, const char* predmet, int trajanje){
    if(broj_casova==200) return 0;
    if(trajanje>10) return 0;
    
    int poz=1;
    int i,k,pocetak,dan,moze=0;
    struct Cas cas;
    
    for(i=1;i<7;i++) //prodjemo kroz sedmicu
        for(k=9;k<=19-trajanje;k++){
            int dokle=k;
            int vr=i;
            strcpy(cas.predmet,predmet); //upisemo ime predmeta
            cas=prekopiraj(cas,i,k,trajanje,predmet); // upisemo i ostale podatke
            strcpy(cas.predmet,predmet);
            
            if(poz==1 && k==dokle){
                if(preklapanje(raspored,broj_casova,cas)==0 && i==vr){ //ispitamo preklapanje
                    moze=1;
                    raspored[broj_casova]=cas;
                    return 1;
                }
            }}
        return 0;
    }
    
int MIN(struct Cas raspored[], int broj_casova){ //funkcija vrati sat prvog casa
    int i,j,min=25;
    for(i=0;i<broj_casova;i++){ //prodjemo kroz casove
        if(raspored[i].pocetak.sati<min) 
            min=raspored[i].pocetak.sati; //spasavamo najmanji sati
    }
    return min;
}

void ispis(){
    printf("\n       PON       UTO       SRI       CET       PET       SUB\n");
}

void daliispisuje(struct Cas raspored[], int i, int broj_casova){ //pomocna funkcija koja ispisuje raspored
    int k,j;
    for(j=1;j<7;j++){
        for(k=0;k<broj_casova;k++) 
             if(raspored[k].pocetak.sati<=i && raspored[k].dan_u_sedmici==j && raspored[k].kraj.sati>=i){ //ako je u nasem intervalu ispisujemo 
                    printf("%-10s", raspored[k].predmet);
                    break;
                 }
    if(k==broj_casova) printf("          "); //ako nije, onda ispisujemo prazna mjesta
    }
}

void ispis_rasporeda(struct Cas raspored[], int broj_casova){
    int k;
    int i,j,max=0,indexmaxa=0;
    for(i=0;i<broj_casova;i++){ //prodjemo kroz casove
        if(raspored[i].kraj.sati>max){
            max=raspored[i].kraj.sati; //spavamo, a onda pamtimo mu i index 
            indexmaxa=i; 
        }
    }
    if(raspored[indexmaxa].kraj.minute==0) max=max-1; 
    int min=MIN(raspored,broj_casova); //pozovemo funkciju koja vraca odakle pocinju casovi
    ispis();
    
    for(i=min;i<=max;i++){ //od min do max idemo i pozivamo funkciju koja ispisuje raspored
        if(i<10) printf("9:00   ");
        else printf("%d:00  ",i);
        daliispisuje(raspored,i,broj_casova);
        printf("\n");
    }
}

void dansispis(struct Cas raspored[], int broj_casova, int dan){
    int k=1, i;
    int ispis=0;
    for(i=0;i<broj_casova;i++){
        if(raspored[i].dan_u_sedmici==dan){
            ispis=1; //ispisemo cijeli dan
            printf("\n%d) %s (",k++,raspored[i].predmet); //morali ispitivati zbog dodavanja 0 pri ispisu
            if(raspored[i].pocetak.sati<10) printf("0");
            printf("%d:",raspored[i].pocetak.sati);
            if(raspored[i].pocetak.minute<10) printf("0"); // da li je jednocifren il dvocifren
            printf("%d", raspored[i].pocetak.minute);
            printf("-");
            if(raspored[i].kraj.sati<10) printf("0");
            printf("%d", raspored[i].kraj.sati);
            printf(":");
            if(raspored[i].kraj.minute<10) printf("0");
            if(ispis==1) printf("%d)",raspored[i].kraj.minute);
            }
    }
}
void ispisi_dan(struct Cas raspored[], int broj_casova, int dan){
    int i;
    printf("Uneseni su casovi: ");
    
    dansispis(raspored,broj_casova, dan);
    return;
}

void unosss(){ //pomocna funkcija da ne pisemo vise puta
    printf("\nIzaberite koji cas zelite promijeniti: ");
    printf("Naziv predmeta: ");
    printf("Vrijeme pocetka: ");
    printf("Vrijeme zavrsetka: ");
}

struct Cas pr(int dan, int sat, int min, int sat1, int min1, char* ime){ //prekopiranje podataka u strukturu
    struct Cas casko;
    int dan_u_sedmici=dan;
    strcpy(casko.predmet,ime);
    casko.dan_u_sedmici=dan_u_sedmici;
    casko.pocetak.sati=sat;
    casko.pocetak.minute=min;
    casko.kraj.sati=sat1;
    casko.kraj.minute=min1;
    strcpy(casko.predmet,ime);
    return casko;
}

void promijeni_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj, struct Cas promjena){
    int i, k=0; int index=0;
    
    for(i=0;i<broj_casova;i++){
        if(raspored[i].dan_u_sedmici==dan) k++;
        if(k==redni_broj){ //nadjemo onaj koji treba zamijeniti i upamtimo mu index
            index=i;
        }
    }
    raspored[index]=promjena;
}

int zapisi_datoteku (struct Cas raspored[], int broj_casova){//zapisivanje binarne
    FILE* dat=fopen("raspored.dat","wb");
    int ucitano=fwrite(raspored,sizeof(struct Cas),broj_casova,dat);
    fclose(dat);
    return 1;
}



void obrisi_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj){
    int i, k=0, j, r=0;
    
    for(i=0;i<broj_casova;i++){
        if(raspored[i].dan_u_sedmici==dan) {k++;r++;}
        
        if(k==redni_broj){
            if(r==redni_broj) for(j=i;j<broj_casova-1;j++) //izbacivanje iz niza
            raspored[j]=raspored[j+1];
            break;
            return;
        }
    }
}
int main() {

struct Cas raspored[KAPACITET];
int ucit=ucitaj_datoteku(raspored);
int broj, br, dan, cs;
char ime[100];
int zap;

do{
    ispismain();
    
    scanf("%d",&broj);
    
    switch(broj){
        case 2:
            printf("Unesite naziv predmeta: ");
            printf("Unesite broj casova: ");
            unesi(ime);
            scanf("%d", &br);
            int nema=dodaj_cas(raspored,ucit,ime,br);
            if(nema==1) ucit++;
            if(nema==0) printf("Nema dovoljno mjesta u rasporedu za %d casova.\n",br);
            break;
            
        case 1:
            ispis_rasporeda(raspored,ucit);
            int i;
            
            for(i=0;i<ucit;i++){
                if(raspored[i].pocetak.sati<9) return 1;
            }
            break;
            
            case 3: 
                printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
                scanf("%d",&dan);
                ispisi_dan(raspored,ucit,dan);
            
            unosss();
            
            int sat, min;
            char z;
            
            int sat1,min1;
            char z1;
            
            scanf("%d",&cs);

            unesi(ime);
            
            scanf("%d%c%d",&sat,&z,&min);
            scanf("%d%c%d", &sat1,&z1,&min1);
            
            struct Cas casko=pr(dan,sat,min,sat1,min1,ime);
            
            promijeni_cas(raspored,ucit,dan,cs,casko);
            break;
            
        case 0:
                zap=zapisi_datoteku(raspored,ucit);
                return 0;
            
        case 4: 
                printf("Unesite dan ");
                printf("(1=ponedjeljak, 2=utorak..., 6=subota): ");
                scanf("%d", &dan);
                ispisi_dan(raspored,ucit,dan);
                printf("\nIzaberite koji cas zelite obrisati: ");
                scanf("%d", &cs);
                obrisi_cas(raspored,ucit,dan,cs);
                printf("Cas obrisan\n");
                if(dan>0) ucit--;
                break;
        
    }
}while(broj!=0);
	
	return 0;
}
