#include <stdio.h>

// Ova funkcija provjerava da li je proslijedjeni znak slovo (a-z ili A-Z)
int daLiJeZnakSlovo(char s) {
    if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z')) {
        return 1;
    }
    return 0;
}
// Ova funkcija provjerava da li su dva slova jednaka, ne praveci razliku izmedju velikih i malih slova
int daLiSuJednakaSlova(char a, char b) {
    if (a == b) return 1;
    if (!daLiJeZnakSlovo(a) || !daLiJeZnakSlovo(b)) return 0;
    if (a > b && a == b + 32) return 1;
    if (a < b && a == b - 32) return 1;
    return 0;
}
//Ovo je funkcija u kojoj saljem lokacije rijec po rijec i provjeravam u stringu koliko se puta ponavlja
int brojPonavljanjaRijeci(char* s, int poc, int kraj){
    int i = kraj, brojac = 0, rijecDetektovana = 1, j = 0;
    while (s[i] != '\0'){
        if (daLiJeZnakSlovo(s[i-1])) {
            i++;
            continue;
        }
        j = 0;
        rijecDetektovana = 1;
        //Povecavajmo brojac j sve dok nalazimo rijec u tekstu
        while (daLiSuJednakaSlova(s[poc+j], s[i+j]) && poc + j < kraj) j++;
        /*Ako nakon provjere se sva slova rijeci podudaraju provjerim da li su obje rijeci dosle do kraja
        zbog toga sto se u jednoj rijeci moze nalaziti druga rijec a da nismo dosli do kraja te rijeci*/
        if (poc+j != kraj || daLiJeZnakSlovo(s[i+j])) rijecDetektovana = 0;
        if (rijecDetektovana) {
            brojac++;
            i+=j;
        }
        if (s[i] == '\0') break;
        i++;
    }
    return brojac;
}
// Ova funkcija izbacuje odredjenu rijec iz stringa
void izbaciRijec(char* p, int poc, int kraj){
    int i = 0, j, rijecDetektovana;
    // Kopirajmo rijec koja se ponavlja kao novi string
    char q[100000];
    while (i + poc < kraj){
        q[i] = p[i + poc];
        i++;
    }
    q[i] = '\0';
    i = 0;
    // Detektujemo pojavljivanje rijeci q u tekstu p i onda je izbacujemo
    while (p[i] != '\0'){
        if (i > 0 && daLiJeZnakSlovo(p[i-1])) {
            i++;
            continue;
        }
        j = 0;
        rijecDetektovana = 1;
        //Povecavajmo brojac j sve dok nalazimo rijec q u tekstu
        while (daLiSuJednakaSlova(q[j], p[i+j]) && q[j]!= '\0') j++;
        /*Ako nakon provjere se sva slova rijeci podudaraju provjerim da li su obje rijeci dosle do kraja
        zbog toga sto se u jednoj rijeci moze nalaziti druga rijec a da nismo dosli do kraja te rijeci*/
        if (q[j] != '\0' || daLiJeZnakSlovo(p[i+j])) rijecDetektovana = 0;

        // Ako je rijec detektovana izbaci je
        if (rijecDetektovana)
        {
            int temp = i;
            while (p[temp + j] != '\0') {
                p[temp] = p[temp + j];
                temp++;
            }
            p[temp] = p[temp + j];
        }
        if (*(p+i) == '\0') break;
        i++;
    }
}

char* izbaci_najcescu(char* text){
    int i = 0, pocetak_trenutne_rijeci = -1, kraj_trenutne_rijeci = -1, maksimalan_broj_ponavljanja = -1;
    int pocetak_najcesce_rijeci = -1, kraj_najcesce_rijeci = -1;
    //Provjeravam da li string uopste ima elemenata da ni bi radio operacije ispod jer bi pristupao neinicijalizovanim vrijednostima!!!
    if (text[i] == '\0') return text;
    while (text[i] != '\0'){
        //Registrujemo pocetak rijeci u stringu!
        if (pocetak_trenutne_rijeci == -1 && daLiJeZnakSlovo(text[i]))
            pocetak_trenutne_rijeci = i;
        //Kada dodemo do nekog znaka znaci da je to kraj rijeci pa to mjesto zapisujem kao kraj rijeci u matricu za duzine rijeci!
        if (pocetak_trenutne_rijeci != -1 && (!daLiJeZnakSlovo(text[i]) || text[i+1] == '\0')){
            if (daLiJeZnakSlovo(text[i])) kraj_trenutne_rijeci = i + 1;
            else kraj_trenutne_rijeci = i;
            //U niz brojaca za ponavljanje rijeci upisujem broj ponavljanja rijeci koju saljem u funkciju iz koje dobijam broj ponavljanja!
           int broj_ponavljanja_rijeci = brojPonavljanjaRijeci(text, pocetak_trenutne_rijeci, kraj_trenutne_rijeci);
            if (broj_ponavljanja_rijeci > maksimalan_broj_ponavljanja) {
                pocetak_najcesce_rijeci = pocetak_trenutne_rijeci;
                kraj_najcesce_rijeci = kraj_trenutne_rijeci;
                maksimalan_broj_ponavljanja = broj_ponavljanja_rijeci;
            }
            pocetak_trenutne_rijeci = -1;
        }
        i++;
    }
    //Sljedeci korak bi trebao biti izbacivanje rijeci koja se najvise ponavlja
    if (maksimalan_broj_ponavljanja == -1) return text;
    izbaciRijec (text, pocetak_najcesce_rijeci, kraj_najcesce_rijeci);
    return text;
}

int main() {
    
    return 0;
}