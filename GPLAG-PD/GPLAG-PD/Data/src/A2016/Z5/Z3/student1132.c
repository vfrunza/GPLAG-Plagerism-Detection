#include <stdio.h>
#include <string.h>
#define KAPACITET 200
struct Vrijeme 
{
		int sati, minute, sekunde;
};
struct Cas 
{
		char predmet[10];
		int dan_u_sedmici;
		struct Vrijeme pocetak, kraj;
};

/* Poredi dva vremena -> -1 - prvo je ranije; 0 - ista; 1 - prvo je kasnije*/
int cmp_Vrijeme(struct Vrijeme v1,struct Vrijeme v2)
{
    int min1 = v1.sati*60 + v1.minute;
    int min2 = v2.sati*60 + v2.minute;
    if(min1 < min2) return -1;
    if(min1 == min2) return 0;
    return 1;
}
/* Pretvara vrijeme dato u satima i minutama u minute*/
int convert_Vrijeme(struct Vrijeme v)
{
    return v.sati*60 + v.minute;
}
/* Da li se dva vremena poklapaju u nekoj minuti*/
int conflict(struct Cas a,struct Cas b)
{
    int ap = a.pocetak.sati*60 + a.pocetak.minute;
    int ak = a.kraj.sati*60 + a.kraj.minute;
    int bp = b.pocetak.sati*60 + b.pocetak.minute;
    int bk = b.kraj.sati*60 + b.kraj.minute;
   if(ak<=bp || bk<=ap) return 0;
    return 1;
}
/* Ucitava datoteku "raspored.dat" u niz raspored[]*/
int ucitaj_datoteku(struct Cas raspored[])
{
    FILE* cin = fopen("raspored.dat","rb");
    if(cin==NULL) return -1;
    int r = fread(raspored, sizeof(struct Cas), KAPACITET, cin);
    fclose(cin);
    return r;
}
/* Upisuje podatke iz niza "raspored" u binarnu datoteku "raspored.dat"*/
int zapisi_datoteku(struct Cas raspored[], int broj_casova)
{
   FILE* cout = fopen("raspored.dat","wb");
   if(cout==NULL) return 0;
   fwrite(raspored,sizeof(struct Cas),broj_casova,cout);
   fclose(cout);
   return 1;
}
/* Funcija ispituje da li u nizu Cas-ova raspored[] postoji preklapanje sa casom "cas"*/
int preklapanje(struct Cas raspored[], int broj_casova, struct Cas cas)
{
    struct Cas *pok = raspored;
    while(pok < raspored + broj_casova)
    {
        if(strcmp(cas.predmet,pok->predmet)==0)
        {
            pok++;
            continue;
        }
        if(cas.dan_u_sedmici == pok->dan_u_sedmici )
        {
            if(!(cmp_Vrijeme(cas.kraj, pok->pocetak) <=0 || cmp_Vrijeme(cas.pocetak,pok->kraj) >= 0)) return 1;
        }
        pok++;
    }
    return 0;
}

/* Funkcija dodaje cas u raspored u prvi slobodan termin, ako ne uspije vraca 0, ako uspije vraca 1*/
int dodaj_cas(struct Cas raspored[], int broj_casova, const char* predmett, int trajanje)
{
    struct Cas temp;
    int i,j,cnf,k,pp,start,finish;
    for(i=0;i<6;i++)
    {
        for(j=9*60;j <= 19*60;j++)
        {
            temp.pocetak.sati = j/60;
            temp.kraj.sati = j/60 + trajanje;
            temp.pocetak.minute = temp.kraj.minute = j%60;
            if(temp.kraj.sati*60 + temp.kraj.minute > 19*60) break;
            cnf = 0;
            for(k=0;k<broj_casova;k++)
            {
                if(raspored[k].dan_u_sedmici != i+1) continue;
                if(conflict(raspored[k],temp)) 
                {
                    cnf = 1;
                    break;
                }
            }
         if(cnf==0)
         {
             strcpy(temp.predmet,predmett);
             temp.dan_u_sedmici = i+1;
             raspored[broj_casova] = temp;
             return 1;
         }
        }
    }
    return 0;
}
/* Ispisuje casove iz niza raspored koji se u danu "dan"*/
void ispisi_dan(struct Cas raspored[], int broj_casova, int dan)
{
    printf("Uneseni su casovi: \n");
    int i,cnt=1;
    struct Cas* p;
    for(i=0;i<broj_casova;i++)
    {
        if(raspored[i].dan_u_sedmici == dan)
        {
            p = raspored+i;
            printf("%d) %s (%s%d:",cnt,p->predmet,p->pocetak.sati<10 ? "0" : "",p->pocetak.sati);
            printf("%s%d",p->pocetak.minute < 10 ? "0" : "",p->pocetak.minute);
            printf("-%s%d:",p->kraj.sati<10 ? "0":"",p->kraj.sati);
            printf("%s%d)\n",p->kraj.minute < 10 ? "0" : "",p->kraj.minute);
            cnt++;
        }
    }
}
/*Ispisuje raspored u formi tabele*/
void ispis_rasporeda(struct Cas raspored[], int broj_casova)
{
      int mmt,immt,ear = 24, lat = 0,i,j,k,temp;
      char pom[10] = "";
      for(i=0;i<broj_casova;i++)
      {
          if(raspored[i].pocetak.sati < ear) ear = raspored[i].pocetak.sati;
          if(raspored[i].kraj.sati > lat && raspored[i].kraj.minute != 0) lat = raspored[i].kraj.sati;
          else if(raspored[i].kraj.sati-1 > lat) lat = raspored[i].kraj.sati-1;
      }
    printf("\n       ");
    printf("PON       UTO       SRI       CET       PET       SUB\n");
    for(j=ear;j<=lat;j++)
    {
        printf("%d:00  ",j);
        if(j<10) printf(" ");
        for(i=1;i<=6;i++)
         {
            mmt = 60606060;
            immt = 0;
            for(k=0;k<broj_casova;k++)
            {
                if(raspored[k].dan_u_sedmici == i)
                {
                    if(raspored[k].pocetak.sati <= j && j <= raspored[k].kraj.sati && (!(raspored[k].kraj.sati == j && raspored[k].kraj.minute == 0)))
                    {
                        temp = raspored[k].pocetak.sati*60 + raspored[k].pocetak.minute;
                        if(temp<mmt)
                        {
                            mmt = temp;
                            immt = k;
                        }
                    }
                }
            }
            printf("%-10s",mmt==60606060 ? "" : raspored[immt].predmet);
        }
        printf("\n");
    }
}
/* Brise iz raspored "redni_broj"-ti cas u danu "dan"*/
void obrisi_cas(struct Cas raspored[], int broj_casova, int dan,int redni_broj)
{
    int i,cnt=0,j;
    for(i=0;i<broj_casova;i++)
    {
        if(raspored[i].dan_u_sedmici == dan) cnt++;
        if(cnt == redni_broj)
        {
            for(j=i;j<broj_casova-1;j++) raspored[j] = raspored[j+1];
            break;
        }
    }
}
/* Mijenja cas koji se nalazi u danu "dan" sa casom promjena(Cas iz dana "dan" koji se nalazi na rednom broju "redni_broj" u nizu raspored)*/
void promijeni_cas(struct Cas raspored[], int broj_casova, int dan,int redni_broj, struct Cas promjena)
{
    int i,cnt=0;
    for(i=0;i<broj_casova;i++)
    {
        if(raspored[i].dan_u_sedmici == dan) cnt++;
        if(cnt == redni_broj)
        {
            raspored[i] = promjena;
            break;
        }
    }
}
int main() 
{
   struct Cas raspored[KAPACITET], aux;
   int opt,i,ret,broj_casova=0,dan,cas,cnt,cnf,s1,s2,m1,m2,rr=0;
   ucitaj_datoteku(raspored);
   char x;
   char predmet[10];
   while(20)
   {
       printf("1) Ispis rasporeda\n2) Dodavanje casa\n3) Promjena casa\n4) Brisanje casa\n0) Kraj rada\nIzaberite opciju: ");
       scanf("%d",&opt);
       if(opt==0)
       {
           break;
       }
       else if(opt==1)
       {
           ispis_rasporeda(raspored,broj_casova);
       }
       else if(opt==2)
       {
            printf("Unesite naziv predmeta: ");
            i = 0;
            x = '\n';
            while(x=='\n' || x==' ')
            {
                scanf("%c",&x);
            }
            predmet[0] = x;
            i++;
            while(i<9)
            {
                scanf("%c",&x);
                if(x=='\n') break;
                predmet[i++] = x;
            }
            predmet[i] = 0;
            if(x!='\n') while(x!='\n') scanf("%c",&x);
            
            printf("Unesite broj casova: ");
            scanf("%d",&i);
            ret = dodaj_cas(raspored,broj_casova,predmet,i);
            if(ret==0) printf("Nema dovoljno mjesta u rasporedu za %d casova.\n",i);
            broj_casova += ret;
       }
       else if(opt==3)
       {
           while(1)
           {
           printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
           scanf("%d",&dan);
           ispisi_dan(raspored,broj_casova,dan);
           cnt = 0;
           for(i=0;i<broj_casova;i++) if(raspored[i].dan_u_sedmici == dan) cnt++;
           
           printf("Izaberite koji cas zelite promijeniti: ");
           scanf("%d",&cas);
           if(cnt<cas)
           {
               printf("Neispravan redni broj casa.\n");
               continue;
           }
           printf("Naziv predmeta: ");
             i = 0;
            x = '\n';
            while(x=='\n' || x==' ')
            {
                scanf("%c",&x);
            }
            predmet[0] = x;
            i++;
            while(i<9)
            {
                scanf("%c",&x);
                if(x=='\n') break;
                predmet[i++] = x;
            }
            predmet[i] = 0;
            if(x!='\n') while(x!='\n') scanf("%c",&x);
            printf("Vrijeme pocetka: ");
            scanf("%d:%d",&aux.pocetak.sati,&aux.pocetak.minute);
            printf("Vrijeme zavrsetka: ");
            scanf("%d:%d",&aux.kraj.sati,&aux.kraj.minute);
            strcpy(aux.predmet,predmet);
            cnf = 0;
            cnt = 0;
            for(i=0;i<broj_casova;i++)
            {
                if(dan == raspored[i].dan_u_sedmici) cnt++;
                if(cnt!= cas && dan == raspored[i].dan_u_sedmici && conflict(raspored[i],aux))
                {
                    
                    cnf = 1;
                    break;
                }
            }
            if(cnf)
            {
                printf("Promjena nije moguca jer dovodi do preklapanja\n");
                continue;
            }
            aux.dan_u_sedmici = dan;
            promijeni_cas(raspored,broj_casova,dan,cas,aux);
            break;
            }
       }
       else if(opt==4)
       {
           printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
           scanf("%d",&dan);
           ispisi_dan(raspored,broj_casova,dan);
           printf("Izaberite koji cas zelite obrisati: ");
           scanf("%d",&cas);
           obrisi_cas(raspored,broj_casova,dan,cas);
           broj_casova--;
           printf("Cas obrisan\n");
       }
   }
   zapisi_datoteku(raspored,broj_casova);
	return 0;
}
