#include <stdio.h>

//funkcija koja ce da ispise sve nizove(stringove) koji se nalažu u zadatku
void ispisi(char *s) {
    int i = 0;
    while(s[i] != '\0'){
        printf("%c", s[i++]);
    }
}
//Funkcija koja koja broji koliko se koje slovo puta javlja u stringu
int brojPonavljanja(char* s, char trazena){
    int brojac = 0;
    while (*s != 0){
        if (*s == trazena)
            brojac++;
        s++;
    }
    return brojac;
}
//prilikom formiranja sifrarnika treba se provjeriti da li se znakovi koje treba dopisati vec nalaze u sifrarniku
int daLiZnakIma(char znak, int duzina, char* nizSlova){
    int i = duzina-1;
    while (i >= 0){
        if(nizSlova[i--] == znak)
            return 1;
    }
    return 0;
}
//Funkcija koja dopunjava niz 
void dopuniNiz(int duzinaNiza, char *nizSlova){
    int i = duzinaNiza;
    char znak = 32;
    while (znak <= 126){
        if(!daLiZnakIma(znak, duzinaNiza, nizSlova)){
            nizSlova[i++] = znak++;
        }
        else znak++;
    }
    nizSlova[i] = '\0';
}
//funkcija koja mijenja slova iz sifrarnika sa slovima u stringu zbor rasporeda po broju ponavljanja
void zamijeniSlova(char *maxSlovo, char* zamjensko_slovo, char* testnoslovo){
    *testnoslovo = *zamjensko_slovo;
    *zamjensko_slovo = *maxSlovo;
    *maxSlovo = *testnoslovo;
}
//funkcija koja mijenja vrijednosti brojaca redajuci ih od najveceg do najmanjeg
void zamijeniBrojace(int *testni_broj, int *zamjenski_broj, int *max){
    *testni_broj = *zamjenski_broj;
    *zamjenski_broj = *max;
    *max = *testni_broj;
}
//Funkcija koja poziva dvije prethodne funkcije i reda sifrarnik i tabelu brojaca po broju ponavljaja pri tome pazeci na vrijednos u ascii tabeli
void poredajPoRedu(int* brojaci, int duzina, char* nizSlova){
    int max, i = 0, j = 0;
    char maxSlovo;
    while (i < duzina-1){
        max = brojaci[i];
        maxSlovo = nizSlova[i];
        j = i;
        while (j < duzina){
            if (brojaci[j] >= max){
                if (brojaci[j] == max){
                    if (maxSlovo > nizSlova[j]) {
                        zamijeniBrojace(brojaci+i, brojaci+j, &max);
                        zamijeniSlova(&maxSlovo, nizSlova+j, nizSlova+i);
                    }
                }
                else{
                    zamijeniBrojace(brojaci+i, brojaci+j, &max);
                    zamijeniSlova(&maxSlovo, nizSlova+j, nizSlova+i);
                }
            }
            j++;
        }
        i++;
    }
}
//Funkcija koja mijenja slova stringa sa znakom (126 - (pozicija u sifrarniku tog slova))
void izmijeniKodiraj(char *tekst, char* code){
    int i = 0, j = 0;
    while (tekst[i] != '\0') {
        j = 0;
        while(code[j] != '\0') {
            if (code[j] == tekst[i]) break;
            j++;
        }
        tekst[i] = 126 - j;
        i++;
    }
}
//Glavna funkcija koja vrsi kodiranje datog teksta kao sto je trazeno u postavci zadatka uz pomoc ostalih funkcija
char* kodiraj(char* text, char* code){
    char *p, *q, temp;
    int brojacSlova[96] = {0};
    p = text;
    int i = 0;
    while (*p != '\0'){
        temp = *p;
        if (p > text){
            q = p-1;
            while (q >= text && *p != '\0'){
                if (temp == *q){
                    p++;
                    temp = *p;
                    q = p-1;
                }
                q--;
            }
        }
        if (temp == '\0') {
            break;
        }
        brojacSlova[i] = brojPonavljanja(text, temp);
        code[i] = *p;
        i++;
        p++;
    }
    poredajPoRedu (brojacSlova, i, code);
    dopuniNiz(i, code);
    izmijeniKodiraj(text, code);
    return text;
}
//Funkcija koja vrsi dekodiranje kodiranog teksta uz pomoc tablice sifrovanja
char* dekodiraj(char* text, char* code) {
    int i = 0, j = 0;
    while (text[i] != '\0') {
        j = 0;
        while(code[j] != '\0') {
            if (text[i] + j == 126) break;
            j++;
        }
        text[i] = code[j];
        i++;
    }
    return text;
}
int main() {
    return 0;
}