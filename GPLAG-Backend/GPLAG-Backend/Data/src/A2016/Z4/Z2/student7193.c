#include <stdio.h>

char staviKod(char x, char* sifrarnik) {
    int n = 0;
    while (*sifrarnik != 0) {
        if (x == *sifrarnik++) {
            return 126 - n;
        }
        n++;
    }
    return 0;
}

char* kodiraj (char* tekst, char* sifrarnik) {
    char* pocetakTeksta, *pocetakSifrarnika, *pom;
    int slova[95] = {0}, max = 0, i;
    
    pocetakTeksta = pom = tekst;
    pocetakSifrarnika = sifrarnik;
    
    while (*pom != 0) {
        slova[*pom-32]++;
        if (slova[*pom-32] > max)
            max = slova[*pom-32];
        pom++;
    }
    
    while (max >= 0) {
        for (i = 0; i < 95; i++) {
            if (max == slova[i]) {
                *sifrarnik = i + 32;
                sifrarnik++;
            }
        }
        max--;
    }
    while (*tekst != 0) {
	    *tekst = staviKod(*tekst, pocetakSifrarnika);
	    tekst++;
	}
	return pocetakTeksta;
}

char* dekodiraj (char* tekst, char* sifrarnik) {
	char* pocetak = tekst;
	while (*tekst != 0) {
	    *tekst = sifrarnik[126 - *tekst];
	    tekst++;
	}
	return pocetak;
}

int main() {
    char tablica[100] = "", tekst[100] = "LLMLNLNMONM";
    
    printf("%s\n", tekst);
    kodiraj(tekst, tablica);
	printf("%s\n", tekst);
	dekodiraj(tekst, tablica);
	printf("%s\n", tekst);
	
	return 0;
}
