#include <stdio.h>

int duzinaRijeci(char* rijec) {
    int duzina = 0;
    while (*rijec++ != '\0')  duzina++;
    return duzina;
}
// Funkcija koja izbacuje rijec sa lokacij
void izbaciRijecSaLokacije(char* tekst, int index){
    int i = index;
    while(tekst[i] != ' ' && tekst[i] != '\0'){
        int j = i+1;
        while (tekst[j-1] != '\0') tekst[j-1] = tekst[j++];
    }
}
// Funkcija koja uveca string ya potrebnu velicinu pa upise rijec iy yamjene
void ubaciRijecNaLokaciju(char* tekst, char *rijec, int index) {
    int i = 0;
    int duzina_rijeci = duzinaRijeci(rijec);
    while(tekst[i] != '\0') i++;
    int temp = i;
    while (duzina_rijeci-- > 0){
        i = temp++;
        while (i >= index) {
            tekst[i+1] = tekst[i];
            i--;
        }
    }
    i = 0;
    while(rijec[i] != '\0'){
        tekst[index+i] = rijec[i++];
    }
}

int porediRijeci(char* rijec1, char* rijec2) {
    // uporedi rijeci
    while((*(rijec1) != '\0' || *(rijec2) != '\0') && (*rijec1 == *rijec2)) {
        rijec1++;
        rijec2++;
    }
    if (*rijec1 == '\0' && *rijec2 == '\0') return 1;
    return 0;
}

char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci) {
    if (broj_rijeci == 0 || tekst[0] == '\0') return tekst;
    int i = 0;
    while (tekst[i] != '\0') {
        while (tekst[i] == ' ') i++;
        if (tekst[i] == '\0') break;
        int j = 0; // sluzi za prolazak kroz rijec
        char temp;
        // Uvecavamo brojac j do kraja trenutne rijeci
        while (tekst[i + j] != ' ' && tekst[i + j] != '\0') j++;
        // Privremeno postavimo oznaku za kraj stringa na kraj rijeci
        temp = tekst[i+j];
        tekst[i+j] = '\0';
        int indeksRijec = -1, brojac_rijeci = 0;
        // Pokusajmo naci rijeci u nizu rijeci za zamjeniti
        while (brojac_rijeci < broj_rijeci) {
            if (porediRijeci(tekst + i, rijeci[brojac_rijeci])) {
                indeksRijec = brojac_rijeci;
                break;
            }
            brojac_rijeci++;
        }
        tekst[i+j] = temp;
        // Ukoliko je indeks rijeci = -1, rijec nije nadjena u nizu rijeci za zamjeniti
        if (indeksRijec != -1) {
            izbaciRijecSaLokacije(tekst, i);
            ubaciRijecNaLokaciju(tekst, zamjene[indeksRijec], i);
            i += duzinaRijeci(zamjene[indeksRijec]);
        } else i+=j;
    }
    return tekst;
}

int main() {
    char* rijeci[2] = { "Prijestolonasljednikovica" };
    char* zamjene[2] = { "c" };
    char tekst[100] = "Prijestolonasljednikovica";
    printf("%s", zamjena_rijeci(tekst, rijeci, zamjene, 1));
    return 0;
}