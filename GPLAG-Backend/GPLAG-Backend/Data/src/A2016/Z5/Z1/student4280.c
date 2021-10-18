#include <stdio.h>
#include <string.h>

struct Student {
    char ime[20], prezime[20];
    int ocjene[50];
    int br_ocjena;
} slog[5], ispis[5], swap;

float prosjek_ocjena(int ocjene[], int broj_ocjena) {
    float prosjek, suma_ocjena = 0;
    int i;
    for (i = 0; i < broj_ocjena; i++) {
        suma_ocjena = suma_ocjena + ocjene[i];
        if (ocjene[i] == 5 || broj_ocjena == 0) return 5.0;
    }
    prosjek = suma_ocjena / broj_ocjena;
    return prosjek;
}

int genijalci(struct Student slog[], int velicina_niza, float prosjek) {
    int i, j, c, d, n, velicina_ispis, broj_ispisanih = 0;
    float max_prosjek = 0;
    // brise ispodprosjećne
    for (j = 0; j < velicina_niza; j++)
        for (i = 0; i < velicina_niza; i++)
            if (prosjek_ocjena(slog[i].ocjene, slog[i].br_ocjena) < prosjek) {
                for (c = i; c < velicina_niza; c++)
                    slog[c] = slog[c + 1];
                velicina_niza = velicina_niza - 1;
            }
    if (velicina_niza == 1 && prosjek_ocjena(slog[0].ocjene, slog[0].br_ocjena) < prosjek) velicina_niza = 0;
    //nadji max prosjek
    for (i = 0; i < velicina_niza; i++)
        if (max_prosjek < prosjek_ocjena(slog[i].ocjene, slog[i].br_ocjena))
            max_prosjek = prosjek_ocjena(slog[i].ocjene, slog[i].br_ocjena);
    //izdvoji studente sa maksimalnim prosjekom
    velicina_ispis = 0;
    for (i = 0; i < velicina_niza; i++) {
        if (max_prosjek == prosjek_ocjena(slog[i].ocjene, slog[i].br_ocjena)) {
            ispis[velicina_ispis] = slog[i];
            velicina_ispis = velicina_ispis + 1;
        }
    }
	   		/*Sortirajmo leksikografski ispis*/
	   for (c = 0; c < (velicina_ispis - 1); c++) {
        for (d = 0; d < velicina_ispis - c - 1; d++) {
            if (strcmp(ispis[d].prezime, ispis[d + 1].prezime) > 0) /* For decreasing order use < */ {
                swap = ispis[d];
                ispis[d] = ispis[d + 1];
                ispis[d + 1] = swap;
            } else if (strcmp(ispis[d].prezime, ispis[d + 1].prezime) == 0) {
                if (strcmp(ispis[d].ime, ispis[d + 1].ime) > 0) /* For decreasing order use < */ {
                    swap = ispis[d];
                    ispis[d] = ispis[d + 1];
                    ispis[d + 1] = swap;
                }
            }
        }
    }
     //ispisi najbolje studente
    for (i = 0; i < velicina_ispis; i++) {
        if (broj_ispisanih < 3) {
            printf("\n %s", ispis[i].prezime);
            printf(" %s", ispis[i].ime);
            //            printf(" %f", prosjek_ocjena(ispis[i].ocjene, ispis[i].br_ocjena));
            broj_ispisanih = broj_ispisanih + 1;
        }
    }
    // brise ispisane
    for (i = 0; i < velicina_niza; i++)
        if (prosjek_ocjena(slog[i].ocjene, slog[i].br_ocjena) == max_prosjek) {
            for (c = i; c < velicina_niza; c++)
                slog[c] = slog[c + 1];
            velicina_niza = velicina_niza - 1;
        }
 //nadji sljedeci max prosjek
    max_prosjek = 0;
    for (i = 0; i < velicina_niza; i++)
        if (max_prosjek < prosjek_ocjena(slog[i].ocjene, slog[i].br_ocjena))
            max_prosjek = prosjek_ocjena(slog[i].ocjene, slog[i].br_ocjena);
    //izdvoji studente sa maksimalnim prosjekom
    velicina_ispis = 0;
    for (i = 0; i < velicina_niza; i++) {
        if (max_prosjek == prosjek_ocjena(slog[i].ocjene, slog[i].br_ocjena)) {
            ispis[velicina_ispis] = slog[i];
            velicina_ispis = velicina_ispis + 1;
        }
    }
    // sortiraj leksikografski ispis
    for (c = 0; c < (velicina_ispis - 1); c++) {
        for (d = 0; d < velicina_ispis - c - 1; d++) {
            if (strcmp(ispis[d].prezime, ispis[d + 1].prezime) > 0) /* For decreasing order use < */ {
                swap = ispis[d];
                ispis[d] = ispis[d + 1];
                ispis[d + 1] = swap;
            } else if (strcmp(ispis[d].prezime, ispis[d + 1].prezime) == 0) {
                if (strcmp(ispis[d].ime, ispis[d + 1].ime) > 0) /* For decreasing order use < */ {
                    swap = ispis[d];
                    ispis[d] = ispis[d + 1];
                    ispis[d + 1] = swap;
                }
            }
        }
    }
    //ispisi najbolje studente
    for (i = 0; i < velicina_ispis; i++) {
        if (broj_ispisanih < 3) {
            printf("\n %s", ispis[i].prezime);
            printf(" %s", ispis[i].ime);
            //            printf(" %f", prosjek_ocjena(ispis[i].ocjene, ispis[i].br_ocjena));
            broj_ispisanih = broj_ispisanih + 1;
        }
    }
    // brise ispisane
    for (i = 0; i < velicina_niza; i++)
        if (prosjek_ocjena(slog[i].ocjene, slog[i].br_ocjena) == max_prosjek) {
            for (c = i; c < velicina_niza; c++)
                slog[c] = slog[c + 1];
            velicina_niza = velicina_niza - 1;
        }
    //nadji sljedeci max prosjek
    max_prosjek = 0;
    for (i = 0; i < velicina_niza; i++)
        if (max_prosjek < prosjek_ocjena(slog[i].ocjene, slog[i].br_ocjena))
            max_prosjek = prosjek_ocjena(slog[i].ocjene, slog[i].br_ocjena);
    //izdvoji studente sa maksimalnim prosjekom
    velicina_ispis = 0;
    for (i = 0; i < velicina_niza; i++) {
        if (max_prosjek == prosjek_ocjena(slog[i].ocjene, slog[i].br_ocjena)) {
            ispis[velicina_ispis] = slog[i];
            velicina_ispis = velicina_ispis + 1;
        }
    }
    // sortiraj leksikografski ispis
    for (c = 0; c < (velicina_ispis - 1); c++) {
        for (d = 0; d < velicina_ispis - c - 1; d++) {
            if (strcmp(ispis[d].prezime, ispis[d + 1].prezime) > 0) /* For decreasing order use < */ {
                swap = ispis[d];
                ispis[d] = ispis[d + 1];
                ispis[d + 1] = swap;
            } else if (strcmp(ispis[d].prezime, ispis[d + 1].prezime) == 0) {
                if (strcmp(ispis[d].ime, ispis[d + 1].ime) > 0) /* For decreasing order use < */ {
                    swap = ispis[d];
                    ispis[d] = ispis[d + 1];
                    ispis[d + 1] = swap;
                }
            }
        }
    }
    //ispisi najbolje studente
    for (i = 0; i < velicina_ispis; i++) {
        if (broj_ispisanih < 3) {
            printf("\n %s", ispis[i].prezime);
            printf(" %s", ispis[i].ime);
            //            printf(" %f", prosjek_ocjena(ispis[i].ocjene, ispis[i].br_ocjena));
            broj_ispisanih = broj_ispisanih + 1;
        }
    }

    printf(" \n");
    return velicina_niza;
}

int main() {
    int i, j;
    //    struct Student slog[3];

    // 1st Student's slog
    strcpy(slog[0].ime, "Nadir");
    strcpy(slog[0].prezime, "Kahvedzic");
    slog[0].ocjene[0] = 6;
    slog[0].ocjene[1] = 7;
    slog[0].ocjene[2] = 8;
    slog[0].ocjene[3] = 8;
    slog[0].ocjene[4] = 10;
    slog[0].br_ocjena = 5;

    // 2nd Student's slog        
    strcpy(slog[1].ime, "Selma");
    strcpy(slog[1].prezime, "Kahvedzic");
    slog[1].ocjene[0] = 6;
    slog[1].ocjene[1] = 10;
    slog[1].ocjene[2] = 7;
    slog[1].ocjene[3] = 9;
    slog[1].ocjene[4] = 9;
    slog[1].br_ocjena = 5;

    // 3rd Student's slog
    strcpy(slog[2].ime, "Alma");
    strcpy(slog[2].prezime, "Melic");
    slog[2].ocjene[0] = 6;
    slog[2].ocjene[1] = 7;
    slog[2].ocjene[2] = 7;
    slog[2].ocjene[3] = 10;
    slog[2].ocjene[4] = 8;
    slog[2].br_ocjena = 5;

    // 4st Student's slog
    strcpy(slog[3].ime, "Faruk");
    strcpy(slog[3].prezime, "Kahvedzic");
    slog[3].ocjene[0] = 6;
    slog[3].ocjene[1] = 7;
    slog[3].ocjene[2] = 8;
    slog[3].ocjene[3] = 8;
    slog[3].ocjene[4] = 10;
    slog[3].br_ocjena = 5;

    // 5st Student's slog
    strcpy(slog[4].ime, "Sulejman");
    strcpy(slog[4].prezime, "Zlotrg");
    slog[4].ocjene[0] = 6;
    slog[4].ocjene[1] = 7;
    slog[4].ocjene[2] = 8;
    slog[4].ocjene[3] = 5;
    slog[4].ocjene[4] = 10;
    slog[4].br_ocjena = 5;

    /*    for (i = 0; i < 5; i++) {
            printf("     Slog studenata : %d \n", i + 1);
            printf(" %s", slog[i].prezime);
            printf(" %s", slog[i].ime);
            printf(" \n");
            printf(" Ocjene su: ");
            for (j = 0; j < slog[i].br_ocjena; j++) {
                printf(" %d", slog[i].ocjene[j]);
            }
            printf(" \n");
            printf(" Broj ocjena je: %d \n", slog[i].br_ocjena);
        }*/
    genijalci(slog, 5, 6.1);
    return 0;
}