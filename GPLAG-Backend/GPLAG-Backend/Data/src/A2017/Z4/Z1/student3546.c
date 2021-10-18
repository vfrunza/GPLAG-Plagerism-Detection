#include <stdio.h>
char* ubacibroj(char *pok, int broj) {
    /* Funkcija koja ubacuje broj u string (ovo NIJE funkcija koja se trazi u zadatku) */
    int temp, brojac=0, negativanBroj=0;
    char *pok2;
    if (broj<0) {
        broj*=-1;
        brojac++; /* Brojac broji koliko ce se novih elemenata ubaciti u string */
        negativanBroj=1; /*Logicka varijabla koja ce u slucaju potrebe staviti - ispred broja u stringu, ako je on negativan */
    }
    temp=broj;
    do {
        temp/=10;
        brojac++;
    } while (temp); /* Temp varijabla preuzima vrijednost broja i broji njegove cifre */
   
    pok2=pok;
    while (*pok2)
        pok2++; /* Pomjera pomocni pokazivac na kraj stringa */
    *(pok2+brojac)='\0'; /*Pomjera kraj stringa za broj novih elemenata */
    pok2--;
    while (pok2>=pok) {
        *(pok2+brojac)=*pok2; /* Pomjera sve elemente za broj novih elemenata */
        pok2--;
    }
    pok2+=brojac; /* Pomjera pokazivac za broj novih elemenata, da bi se mogao broj normalno pretvoriti u string */
    do {
        *pok2--=broj%10+'0';
        broj/=10;
    } while(broj); /* Ubacivanje broja u string */
    if (negativanBroj) {
        *pok2='-';
        pok2--;
    }
    pok2+=brojac+1; /*Pomjeramo pokazivac da pokazuje na element iza broja, da bi funkcija ubaci_broj mogla normalno nastaviti sa radom */
    return pok2;
}
int prebrojirijeci(char* niz) {
    /* Blago modificirana funkcija prebrojavanja rijeci TUT 10 ZAD 4 (modificirana za novu definiciju rijeci) */
    int brojac, brojrijeci=0;
    while (*niz) {
        brojac=0;
        while (*niz!=' ' && *niz!='\n' && *niz!='\t' && *niz!='\0') {
            brojac++;
            niz++;
        }
        if (brojac) {
            brojrijeci++;
            niz--;
        }
        niz++;
    }
    return brojrijeci;
}
void ubacirazmak(char* niz) {
    /* Ovu funkciju koristimo u slucaju da se izmedju dvije rijeci nalazi samo jedan razmak */
    char *pokNaKraj;
    pokNaKraj=niz;
    while (*pokNaKraj) {
        pokNaKraj++; /*Pomjeramo pokazivac na kraj niza */
    }
    *(pokNaKraj+1)='\0';
    while (pokNaKraj>niz) {
        *pokNaKraj=*(pokNaKraj-1); /*Pomjeramo sve elemente za jedno mjesto */
        pokNaKraj--;
    }
    /* Nema potrebe da stavimo *pokNakraj=' ', jer ce se svejedno u funkciji ubaci_broj slati u ovu funkciju pokazivac na razmak, tako da ce posljednji prekopirani element biti razmak */
}
char* ubaci_broj(char* tekst, int broj) {
    int brojrijeci=prebrojirijeci(tekst);
    int brojubacivanja=0;
    char* returnPok=tekst;
    while (*tekst==' ' || *tekst=='\n' || *tekst=='\t')
        tekst++; /* Pomjeramo pokazivac do prve rijeci */
    while (brojubacivanja<brojrijeci-1) {
        while (*tekst!=' ' && *tekst!='\n' && *tekst!='\t') {
            tekst++; /* Pomjeramo pokazivac na prvi razmak izmedju dvije rijeci */
        }
        if (*(tekst+1)!=' ')
            ubacirazmak(tekst); /* U slucaju da se izmedju dvije rijeci nalazi samo jedan razmak, pozivamo funkciju ubacirazmak */
        tekst++;
        tekst=ubacibroj(tekst, broj); /* Prvo pomjeramo pokazivac na drugi razmak, jer po uslovu zadatka treba da se ostavi jedan razmak izmedju kraja rijeci i broja, pa onda pozivamo funkciju ubacibroj */
        brojubacivanja++;
        while (*tekst==' ' || *tekst=='\n' || *tekst=='\t')
            tekst++; /* Pomjeramo pokazivac na sljedecu rijec */
    }
    return returnPok;
}
int main() {
    char niz[100]={"Sta ja znam et"};
    printf("%s", ubaci_broj(niz, -123));
   
    return 0;
}