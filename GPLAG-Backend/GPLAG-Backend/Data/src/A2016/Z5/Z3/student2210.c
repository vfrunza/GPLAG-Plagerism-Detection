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

int ucitaj_datoteku(struct Cas raspored[])
{
    int ucitano;
    FILE* datoteka = fopen("raspored.dat", "ab");
    if(datoteka == NULL)
    {
        printf("Greska pri otvaranju datoteke.");
        return 0;
    }

    ucitano = fread(raspored, sizeof(struct Cas), KAPACITET, datoteka);

    fclose(datoteka);

    return ucitano;
}


int zapisi_datoteku(struct Cas raspored[], int broj_casova)
{
    int zapisano;

    FILE* dat = fopen("raspored.dat", "wb");
    if(dat == NULL)
    {
        printf("Greska pri otvaranju datoteke.");
        return 1;
    }
    zapisano = fwrite(raspored, sizeof(struct Cas), broj_casova, dat);
    if(ferror(dat))
    {
        printf("Greska prilikom zapisivanja u datoteku.");
        printf("Zapisano je %d elemenata niza.", zapisano);
    }
    fclose(dat);

    return zapisano;
}

int dodaj_cas(struct Cas raspored[], int broj_casova, const char* predmet, int trajanje)
{
    int brojac_dana[6] = {0};
    int dani[6][6] = {{0},{0},{0},{0},{0},{0}};
    int i = 0, j = 0;
    int temp;
    if(raspored[0].dan_u_sedmici == 0)  /* niz rasporeda prazan */
    {
        strcpy(raspored[0].predmet, predmet);
        raspored[0].dan_u_sedmici = 1;
        raspored[0].pocetak.sati = 9;
        raspored[0].kraj.sati = raspored[0].pocetak.sati + trajanje;
        ++broj_casova;
        return 1;
    }
    else
    {
        for(i = 0; i < broj_casova; i++)
        {
            switch(raspored[i].dan_u_sedmici)
            {
            case 1:
                dani[raspored[i].dan_u_sedmici-1][brojac_dana[0]++] = raspored[i].pocetak.sati;
                break;
            case 2:
                dani[raspored[i].dan_u_sedmici-1][brojac_dana[1]++] = raspored[i].pocetak.sati;
                break;
            case 3:
                dani[raspored[i].dan_u_sedmici-1][brojac_dana[2]++] = raspored[i].pocetak.sati;
                break;
            case 4:
                dani[raspored[i].dan_u_sedmici-1][brojac_dana[3]++] = raspored[i].pocetak.sati;
                break;
            case 5:
                dani[raspored[i].dan_u_sedmici-1][brojac_dana[4]++] = raspored[i].pocetak.sati;
                break;
            case 6:
                dani[raspored[i].dan_u_sedmici-1][brojac_dana[5]++] = raspored[i].pocetak.sati;
                break;
            }
        }
        /*sortirana vremena casova po danima*/
        for(i = 0; i < 6; i++)
        {
            for(j = 0; j < 5; j++)
            {
                if(dani[i][j] < dani[i][j+1])
                {
                    temp = dani[i][j];
                    dani[i][j] = dani[i][j+1];
                    dani[i][j+1] = temp;
                }
            }
        }
        int razlika = 0;
        int dan = 0;
        for(i = 0; i < 6; i++)
        {
            for(j = 0; j < 5; j++)
            {
                razlika = dani[i][j] - dani[i][j+1];
                if(razlika > trajanje)
                {
                    raspored[++broj_casova].dan_u_sedmici = i;
                    raspored[broj_casova].pocetak.sati = dani[i][j];
                    raspored[broj_casova].kraj.sati = dani[i][j] + trajanje;
                    return 1;
                }
            }
        }
    }

    return 0;
}




int preklapanje(struct Cas raspored[], int broj_casova, struct Cas cas);

void ispis_rasporeda(struct Cas raspored[], int broj_casova)
{
//    int i;
//    printf("%6s%s%10s%10s%10s%10s%10s","", "PON", "UTO", "SRI", "CET", "PET", "SUB");
//    for(i = 0; i < broj_casova; i++)
//    {
//        printf("")
//    }
}
void ispisi_dan(struct Cas raspored[], int broj_casova, int dan);
void promijeni_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj, struct Cas promjena);
void obrisi_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj);

void unesi(char niz[], int velicina)
{
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n')
    {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}

void PostaviDaneNaNulu(struct Cas raspored[])
{
    int i;
    for(i = 0; i < KAPACITET; i++)
        raspored[i].dan_u_sedmici = 0;
}

void PostaviPredmeteNaPrazno(struct Cas raspored[])
{
	int i;
	for(i = 0; i < KAPACITET; i++)
		strcpy(raspored[i].predmet, "");
}

int main()
{
    int izbornik;
    struct Cas raspored[KAPACITET];
    int ucitano;
    int zapisano;
    int unesi_br_casova = 0;
    int broj_casova = 0;
    int i;
    char naziv_predmeta[10];
    PostaviDaneNaNulu(raspored);
    PostaviPredmeteNaPrazno(raspored);
    ucitano = ucitaj_datoteku(raspored);
    do
    {
        printf("1) Ispis rasporeda\n2) Dodavanje casa\n3) Promjena casa\n4) Brisanje casa\n0) Kraj rada\nIzaberite opciju: ");
        scanf("%d", &izbornik);
        switch(izbornik)
        {
        case 1:
            ispis_rasporeda(raspored, broj_casova);
            break;
        case 2:
            printf("Unesite naziv predmeta: ");
            unesi(naziv_predmeta, 10);
            printf("Unesite broj casova: ");
            scanf("%d", &unesi_br_casova);
            int dodan = dodaj_cas(raspored, broj_casova, naziv_predmeta, unesi_br_casova);
            if(dodan)
                broj_casova++;
            zapisano = zapisi_datoteku(raspored, broj_casova);
            break;
        case 3:

            break;
        case 4:

            break;
        case 0:
            zapisano = zapisi_datoteku(raspored, broj_casova);
            return 0;
            break;
        }
    } while(izbornik != 0);


    return 0;
}
