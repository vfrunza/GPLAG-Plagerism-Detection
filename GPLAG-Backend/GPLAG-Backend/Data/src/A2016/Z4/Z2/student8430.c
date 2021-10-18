#include <stdio.h>
#include <stdlib.h>
#define vel 96
int pos (char niz2[], char veli){
    char *p;
    for(p=niz2;*p;p++) if(*p==veli) return p-niz2;
}
int duzina(char *s)
{
    char *p;
    p=s;
    while(*s!='\0') s++;
    return s-p;
}

char pozicija_dekodiranja (char niz2[], char veli)
{
    char *p;
    for (p=niz2; *p; p++) if (126-pos(niz2,*p)==veli) return *p;
}
char *kodiraj(char niz_1[], char niz_2[vel])
{
    int i, j = 0, z, brojac[127] = {0}, brojac2[127] = {0}, max = 0, kanter = 0, brisi;
    char c, *p=niz_1, *p2;
    char pomocni[1000]="";
    for (z=0; z<duzina(niz_1); z++) pomocni[z]=niz_1[z];
    p2=pomocni;
    for (i = 0; niz_1[i] != '\0'; i++) {
        c = niz_1[i];
        brojac[c]++;
        brojac2[c]++;
    }
    for (i = 32; i < 127; i++) {
        if (brojac[i]!= 0) kanter++;
    }
    for (j = 0; j < kanter; j++) {
        max = 0;
        for (i = 32; i < 127; i++) {
            if (brojac[i] > max) {
                max = brojac[i];
                brisi = i;
            }
        }
        niz_2[j] = brisi;
        brojac[brisi] = 0;
    }
    brisi = j;
    for (i = 32; i < 127; i++) {
        if (brojac2[i] == 0) niz_2[j++] = i;
    }

    niz_2[brisi+95] = '\0';



    for (i = 0; niz_1[i] != '\0'; i++) {
        for (j = 0; niz_2[j]!='\0'; j++) {
            if (niz_2[j] == niz_1[i]) {
                niz_1[i] = (char)126-j;
                break;
            }
        }
    }
    return p;
}

char *dekodiraj(char niz_1[], char niz_2[])
{
   char *i, j;
    char *p=niz_1;
    for (i=niz_1;*i;i++) *i=pozicija_dekodiranja(niz_2,*i);
    return p;
}

int main()
{

    return 0;
}
