#include <stdio.h>
#include <string.h>

struct Datum {
    int dan, mjesec, godina;
};

struct Uposlenik {
    char ime_prezime[50];
    struct Datum datum_rodjenja;
};

int PoredjenjePrezimena (char *p1, char *p2) {
    char *pomocni1 = p1;
    char *pomocni2 = p2;
    int brojac_razmaka1 = 0;
    int brojac_razmaka2 = 0;
    int brojac_crtica1 = 0;
    int brojac_crtica2 = 0;

    while(*pomocni1 != '\0') {
        if(*pomocni1 == ' ') brojac_razmaka1++;
        if(*pomocni1 == '-') brojac_crtica1++;
        pomocni1++;
    }

    while(*pomocni2 != '\0') {
        if(*pomocni2 == ' ') brojac_razmaka2++;
        if(*pomocni2 == '-') brojac_crtica2++;
    }

    if(brojac_razmaka1 == 1 && brojac_razmaka2 == 1) {
        while(*p1 != ' ') p1++;
        p1++;
        while(*p2 != ' ') p2++;
        p2++;
        if(strcmp(p1, p2) == 0) return 0;
        return 1;
    }
    else if(brojac_razmaka1 == 2 && brojac_razmaka2 == 2) {
        while(*p1 != ' ') p1++;
        p1++;
        while(*p1 != ' ') p1++;
        p1++;
        while(*p2 != ' ') p2++;
        p2++;
        while(*p2 != ' ') p2++;
        p2++;
        if(strcmp(p1,p2) == 0) return 0;
        return 1;
    }
    else if(brojac_razmaka1 == 1 && brojac_razmaka2 == 2){
        while(*p1 != ' ') p1++;
        p1++;
        while(*p2 != ' ') p2++;
        p2++;
        while(*p2 != ' ') p2++;
        p2++;
        if(strcmp(p1,p2) == 0) return 0;
        return 1;
    }
    else if(brojac_razmaka1 == 2 && brojac_razmaka2 == 1) {
        while(*p1 != ' ') p1++;
        p1++;
        while(*p1 != ' ') p1++;
        p1++;
        while(*p2 != ' ') p2++;
        p2++;
        if(strcmp(p1,p2) == 0) return 0;
        return 1;
    }
    else if(brojac_crtica1 == 1 && brojac_crtica2== 1) {
        while(*p1 != ' ') p1++;
        p1++;
        while(*p2 != ' ') p2++;
        p2++;
        if(strcmp(p1,p2) == 0) return 0;
        else {
            while(*p1 != '-') p1++;
            p1++;
            while(*p2 != '-') p2++;
            p2++;
            if(strcmp(p1,p2) == 0) return 0;
            return 1;
        }
    }
    else if(brojac_crtica1 == 1 && brojac_crtica2 == 0) {
        if(brojac_razmaka2 == 2) {
            while(*p1 != ' ') p1++;
            p1++;
            while(*p2 != ' ') p2++;
            p2++;
            while(*p2 != ' ') p2++;
            p2++;
            if(strcmp(p1,p2) == 0) return 0;
            else {
                while(*p1 != '-') p1++;
                p1++;
                if(strcmp(p1,p2) == 0) return 0;
                return 1;
            }
        }else {
            while(*p1 != ' ') p1++;
            p1++;
            while(*p2 != ' ') p2++;
            p2++;
            if(strcmp(p1,p2) == 0) return 0;
            else {
                while(*p1 != '-') p1++;
                p1++;
                if(strcmp(p1,p2) == 0) return 0;
                return 1;
            }
        }
    }
    else if(brojac_crtica1 == 0 && brojac_crtica2 == 1) {
        if(brojac_razmaka1 == 2) {
            while(*p1 != ' ')p1++;
            p1++;
            while(*p1 != ' ')p1++;
            p1++;
            while(*p2 != ' ') p2++;
            p2++;
            if(strcmp(p1,p2) == 0) return 0;
            else {
                while(*p2 != '-') p2++;
                p2++;
                if(strcmp(p1,p2) == 0) return 0;
                return 1;
            }
        }else {
            while(*p1 != ' ') p1++;
            p1++;
            while(*p2 != ' ') p2++;
            p2++;
            if(strcmp(p1,p2) == 0) return 0;
            else {
                while(*p2 != '-') p2++;
                p2++;
                if(strcmp(p1,p2) == 0) return 0;
                return 1;
            }
        }
    }
    else if(brojac_crtica1 == 1 && brojac_crtica2 == 1) {
        while(*p1 != ' ') p1++;
        p1++;
        while(*p2 != ' ') p2++;
        char *pomocni = p2;
        if(strcmp(p1,p2) == 0) return 0;
        else {
            while(*p2 != '-') p2++;
            p2++;
            if(strcmp(p1,p2) == 0) return 0;
            else {
                while(*p1 != '-') p1++;
                p1++;
                if(strcmp(p1,pomocni1) == 0) return 0;
                return 1;
            }
        }
    }

}
int BrojDana(struct Datum d) {
    int dani[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int i;
    int broj_dana = 0;

    for(i = 1800; i < d.godina; i++) {
        if(i % 4 == 0 && (i % 100 != 0 || i % 400 == 0)) dani[1] = 29;
        else dani[1] = 28;

        int j;
        for(j = 0; j < 12; j++) {
            broj_dana += dani[i];
        }
    }
    if(d.godina % 4 == 0 && (d.godina % 100 != 0 || d.godina % 400 == 0)) dani[1] = 29;
    else dani[1] = 28;
    for(i = 0; i < d.mjesec; i++) {
        broj_dana += dani[i];
    }
    broj_dana += d.dan;

    return broj_dana;
}
int DaLiJeStariji(struct Uposlenik kandidat, struct Uposlenik direktor, int broj_dana) {
    if(broj_dana < 0) broj_dana *= -1;
    if(BrojDana(kandidat.datum_rodjenja) - BrojDana(direktor.datum_rodjenja) > broj_dana) return 1;
    return 0;
}
int suzi_listu(struct Uposlenik *kandidati, int vel, struct Uposlenik direktor, int broj_dana) {
    int i,j;
    for(i = 0; i < vel; i++) {
        if(PoredjenjePrezimena(kandidati[i].ime_prezime,direktor.ime_prezime) == 1 && DaLiJeStariji(kandidati[i],
            direktor, broj_dana) == 1) {
                for(j = i; j < vel - 1; j++) {
                    kandidati[j] = kandidati[j+1];
                }
                i--;
                vel--;
            }
    }
    return vel;
}

int main()  /* AT4: 1900-ta godina nije bila prestupna */
{
    struct Uposlenik direktor = {"Mujo Mujic", {1, 3, 1900} };
    struct Uposlenik kandidati[7] = {
        { "Meho Mehic", { 31, 1, 1900 } },
        { "Pero Peric", { 1, 2, 1900 } },
        { "Sara Sarac", { 2, 2, 1900 } },
        { "Fata Mujic", { 1, 2, 1896 } },
        { "Jozo Jozic", { 1, 10, 1900 } },
        { "Mijo Mijic", { 4, 3, 1899 } },
        { "Suljo Suljic", { 15, 1, 1902 } },
    };

    int novi_br = suzi_listu(kandidati, 7, direktor, 28);
    int i;
    printf("Nakon suzenja liste:\n");
    for (i=0; i<novi_br; i++)
        printf("%s\n", kandidati[i].ime_prezime);
    return 0;
}