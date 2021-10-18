#include <stdio.h>
int main ()
{
    int i, j, k, j2, k2, redovi, kolone, sirina; //radi jednostavnosti primjera zamislimo da su nam hardkodirani brojevi (lako je napisati do-while za potpuno ispravan kod)
    printf("Unesite broj redova: ");
    scanf("%d", &redovi);
    printf("Unesite broj kolona: ");
    scanf("%d", &kolone);
    printf("Unesite sirinu jedne kolone: ");
    scanf("%d", &sirina);
    for (i=0; i<redovi; i++) //ispisuje onoliko puta koliko nam redova treba, trebalo bi da je jasno
    {
        for (j=0; j<kolone; j++) //ispisujemo kolonu
        {
            if (j==0) printf("+"); //ako je prvi clan ispisi +, jer u protivnom imamo duple pluseve, npr. +---++---+
            for (k=0; k<sirina; k++) printf ("-"); //onoliko koliko korisnik zada sirinu ispisa kvadratica, toliko nam treba -
            printf ("+"); //svaki red zavrsava sa plusem
        }
        printf("\n"); //zavrsili smo ispis reda, sada prelazimo u iduci red van petlje ispisa
        for (j2=0; j2<kolone; j2++) //nakon sto je ispisan cijeli red sa + i -, potrebno je ispisati međured
        {
            if (j2==0) printf ("|"); //ispisujemo prvi znak, isti slucaj kao u prvoj petlji, ne zelimo duple |
            for (k2=0; k2<sirina; k2++) printf (" "); //ispisujemo onoliko razmaka kolika je sirina
            printf ("|"); //posljednji clan
        }
        printf("\n"); //prelazimo u novi red i proces se ponavlja
    }
    //eh sad posto se velika petlja zavrsava sa redom |   |, potrebno je ispisati i posljednji red zasebno (mada postoje efikasnija rjesenja, radi jednostavnosti cemo zasebno) da to sve izgleda fino
               for (j=0; j<kolone; j++)
        {
            if (j==0) printf("+"); //analogno prethodnom u petlji, obicni red sa + i -
            for (k=0; k<sirina; k++) printf ("-");
            printf ("+");
        }
    return 0;
}