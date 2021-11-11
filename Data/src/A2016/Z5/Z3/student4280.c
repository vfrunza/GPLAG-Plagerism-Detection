#include <stdio.h>
#include <string.h>
#define KAPACITET 200

/* random record description - could be anything */
struct Vrijeme {
    int sati, minute, sekunde;
};

struct Cas {
    char predmet[10];
    int dan_u_sedmici;
    struct Vrijeme pocetak, kraj;
};

struct Cas raspored[200], cas;

struct CasoviZaDan {
    int rb;
    int predmetid;
    char predmet[10];
    struct Vrijeme pocetak, kraj;
};

struct CasoviZaDan casovizadan[200];

int ukupno_casova = 1, br, ukupno_casova_za_dan = 0;

int kraj_predmeta_sati(struct Cas raspored[], int ukupno_casova, int dan_u_sedmici, const char* predmet) {
    int j, kraj = 9;
    for (j = 0; j < ukupno_casova; ++j) {
        if (strcmp(raspored[j].predmet, predmet) == 0 && raspored[j].dan_u_sedmici == dan_u_sedmici) {
            if (raspored[j].kraj.sati > kraj) {
                kraj = raspored[j].kraj.sati;
            }
        }
    }
    return kraj;
}

int kraj_predmeta_minute(struct Cas raspored[], int ukupno_casova, int dan_u_sedmici, const char* predmet) {
    int j, kraj = 9;
    for (j = 0; j < ukupno_casova; ++j) {
        if (raspored[j].predmet == predmet && raspored[j].dan_u_sedmici == dan_u_sedmici) {
            if (raspored[j].kraj.sati > kraj) {
                kraj = raspored[j].kraj.minute;
            }
        }
    }
    return kraj;
}

void ispis_rasporeda(struct Cas raspored[], int ukupno_casova) {
    int i, j, dat;

    for (i = 1; i < ukupno_casova; i++) printf("predmet=%3s dan u sedmici=%d pocetak=%d\n", raspored[i].predmet, raspored[i].dan_u_sedmici, raspored[i].pocetak.sati);

    printf("      PON       UTO       SRI       CET       PET       SUB\n");
    printf("09:00 ");
    for (j = 0; j < ukupno_casova; j++) if (raspored[j].pocetak.sati == 9 && raspored[j].dan_u_sedmici == 0) {
            printf("%1s", raspored[j].predmet);
            break;
        }
    if (j == ukupno_casova) printf("          ");
    for (j = 0; j < ukupno_casova; j++) if (raspored[j].pocetak.sati == 9 && raspored[j].dan_u_sedmici == 1) {
            printf("%10s", raspored[j].predmet);
            break;
        }
    if (j == ukupno_casova) printf("          ");
    for (j = 0; j < ukupno_casova; j++) if (raspored[j].pocetak.sati == 9 && raspored[j].dan_u_sedmici == 2) {
            printf("%10s", raspored[j].predmet);
            break;
        }
    if (j == ukupno_casova) printf("          ");
    for (j = 0; j < ukupno_casova; j++) if (raspored[j].pocetak.sati == 9 && raspored[j].dan_u_sedmici == 3) {
            printf("%10s", raspored[j].predmet);
            break;
        }
    if (j == ukupno_casova) printf("          ");
    for (j = 0; j < ukupno_casova; j++) if (raspored[j].pocetak.sati == 9 && raspored[j].dan_u_sedmici == 4) {
            printf("%10s", raspored[j].predmet);
            break;
        }
    if (j == ukupno_casova) printf("          ");
    for (j = 0; j < ukupno_casova; j++) if (raspored[j].pocetak.sati == 9 && raspored[j].dan_u_sedmici == 5) {
            printf("%10s", raspored[j].predmet);
            break;
        }
    if (j == ukupno_casova) printf("          ");
    printf("\n");
    printf("10:00 ");
    for (j = 0; j < ukupno_casova; j++) if (raspored[j].pocetak.sati == 10 && raspored[j].dan_u_sedmici == 0) {
            printf("%1s", raspored[j].predmet);
            break;
        }
    if (j == ukupno_casova) printf("          ");
    for (j = 0; j < ukupno_casova; j++) if (raspored[j].pocetak.sati == 10 && raspored[j].dan_u_sedmici == 1) {
            printf("%10s", raspored[j].predmet);
            break;
        }
    if (j == ukupno_casova) printf("          ");
    for (j = 0; j < ukupno_casova; j++) if (raspored[j].pocetak.sati == 10 && raspored[j].dan_u_sedmici == 2) {
            printf("%10s", raspored[j].predmet);
            break;
        }
    if (j == ukupno_casova) printf("          ");
    for (j = 0; j < ukupno_casova; j++) if (raspored[j].pocetak.sati == 10 && raspored[j].dan_u_sedmici == 3) {
            printf("%10s", raspored[j].predmet);
            break;
        }
    if (j == ukupno_casova) printf("          ");
    for (j = 0; j < ukupno_casova; j++) if (raspored[j].pocetak.sati == 10 && raspored[j].dan_u_sedmici == 4) {
            printf("%10s", raspored[j].predmet);
            break;
        }
    if (j == ukupno_casova) printf("          ");
    for (j = 0; j < ukupno_casova; j++) if (raspored[j].pocetak.sati == 10 && raspored[j].dan_u_sedmici == 5) {
            printf("%10s", raspored[j].predmet);
            break;
        }
    if (j == ukupno_casova) printf("          ");
    printf("\n");
    printf("11:00 ");
    for (j = 0; j < ukupno_casova; j++) if (raspored[j].pocetak.sati == 11 && raspored[j].dan_u_sedmici == 0) {
            printf("%1s", raspored[j].predmet);
            break;
        }
    if (j == ukupno_casova) printf("          ");
    for (j = 0; j < ukupno_casova; j++) if (raspored[j].pocetak.sati == 11 && raspored[j].dan_u_sedmici == 1) {
            printf("%10s", raspored[j].predmet);
            break;
        }
    if (j == ukupno_casova) printf("          ");
    for (j = 0; j < ukupno_casova; j++) if (raspored[j].pocetak.sati == 11 && raspored[j].dan_u_sedmici == 2) {
            printf("%10s", raspored[j].predmet);
            break;
        }
    if (j == ukupno_casova) printf("          ");
    for (j = 0; j < ukupno_casova; j++) if (raspored[j].pocetak.sati == 11 && raspored[j].dan_u_sedmici == 3) {
            printf("%10s", raspored[j].predmet);
            break;
        }
    if (j == ukupno_casova) printf("          ");
    for (j = 0; j < ukupno_casova; j++) if (raspored[j].pocetak.sati == 11 && raspored[j].dan_u_sedmici == 4) {
            printf("%10s", raspored[j].predmet);
            break;
        }
    if (j == ukupno_casova) printf("          ");
    for (j = 0; j < ukupno_casova; j++) if (raspored[j].pocetak.sati == 11 && raspored[j].dan_u_sedmici == 5) {
            printf("%10s", raspored[j].predmet);
            break;
        }
    if (j == ukupno_casova) printf("          ");
    printf("\n");
    printf("12:00 ");
    for (j = 0; j < ukupno_casova; j++) if (raspored[j].pocetak.sati == 12 && raspored[j].dan_u_sedmici == 0) {
            printf("%1s", raspored[j].predmet);
            break;
        }
    if (j == ukupno_casova) printf("          ");
    for (j = 0; j < ukupno_casova; j++) if (raspored[j].pocetak.sati == 12 && raspored[j].dan_u_sedmici == 1) {
            printf("%10s", raspored[j].predmet);
            break;
        }
    if (j == ukupno_casova) printf("          ");
    for (j = 0; j < ukupno_casova; j++) if (raspored[j].pocetak.sati == 12 && raspored[j].dan_u_sedmici == 2) {
            printf("%10s", raspored[j].predmet);
            break;
        }
    if (j == ukupno_casova) printf("          ");
    for (j = 0; j < ukupno_casova; j++) if (raspored[j].pocetak.sati == 12 && raspored[j].dan_u_sedmici == 3) {
            printf("%10s", raspored[j].predmet);
            break;
        }
    if (j == ukupno_casova) printf("          ");
    for (j = 0; j < ukupno_casova; j++) if (raspored[j].pocetak.sati == 12 && raspored[j].dan_u_sedmici == 4) {
            printf("%10s", raspored[j].predmet);
            break;
        }
    if (j == ukupno_casova) printf("          ");
    for (j = 0; j < ukupno_casova; j++) if (raspored[j].pocetak.sati == 12 && raspored[j].dan_u_sedmici == 5) {
            printf("%10s", raspored[j].predmet);
            break;
        }
    if (j == ukupno_casova) printf("          ");
    printf("\n");
    printf("13:00 ");
    for (j = 0; j < ukupno_casova; j++) if (raspored[j].pocetak.sati == 13 && raspored[j].dan_u_sedmici == 0) {
            printf("%1s", raspored[j].predmet);
            break;
        }
    if (j == ukupno_casova) printf("          ");
    for (j = 0; j < ukupno_casova; j++) if (raspored[j].pocetak.sati == 13 && raspored[j].dan_u_sedmici == 1) {
            printf("%10s", raspored[j].predmet);
            break;
        }
    if (j == ukupno_casova) printf("          ");
    for (j = 0; j < ukupno_casova; j++) if (raspored[j].pocetak.sati == 13 && raspored[j].dan_u_sedmici == 2) {
            printf("%10s", raspored[j].predmet);
            break;
        }
    if (j == ukupno_casova) printf("          ");
    for (j = 0; j < ukupno_casova; j++) if (raspored[j].pocetak.sati == 13 && raspored[j].dan_u_sedmici == 3) {
            printf("%10s", raspored[j].predmet);
            break;
        }
    if (j == ukupno_casova) printf("          ");
    for (j = 0; j < ukupno_casova; j++) if (raspored[j].pocetak.sati == 13 && raspored[j].dan_u_sedmici == 4) {
            printf("%10s", raspored[j].predmet);
            break;
        }
    if (j == ukupno_casova) printf("          ");
    for (j = 0; j < ukupno_casova; j++) if (raspored[j].pocetak.sati == 13 && raspored[j].dan_u_sedmici == 5) {
            printf("%10s", raspored[j].predmet);
            break;
        }
    if (j == ukupno_casova) printf("          ");
    printf("\n");
    printf("14:00 ");
    for (j = 0; j < ukupno_casova; j++) if (raspored[j].pocetak.sati == 14 && raspored[j].dan_u_sedmici == 0) {
            printf("%1s", raspored[j].predmet);
            break;
        }
    if (j == ukupno_casova) printf("          ");
    for (j = 0; j < ukupno_casova; j++) if (raspored[j].pocetak.sati == 14 && raspored[j].dan_u_sedmici == 1) {
            printf("%10s", raspored[j].predmet);
            break;
        }
    if (j == ukupno_casova) printf("          ");
    for (j = 0; j < ukupno_casova; j++) if (raspored[j].pocetak.sati == 14 && raspored[j].dan_u_sedmici == 2) {
            printf("%10s", raspored[j].predmet);
            break;
        }
    if (j == ukupno_casova) printf("          ");
    for (j = 0; j < ukupno_casova; j++) if (raspored[j].pocetak.sati == 14 && raspored[j].dan_u_sedmici == 3) {
            printf("%10s", raspored[j].predmet);
            break;
        }
    if (j == ukupno_casova) printf("          ");
    for (j = 0; j < ukupno_casova; j++) if (raspored[j].pocetak.sati == 14 && raspored[j].dan_u_sedmici == 4) {
            printf("%10s", raspored[j].predmet);
            break;
        }
    if (j == ukupno_casova) printf("          ");
    for (j = 0; j < ukupno_casova; j++) if (raspored[j].pocetak.sati == 14 && raspored[j].dan_u_sedmici == 5) {
            printf("%10s", raspored[j].predmet);
            break;
        }
    if (j == ukupno_casova) printf("          ");
    printf("\n");

}

void ispisi_sve(struct Cas raspored[], int ukupno_casova) {
    int i;
    for (i = 0; i < ukupno_casova; i++) printf("predmet=%s dan u sedmici=%d pocetak=%d:%d kraj=%d:%d\n",
            raspored[i].predmet, raspored[i].dan_u_sedmici,
            raspored[i].pocetak.sati, raspored[i].pocetak.minute,
            raspored[i].kraj.sati, raspored[i].kraj.minute);
}

void ispisi_dan(struct Cas raspored[], int ukupno_casova, int dan) {
    int i, j, k, m, dat, pom_sati, pom_minute;

    //izdvoji casove u danu
    ukupno_casova_za_dan = 0;
    for (j = 0; j < ukupno_casova; j++) {
        if (raspored[j].dan_u_sedmici == dan/*-1*/) {
            casovizadan[ukupno_casova_za_dan].rb = ukupno_casova_za_dan;
            strcpy(casovizadan[ukupno_casova_za_dan].predmet, raspored[j].predmet);
            casovizadan[ukupno_casova_za_dan].pocetak = raspored[j].pocetak;
            casovizadan[ukupno_casova_za_dan].kraj = raspored[j].kraj;
            ukupno_casova_za_dan++;
        }
    }
    //sifriraj predmete
    i = 0;
    casovizadan[i].predmetid = i;
    for (j = 1; j < ukupno_casova_za_dan; j++) {
        if (strcmp(casovizadan[j].predmet, casovizadan[j - 1].predmet) == 0) {
            casovizadan[j].predmetid = i;
        } else {
            i++;
            casovizadan[j].predmetid = i;
        }
    }
    // azurirati rb
    for (i = 0; i < ukupno_casova_za_dan; i++) {
        casovizadan[i].rb = i + 1;
    }
    //ispis
    printf("Uneseni su casovi:\n");
    for (j = 0; j < ukupno_casova_za_dan; j++) {
        printf("%d) %s (%02d:%02d-%02d:%02d)\n", casovizadan[j].rb, casovizadan[j].predmet,
                casovizadan[j].pocetak.sati, casovizadan[j].pocetak.minute,
                casovizadan[j].kraj.sati, casovizadan[j].kraj.minute);
    }
}

int zapisi_datoteku(struct Cas raspored[], int ukupno_casova) {
    FILE* dat = fopen("raspored.dat", "wb");
    if (dat == NULL) {
        printf("Greska pri otvaranju datoteke.\n");
    }
    int zapisano = fwrite(raspored, sizeof (struct Cas),
            ukupno_casova, dat);
    if (ferror(dat)) {
        printf("Greska prilikom pisanja datoteke.\n");
        printf("Zapisano je samo %d osoba\n", zapisano);
    }
    fclose(dat);
    if (zapisano > 0) return 1;
    else return 0;
}

int ucitaj_datoteku(struct Cas raspored[]) {

    FILE* dat = fopen("raspored.dat", "rb");
    if (dat == NULL) {
        printf("Greska pri otvaranju datoteke.\n");
        return 0;
    }
    int ukupno_casova = fread(raspored, sizeof (struct Cas),
            KAPACITET, dat);
    fclose(dat);
    return ukupno_casova;
}

int dodaj_cas(struct Cas raspored[], int ukupno_casova, const char* predmet, int trajanje) {
    char naziv_predmeta;
    int ukupno_casova_pocetak, i, j, k, l = 0, m = 0, n = 0, broj_slobodnih_termina = 0, broj_zauzetih_termina = 0,
            slobodni_sat = 9, slobodni_dan = 0, termin_nadjen = 0, dat;

    int nadji_termin(struct Cas raspored[], int ukupno_casova, int dan, int sati, int trajanje) {
        int j, k, termin_zauzet = 0;

        for (k = 0; k < ukupno_casova; ++k) {
            if (raspored[k].dan_u_sedmici == dan &&
                    raspored[k].pocetak.sati <= sati &&
                    raspored[k].kraj.sati > sati) {
                termin_zauzet = 1;
            }
        }
        if (termin_zauzet == 1) return 0;
        else return 1;
    }
    // dani u sedmici
    i = 1;
    termin_nadjen = 0;
    ukupno_casova_pocetak = ukupno_casova;
    if (trajanje < 10) {
        while (i <= 6 && termin_nadjen == 0) {
            // sati u danu
            j = 9;
            while (j <= 19 - trajanje && termin_nadjen == 0) {
                termin_nadjen = nadji_termin(raspored, ukupno_casova, i, j, trajanje);
                j++;
            }
            i++;
        }
        if (nadji_termin(raspored, ukupno_casova, i - 1, j - 1, trajanje) == 1) {
            strcpy(raspored[ukupno_casova].predmet, predmet);
            raspored[ukupno_casova].dan_u_sedmici = i - 1;
            raspored[ukupno_casova].pocetak.sati = j - 1;
            raspored[ukupno_casova].pocetak.minute = 0;
            raspored[ukupno_casova].kraj.sati = j - 1 + trajanje;
            raspored[ukupno_casova].kraj.minute = 0;
            ukupno_casova++;
        }
    }
    if (ukupno_casova_pocetak == ukupno_casova) return 0;
    else return 1;
}

int dodaj_cas_ulaz(struct Cas raspored[], int ukupno_casova, const char* predmet, int trajanje) {
    char naziv_predmeta;
    int i, j, k, l = 0, m = 0, n = 0, broj_slobodnih_termina = 0, broj_zauzetih_termina = 0,
            slobodni_sat = 9, slobodni_dan = 0, termin_nadjen = 0, dat;

    printf("Unesite naziv predmeta:");
    scanf("%9s", &predmet);
    printf("Unesite broj casova:");
    scanf("%d", &trajanje);
    ukupno_casova = dodaj_cas(raspored, ukupno_casova, &predmet, &trajanje);
    return ukupno_casova;
}

int preklapanje(struct Cas raspored[], int ukupno_casova, struct Cas cas) {
    int i, j, k, l = 0, m = 0, n = 0, ukupno_casova_predmeta, broj_slobodnih_termina = 0, broj_zauzetih_termina = 0,
            slobodni_sat = 9, slobodni_dan = 0, termin_nadjen = 0, dat, preklapanje = 0;

    int poredi_vrijeme(int sati1, int minute1, int sati2, int minute2) {
        if (sati1 > sati2) {
            return 1;
        } else if (sati1 < sati2) {
            return 2;
        } else if (sati1 = sati2) {
            if (minute1 > minute2) {
                return 1;
            } else if (minute1 < minute2) {
                return 2;
            } else if (minute1 = minute2) {
                return 0;
            }
        }
    }
    if (cas.dan_u_sedmici == 1 && cas.pocetak.sati <= 9) preklapanje = 1;
    for (j = 0; j <= ukupno_casova; ++j) {
        if (strcmp(raspored[j].predmet, cas.predmet) != 0 &&
                raspored[j].dan_u_sedmici == cas.dan_u_sedmici &&
                poredi_vrijeme(raspored[j].kraj.sati, raspored[j].kraj.minute, cas.pocetak.sati, cas.pocetak.minute) == 2) {
            preklapanje = 1;
        };
    };

    return preklapanje;

    int nadji_termin(struct Cas raspored[], int ukupno_casova, int dan, int sati, int ukupno_casova_predmet) {
        int j, k, termin_zauzet = 0;

        for (j = 0; j <= ukupno_casova_predmet; ++j) {
            for (k = 0; k <= ukupno_casova; ++k) {
                if (raspored[k].dan_u_sedmici == dan && raspored[k].pocetak.sati == sati + j) {
                    termin_zauzet = 1;
                }
            }
        }
        if (termin_zauzet == 1) return 0;
        else return 1;
    }

    printf("Unesite broj casova:");
    scanf("%d", &ukupno_casova_predmeta);
    // dani u sedmici
    i = 0;
    termin_nadjen = 0;
    while (i < 6 && termin_nadjen == 0) {
        // sati u danu
        j = 9;
        while (j < 16 - ukupno_casova_predmeta && termin_nadjen == 0) {
            termin_nadjen = nadji_termin(raspored, ukupno_casova, i, j, ukupno_casova_predmeta);
            j++;
        }
        i++;
    }
    if (nadji_termin(raspored, ukupno_casova, i, j, ukupno_casova_predmeta) == 1) {
        for (k = 0; k < ukupno_casova_predmeta; k++) {
            raspored[ukupno_casova] = raspored[0];
            raspored[ukupno_casova].dan_u_sedmici = i - 1;
            raspored[ukupno_casova].pocetak.sati = j - 1 + k;
            ukupno_casova++;
        }
    }

    return ukupno_casova;
}

int promjeni_cas(struct Cas raspored[], int ukupno_casova) {
    int i, j, k, dan_u_sedmici, redni_broj_casa, ukupno_casova_za_dan = 0,
            pocetak_sati, pocetak_minute, kraj_sati, kraj_minute;
    char predmet;

    printf("Unesite dan (1=ponedeljak, 2=utorak, 3=srijeda,4=cetvrtak, 5=petak, 6=subota):");
    scanf("%d", &cas.dan_u_sedmici);
    printf("Uneseni su casovi:\n");
    ispisi_dan(raspored, ukupno_casova, cas.dan_u_sedmici);
    printf("Izaberite koji cas zelite promijeniti:");
    scanf("%d", &redni_broj_casa);
    printf("Naziv predmeta:");
    scanf("%s", &cas.predmet);
    printf("Vrijeme pocetka:");
    scanf("%d:%d", &cas.pocetak.sati, &cas.pocetak.minute);
    printf("Vrijeme zavrsetka:");
    scanf("%d:%d", &cas.kraj.sati, &cas.kraj.minute);
    printf("Vrijeme: %d:%d  %d:%d\n", pocetak_sati, pocetak_minute, kraj_sati, kraj_minute);

    void promijeni_slog(struct Cas raspored[], int ukupno_casova, struct Cas cas, int redni_broj_casa, struct CasoviZaDan casovizadan[]) {
        int i = 0, min_sati = 9, max_sati = 19;
        char V_predmet;
        for (i = 0; i < ukupno_casova_za_dan; i++) if (casovizadan[i].rb == redni_broj_casa) V_predmet = casovizadan[i].predmet;
        while (strcmp(raspored[i].predmet, V_predmet) != 0 && raspored[i].dan_u_sedmici != cas.dan_u_sedmici) i++;
        i--;
        raspored[i].pocetak.sati = cas.pocetak.sati;
        raspored[i + cas.pocetak.sati - cas.kraj.sati].kraj.sati = cas.kraj.sati;
    }

    if (preklapanje(raspored, ukupno_casova, cas) == 1) printf("Promjena nije moguca jer dovodi do preklapanja\n");
    else promijeni_slog(raspored, ukupno_casova, cas, redni_broj_casa, casovizadan);
    for (i = 0; i < ukupno_casova; i++) printf("predmet=%s dan u sedmici=%d pocetak=%d:%d kraj=%d:%d", raspored[i].predmet, raspored[i].dan_u_sedmici, raspored[i].pocetak.sati, raspored[i].pocetak.minute, raspored[i].kraj.sati, raspored[i].kraj.minute);


    return ukupno_casova;
}

int brisi_cas(struct Cas raspored[], int ukupno_casova) {
    int i, j, k, redni_broj_casa;

    printf("Unesite dan (1=ponedeljak, 2=utorak, 3=srijeda,4=cetvrtak, 5=petak, 6=subota):");
    scanf("%d", &cas.dan_u_sedmici);
    printf("Uneseni su casovi:\n");
    ispisi_dan(raspored, ukupno_casova, cas.dan_u_sedmici);
    printf("Izaberite koji cas koji zelite obrisati:");
    scanf("%d", &redni_broj_casa);
    for (i = 0; i < ukupno_casova; ++i) {
        printf("predmet=%s dan u sedmici=%d pocetak=%d:%d kraj=%d:%d\n", raspored[i].predmet, raspored[i].dan_u_sedmici,
                raspored[i].pocetak.sati, raspored[i].pocetak.minute,
                raspored[i].kraj.sati, raspored[i].kraj.minute);
    }
    for (k = 0; k < ukupno_casova; ++k) {
        for (i = 0; i < ukupno_casova; ++i) {
            if (strcmp(raspored[i].predmet, casovizadan[redni_broj_casa - 1].predmet) == 0 && raspored[i].dan_u_sedmici == cas.dan_u_sedmici - 1) {
                for (j = i; j < ukupno_casova; ++j) {
                    raspored[j] = raspored[j + 1];
                }
                --ukupno_casova;
            }
        }
    }
    printf("Nakon brisanja:\n");
    for (i = 0; i < ukupno_casova; ++i) {
        printf("predmet=%s dan u sedmici=%d pocetak=%d:%d kraj=%d:%d\n", raspored[i].predmet, raspored[i].dan_u_sedmici,
                raspored[i].pocetak.sati, raspored[i].pocetak.minute,
                raspored[i].kraj.sati, raspored[i].kraj.minute);
    }
    return ukupno_casova;
}

void meni() {
    int dat, opcija;
    ukupno_casova = ucitaj_datoteku(raspored);

    do {
        printf("1 - Ispis rasporeda\n2 - Dodavanje casa\n3 - Promjena casa\n4 - Brisanje casa\n0 - Kraj rada\nIzaberite opciju:");
        scanf("%d", &opcija);
        switch (opcija) {
            case 1: ispis_rasporeda(raspored, ukupno_casova);

                break;
            case 2: ukupno_casova = dodaj_cas(raspored, ukupno_casova, A, ukupno_casova);
                break;
            case 3: ukupno_casova = promjeni_cas(raspored, ukupno_casova);
                break;
            case 4: ukupno_casova = brisi_cas(raspored, ukupno_casova);
                break;
            case 0: dat = zapisi_datoteku(raspored, ukupno_casova);
                break;
            default: printf("Nepoznata opcija\n");
        }
    } while (opcija != 0);
}

/* writes and then reads 10 arbitrary records
   from the file "junk". */
int main() {
    int i, j;
    FILE *f;

    { //AT1: Provjera ispravnosti funkcije preklapanje na jednostavnijim slučajevima
        struct Cas raspored[] = {
            {A, 1,
                {9, 0, 0},
                {11, 0, 0}}
        };
        struct Cas c = {"TP", 1,
            {8, 0, 0},
            {10, 0, 0}};
        //Prva situacija, ocigledan preklop jer su od 9-10h oba predmeta u toku
        printf("Preklop (ponedjeljak 9:00-11:00 i ponedjeljak 8:00-10:00): %d\n", preklapanje(raspored, 1, c));

        struct Cas raspored2[] = {
            {A, 2,
                {9, 0, 0},
                {11, 0, 0}}
        };
        struct Cas d = {"TP", 2,
            {11, 0, 0},
            {13, 0, 0}};

        //Druga situacija, nije preklop jer su jedan iza drugoga
        printf("Preklop(utorak 9 : 00 - 11 : 00 i utorak 11 : 00 - 13 : 00) : % d\n", preklapanje(raspored2, 1, d));

        //Sada cemo iste situacije ponoviti i po drugi put, samo sto sada nece biti preklapanja jer su casovi u razlicitim danima

        struct Cas raspored3[] = {
            {A, 1,
                {9, 0, 0},
                {11, 0, 0}}
        };
        struct Cas e = {"TP", 5,
            {8, 0, 0},
            {10, 0, 0}};

        //Prva situacija, ponedjeljak i petak, da su predmeti isti dan, bili bi preklopljeni
        printf("Preklop(utorak 9 : 00 - 11 : 00 i petak 8 : 00 - 10 : 00) : % d\n", preklapanje(raspored3, 1, e));

        struct Cas raspored4[] = {
            {A, 2,
                {9, 0, 0},
                {11, 0, 0}}
        };
        struct Cas f = {"TP", 4,
            {11, 0, 0},
            {13, 0, 0}};

        //Druga situacija, utorak i cetvrtak, svejedno nije preklop
        printf("Preklop(utorak 9 : 00 - 11 : 00 i cetvrtak 11 : 00 - 13 : 00) : % d\n", preklapanje(raspored4, 1, f));
    }

    meni();
    return 0;
}