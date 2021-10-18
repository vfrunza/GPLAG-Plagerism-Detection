#include <stdio.h>
#include <string.h>
#define KAPACITET 200

typedef struct {                                                                // novi tip ime dana
    char d[5];
} Dan;

typedef struct {                                                                // novi tip sat npr. "19:00"
    char d[7];
} Sat;

typedef struct Vrijeme {
    int sati, minute, sekunde;
} Vrijeme;

typedef struct Cas {
    char predmet[10];
    int dan_u_sedmici;
    struct Vrijeme pocetak, kraj;
} Cas;

void clear ()                                                                   // clear kojim praznimo buffer
{
    while ( getchar() != '\n' );
}

void unesi(char niz[], int velicina)                                            // funkcija unesi
{
    char znak = getchar();
    if (znak == '\n') {
        znak=getchar();
    }
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
    if (znak != '\n') {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }
    }
}

int PorediVrj (Vrijeme t1, Vrijeme t2)                                          // funkcija kojim poredimo dva vremena vracamo 0 ako su jednaka 1 ako je prvo ispred drugog i -1 ako je prije 
{

    int d1 = t1.sati*3600 + t1.minute*60 + t1.sekunde;
    int d2 = t2.sati*3600 + t2.minute*60 + t2.sekunde;
    if (d1 == d2) {
        return 0;
    }
    if (d1 > d2) {
        return 1;
    }
    if (d1 < d2) {
        return -1;
    }
    return -2;
}

int preklapanje (struct Cas raspored[], int broj_casova, struct Cas cas)        // funkcija preklapanje koja nam vraca 1 ako se dva casa preklapaju
{

    int flag = 0;
    int i;
    for (i = 0; i < broj_casova; i++) {

        if ((PorediVrj(raspored[i].kraj,cas.pocetak) == 1) && (PorediVrj(cas.kraj, raspored[i].pocetak) == 1 ) && (cas.dan_u_sedmici == raspored[i].dan_u_sedmici)) {
            flag = 1;
            break;
        }
    }
    return flag;
}

int zadnji_sat (struct Cas raspored[], int broj_casova)                         // funkcija zadnji sat koja nam vraca zadnji sat u rasporedu npr . 17:00
{
    int flag = 1;
    int zad_sat = 0;
    int i;
    for (i = 0; i < broj_casova; i++) {
        if (flag) {
            if (raspored[i].kraj.minute == 0)
                zad_sat = raspored[i].kraj.sati-1;
            else zad_sat = raspored[i].kraj.sati;
            flag = 0;
        } else if (raspored[i].kraj.sati > zad_sat) {
            if (raspored[i].kraj.minute == 0)
                zad_sat = raspored[i].kraj.sati-1;
            else zad_sat = raspored[i].kraj.sati;
        }
    }
    return zad_sat;
}

int Pr_sat (struct Cas raspored[], int broj_casova)                             // funkcija prvi sat isto kao i zadnji, samo vraca nam prvi sat u rasporedu
{
    int flag = 1;
    int prvi_sat = 0;
    int i;
    for (i = 0; i < broj_casova; i++) {
        if (flag) {
            prvi_sat = raspored[i].pocetak.sati;
            flag = 0;
        } else if (raspored[i].pocetak.sati < prvi_sat) {
            prvi_sat = raspored[i].pocetak.minute;
        }
    }
    return prvi_sat;
}
int dodaj_cas(struct Cas raspored[], int broj_casova, const char* predmet, int trajanje)        // funkcija dodaj cas koja dodaje cas u raspored
{

    if (trajanje > 10) {

        return 0;
    }
    struct Cas cas;
    strncpy (cas.predmet, predmet, 10);
    cas.pocetak.sekunde = 0;
    cas.kraj.sekunde = 0;
    int flag = 0;
    int flag2 = 0;

    int i, j, k;
    for (i = 1; i < 7 && flag == 0; i++) {
        cas.dan_u_sedmici = i;                                                  // prolazimo kroz dane postavljamo dan na 1. (ponedjeljak)
        flag2 = 0;
        for (j = 9; j < 19 && flag == 0 && flag2 == 0; j++) {
            cas.pocetak.sati = j;                                               // prolazimo kroz sati od 9:00 do 19:00
            cas.kraj = cas.pocetak;
            cas.kraj.sati += trajanje;



            for (k = 0; k < 60 && flag == 0 && flag2 == 0; k++) {                             // prolazimo kroz minute
                cas.pocetak.minute = k;                                         // kraj = pocetak + broj casova
                cas.kraj = cas.pocetak;
                cas.kraj.sati += trajanje;

                if (cas.kraj.sati >= 19) {
                    if (cas.kraj.sati == 19 && cas.kraj.minute > 0) {
                        flag2 = 1;
                    } else if (cas.kraj.sati > 19) {
                        flag2 = 1;
                    }
                }

                if (preklapanje(raspored, broj_casova, cas) == 0 && flag2 == 0) {
                    flag = 1;
                }
            }
        }
    }
    if (flag == 0) {

        return 0;
    }
    if (broj_casova > 199) {

        return 0;
    }
    raspored[broj_casova] = cas;
    return 1;
}

int ucitaj_datoteku(struct Cas* raspored)                                       // ucitavamo datoteku uz provjeru da li je ispravno ucitana i vraca broj ucitani casova
{
    int i;
    FILE* ulaz = fopen ("raspored.dat","rb+");
    if (ulaz == NULL) {

        return 0;
    }
    i = fread (raspored, sizeof (struct Cas), KAPACITET, ulaz);
    fclose (ulaz);
    return i;
}
    
int zapisi_datoteku(struct Cas raspored[], int broj_casova)                     // zapisujemo datoteku
{

    FILE* ulaz = fopen ("raspored.dat","wb+");
    if (ulaz == NULL) {
        printf ("Greska pri otvaranju datoteke zapisi.\n");
        return 0;
    }

    int zapisano = fwrite (raspored, sizeof (struct Cas), broj_casova, ulaz);

    if (ferror(ulaz)) {
        printf("Greska prilikom pisanja datoteke.\n");
        printf("Zapisano je samo %d casova\n %d%%", zapisano, 100/broj_casova*zapisano);
    }

    fclose (ulaz);
    return 1;

}

void ispisi_dan(struct Cas raspored[], int broj_casova, int dan)                // funkcija koja nam ispisuje jedan dan
{

    int brojac = 1;

    int i;
    printf("Uneseni su casovi: \n");
    for (i = 0; i < broj_casova; i++) {
        if (raspored[i].dan_u_sedmici == dan) {
            printf ("%d) %s (%02d:%02d-%02d:%02d)\n",brojac, raspored[i].predmet, raspored[i].pocetak.sati, raspored[i].pocetak.minute, raspored[i].kraj.sati, raspored[i].kraj.minute);
            brojac++;
        }

    }
}

void promijeni_cas (struct Cas raspored[], int broj_casova, int dan, int redni_broj, struct Cas promjena)       // funkcija koja mjenja dati cas (naziv, vrijeme pocetka i vrijeme kraja)
{

    int brojac = 1;
    int flag = 0;
    int i;
    for (i = 0; i < broj_casova; i++) {
        if (raspored[i].dan_u_sedmici == dan && brojac == redni_broj) {
            flag = 1;
            break;
        } else if (raspored[i].dan_u_sedmici == dan) {
            brojac ++;
        }
    }
    if (flag == 0) {
        return;
    }
    raspored[i] = promjena;

}

int promijeni_cas_2 (struct Cas raspored[], int broj_casova)                    // u ovoj funkciji prije pozivanja funkcije promjeni_cas provjeravamo da li dolazi do preklapanja 
{                                                                               // i da li ispravno unesen redni broj , nakon toga se unosi novo ime i vrijeme
    int dan;                                                                    // zasto to nisam radio u promjeni cas ? jer kada se u autotestovima provjerava sama funkcija promjeni cas 
    int redni_broj;                                                             // ne provjerava se da li je unos ispravan i kao parametar se trazi novi cas koji se prije toga negdje mora unijeti
    printf ("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
    scanf ("%d", &dan);
    ispisi_dan(raspored, broj_casova, dan);
    printf ("Izaberite koji cas zelite promijeniti: ");
    scanf ("%d",&redni_broj);
    struct Cas temp;
    int brojac = 1;
    int flag = 0;
    int i;
    struct Cas promjena;

    Vrijeme reset = {-1, -1, -1};
    for (i = 0; i < broj_casova; i++) {
        if (raspored[i].dan_u_sedmici == dan && brojac == redni_broj) {
            flag = 1;
            break;
        } else if (raspored[i].dan_u_sedmici == dan) {
            brojac ++;
        }
    }
    if (flag == 0) {
        printf ("Neispravan redni broj casa.");
        return 1;
    }
    printf ("Naziv predmeta: ");
    unesi(promjena.predmet,10);
    printf ("Vrijeme pocetka: ");
    scanf ("%d:%d", &promjena.pocetak.sati, &promjena.pocetak.minute);
    printf ("Vrijeme zavrsetka: ");
    scanf ("%d:%d", &promjena.kraj.sati, &promjena.kraj.minute);
    promjena.pocetak.sekunde = 0;
    promjena.kraj.sekunde = 0;
    promjena.dan_u_sedmici = dan;
    temp = raspored[i];
    raspored[i].pocetak = reset;
    raspored[i].kraj = reset;

    if (preklapanje(raspored, broj_casova, promjena) == 1) {
        printf ("Promjena nije moguca jer dovodi do preklapanja\n");
        raspored[i] = temp;
        return 1;
    }
    raspored[i] = promjena;

    return 0;
}
int obrisi_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj) // funkcija koja brise dati cas iz niza
{

    int brojac = 1;
    int flag = 0;
    int i;

    for (i = 0; i < broj_casova; i++) {
        if (raspored[i].dan_u_sedmici == dan && brojac == redni_broj) {
            flag = 1;
            break;
        } else if (raspored[i].dan_u_sedmici == dan) {
            brojac ++;
        }
    }
    if (flag == 0) {
        printf ("Neispravan redni broj casa.");
        return 1;
    }
    raspored[i] = raspored[broj_casova - 1];
    return 0;
}



void ispis_rasporeda(struct Cas raspored[], int broj_casova)                    // funkcija koja ispisuje raspored
{
    int i,j,k;

    int flag2 = 1;

    int index_min = -1;
    int zd_sat = zadnji_sat(raspored,broj_casova);

    Dan sedmica[6] = {"PON","UTO","SRI","CET","PET","SUB"};
    Sat sati2[24] = {"0:00","1:00","2:00","3:00","4:00","5:00","6:00","7:00","8:00","9:00","10:00","11:00","12:00","13:00","14:00","15:00","16:00","17:00","18:00","19:00","20:00","21:00","22:00","23:00"};
    printf ("\n");
    printf ("%-7s"," ");
    for (i = 0; i < 6; i++) {
        printf("%-10s",sedmica[i].d);
    }
    printf ("\n");
    for (i = Pr_sat(raspored,broj_casova); i < zd_sat+1 && zd_sat != 0; i++) {

        printf("%-7s",sati2[i].d);
        for (k = 1; k < 7; k++) {
            index_min = -1;
            flag2 = 1;
            for (j = 0; j < broj_casova; j++) {

                if (raspored[j].dan_u_sedmici == k) {
                    if ((raspored[j].pocetak.sati <= i) && (raspored[j].kraj.sati >= i ) && !(raspored[j].kraj.sati == i && raspored[j].kraj.minute == 0)) {


                        if (flag2) {
                            index_min = j;
                            flag2 = 0;
                        } else if (PorediVrj(raspored[j].pocetak,raspored[index_min].pocetak) == -1) {
                            index_min = j;
                        }
                    }
                }
            }
            if (index_min == -1 ) {
                printf("%-10s"," ");
            } else if (index_min != -1 ) {
                printf ("%-10s",raspored[index_min].predmet);
            }
        }
        printf ("\n");
    }
}

int  dodaj_cas2 (struct Cas raspored[], int broj_casova)                        // isto kao i promjeni_cas_2 prije pozivanja dodaj_cas provjeravamo da li ima dovoljno mjesta 
{                                                                               // i da li je unesen redni broj ispravno
    char ime_cas[13];
    int br_cas;
    printf ("Unesite naziv predmeta: ");
    unesi(ime_cas,10);
    if (strcmp(ime_cas," ") == 0) unesi(ime_cas,10);
    printf ("Unesite broj casova: ");
    scanf ("%d", &br_cas);
    if (dodaj_cas(raspored, broj_casova,ime_cas, br_cas) == 1) {

        return 0;
    } else {
        printf("Nema dovoljno mjesta u rasporedu za %d casova.\n",br_cas);
        return 1;
    }
}

int obrisi_cas_2(struct Cas raspored[], int broj_casova)                        // analogno doda_cas_2  provjera da li je unesen redni broj ispravno
{
    int dan_op;
    int rd_br;
    printf ("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
    scanf ("%d", &dan_op);
    ispisi_dan(raspored, broj_casova, dan_op);
    printf ("Izaberite koji cas zelite obrisati: ");
    scanf ("%d",&rd_br);
    if (obrisi_cas(raspored,broj_casova,dan_op, rd_br) == 0) {
        printf ("Cas obrisan\n");
        return 0;
    } else return 1;

}

int menu (struct Cas raspored[], int broj_casova)                               // funkcija menu kojom biramo opciju i vracamo novu velicinu niza u main
{
    int a = 0;
    int opcija;
    do {
        printf ("1) Ispis rasporeda\n2) Dodavanje casa\n3) Promjena casa\n4) Brisanje casa\n0) Kraj rada\nIzaberite opciju: ");
        if (scanf ("%d", &opcija) == 0) {
            printf ("nepoznata opcija");
            clear();
            continue;
        }

        switch (opcija) {
        case 1:
            ispis_rasporeda(raspored,broj_casova);
            break;

        case 2:
            if (dodaj_cas2(raspored,broj_casova) == 0) broj_casova++;
            break;


        case 3:
            while (promijeni_cas_2(raspored,broj_casova) != 0);
            break;

        case 4:
            while (obrisi_cas_2(raspored,broj_casova) != 0);
            broj_casova--;
            break;

        case 5:
            a = Pr_sat(raspored,broj_casova);
            printf("\n zadnji sat je %d\n",a);
            break;

        case 0:
            break;

        default :
            printf ("nepoznata opcija");
            break;
        }
    } while (opcija != 0);
    return broj_casova;
}


int main ()
{
    struct Cas raspored[KAPACITET];
    int broj_casova = ucitaj_datoteku(raspored);
    broj_casova = menu(raspored,broj_casova);
    zapisi_datoteku(raspored,broj_casova);
    return 0;
}
