#include <stdio.h>
#include <string.h>

#define MAXN 5000
int duzina(char *s) {
    int duz = 0;
    while (*s++) duz++;
    return duz;
}
void zamijeni(char *a, char *b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}
char* kodiraj(char *ulazni, char *tablica) {
    int n = duzina(ulazni);
    char *p = ulazni;
    char *q = tablica;
    int ascii_brojac[128];
    char nova_tablica[128];
    int bio[128];
    char coded[MAXN];
    int indeks_slova[128];
    int i, X;
    for (i = 0; i < 128; i++) ascii_brojac[i] = bio[i] = 0;
    
    while (*p != '\0') {
        ascii_brojac[(int)*p]++;
        p++;
    }
    p = ulazni;
    for (X = 32; X < 128; X++) {
        int maxi = -1;
        int indeks_maxi = -1;
        for (i = 32; i < 128; i++) {
            if (ascii_brojac[i] > maxi && !bio[i]) {
                maxi = ascii_brojac[i];
                indeks_maxi = i;
            }
        }
        //printf("%c\n", );
        *q = (char)(126-X+32);
        bio[indeks_maxi] = 1;
        p = ulazni;
        for (i = 0; *p != '\0'; i++) {
            if (*p == (char)indeks_maxi) {
                //printf("%c mijenjam sa %c\n", *p, 126-X+32);
                coded[i] = *q;
            }
            p++;
        }
        *q = (char)indeks_maxi;
        q++;
    }
    *(q - 1) = '\0';
    
    q = tablica;
    p = ulazni;
    
    for (i = 0; i < n; i++)
        *(p + i) = coded[i];
    return p;
}

char* dekodiraj(char tekst[], char *tablica) {
    char *p = tekst;
    char *q = tablica;
    int ascii_brojac[128];
    int bio[128];
    int i, X;
    int n = duzina(tekst);
    int *decoded[MAXN];

    for (i = 0; i < 128; i++) ascii_brojac[i] = bio[i] = 0;
    
    while (*p != '\0') {
        ascii_brojac[(int)*p]++;
        p++;
    }
    p = tekst;
    q = tablica;
    for (X = 32; X < 128 && *q != '\0'; X++) {
        int maxi = -1;
        int indeks_maxi = -1;
        for (i = 32; i < 128; i++) 
            if (ascii_brojac[i] >= maxi && !bio[i]) {
                maxi = ascii_brojac[i];
                indeks_maxi = i;
            }
        bio[indeks_maxi] = 1;
        p = tekst;
        for (i = 0; *p != '\0'; i++) {
            if (*p == (char)indeks_maxi) {
                decoded[i] = q;
            }
            p++;
        }
        q++;
        //printf("\n");
        //printf("%c, %d, %d\n", (char)indeks_maxi, indeks_maxi, maxi);
    }
    p = tekst;
    for (i = 0; i < n; i++)
        *(p+i) = *decoded[i];
    *(p + n) = '\0';
    return p;
}
int main() {
	printf("%s\n", kodiraj("LLMLNLNMONM", ""));
	printf("%s", dekodiraj("~~}~|~|}{|}", "LMNO !""#$%"));
	return 0;
}
