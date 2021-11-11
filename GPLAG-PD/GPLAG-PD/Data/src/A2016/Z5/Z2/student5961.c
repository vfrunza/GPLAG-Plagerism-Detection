#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void unesi(char niz[], int velicina) {
    char znak = getchar();
    if (znak == '\n') znak = getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i] = '\0';
}

void zapisiKompresovaniTekst(char* ime_ulaza, char* ime_izlaza, char rijeci[][10], int* indeksi, int *ponavljanja){
    FILE* ulaz = fopen(ime_ulaza, "r");
    FILE* izlaz = fopen(ime_izlaza, "a+");
    char znak1 = fgetc(ulaz);
    while (znak1 != EOF){
        //Upisujem sve razmake, nove redove...
        while((znak1 < 'A' || znak1 > 'Z' && znak1 < 'a' || znak1 > 'z') && znak1 != EOF){
            fputc(znak1, izlaz);
            znak1 = fgetc(ulaz);
        }
        if (znak1 == EOF) break;
        //provjeravam da li se rijec nalazi na tabeli
        int zamjena = 0, vel_trenutne_rijeci = 0;
        char trenutna_rijec[10];
        long long pocetak_rijeci = ftell(ulaz) - 1;
        while((znak1 >= 'A' && znak1 <= 'Z' || znak1 >= 'a' && znak1 <= 'z') && znak1 != EOF){
            trenutna_rijec[vel_trenutne_rijeci++] = znak1;
            znak1 = fgetc(ulaz);
            if (vel_trenutne_rijeci == 10)  break;
        }
        if (vel_trenutne_rijeci > 1 && vel_trenutne_rijeci < 10) {
            trenutna_rijec[vel_trenutne_rijeci] = '\0';
            int i = 0;
            while (i < 10) {
                if (ponavljanja[i] == 0) break;
                if (strcmp(rijeci[indeksi[i]], trenutna_rijec) == 0) {
                    zamjena = 20 + i;
                    break;
                }
                i++;
            }
        }
        if(zamjena){
            fputc(zamjena, izlaz);
            while((znak1 >= 'A' && znak1 <= 'Z' || znak1 >= 'a' && znak1 <= 'z') && znak1 != EOF) znak1 = fgetc(ulaz);
        }
            //Ako se rijec ne nalazi u tabeli onda je samo prepisem
        else {
            fseek(ulaz, pocetak_rijeci, SEEK_SET);
            znak1 = fgetc(ulaz);
            while((znak1 >= 'A' && znak1 <= 'Z' || znak1 >= 'a' && znak1 <= 'z') && znak1 != EOF){
                fputc(znak1, izlaz);
                znak1 = fgetc(ulaz);
            }
        }
    }
    fclose(ulaz);
    fclose(izlaz);

}

int porediLeksikografski(char* rijec1, char* rijec2) {
    int i = 0;
    while (rijec1[i] != '\0' && rijec2[i] != '\0' && rijec1[i] == rijec2[i]) i++;
    if (rijec1[i] != '\0' && rijec2[i] != '\0') return rijec1[i] < rijec2[i];
    if (rijec1[i] != '\0' && rijec2[i] == '\0') return 0;
    if(rijec1[i] == '\0' && rijec2[i] != '\0') return 1;
    return 0;
}

void ubaciRijecUNajbrojnije(char rijeci[][10], int* indeksi,  int *ponavljanja, char* rijec, int indeks_rijeci, int ponavljanje_rijeci) {
    int i = 0;
    while (i < 10) {
        if (ponavljanja[i] == 0) {
            indeksi[i] = indeks_rijeci;
            ponavljanja[i] = ponavljanje_rijeci;
            return;
        }
        /* ukoliko primljena rijec se ponavlja veci broj puta od neke druge rijeci ili
          ukoliko je broj ponavljanja isti a rijec leksikografski prednjaci zamijeni sa trenutnom */
        if (ponavljanje_rijeci > ponavljanja[i] ||
            (ponavljanje_rijeci == ponavljanja[i] && porediLeksikografski(rijec, rijeci[indeksi[i]]) == 1)) {
            // stavi rijec na ovo mjesto a sve ostale pomjeri dalje
            int j = 9;
            while (j > i) {
                int temp_ponavljanja, temp_indeks;
                temp_ponavljanja = ponavljanja[j];
                ponavljanja[j] = ponavljanja[j - 1];
                ponavljanja[j - 1] = temp_ponavljanja;
                temp_indeks = indeksi[j];
                indeksi[j] = indeksi[j-1];
                indeksi[j-1] = temp_indeks;
                j--;
            }
            ponavljanja[i] =  ponavljanje_rijeci;
            indeksi[i] = indeks_rijeci;
            break;
        }
        i++;
    }
}

int nadjiRijec(char rijeci[][10], char* rijec, int broj_rijeci) {
    int i = -1;
    while (++i < broj_rijeci) {
        int j = 0;
        while (rijeci[i][j] != '\0' && rijec[j] != '\0' && rijeci[i][j] == rijec[j]) j++;
        if (rijeci[i][j] == '\0' && rijec[j] == '\0') return i;
    }
    return -1;
}

void kompresuj(char *ime_ulaza, char* ime_izlaza) {
    FILE *ulazna_datoteka = fopen(ime_ulaza, "r");
    char rijeci[1000][10];
    int ponavljanja_rijeci[1000] = {0}, broj_rijeci = 0;
    char znak = fgetc(ulazna_datoteka);
    // Naci sva ponavljanja rijeci
    while (znak != EOF){
        char trenutna_rijec[10];
        int vel_trenutne_rijeci  = 0;
        // Preskacemo sve znakove koji nisu slova
        while ((znak < 'A' || znak > 'Z' && znak < 'a' || znak > 'z') && znak != EOF) znak = fgetc(ulazna_datoteka);
        // Dosli smo do rijeci, ucitamo je ako je manja od 10 znakova
        while((znak >= 'A' && znak <= 'Z' || znak >= 'a' && znak <= 'z') && znak != EOF){
            trenutna_rijec[vel_trenutne_rijeci++] = znak;
            znak = fgetc(ulazna_datoteka);
            // Ako rijec ima vise od 10 znakova idemo do kraja rijeci i nastavljamo dalje
            if (vel_trenutne_rijeci == 10) {
                while((znak >= 'A' && znak <= 'Z' || znak >= 'a' && znak <= 'z') && znak != EOF) znak = fgetc(ulazna_datoteka);
                break;
            }
        }
        if (vel_trenutne_rijeci > 1 && vel_trenutne_rijeci < 10) {
            trenutna_rijec[vel_trenutne_rijeci] = '\0';
            int indeks_rijeci = nadjiRijec(rijeci, trenutna_rijec, broj_rijeci);
            if (indeks_rijeci != -1) ponavljanja_rijeci[indeks_rijeci]++;
            else {
                strcpy(rijeci[broj_rijeci], trenutna_rijec);
                ponavljanja_rijeci[broj_rijeci]++;
                broj_rijeci++;
            }
        }
    }
    // Naci deset najbrojnijih rijeci
    int indeksi_najbrojnijih[10] = {0};
    int ponavljanja_najbrojnijih[10] = {0};
    int i = 0;
    for (i = 0; i < broj_rijeci; i++) {
        ubaciRijecUNajbrojnije(rijeci, indeksi_najbrojnijih, ponavljanja_najbrojnijih, rijeci[i], i, ponavljanja_rijeci[i]);
    }

    // Zapisi pronadjene rijeci u izlaznu datoteku
    FILE* izlazna_datoteka = fopen(ime_izlaza, "w+");
    // Zapisujemo tabelu rijeci
    i = 0;
    while (i < 10) {
        if (ponavljanja_najbrojnijih[i] != 0){
            int j = 0;
            while (rijeci[indeksi_najbrojnijih[i]][j] != '\0') {
                fputc(rijeci[indeksi_najbrojnijih[i]][j++], izlazna_datoteka);
            }
        }
        else {
            fprintf(izlazna_datoteka, "\n");
            break;
        }
        fprintf(izlazna_datoteka, "\n");
        i++;
    }
    //Nakon sto se napravi tabela rijeci mora da se zatvori izlazna datoteka zbog daljeg dopisivanja u nju iz druge funkcije
    //Dok za ulaznu nije obavezno ali je dobro zbog smanjenja koristene memorije
    fclose(ulazna_datoteka);
    fclose(izlazna_datoteka);
    zapisiKompresovaniTekst(ime_ulaza, ime_izlaza, rijeci, indeksi_najbrojnijih, ponavljanja_najbrojnijih);
    printf("Datoteka kompresovana.\n");

}

void dekompresuj(char*ime_ulaza, char* ime_izlaza){
    FILE* ulaz = fopen(ime_ulaza, "r");
    FILE* izlaz = fopen(ime_izlaza, "w+");
    if (ulaz == NULL || izlaz == NULL) exit(1);
    char znak = fgetc(ulaz);
    int brojac_rijeci = 0;
    char rijeci[10][10];
    if (znak == '\n'){
        printf("Nema rijeci u tabeli");
        fclose(ulaz);
        return;
    }
    // Ucitavamo rijeci iz tabele
    while (znak != '\n'){
        int j = 0;
        while (znak != '\n') {
            rijeci[brojac_rijeci][j++] = znak;
            znak = fgetc (ulaz);
        }
        rijeci[brojac_rijeci][j] = '\0';
        brojac_rijeci++;
        if (brojac_rijeci == 10) break;
        znak = fgetc(ulaz);
    }

    // Dosli smo do teksta
    znak = fgetc(ulaz);
    char max_code = brojac_rijeci - 1 + 20;
    char min_code = 20;
    while (znak != EOF) {
        // Prepisi sve znakove koji nisu slova
        while ((znak < 'A' || znak > 'Z' && znak < 'a' || znak > 'z') && znak != EOF && (znak < min_code || znak > max_code)) {
            fputc(znak, izlaz);
            znak = fgetc(ulaz);
        }
        if (znak == EOF) break;
        // Ako je znak jedan od kodova provjeri da nije u sklopu rijeci i nadji indeks odgovarajuce rijeci
        int index_rijeci = -1;
        if (znak >= min_code && znak <= max_code) {
            char temp_znak = znak;
            znak = fgetc(ulaz);
            if ((znak < 'A' || znak > 'Z' && znak < 'a' || znak > 'z')) {
                index_rijeci = temp_znak % 20;
            } else {
                fputc(temp_znak, izlaz);
            }
        }
        // Ako je indeks odgovarajuce rijeci pronadjen zapisi je
        if (index_rijeci != -1) {
            // Zapisujemo zamjensku rijec
            int i = 0;
            while (rijeci[index_rijeci][i] != '\0') {
                fputc(rijeci[index_rijeci][i++], izlaz);
            }
        }
        // Prepisi ostatak rijeci koja nije imala zamjenu
        while((znak >= 'A' && znak <= 'Z' || znak >= 'a' && znak <= 'z') && znak != EOF) {
            fputc(znak, izlaz);
            znak = fgetc(ulaz);
        }
    }


    fclose(ulaz);
    fclose(izlaz);
    printf("Datoteka dekompresovana.\n");
}

int main() {
    int odabir;
    char ime_ulazne_datoteke[1000];
    char ime_izlazne_datoteke[1000];
    do {
        printf("Odaberite: 1 - kompresuj, 2 - dekompresuj, 0 - izlaz: ");
        scanf("%d", &odabir);
        switch (odabir){
            case 1:
                printf("Unesite ime ulazne datoteke: ");
                unesi(ime_ulazne_datoteke, 1000);
                printf("Unesite ime izlazne datoteke: ");
                unesi(ime_izlazne_datoteke, 1000);
                kompresuj(ime_ulazne_datoteke, ime_izlazne_datoteke);
                break;
            case 2:
                printf("Unesite ime ulazne datoteke: ");
                unesi(ime_ulazne_datoteke, 1000);
                printf("Unesite ime izlazne datoteke: ");
                unesi(ime_izlazne_datoteke, 1000);
                dekompresuj(ime_ulazne_datoteke, ime_izlazne_datoteke);
                break;
            case 0:
                return 0;
            default:
                break;
        }
        printf ("\n");
    } while (odabir != 0);
    return 0;
}